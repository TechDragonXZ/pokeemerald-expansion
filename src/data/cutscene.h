#ifndef GUARD_IKIGAI_DATA_GUARD_CUTSCENE_H
#define GUARD_IKIGAI_DATA_GUARD_CUTSCENE_H

#include "global.h"
#include "gba/gba.h"
#include "constants/cutscene.h"
#include "constants/flags.h"
#include "main.h"

// extern const u8 EventScript_ExampleCutsceneSkip[];

extern const u8 MtChimney_EventScript_Maxie_CutsceneSkipped[];
extern const u8 MagmaHideout_4F_EventScript_Maxie_CutsceneSkipped[];
extern const u8 SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre_CutsceneSkipped[];

const struct CutscenesSkips sCutsceneSkipScripts[] =
{
    // [CUTSCENE_EXAMPLE] =
    // {
    //     .scriptCutsceneSkipPtr = EventScript_ExampleCutsceneSkip,
    //     .flag = FLAG_SEEN_CUTSCENE_EXAMPLE,      // Do not include the flag if CUTSCENE_FLAG_TRACKING is set to FALSE
    // },
    [CUTSCENE_MAXIE_MT_CHIMNEY] =
    {
        .scriptCutsceneSkipPtr = MtChimney_EventScript_Maxie_CutsceneSkipped,
        .flag = FLAG_SEEN_CUTSCENE_MAXIE_MT_CHIMNEY,
    },
    [CUTSCENE_MAXIE_MAGMA_BASE] =
    {
        .scriptCutsceneSkipPtr = MagmaHideout_4F_EventScript_Maxie_CutsceneSkipped,
        .flag = FLAG_SEEN_CUTSCENE_MAXIE_MAGMA_BASE,
    },
    [CUTSCENE_ARCHIE_SEAFLOOR_CAVERN] =
    {
        .scriptCutsceneSkipPtr = SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre_CutsceneSkipped,
        .flag = FLAG_SEEN_CUTSCENE_ARCHIE_SEAFLOOR_CAVERN,
    },
};

#endif // GUARD_IKIGAI_DATA_GUARD_CUTSCENE_H