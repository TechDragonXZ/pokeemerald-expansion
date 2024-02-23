#include "global.h"
#include "bg.h"
#include "craft_menu.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "start_menu.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// Menu actions
enum CraftMenuActions {
    MENU_ACTION_SWAP,
    MENU_ACTION_BAG,
    MENU_ACTION_READY,
    MENU_ACTION_CANCEL,
};

// Table actions 
enum TableActions {
    TABLE_ACTION_BLANK,
    TABLE_ACTION_ITEM,
};

// sCurrentCraftTableItems[][] slot names
enum CraftTableSlots {
    CRAFT_TABLE_ITEM,
    CRAFT_TABLE_ACTION,
};

// Input handling
enum CraftState {
    STATE_TABLE_INPUT,
    STATE_OPTIONS_INPUT,
    STATE_CONFIRM_READY,
    STATE_CONFIRM_PACKUP,
};

// Confirm Messages
enum CraftConfirmMessages{
    CRAFT_PACKUP_CONFIRM,
    CRAFT_READY_CONFIRM
};

// IWRAM common
bool8 (*gMenuCallback)(void);

// EWRAM
EWRAM_DATA static u8 sCraftTableWindowId = 0;
EWRAM_DATA static u8 sCraftInfoWindowId = 0;
EWRAM_DATA static u8 sCraftOptionsWindowId = 0;
EWRAM_DATA static u8 sCraftSousChefsWindowId = 0;

EWRAM_DATA static u8 sCraftMenuCursorPos = 0;
EWRAM_DATA static u8 sInitCraftMenuData[1] = {0};
EWRAM_DATA static u16 sCurrentCraftTableItems[4][2] = {0}; //craft table items, actions
EWRAM_DATA static u8 sCraftState = 0;
EWRAM_DATA static u32 sPauseCounter = 0;
EWRAM_DATA static u8 (*sCraftDialogCallback)(void) = NULL;
EWRAM_DATA static u8 CraftMessage = 0;

// Menu action callbacks - SWAP/BAG/READY/CANCEL
static bool8 CraftMenuItemOptionsCallback(void);
static u8 CraftMenuPackUpCallback(void);
static bool8 CraftMenuAddSwapCallback(void);
static bool8 CraftMenuDoOptionsSwapCallback(void);
static void CraftMenuRemoveBagCallback(void);
static bool8 CraftMenuReadyCallback(void);
static bool8 CraftMenuCancelCallback(void);

// Functions
static void HideOptionsWindow(void);
static void Task_WaitForPaletteFade(u8);
static void Task_AddCraftDelay(u8 taskId);
static bool8 CraftDelay(void);
static u8 CraftPackUpCheckItem(void);
static u8 CraftPackUpFinish(void);

// Messaging
static void CraftReturnToTableFromDialogue(void);
static u8 CraftPackUpConfirmInputCallback(void);
static u8 CraftYesNoCallback(void);
static void ShowCraftMessage(const u8 *message, u8 (*craftCallback)(void));
static u8 sCraftPackupConfirmCallback(void);
static u8 WriteCraftMessageCallback(void);
static bool8 CraftStartConfirmCallback(void);
static bool8 CraftConfirmCallback(void);

// Menu callbacks
static bool8 HandleCraftMenuInput(void);

// Task callbacks
static void CraftMenuTask(u8 taskId);
static bool8 FieldCB_ReturnToFieldCraftMenu(void);

static const u8 sText_Ready[] = _("READY");

static const struct MenuAction sCraftTableActions[] = {
    [TABLE_ACTION_BLANK]            = {gText_Dash,        {.u8_void = CraftMenuAddSwapCallback}},
    [TABLE_ACTION_ITEM]             = {gText_Dash,        {.u8_void = CraftMenuItemOptionsCallback}} //check out startmenusavecallback
};

static const struct MenuAction sCraftOptionsActions[] = { //craft actions, SWAP/READY/PUT AWAY/CANCEL
    [MENU_ACTION_SWAP]            = {gText_Swap,        {.u8_void = CraftMenuAddSwapCallback}},
    [MENU_ACTION_BAG]             = {gText_PutAway,     NULL},
    [MENU_ACTION_READY]           = {sText_Ready,       {.u8_void = CraftMenuReadyCallback}},
    [MENU_ACTION_CANCEL]          = {gText_Cancel,      {.u8_void = CraftMenuCancelCallback}}
};

static const u8 sCraftOptionsActions_List[] = {
    MENU_ACTION_SWAP,       MENU_ACTION_READY,
    MENU_ACTION_BAG,        MENU_ACTION_CANCEL
};

enum CraftWindows {
    WINDOW_CRAFT_MSG,
    WINDOW_CRAFT_TABLE,
    WINDOW_CRAFT_INFO,
    WINDOW_CRAFT_YESNO,
    WINDOW_CRAFT_OPTIONS,
    WINDOW_CRAFT_SOUSCHEFS,
};

static const struct WindowTemplate sCraftWindowTemplates[] = {
    [WINDOW_CRAFT_MSG] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },    
    [WINDOW_CRAFT_TABLE] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 18,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1 + 27*4,
    },
    [WINDOW_CRAFT_INFO] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 15,
        .width = 8,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1 + 27*4 + 18*4,
    },
    [WINDOW_CRAFT_YESNO] = {
        .bg = 0,
        .tilemapLeft = 26,
        .tilemapTop = 9,
        .width = 3,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1 + 27*4 + 18*4 + 8*4,
    },
    [WINDOW_CRAFT_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 9,
        .width = 14,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1 + 27*4 + 18*4 + 8*4 + 3*4,
    },
    DUMMY_WIN_TEMPLATE
};

//Local functions
static void BuildCraftTableActions(void);
static void ShowCraftTableWindow(void);
static void ShowCraftInfoWindow(void);
static void ShowCraftOptionsWindow(void);
static void ShowCraftTableAndInfoWindows(void);
static void LoadCraftWindows(void);

static const u8 *GetCraftTableItemName(u16 itemId);
static void RemoveExtraCraftMenuWindows(void);
static void PrintCraftTableItems(void);
static void PrintOptionsMenuGrid(u8, u8, u8);
static bool32 InitCraftMenuStep(void);
static void CraftMenuTask(u8 taskId);
static void UpdateCraftTable(void);
static void ClearCraftTable(void);
static void Task_CreateCraftMenu(TaskFunc followupFunc);



static void BuildCraftTableActions(void){
    u8 i;

    //Stores action per item. 
    for (i = 0; i < 4; i++){
        if(sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] == ITEM_NONE ||
            sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] > ITEM_OLD_SEA_MAP){
            
            sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] = ITEM_NONE;
            sCurrentCraftTableItems[i][CRAFT_TABLE_ACTION] = TABLE_ACTION_BLANK;
        }
        else sCurrentCraftTableItems[i][CRAFT_TABLE_ACTION] = TABLE_ACTION_ITEM;
    } 

}

static void ShowCraftTableWindow(void)
{
    //sCraftTableWindowId = AddWindow(&sCraftWindowTemplates[WINDOW_CRAFT_TABLE]);
    PutWindowTilemap(sCraftTableWindowId);
    DrawStdWindowFrame(sCraftTableWindowId, FALSE);
    CopyWindowToVram(sCraftTableWindowId, COPYWIN_GFX);
}

static void ShowCraftInfoWindow(void)
{
    //sCraftInfoWindowId = AddWindow(&sCraftWindowTemplates[WINDOW_CRAFT_INFO]);
    PutWindowTilemap(sCraftInfoWindowId);
    DrawStdWindowFrame(sCraftInfoWindowId, FALSE);
    //ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
    //StringExpandPlaceholders(gStringVar4, gText_SafariBallStock);
    //AddTextPrinterParameterized(sCraftInfoWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sCraftInfoWindowId, COPYWIN_GFX);
}

static void PrintOptionsMenuGrid(u8 windowId, u8 columns, u8 rows)
{
    PrintMenuActionGrid(windowId, FONT_NORMAL, 8, 1, 56, columns, rows, sCraftOptionsActions, sCraftOptionsActions_List);
    InitMenuActionGrid(windowId, 56, columns, rows, 0);
}

static void ShowCraftOptionsWindow(void)
{
    ClearStdWindowAndFrame(sCraftOptionsWindowId, TRUE); //need to clear it first, otherwise only partially fills
    
    FillWindowPixelBuffer(sCraftOptionsWindowId, PIXEL_FILL(0));
    DrawStdWindowFrame(sCraftOptionsWindowId, FALSE);
    PrintOptionsMenuGrid(sCraftOptionsWindowId, 2, 2);
    
    //PutWindowTilemap(sCraftOptionsWindowId);
    ScheduleBgCopyTilemapToVram(0);
}

static void ShowCraftTableAndInfoWindows(void){
    ShowCraftTableWindow();
    ShowCraftInfoWindow();
}

static void LoadCraftWindows(void){
    //Craft Table
    sCraftTableWindowId = AddWindow(&sCraftWindowTemplates[WINDOW_CRAFT_TABLE]);

    //Info
    sCraftInfoWindowId = AddWindow(&sCraftWindowTemplates[WINDOW_CRAFT_INFO]);

    //Ready/Options
    sCraftOptionsWindowId = AddWindow(&sCraftWindowTemplates[WINDOW_CRAFT_OPTIONS]);


}

static const u8 *GetCraftTableItemName(u16 itemId){
    //Print filters for item names. GetFacilityCancelString makes the function a pointer so ¯\_(ツ)_/¯

    if(itemId == ITEM_NONE || itemId >= ITEMS_COUNT)
    {
        return gText_Dash;
    }
    else
    {
        return ItemId_GetName(itemId);
    }
}

static void RemoveExtraCraftMenuWindows(void)
{

}

static void PrintCraftTableItems(void){
    //Modified from PrintMenuGridTable
    u32 i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            AddTextPrinterParameterized(sCraftTableWindowId, 7,
                GetCraftTableItemName(sCurrentCraftTableItems[(i * 2) + j][CRAFT_TABLE_ITEM]),
                (9*8 * j) + 8, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
    }

}

static bool32 InitCraftMenuStep(void)
{
    //list items, draw window, check for extra windows, print menu actions, place cursor, draw everything
    s8 state = sInitCraftMenuData[0];

    switch (state)
    {
    case 0:
        sInitCraftMenuData[0]++;
        break;
    case 1:
        BuildCraftTableActions(); //update to list blank/item. Old function checks what kind of menu,
                                 //adds items based on flags, then adds each one w/ appendtolist
                                 //uses sCurrentStartMenuActions, sNumStartMenuActions
        sInitCraftMenuData[0]++;
        break;
    case 2:
        LoadMessageBoxAndBorderGfx();
        LoadCraftWindows();
        sInitCraftMenuData[0]++;
        break;
    case 3:
        // if (GetSafariZoneFlag()) //update to sous chefs??
        //     ShowSafariBallsWindow();
        // if (InBattlePyramid())
        //     ShowPyramidFloorWindow();
        ShowCraftTableAndInfoWindows();
        sInitCraftMenuData[0]++;
        break;
    case 4:
        PrintCraftTableItems();
        sInitCraftMenuData[0]++;
        break;
    case 5:
        sCraftMenuCursorPos = InitMenuGrid(sCraftTableWindowId, FONT_NARROW, 0, 1, 9 * 8, 15, 2, //9*8 from ScriptMenu_MultichoiceGrid, 15 from FONT_NARROW
                                                2, 4, sCraftMenuCursorPos);
        CopyWindowToVram(sCraftTableWindowId, COPYWIN_MAP);
        return TRUE;
    }

    return FALSE;
}

static void CraftMenuTask(u8 taskId){
    
    if (InitCraftMenuStep() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

static void UpdateCraftTable(void){

    BuildCraftTableActions();
    FillWindowPixelBuffer(sCraftTableWindowId, PIXEL_FILL(TEXT_COLOR_WHITE));
    PrintCraftTableItems();
    PutWindowTilemap(sCraftTableWindowId);
    ScheduleBgCopyTilemapToVram(0);
}

static void ClearCraftTable(void){
    //ClearRoamerLocationData wasn't cool with just = {0} for a 2D array so guess we gotta do it here
    u32 i;

    //reset cursor position
    sCraftMenuCursorPos = 0;

    //clear table
    for (i = 0; i < 4; i++){
        sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] = ITEM_NONE;
        sCurrentCraftTableItems[i][CRAFT_TABLE_ACTION] = TABLE_ACTION_BLANK;
    }
}

static void Task_CreateCraftMenu(TaskFunc followupFunc){
    
    u8 taskId;

    sInitCraftMenuData[0] = 0;

    //everything else goes straight to Task_ShowStartMenu, so this Create function must be like a startup init    
    ClearCraftTable();

    taskId = CreateTask(CraftMenuTask, 0x50);
    SetTaskFuncWithFollowupFunc(taskId, CraftMenuTask, followupFunc);
}

static bool8 FieldCB_ReturnToFieldCraftMenu(void)
{
    if (InitCraftMenuStep() == FALSE)
    {
        return FALSE;
    }

    ReturnToField_OpenCraftMenu();
    return TRUE;
}

void ShowReturnToFieldCraftMenu(void)
{
    u16 *SwapItem;

    SwapItem = &sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM];

    sInitCraftMenuData[0] = 0;
    if (gSpecialVar_ItemId != ITEM_NONE){
        AddBagItem(*SwapItem, 1);
        RemoveBagItem(gSpecialVar_ItemId, 1);
        *SwapItem = gSpecialVar_ItemId;
    }
    BuildCraftTableActions();
    gFieldCallback2 = FieldCB_ReturnToFieldCraftMenu;
}

void Task_ShowCraftMenu(u8 taskId){
              
                //pointer for global task location, data[0] acts as state for create switch
    struct Task *task = &gTasks[taskId];

    switch(task->data[0])
    {
    case 0:
        gMenuCallback = HandleCraftMenuInput;
        task->data[0]++;
        break;
    case 1:
        if (gMenuCallback() == TRUE)
            DestroyTask(taskId);
        break;
    }
}

void ShowCraftMenu(void){
    PlayerFreeze();
    StopPlayerAvatar();

    Task_CreateCraftMenu(Task_ShowCraftMenu);
    LockPlayerFieldControls();
}

#define sCraftDelay data[2]

static bool8 CraftDelay(void){
    if (--sPauseCounter < 1){
        gMenuCallback == CraftMenuPackUpCallback;
    }

    return FALSE;
}

static void Task_AddCraftDelay(u8 taskId)
{
    if (--gTasks[taskId].sCraftDelay == 0)
    {


        DestroyTask(taskId);
    }
}


static bool8 HandleCraftMenuInput(void)
{
    /*update info window with every cursor move (item: xQty in Bag & str to craft, blank: A to add item & "items ? str to craft : B to leave")
      if clicking on something, either add or show options
      options = SWAP/READY/BAG/CANCEL
      swap - get different item, ready - check craft recipe, bag - remove item, cancel - close options (update info window!)
      ready: Want to craft this item? YES/NO
      Crafting... mixing... combining... item obtained!
      packup: Pack up items? YES/NO
      Item4 -> blank, item3 -> blank, item2 -> blank, item1 -> blank, exit
      Select for secret recipe book? Or add to options once flagged
      soux chefs: charmander, squirtle, bulbasaur, aron, snorunt (heat, water, spices, salt/tools, ice)
    */

    switch(sCraftState)
    {

    u8 OptionsCursorPos;

    case STATE_TABLE_INPUT:

        if (JOY_NEW(DPAD_UP))
        {
            PlaySE(SE_SELECT);
            sCraftMenuCursorPos = ChangeGridMenuCursorPosition(0,-1);
        }
        if (JOY_NEW(DPAD_LEFT))
        {
            PlaySE(SE_SELECT);
            sCraftMenuCursorPos = ChangeGridMenuCursorPosition(-1,0);
        }
        if (JOY_NEW(DPAD_RIGHT))
        {
            PlaySE(SE_SELECT);
            sCraftMenuCursorPos = ChangeGridMenuCursorPosition(1,0);
        }
        if (JOY_NEW(DPAD_DOWN))
        {
            PlaySE(SE_SELECT);
            sCraftMenuCursorPos = ChangeGridMenuCursorPosition(0,1);
        }

        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);

            gMenuCallback = sCraftTableActions[
                sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ACTION]].func.u8_void;

            if (gMenuCallback == CraftMenuAddSwapCallback) //if it's blank
                FadeScreen(FADE_TO_BLACK, 0);
            
            return FALSE;
        }

        if (JOY_NEW(START_BUTTON))
        {
            //PlaySE(SE_SELECT);
            //gMenuCallback = CraftMenuReadyCallback; //set up yes/no window
        }

        //select button, instant addswap item (or recipe book??)
        if (JOY_NEW(SELECT_BUTTON))
        {
            PlaySE(SE_SELECT);
            ShowCraftOptionsWindow();
            sCraftState = STATE_OPTIONS_INPUT;
        }

        if (JOY_NEW(B_BUTTON)) //If !IsCraftTableEmpty then gmenucallback = CraftMenuPackUpCallback, otherwise just quit
        {
            //Check if 
            u8 i;
            for (i = 0; i < 4; i++){
                if (sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] != ITEM_NONE)
                    break;
            }
            if (i == 4){
                HideCraftMenu();
                return TRUE;
            }

            CraftMessage = CRAFT_PACKUP_CONFIRM;
            gMenuCallback = CraftStartConfirmCallback; //let the gMenu pinball begin
            
            //RemoveExtraCraftMenuWindows(); //if safarizone/battlepyramid flags, remove those windows. In this case,
                                             //it'd be sous chefs 
            //HideCraftMenu();
            //return True;
        }

        return FALSE;

    case STATE_OPTIONS_INPUT:
        /*How the ITEM MENU works:
          gray cursor in item list
          gspecialvar_itemId
          open context menu
                ask what you wanna do with var_itemid
                print options grid
          taskid = which grid format handling?
          ACTION_CANCEL
                remove window
                reprint desc
                black cursor
                return to item list handling
                        refresh graphics
                        taskid = bag handling
        */

        OptionsCursorPos = Menu_GetCursorPos();

        if (JOY_NEW(DPAD_UP))
        {
            if (OptionsCursorPos > 1)
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_UP);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (OptionsCursorPos < 2)
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_DOWN);
            }
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            if (OptionsCursorPos + 1 == 2 || OptionsCursorPos + 1 == 4)
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_LEFT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (OptionsCursorPos + 1 == 1 || OptionsCursorPos + 1 == 3)
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_RIGHT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {

            switch (sCraftOptionsActions_List[OptionsCursorPos])
            {
            case MENU_ACTION_SWAP:
                PlaySE(SE_SELECT);
                CraftMenuDoOptionsSwapCallback();
                FadeScreen(FADE_TO_BLACK, 0);
                break;
            case MENU_ACTION_BAG:
                PlaySE(SE_SELECT);
                CraftMenuRemoveBagCallback();
                break;
            case MENU_ACTION_READY:
                PlaySE(SE_SELECT);
                CraftMenuReadyCallback();
                break;
            case MENU_ACTION_CANCEL:
            default:
                CraftMenuCancelCallback();
                break;
            }

            //gMenuCallback = 
            //sCraftOptionsActions[sCraftOptionsActions_List[OptionsCursorPos]].func.void_u8;

            //if (gMenuCallback == CraftMenuAddSwapCallback)
            //    FadeScreen(FADE_TO_BLACK, 0); 

            return FALSE;
        }
        else if (JOY_NEW(B_BUTTON)){
            CraftMenuCancelCallback();
       }

        return FALSE;
    }
}

static void Task_WaitForPaletteFade(u8 taskId)
{
    if (!gPaletteFade.active)
        HandleCraftMenuInput;
}


static bool8 CraftMenuItemOptionsCallback(void){
    
    //gray cursor
    ShowCraftOptionsWindow();
    sCraftState = STATE_OPTIONS_INPUT;
    gMenuCallback = HandleCraftMenuInput;

    return FALSE;
}

enum PackUpState {
    NO_ITEM,
    YES_ITEM
};

static u8 CraftPackUpCheckItem(void){
    if (sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM] == ITEM_NONE || 
        sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM] > ITEM_OLD_SEA_MAP)
    {
        return NO_ITEM;
    }
    else {
        return YES_ITEM;
    }
}

enum CraftMessageState {
    CRAFT_MESSAGE_IN_PROGRESS,
    CRAFT_MESSAGE_CONFIRM,
    CRAFT_MESSAGE_CANCEL
};

static bool8 CraftPackUpFinish(void){
    PlaySE(SE_RG_BAG_POCKET);
    HideCraftMenu();
    return CRAFT_MESSAGE_CONFIRM;
}

static u8 CraftMenuPackUpCallback(void){
    
    s8 i;
    u8 taskId;
    u16 *CraftItem;

    CraftItem = &sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM]; 

    //This times out the removal ok but freezes on the last item / empty items
    //Backing out of menu is slow if item in pos = 0 ',:/

    //if (sPauseCounter-- > 0)
    //    return CRAFT_MESSAGE_IN_PROGRESS;
    

//switch statement attempt 2    
/*/    switch (CraftPackUpCheckItem())
    {
    case NO_ITEM:
        if (sCraftMenuCursorPos == 0) //done packing up
        {
            HideCraftMenu();
            return TRUE; 
        }
        sCraftMenuCursorPos--;
        return FALSE;    
    case YES_ITEM:
        PlaySE(SE_BALL);
        CraftMenuRemoveBagCallback();
        sPauseCounter = 25;
        return FALSE;
    }

    return FALSE;
*/

//if statements attempt 2
    /*if (sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM] == ITEM_NONE){
        if (sCraftMenuCursorPos == 0){
            HideCraftMenu();
            return TRUE;
        }
    }
    else {
        PlaySE(SE_SUDOWOODO_SHAKE);
        CraftMenuRemoveBagCallback();
        sPauseCounter = 25;
        return FALSE;
    }

    sCraftMenuCursorPos--;
    UpdateCraftTable();
    sCraftMenuCursorPos = InitMenuGrid(sCraftTableWindowId, FONT_NARROW, 0, 1, 9 * 8, 15, 2, //9*8 from ScriptMenu_MultichoiceGrid, 15 from FONT_NARROW
                                    2, 4, sCraftMenuCursorPos);
    return FALSE;
*/

//switch statement attempt 1 (only working version)

    switch (sCraftMenuCursorPos)
    {
    case 0: //if this has an item, it freezes
        if (*CraftItem == ITEM_NONE){

            sCraftDialogCallback = CraftPackUpFinish;
            break;
            //return CraftPackUpFinish();
            //gMenuCallback = CraftPackUpFinish;
        }

    default:
        if (*CraftItem != ITEM_NONE){
            PlaySE(SE_BALL);
            CraftMenuRemoveBagCallback();
            sPauseCounter = 25;  //check out Task_AnimateAfterDelay
        }
        sCraftMenuCursorPos != 0 ? --sCraftMenuCursorPos : 0;
        break;
    }

    return CRAFT_MESSAGE_IN_PROGRESS;
    //return FALSE;
    
//if statements attempt 1    
    /*
    //make switch statement?    
        if (sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM] != ITEM_NONE){
            PlaySE(SE_ICE_CRACK);
            CraftMenuRemoveBagCallback();

            //taskId = CreateTask(Task_AddCraftDelay, 0);
            //gTasks[taskId].sCraftDelay = 600; //delay seems to come after everything is done?

            gMenuCallback = CraftDelay;
            sPauseCounter = 25;
            //Add delay: gmenucallback = dotimer, if timer ? handlecraftinput : return false
        }

    //}

    if (sCraftMenuCursorPos < 1 && sCurrentCraftTableItems[0][CRAFT_TABLE_ITEM] == ITEM_NONE){
        HideCraftMenu();
        return TRUE;
    }

    sCraftMenuCursorPos--;
    */
}

static void HideOptionsWindow(void)
{
    ClearStdWindowAndFrame(sCraftOptionsWindowId, TRUE);
    sCraftMenuCursorPos = InitMenuGrid(sCraftTableWindowId, FONT_NARROW, 0, 1, 9 * 8, 15, 2, //9*8 from ScriptMenu_MultichoiceGrid, 15 from FONT_NARROW
                                        2, 4, sCraftMenuCursorPos);
    sCraftState = STATE_TABLE_INPUT;

}

static bool8 CraftMenuAddSwapCallback(void){
    /*HideOptionsWindow();
    sCraftState = STATE_TABLE_INPUT;
    return TRUE;
    */

    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        HideCraftMenu();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromCraftMenu);

        return TRUE;
    }

    return FALSE;  
}

static bool8 CraftMenuDoOptionsSwapCallback(void){

    gMenuCallback = CraftMenuAddSwapCallback;

    sCraftState = STATE_TABLE_INPUT;

    return FALSE;
}

static void CraftMenuRemoveBagCallback(void){
     
    u16 *CraftItem;

    CraftItem = &sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM]; 
    
    if (*CraftItem != ITEM_NONE){
        AddBagItem(*CraftItem, 1);
        *CraftItem = ITEM_NONE;
    }

    UpdateCraftTable();
    HideOptionsWindow();
}

static bool8 CraftMenuReadyCallback(void){
    HideOptionsWindow();
    gMenuCallback = HandleCraftMenuInput;

    return FALSE;      
}

static bool8 CraftMenuCancelCallback(void){
    PlaySE(SE_BOO);
    HideOptionsWindow();

    return FALSE;  
}

void HideCraftMenu(void){

    ClearStdWindowAndFrame(sCraftTableWindowId, TRUE);
    if (sCraftTableWindowId != WINDOW_NONE){
        RemoveWindow(sCraftTableWindowId);
        sCraftTableWindowId = WINDOW_NONE;
    }

    ClearStdWindowAndFrame(sCraftInfoWindowId, TRUE);
    if (sCraftInfoWindowId != WINDOW_NONE){
        RemoveWindow(sCraftInfoWindowId);
        sCraftInfoWindowId = WINDOW_NONE;
    }

    if (sCraftOptionsWindowId != WINDOW_NONE){
        RemoveWindow(sCraftOptionsWindowId);
        sCraftOptionsWindowId = WINDOW_NONE;
    }


    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}


static const u8 sText_ConfirmPackUp[] = _("Would you like to pack up?");
static const u8 sText_ConfirmReady[] = _("Craft {STR_VAR_1}?");
static const u8 sText_CraftNo[] = _("This won't make anything useful...");
static const u8 sText_WouldYouLikeToCraft[] = _("There's a crafting table.\nWant to craft something?");


static void CraftReturnToTableFromDialogue(void)
{
    ClearDialogWindowAndFrame(0, TRUE);
    ClearDialogWindowAndFrameToTransparent(0, FALSE);
    
    sInitCraftMenuData[0] = 0;
    while (!InitCraftMenuStep())
        ;
}

static u8 CraftPackUpConfirmInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        //ClearDialogWindowAndFrame(0, TRUE);
        CraftReturnToTableFromDialogue();
        sCraftMenuCursorPos = 3;
        sPauseCounter = 30;
        sCraftDialogCallback = CraftMenuPackUpCallback;
        break;
        //return CRAFT_MESSAGE_CONFIRM;
    case MENU_B_PRESSED:
    case 1:
        CraftReturnToTableFromDialogue();
        return CRAFT_MESSAGE_CANCEL;
    }

    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 CraftYesNoCallback(void)
{
    u8 MessageState; 
    MessageState = CraftMessage > 1 ? 0 : abs(CraftMessage - 1);
    
    DisplayYesNoMenuWithDefault(MessageState); // Show Yes/No menu, 0 = Yes, 1 = No
    
    switch (CraftMessage)
    {
    case CRAFT_PACKUP_CONFIRM:
        sCraftDialogCallback = CraftPackUpConfirmInputCallback;
        break;
    
    case CRAFT_READY_CONFIRM:
        break;
    }
    
    return CRAFT_MESSAGE_IN_PROGRESS;
}

static void ShowCraftMessage(const u8 *message, u8 (*craftCallback)(void))
{
    StringExpandPlaceholders(gStringVar4, message);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    AddTextPrinterForMessage_2(TRUE);
    sCraftDialogCallback = craftCallback;
}

static u8 sCraftPackupConfirmCallback(void)
{
    //ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    //RemoveStartMenuWindow(); //removes and sets to window_none
    //ShowSaveInfoWindow(); //craft copywin_gfx

    HideCraftMenu();
    FreezeObjectEvents();
    LockPlayerFieldControls();

    ShowCraftMessage(sText_ConfirmPackUp, CraftYesNoCallback);
    
    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 WriteCraftMessageCallback(void)
{
    // True if text is still printing
    if (RunTextPrintersAndIsPrinter0Active() == TRUE)
    {
        return CRAFT_MESSAGE_IN_PROGRESS;
    }
    
    return sCraftDialogCallback();
}

static bool8 CraftStartConfirmCallback(void)
{
    switch (CraftMessage)
    {
    case CRAFT_PACKUP_CONFIRM:
        sCraftDialogCallback = sCraftPackupConfirmCallback;
        break;
    case CRAFT_READY_CONFIRM:
        //sCraftDialogCallback = sCraftReadyConfirmCallback;
        break;
    }

    gMenuCallback = CraftConfirmCallback;

    return FALSE;
}

static bool8 CraftConfirmCallback(void){
        
    switch (WriteCraftMessageCallback())
    {
    case CRAFT_MESSAGE_IN_PROGRESS:
        return FALSE;
    case CRAFT_MESSAGE_CONFIRM:
        switch (CraftMessage)
        {
        case CRAFT_PACKUP_CONFIRM:
            return TRUE;
        case CRAFT_READY_CONFIRM:
            break;
        }
    case CRAFT_MESSAGE_CANCEL:
        gMenuCallback = HandleCraftMenuInput;
        return FALSE;
    }

    return FALSE;
}

