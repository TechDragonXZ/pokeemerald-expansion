#include "global.h"
#include "bg.h"
#include "battle_pyramid.h"
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

// Credits!!
//--------------
//TheSylphIsIn: comparing chosen items against an array
//Lunos: ChooseItem
//MrGriffin: example-screen
//Ghoulslash: item icons

// Menu actions
enum CraftMenuActions {
    MENU_ACTION_SWAP,
    MENU_ACTION_BAG,
    MENU_ACTION_READY, //switch this out for GARBAGE / TOSS depending on if indoors
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

EWRAM_DATA u16 sCurrentCraftTableItems[4][2] = {0}; //craft table items, actions
EWRAM_DATA static u8 sCraftMenuCursorPos = 0;
EWRAM_DATA static u8 sInitCraftMenuData[1] = {0};
EWRAM_DATA static u8 sCraftState = 0;
EWRAM_DATA static u32 sPauseCounter = 0;
EWRAM_DATA static u8 (*sCraftDialogCallback)(void) = NULL;
EWRAM_DATA static u8 CraftMessage = 0;

static const u8 sStartButton_Gfx[] = INCBIN_U8("graphics/bag/start_button.4bpp");

// Menu action callbacks - SWAP/PUTAWAY/READY/CANCEL
static bool8 CraftMenuItemOptionsCallback(void);
static u8 CraftMenuPackUpCallback(void);
static bool8 CraftMenuAddSwapCallback(void);
static bool8 CraftMenuDoOptionsSwapCallback(void);
static bool8 CraftMenuDoOptionsReadyCallback(void);
static void CraftMenuRemoveBagCallback(void);
static u8 CraftMenuReadyCallback(void);
static bool8 CraftMenuCancelCallback(void);


// Functions
static void OrganizeCraftItems(u16 *SwapCraftOrder);
static u16 FindCraftProduct(int);
static void InitItemSprites(void);
static void HideOptionsWindow(void);
static void Task_WaitForPaletteFade(u8);
static void Task_AddCraftDelay(u8 taskId);
static bool8 CraftDelay(void);
static bool8 IsCraftTableEmpty(void);
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
static u8 CraftDialoguePackUp(void);

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
    [MENU_ACTION_BAG]             = {gText_PutAway,                 NULL},
    [MENU_ACTION_READY]           = {sText_Ready,       {.u8_void = CraftMenuReadyCallback}},
    [MENU_ACTION_CANCEL]          = {gText_Cancel,      {.u8_void = CraftMenuCancelCallback}}
};

static const u8 sCraftOptionsActions_List[] = {
    MENU_ACTION_SWAP,       MENU_ACTION_READY,
    MENU_ACTION_BAG,        MENU_ACTION_CANCEL
};

enum TextColors {
    COLORID_GRAY,
    COLORID_BLACK,
    COLORID_LIGHT_GRAY,
    COLORID_BLUE,
    COLORID_GREEN,
    COLORID_RED,
};

static const u8 sTextColorTable[][3] =
{
    [COLORID_GRAY]       = {TEXT_COLOR_WHITE,       TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [COLORID_BLACK]      = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [COLORID_LIGHT_GRAY] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_RED},
    [COLORID_BLUE]       = {TEXT_COLOR_WHITE,       TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_BLUE},
    [COLORID_GREEN]      = {TEXT_COLOR_WHITE,       TEXT_COLOR_GREEN,      TEXT_COLOR_LIGHT_GREEN},
    [COLORID_RED]        = {TEXT_COLOR_WHITE,       TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_RED},
};

//User Interaction
static const u8 sText_ConfirmPackUp[] = _("Would you like to pack up?");
static const u8 sText_ConfirmReady[] = _("This looks like it'll be good.\nCraft {STR_VAR_1}{STR_VAR_2}?");
static const u8 sText_ConfirmReadyQty[] = _(" ({COLOR GREEN}{SHADOW LIGHT_GREEN}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY})");
static const u8 sText_CraftNo[] = _("Hmm, this won't make anything useful...");
static const u8 sText_WouldYouLikeToCraft[] = _("There's a crafting table.\nWant to craft something?");
    //each item should get array w craftinprocess messages & requirements (indoors or heat/water/spice/tools/ice)
static const u8 sText_CraftInProcess[] = _("Prepping ingredients... {PAUSE 15}Assembling... {PAUSE 15}Finishing...{PAUSE_UNTIL_PRESS}");
static const u8 sText_ItemCrafted[] = _("{STR_VAR_2}{STR_VAR_1} crafted!");
static const u8 sText_AddItem[] = _("{COLOR BLUE}ADD ITEM");
static const u8 sText_AButton[] = _("{A_BUTTON}");
static const u8 sText_BButton[] = _("{B_BUTTON}");
static const u8 sText_InBag[] = _("IN BAG:");
static const u8 sText_Var2Var1[] = _("{STR_VAR_2}{STR_VAR_1}");
extern const u8 gText_DiplomaEmpty[]; //red, lol
static const u8 sText_PackingUp[] = _("Packing up{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}\p{PLAYER} put the items back in the bag.{PAUSE_UNTIL_PRESS}");



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
static void UpdateCraftInfoWindow(void);
static void ClearCraftTable(void);
static void Task_CreateCraftMenu(TaskFunc followupFunc);

static const u16 Craft_Recipes[][6] = {
// Ingredients (ITEM_1234) must be arranged with Smallest -> Largest ItemId
//  {ITEM_1,        ITEM_2,            ITEM_3,            ITEM_4,            ITEM_PRODUCT,   QUANTITY},    
    {0,             0,                 ITEM_POTION,       ITEM_PECHA_BERRY,  ITEM_ANTIDOTE,         3},
    {0,             ITEM_REPEL,        ITEM_REPEL,        ITEM_REPEL,        ITEM_SUPER_REPEL,      2},
    {0,             ITEM_SUPER_REPEL,  ITEM_SUPER_REPEL,  ITEM_SUPER_REPEL,  ITEM_MAX_REPEL,        2},
    {0,             0,                 ITEM_POKE_BALL,    ITEM_MAX_REPEL,    ITEM_SMOKE_BALL,       1},
    {0,             0,                 ITEM_ORAN_BERRY,   ITEM_ORAN_BERRY,   ITEM_BERRY_JUICE,      1}
};

//Menu / Window Functions
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
        InitItemSprites();
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
        UpdateCraftInfoWindow();
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

static void UpdateCraftInfoWindow(void){
//update info window with every cursor move (item: xQty in Bag & str to craft, \
     blank: A to add item & "items ? str to craft : B to leave")

    //Declare Vars
    u16 itemId, palette;
    bool32 handleFlash;
    u32 quantityInBag;

    //Init Vars
    itemId = sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM];
    handleFlash = FALSE;
    quantityInBag = CountTotalItemQuantityInBag(itemId);

    //Check for flash
    if (GetFlashLevel() > 0 || InBattlePyramid())
        handleFlash = TRUE;

    //Clean window
    FillWindowPixelBuffer(sCraftInfoWindowId, PIXEL_FILL(TEXT_COLOR_WHITE));

    //Display Info
    if (itemId){
        // ITEM   In Bag: xNum  \
           ICON   STR-> Ready
        
        //icon
        ShowItemIconSprite(itemId, handleFlash, 184, 140); //176 = tilemapleft + 16 border pixels, 140 from GhoulSlash

        //IN BAG:
        AddTextPrinterParameterized(sCraftInfoWindowId, FONT_SMALL, sText_InBag, 25, 1, TEXT_SKIP_DRAW, NULL);
        ConvertIntToDecimalStringN(gStringVar1, quantityInBag, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS + 1);
        
        //Color for remaining qty
        if (quantityInBag == 0)
            StringCopy(gStringVar2, gText_DiplomaEmpty); //red
        else
            StringCopy(gStringVar2, gText_ColorDarkGray); //normal

        //xQty
        StringExpandPlaceholders(gStringVar4, sText_Var2Var1);
        StringCopy(gStringVar1, gStringVar4);
        StringExpandPlaceholders(gStringVar4, gText_xVar1);
        AddTextPrinterParameterized(sCraftInfoWindowId, FONT_NARROW, gStringVar4, 25, 15, TEXT_SKIP_DRAW, NULL);
        
    }
    else //No Item
    {
        // (A) Add Item      flag-> SEL-> Recipes   \
           (B) Cancel               STR-> Ready

        //------------------------
        //This and (A) button below will replace with SEL= Recipe Book, once the book is implemented that is
        //Add Item 
        StringCopy(gStringVar1, sText_AddItem);
        StringCopy(gStringVar2, gText_ColorBlue);
        StringExpandPlaceholders(gStringVar4, sText_Var2Var1);
        AddTextPrinterParameterized(sCraftInfoWindowId, FONT_SMALL, gStringVar4, 25, 1, TEXT_SKIP_DRAW, NULL);

        //(A) button
        DrawKeypadIcon(sCraftInfoWindowId, CHAR_A_BUTTON, 8, 1);
        //------------------------


        //START = Ready
        if (!IsCraftTableEmpty())
        {
            // (START)
            if (FindCraftProduct(0))
            {
                //Show hint that it's a good recipe
                palette = RGB_BLACK;
                LoadPalette(&palette, BG_PLTT_ID(15) + 10, PLTT_SIZEOF(1));

                BlitBitmapToWindow(sCraftInfoWindowId, sStartButton_Gfx, 0, 16, 24, 16);
            }
            else
            {
                DrawKeypadIcon(sCraftInfoWindowId, CHAR_START_BUTTON, 0, 16);
            }

            // READY
            StringCopy(gStringVar1, sText_Ready);
            StringCopy(gStringVar2, gText_ColorBlue);
            StringExpandPlaceholders(gStringVar4, sText_Var2Var1);
            AddTextPrinterParameterized(sCraftInfoWindowId, FONT_SMALL, gStringVar4, 25, 16, TEXT_SKIP_DRAW, NULL);

        }
        else
        {
            // (B)
            DrawKeypadIcon(sCraftInfoWindowId, CHAR_B_BUTTON, 8, 16);

            // Cancel (in blue1)
            StringCopy(gStringVar1, gText_Cancel);
            StringCopy(gStringVar2, gText_ColorBlue);
            StringExpandPlaceholders(gStringVar4, sText_Var2Var1);
            AddTextPrinterParameterized(sCraftInfoWindowId, FONT_SMALL, gStringVar4, 25, 16, TEXT_SKIP_DRAW, NULL);
        }
    }

    //Draw! (Insert cowboy emoji)
    PutWindowTilemap(sCraftInfoWindowId);
    CopyWindowToVram(sCraftInfoWindowId, COPYWIN_GFX);
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

static void ClearCraftInfo(u8 ItemSpot)
{
    if (sCurrentCraftTableItems[ItemSpot][CRAFT_TABLE_ITEM] > 0 || sCurrentCraftTableItems[ItemSpot][CRAFT_TABLE_ITEM] < ITEMS_COUNT)
        DestroyItemIconSprite();
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

    sPauseCounter--;

    if (JOY_HELD(A_BUTTON)){
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (sPauseCounter == 0 || --sPauseCounter == 0)
        return TRUE;
    
    return FALSE;
}

static void Task_AddCraftDelay(u8 taskId)
{
    if (--gTasks[taskId].sCraftDelay == 0)
    {


        DestroyTask(taskId);
    }
}

static bool8 IsCraftTableEmpty(void){
    u32 i;

    for (i = 0; i < 4; i++)
    {
        if (sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM] != ITEM_NONE)
            return FALSE;
    }

    return TRUE;
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

    u8 OptionsCursorPos;
    u8 OldPos;

    OldPos = sCraftMenuCursorPos;


    switch(sCraftState)
    {

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
            if (IsCraftTableEmpty())
                PlaySE(SE_BOO);
            else {
                ClearCraftInfo(sCraftMenuCursorPos);
                CraftMessage = CRAFT_READY_CONFIRM;
                gMenuCallback = CraftStartConfirmCallback;
            }
            
            return FALSE;
            //PlaySE(SE_SELECT);
            //gMenuCallback = CraftMenuReadyCallback; //set up yes/no window
        }

        //select button, instant addswap item (or recipe book??)
        if (JOY_NEW(SELECT_BUTTON))
        {
            PlaySE(SE_WIN_OPEN);
            ShowCraftOptionsWindow();
            sCraftState = STATE_OPTIONS_INPUT;
        }

        if (JOY_NEW(B_BUTTON)) //If !IsCraftTableEmpty then gmenucallback = CraftMenuPackUpCallback, otherwise just quit
        {
            if (IsCraftTableEmpty())
            {
                PlaySE(SE_WIN_OPEN);
                HideCraftMenu();
                return TRUE;
            }

            ClearCraftInfo(sCraftMenuCursorPos);
            CraftMessage = CRAFT_PACKUP_CONFIRM;
            gMenuCallback = CraftStartConfirmCallback; //let the gMenu pinball begin
            
            //RemoveExtraCraftMenuWindows(); //if safarizone/battlepyramid flags, remove those windows. In this case,
                                             //it'd be sous chefs 
            //HideCraftMenu();
            //return True;
            return FALSE;
        }

        //if (sCraftMenuCursorPos != OldPos)
        /*{
            if (sCurrentCraftTableItems[OldPos][CRAFT_TABLE_ITEM] && sCurrentCraftTableItems[OldPos][CRAFT_TABLE_ITEM] < ITEMS_COUNT)
                DestroyItemIconSprite();

            UpdateCraftInfoWindow();
        //}
            */

            ClearCraftInfo(OldPos);
            UpdateCraftInfoWindow();

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
                ClearCraftInfo(sCraftMenuCursorPos);
                CraftMenuDoOptionsReadyCallback();
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

//Callbacks / Actions
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
        sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM] >= ITEMS_COUNT)
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

static u8 CraftPackUpFinish(void){

    //PlaySE(SE_RG_BAG_POCKET);
    //HideCraftMenu();

    //Until the delay/animated pack up works...
    ShowCraftMessage(sText_PackingUp, CraftDialoguePackUp);

    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 CraftPackUpCheckDelay(void){

    //if (CraftDelay())
    //if(CraftMenuPackUpCallback == TRUE)
        sCraftDialogCallback = CraftPackUpFinish;

    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 CraftMenuPackUpCallback(void){
    
    s8 i;
    u8 taskId;
    //u16 CraftItem;
    u16 *CraftItem;

    //CraftItem = sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM]; 
    CraftItem = &sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM]; 

    /*
    sPauseCounter--;
    if (sPauseCounter > 0)
        return FALSE;
    */

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
    //enabling the spausecounter above only allows for full crafting table packup, missing items cause freeze
    switch (sCraftMenuCursorPos)
    {
    case 0:
        if (*CraftItem == ITEM_NONE){

            sCraftDialogCallback = CraftPackUpFinish;
            break;
            //return TRUE;
            //return CraftPackUpFinish();
            //gMenuCallback = CraftPackUpFinish;
        }

    default:
        if (*CraftItem != ITEM_NONE){
            PlaySE(SE_BALL);
            CraftMenuRemoveBagCallback();
            //return FALSE;
            //break;
            sPauseCounter = 25;  //check out Task_AnimateAfterDelay
        }
        //if (sCurrentCraftTableItems[--sCraftMenuCursorPos][CRAFT_TABLE_ITEM] == ITEM_NONE) 
            sCraftMenuCursorPos != 0 ? --sCraftMenuCursorPos : 0;
        //else
        break;
    }

    //sPauseCounter = (sCurrentCraftTableItems[sCraftMenuCursorPos - 1][CRAFT_TABLE_ITEM] == ITEM_NONE) ? 0 : 25000;
    //sCraftMenuCursorPos--;

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

static bool8 CraftMenuDoOptionsReadyCallback(void){


    CraftMessage = CRAFT_READY_CONFIRM;

    gMenuCallback = CraftStartConfirmCallback;

    return FALSE;
}

static void CraftMenuRemoveBagCallback(void){
     
    u16 *CraftItem;

    CraftItem = &sCurrentCraftTableItems[sCraftMenuCursorPos][CRAFT_TABLE_ITEM]; 
    
    if (*CraftItem != ITEM_NONE){
        DestroyItemIconSprite();
        AddBagItem(*CraftItem, 1);
        *CraftItem = ITEM_NONE;
    }

    UpdateCraftTable();
    UpdateCraftInfoWindow();
    HideOptionsWindow();
}

#define CRAFT_PRODUCT 0
#define CRAFT_QUANTITY 1

static u8 CraftMenuReadyCallback(void){

    u16 CraftProduct, CraftQty;

    CraftProduct = FindCraftProduct(CRAFT_PRODUCT);
    CraftQty = FindCraftProduct(CRAFT_QUANTITY);

    AddBagItem(CraftProduct, CraftQty);
    //AddSwap if more CraftQty

    ClearCraftTable();
    ClearCraftInfo(sCraftMenuCursorPos);

    //showcraftmessage Crafting.... Item crafted!
    CraftReturnToTableFromDialogue();

    return CRAFT_MESSAGE_CONFIRM;
}

static bool8 CraftMenuCancelCallback(void){
    PlaySE(SE_WIN_OPEN);
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

static void OrganizeCraftItems(u16 *SwapCraftOrder){

    u32 i;
    u16 CraftSwapItem;
    //u16 SwapCraftOrder[4];

    //Set up temp list
    for (i = 0; i < 4; i++){
        SwapCraftOrder[i] = sCurrentCraftTableItems[i][CRAFT_TABLE_ITEM];
    }

    //split into two groups and arrange ex: "DB CA" -> "BD AC"
    for (i = 0; i < 3; i += 2){        
        if (SwapCraftOrder[i] > SwapCraftOrder[i + 1])
            SWAP(SwapCraftOrder[i], SwapCraftOrder[i + 1], CraftSwapItem);
    }

    //arrange biggest items ex: "BD AC" -> "BC AD"
    if (SwapCraftOrder[1] > SwapCraftOrder[3])
        SWAP(SwapCraftOrder[1], SwapCraftOrder[3], CraftSwapItem);

    //arrange smallest items ex: "BC AD" -> "AC BD"
    if (SwapCraftOrder[0] > SwapCraftOrder[2])
        SWAP(SwapCraftOrder[0], SwapCraftOrder[2], CraftSwapItem);

    //compare biggest small against smallest big ex: "AC BD" -> "AB CD"
    if (SwapCraftOrder[1] > SwapCraftOrder[2])
        SWAP(SwapCraftOrder[1], SwapCraftOrder[2], CraftSwapItem);

    //Organized!
}

static u16 FindCraftProduct(int PrdOrQty){

    u32 i, j;
    u16 CraftSwapItem;
    u16 CraftProduct = ITEM_NONE;
    u16 CraftItems[4];

    OrganizeCraftItems(CraftItems);

    for (i = 0; i < ARRAY_COUNT(Craft_Recipes); i++)
    {

        for (j = 0; j < 4; j++)
        {
            if (CraftItems[j] != Craft_Recipes[i][j])
                break;
            else if (j == 3){
                CraftProduct = Craft_Recipes[i][4 + PrdOrQty];
                break;
            }
            else {
                CraftProduct = ITEM_NONE;
            }
        }

        if (CraftProduct != ITEM_NONE)
            break;
    }
    
    return CraftProduct;
}

static void InitItemSprites(void)
{
    //Peaches for my peach <3
    ShowItemIconSprite(ITEM_PECHA_BERRY,FALSE,200,1);
    DestroyItemIconSprite();
}

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
        //CraftReturnToTableFromDialogue();

        switch (CraftMessage)
        {
        case CRAFT_PACKUP_CONFIRM:
            sCraftMenuCursorPos = 3;
            sPauseCounter = 30;
            sCraftDialogCallback = CraftMenuPackUpCallback;
            //sCraftDialogCallback = CraftPackUpCheckDelay;
            break;
        case CRAFT_READY_CONFIRM:
            sCraftDialogCallback = CraftMenuReadyCallback;
            break;
        default:
            break;
        }
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

    //For CraftMessages at or over 1, always choose Yes default. 
    MessageState = CraftMessage > 1 ? 0 : abs(CraftMessage - 1);
    
    DisplayYesNoMenuWithDefault(MessageState); // Show Yes/No menu, 0 = Yes, 1 = No
    
    //switch (CraftMessage)
    //{
    //case CRAFT_PACKUP_CONFIRM:
        sCraftDialogCallback = CraftPackUpConfirmInputCallback;
    //    break;
    
    //case CRAFT_READY_CONFIRM:
    //    break;
    //}
    
    return CRAFT_MESSAGE_IN_PROGRESS;
}

static u8 CraftMessageWaitForButtonPress(void){

    if (!IsTextPrinterActive(0) && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))){

        CraftReturnToTableFromDialogue();
        return CRAFT_MESSAGE_CANCEL;
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

    const u8 *message;
    u16 CraftProduct, CraftQty;

    CraftProduct = FindCraftProduct(CRAFT_PRODUCT);
    CraftQty = FindCraftProduct(CRAFT_QUANTITY);

    HideCraftMenu();
    FreezeObjectEvents();
    LockPlayerFieldControls();

    switch (CraftMessage)
    {
    case CRAFT_PACKUP_CONFIRM:
        message = sText_ConfirmPackUp;
        break;
    case CRAFT_READY_CONFIRM:
        if (CraftProduct != ITEM_NONE){
            //expand those placeholders
            if (CraftQty > 1)
            {
                ConvertIntToDecimalStringN(gStringVar1, CraftQty, STR_CONV_MODE_LEFT_ALIGN, 2);
                StringExpandPlaceholders(gStringVar2, sText_ConfirmReadyQty);
            }
            else
                StringCopy(gStringVar2, gText_EmptyString2);

            CopyItemName(CraftProduct, gStringVar1);
            StringExpandPlaceholders(gStringVar4, sText_ConfirmReady);
            message = gStringVar4;
            break;
        }
        else
            message = sText_CraftNo;
            ShowCraftMessage(message, CraftMessageWaitForButtonPress);
            return CRAFT_MESSAGE_IN_PROGRESS;
        break;
    }

    ShowCraftMessage(message, CraftYesNoCallback);
    
    return CRAFT_MESSAGE_IN_PROGRESS;
}

#undef CRAFT_PRODUCT
#undef CRAFT_QUANTITY


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
        sCraftDialogCallback = sCraftPackupConfirmCallback;
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

static u8 CraftDialoguePackUp(void){

    //if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)){
        ClearDialogWindowAndFrame(0, TRUE);
        PlaySE(SE_WIN_OPEN);
        HideCraftMenu();
        return CRAFT_MESSAGE_CONFIRM;
    //}

    //return CRAFT_MESSAGE_IN_PROGRESS;
}

