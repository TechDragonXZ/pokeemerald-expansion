#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen0[] =
{
#endif

    [SPECIES_GENEON] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 85,
        .baseSpeed     = 75,
        .baseSpAttack  = 100,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 65,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_VEEVEE_GUARD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Geneon"),
        .cryId = CRY_EEVEE,
        .natDexNum = NATIONAL_DEX_GENEON,
        .categoryName = _("Evolution"),
        .footprint = gMonFootprint_Eevee,
        .levelUpLearnset = sGeneonLevelUpLearnset,
        .teachableLearnset = sGeneonTeachableLearnset,
        .height = 3,
        .weight = 65,
        .description = COMPOUND_STRING(
            "Geneon has an unstable genetic makeup\n"
            "that can suddenly mutate due to its\n"
            "environment. Energy from various\n"
            "types causes this Pokémon to change."),
        .pokemonScale = 476,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Eevee,
        .frontPicFemale = gMonFrontPic_EeveeF,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Eevee,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Eevee,
        .backPicFemale = gMonBackPic_EeveeF,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Eevee,
        .shinyPalette = gMonShinyPalette_Eevee,
        .iconSprite = gMonIcon_Eevee,
        .iconPalIndex = 2,
        FOOTPRINT(Eevee)
    },
#ifdef __INTELLISENSE__
};
#endif