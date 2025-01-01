.set LOCALID_OW_MON, 1
.set LOCALID_OW_MON2, 2
.set LOCALID_OW_MON3, 3

Terrarium_Center_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terrarium_Center_OnTransition
    map_script MAP_SCRIPT_ON_LOAD, Terrarium_Center_OnLoad
	.byte 0

Terrarium_Center_OnTransition::
    setobjectaswildencounter LOCALID_OW_MON, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON2, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON3, ENCOUNTER_LAND
    setvar VAR_SEASON 0
    end

Terrarium_Center_OnLoad::
    setvar VAR_SEASON 0
    end

Terrarium_Center_EventScript_SeasonChange::
	lockall
	faceplayer
	msgbox Terrarium_Center_Text_Change, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Terrarium_Center_EventScript_SeasonChangeAccepted
	goto_if_eq VAR_RESULT, NO, Terrarium_Center_EventScript_SeasonChangeDeclined
	releaseall
	end

Terrarium_Center_EventScript_SeasonChangeAccepted::
	lockall
	dynmultipush Terrarium_Center_Text_Spring, 0
	dynmultipush Terrarium_Center_Text_Summer, 1
	dynmultipush Terrarium_Center_Text_Autumn, 2
	dynmultipush Terrarium_Center_Text_Winter, 3
	dynmultipush Terrarium_Center_Text_None, 4
	dynmultistack 19, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, Terrarium_Center_EventScript_SeasonChangeSpring
	case 1, Terrarium_Center_EventScript_SeasonChangeSummer
	case 2, Terrarium_Center_EventScript_SeasonChangeAutumn
	case 3, Terrarium_Center_EventScript_SeasonChangeWinter
	case 4, Terrarium_Center_EventScript_SeasonChangeDeclined
	case MULTI_B_PRESSED, Terrarium_Center_EventScript_SeasonChangeDeclined
	closemessage
	release
	return
	end

Terrarium_Center_EventScript_SeasonChangeSpring::
	setvar VAR_FOREST_SET, 0
	setvar VAR_SEASON, 0
	msgbox Terrarium_Center_Text_ChangedToSpring, MSGBOX_AUTOCLOSE
	end

Terrarium_Center_EventScript_SeasonChangeSummer::
	setvar VAR_FOREST_SET, 1
	setvar VAR_SEASON, 1
	msgbox Terrarium_Center_Text_ChangedToSummer, MSGBOX_AUTOCLOSE
	end

Terrarium_Center_EventScript_SeasonChangeAutumn::
	setvar VAR_FOREST_SET, 2
	setvar VAR_SEASON, 2
	msgbox Terrarium_Center_Text_ChangedToAutumn, MSGBOX_AUTOCLOSE
	end

Terrarium_Center_EventScript_SeasonChangeWinter::
	setvar VAR_FOREST_SET, 3
	setvar VAR_SEASON, 3
	msgbox Terrarium_Center_Text_ChangedToWinter, MSGBOX_AUTOCLOSE
	end

Terrarium_Center_EventScript_SeasonChangeDeclined::
	lockall
	msgbox Terrarium_Center_Text_ChangeDeclined, MSGBOX_AUTOCLOSE
	releaseall
	end

Terrarium_Center_Text_Change:
	.string "Do you want to change the\n"
	.string "season of the forest?$"

Terrarium_Center_Text_ChangeDeclined:
	.string "So, you don't want to change the\n"
	.string "season of the forest.$"

Terrarium_Center_Text_ChangedToSpring:
	.string "The season is now Spring.$"

Terrarium_Center_Text_ChangedToSummer:
	.string "The season is now Summer.$"

Terrarium_Center_Text_ChangedToAutumn:
	.string "The season is now Autumn.$"

Terrarium_Center_Text_ChangedToWinter:
	.string "The season is now Winter.$"

Terrarium_Center_Text_Spring:
	.string "Spring$"

Terrarium_Center_Text_Summer:
	.string "Summer$"

Terrarium_Center_Text_Autumn:
	.string "Autumn$"

Terrarium_Center_Text_Winter:
	.string "Winter$"

Terrarium_Center_Text_None:
	.string "Don't Change$"
