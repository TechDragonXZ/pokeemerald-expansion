#ifndef GUARD_IKIGAI_DATA_GUARD_CUTSCENE_H
#define GUARD_IKIGAI_DATA_GUARD_CUTSCENE_H

#include "global.h"
#include "gba/gba.h"
#include "constants/cutscene.h"
#include "constants/flags.h"
#include "main.h"

// extern const u8 EventScript_ExampleCutsceneSkip[];

// Wally
extern const u8 VictoryRoad_1F_EventScript_WallyEntranceBattle_CutsceneSkipped[];

// Aqua & Magma Grunts & Leaders
extern const u8 PetalburgWoods_EventScript_DevonResearcherLeft_CutsceneSkipped[];
extern const u8 PetalburgWoods_EventScript_DevonResearcherRight_CutsceneSkipped[];
extern const u8 RusturfTunnel_EventScript_Grunt_CutsceneSkipped[];
extern const u8 SlateportCity_OceanicMuseum_2F_EventScript_CaptStern_CutsceneSkipped[];
extern const u8 MtChimney_EventScript_Maxie_CutsceneSkipped[];
extern const u8 MagmaHideout_4F_EventScript_Maxie_CutsceneSkipped[];
extern const u8 SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre_CutsceneSkipped[];

// Elite 4 & Champion
extern const u8 EverGrandeCity_SidneysRoom_EventScript_Sidney_CutsceneSkipped[];
extern const u8 EverGrandeCity_SidneysRoom_EventScript_Defeated_CutsceneSkipped[];
extern const u8 EverGrandeCity_PhoebesRoom_EventScript_Phoebe_CutsceneSkipped[];
extern const u8 EverGrandeCity_PhoebesRoom_EventScript_Defeated_Cutscene_Skipped[];
extern const u8 EverGrandeCity_GlaciasRoom_EventScript_Glacia_CutsceneSkipped[];
extern const u8 EverGrandeCity_GlaciasRoom_EventScript_Defeated_CutsceneSkipped[];
extern const u8 EverGrandeCity_DrakesRoom_EventScript_Drake_CutsceneSkipped[];
extern const u8 EverGrandeCity_GlaciasRoom_EventScript_Defeated_CutsceneSkipped[];
extern const u8 EverGrandeCity_DrakesRoom_EventScript_Defeated_CutsceneSkipped[];
extern const u8 EverGrandeCity_ChampionsRoom_EventScript_Wallace_CutsceneSkipped[];
extern const u8 EverGrandeCity_ChampionsRoom_EventScript_HoF_CutsceneSkipped[];
extern const u8 EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame_CutsceneSkipped[];

const struct CutscenesSkips sCutsceneSkipScripts[] =
{
    // [CUTSCENE_EXAMPLE] =
    // {
    //     .scriptCutsceneSkipPtr = EventScript_ExampleCutsceneSkip,
    //     .flag = FLAG_CUTSCENE_EXAMPLE,      // Do not include the flag if CUTSCENE_FLAG_TRACKING is set to FALSE
    // },
    [CUTSCENE_AQUA_GRUNT_PETALBURG_WOODS_LEFT] =
    {
        .scriptCutsceneSkipPtr = PetalburgWoods_EventScript_DevonResearcherLeft_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_AQUA_GRUNT_PETALBURG_WOODS,
    },
    [CUTSCENE_AQUA_GRUNT_PETALBURG_WOODS_RIGHT] =
    {
        .scriptCutsceneSkipPtr = PetalburgWoods_EventScript_DevonResearcherRight_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_AQUA_GRUNT_PETALBURG_WOODS,
    },
    [CUTSCENE_AQUA_GRUNT_RUSTURF_TUNNEL] =
    {
        .scriptCutsceneSkipPtr = RusturfTunnel_EventScript_Grunt_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_AQUA_GRUNT_RUSTURF_TUNNEL,
    },
    [CUTSCENE_AQUA_GRUNTS_OCEANIC_MUSEUM] =
    {
        .scriptCutsceneSkipPtr = SlateportCity_OceanicMuseum_2F_EventScript_CaptStern_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_AQUA_GRUNTS_OCEANIC_MUSEUM,
    },
    [CUTSCENE_MAXIE_MT_CHIMNEY] =
    {
        .scriptCutsceneSkipPtr = MtChimney_EventScript_Maxie_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_MAXIE_MT_CHIMNEY,
    },
    [CUTSCENE_MAXIE_MAGMA_HIDEOUT] =
    {
        .scriptCutsceneSkipPtr = MagmaHideout_4F_EventScript_Maxie_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_MAXIE_MAGMA_HIDEOUT,
    },
    [CUTSCENE_ARCHIE_SEAFLOOR_CAVERN] =
    {
        .scriptCutsceneSkipPtr = SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_ARCHIE_SEAFLOOR_CAVERN,
    },
    [CUTSCENE_WALLY_VICTORY_ROAD] =
    {
        .scriptCutsceneSkipPtr = VictoryRoad_1F_EventScript_WallyEntranceBattle_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_WALLY_VICTORY_ROAD,
    },
    [CUTSCENE_SIDNEY_INTRO] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_SidneysRoom_EventScript_Sidney_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_SIDNEY_INTRO,
    },
    [CUTSCENE_SIDNEY_OUTRO] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_SidneysRoom_EventScript_Defeated_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_SIDNEY_OUTRO,
    },
    [CUTSCENE_PHOEBE_INTRO] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_PhoebesRoom_EventScript_Phoebe_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_PHOEBE_INTRO,
    },
    [CUTSCENE_PHOEBE_OUTRO] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_PhoebesRoom_EventScript_Defeated_Cutscene_Skipped,
        .flag = FLAG_CUTSCENE_PHOEBE_OUTRO,
    },
    [CUTSCENE_GLACIA_INTRO] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_GlaciasRoom_EventScript_Glacia_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_GLACIA_INTRO,
    },
    [CUTSCENE_GLACIA_OUTRO] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_GlaciasRoom_EventScript_Defeated_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_GLACIA_OUTRO,
    },
    [CUTSCENE_DRAKE_INTRO] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_DrakesRoom_EventScript_Drake_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_DRAKE_INTRO,
    },
    [CUTSCENE_DRAKE_OUTRO] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_DrakesRoom_EventScript_Defeated_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_DRAKE_OUTRO,
    },
    [CUTSCENE_WALLACE] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_ChampionsRoom_EventScript_Wallace_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_WALLACE,
    },
    [CUTSCENE_HALL_OF_FAME_PART1] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_ChampionsRoom_EventScript_HoF_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_HALL_OF_FAME_PART1,
    },
    [CUTSCENE_HALL_OF_FAME_PART2] =
    {
        .scriptCutsceneSkipPtr = EverGrandeCity_HallOfFame_EventScript_EnterHallOfFame_CutsceneSkipped,
        .flag = FLAG_CUTSCENE_HALL_OF_FAME_PART2,
    },
};

#endif // GUARD_IKIGAI_DATA_GUARD_CUTSCENE_H