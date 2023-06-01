#ifndef GUARD_CRAFT_H
#define GUARD_CRAFT_H

//extern const u8 *const gStdStrings[];

// Window IDs
#define C_WIN_ITEM_NAME_1         1 // Top left
#define C_WIN_ITEM_NAME_2         2 // Top right
#define C_WIN_ITEM_NAME_3         3 // Bottom left
#define C_WIN_ITEM_NAME_4         4 // Bottom right
#define C_WIN_DUMMY               5
#define C_WIN_CRAFT_PROMPT        6 // Switch which?
#define C_WIN_YESNO               7

// This is from ketsuban's debug_menu_tutorial (https://gist.github.com/ketsuban/1751fd9cdca331831fe4da9283675465)
#define DEBUG_MAIN_MENU_HEIGHT 6
#define DEBUG_MAIN_MENU_WIDTH 11


void Debug_ShowMainMenu(void);
static void Debug_DestroyMainMenu(u8);
static void DebugAction_Cancel(u8);
static void DebugTask_HandleMainMenuInput(u8);

// On to the crafting stuff!
bool32 CraftMenu_Init(void);
void Craft_ShowMainMenu(void);
static void Task_HandleCraftMenuInput(u8 taskId);

#endif // GUARD_CRAFT_H