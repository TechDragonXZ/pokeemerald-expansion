//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 19
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 18
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 17
            .lvl = 42,
#line 16
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 20
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 25
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 29
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 28
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 27
            .lvl = 43,
#line 26
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 30
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 35
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 39
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 38
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 37
            .lvl = 44,
#line 36
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 40
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
#line 45
    [DIFFICULTY_NORMAL][PARTNER_YOUNG_MAN] =
    {
#line 46
        .trainerName = _("Young Man"),
#line 47
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 48
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 50
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 52
            .species = SPECIES_GHOLDENGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 52
            .heldItem = ITEM_ABILITY_SHIELD,
#line 57
            .ev = TRAINER_PARTY_EVS(52, 0, 0, 16, 60, 24),
#line 59
            .iv = TRAINER_PARTY_IVS(31, 0, 31, 20, 31, 31),
#line 53
            .ability = ABILITY_GOOD_AS_GOLD,
#line 54
            .lvl = 30,
#line 55
            .ball = ITEM_TIMER_BALL,
#line 56
            .friendship = 255,
#line 58
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 60
                MOVE_MAKE_IT_RAIN,
                MOVE_HEX,
                MOVE_TERA_BLAST,
                MOVE_METAL_SOUND,
            },
            },
            {
#line 65
            .species = SPECIES_HONCHKROW,
#line 65
            .gender = TRAINER_MON_MALE,
#line 65
            .heldItem = ITEM_SCOPE_LENS,
#line 70
            .ev = TRAINER_PARTY_EVS(32, 12, 0, 8, 8, 60),
#line 72
            .iv = TRAINER_PARTY_IVS(31, 31, 13, 31, 0, 3),
#line 66
            .ability = ABILITY_SUPER_LUCK,
#line 67
            .lvl = 30,
#line 68
            .ball = ITEM_DUSK_BALL,
#line 69
            .friendship = 255,
#line 71
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 73
                MOVE_NIGHT_SLASH,
                MOVE_AIR_CUTTER,
                MOVE_FACADE,
                MOVE_WHIRLWIND,
            },
            },
            {
#line 78
            .nickname = COMPOUND_STRING("Lucky"),
#line 78
            .species = SPECIES_CINCCINO,
#line 78
            .gender = TRAINER_MON_FEMALE,
#line 78
            .heldItem = ITEM_LOADED_DICE,
#line 85
            .ev = TRAINER_PARTY_EVS(16, 24, 28, 20, 28, 4),
#line 87
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 12, 22, 16),
#line 79
            .ability = ABILITY_TECHNICIAN,
#line 80
            .lvl = 30,
#line 81
            .ball = ITEM_FRIEND_BALL,
#line 82
            .friendship = 255,
#line 86
            .nature = NATURE_JOLLY,
#line 83
            .isShiny = TRUE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
#line 84
            .teraType = TYPE_STELLAR,
            .moves = {
#line 88
                MOVE_TAIL_SLAP,
                MOVE_BULLET_SEED,
                MOVE_ROCK_BLAST,
                MOVE_PLAY_ROUGH,
            },
            },
        },
    },
