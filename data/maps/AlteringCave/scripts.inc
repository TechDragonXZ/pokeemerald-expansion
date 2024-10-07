AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AlteringCave_OnResume
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	call_if_unset FLAG_DEFEATED_REGIELEKI, AlteringCave_EventScript_ShowRegieleki
	call_if_unset FLAG_DEFEATED_REGIDRAGO, AlteringCave_EventScript_ShowRegidrago
	end

AlteringCave_EventScript_ShowRegieleki::
	clearflag FLAG_HIDE_REGIELEKI
	return

AlteringCave_EventScript_ShowRegidrago::
	clearflag FLAG_HIDE_REGIDRAGO
	return

AlteringCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave_EventScript_TryRemoveRegieleki
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave_EventScript_TryRemoveRegidrago
	end

AlteringCave_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AlteringCave_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AlteringCave_EventScript_WildChange::
	lockall
	faceplayer
	msgbox AlteringCave_Text_Change, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, AlteringCave_EventScript_WildChangeAccepted
	goto_if_eq VAR_RESULT, NO, AlteringCave_EventScript_WildChangeDeclined
	releaseall
	end

AlteringCave_EventScript_WildChangeAccepted::
	multichoice 20, 0, MULTI_ALTERING_CAVE_ENCOUNTERS, TRUE
	switch VAR_RESULT
	case 0, AlteringCave_EventScript_WildChangeZubat
	case 1, AlteringCave_EventScript_WildChangeMareep
	case 2, AlteringCave_EventScript_WildChangePineco
	case 3, AlteringCave_EventScript_WildChangeAccepted_Page2
	case 4, AlteringCave_EventScript_WildChangeDeclined
	case MULTI_B_PRESSED, AlteringCave_EventScript_WildChangeDeclined

AlteringCave_EventScript_WildChangeAccepted_Page2::
	multichoice 20, 0, MULTI_ALTERING_CAVE_ENCOUNTERS_PAGE2, TRUE
	switch VAR_RESULT
	case 0, AlteringCave_EventScript_WildChangeHoundour
	case 1, AlteringCave_EventScript_WildChangeTeddiursa
	case 2, AlteringCave_EventScript_WildChangeAipom
	case 3, AlteringCave_EventScript_WildChangeAccepted_Page3
	case 4, AlteringCave_EventScript_WildChangeAccepted
	case 5, AlteringCave_EventScript_WildChangeDeclined
	case MULTI_B_PRESSED, AlteringCave_EventScript_WildChangeDeclined

AlteringCave_EventScript_WildChangeAccepted_Page3::
	multichoice 20, 0, MULTI_ALTERING_CAVE_ENCOUNTERS_PAGE3, TRUE
	switch VAR_RESULT
	case 0, AlteringCave_EventScript_WildChangeShuckle
	case 1, AlteringCave_EventScript_WildChangeStantler
	case 2, AlteringCave_EventScript_WildChangeSmeargle
	case 3, AlteringCave_EventScript_WildChangeAccepted_Page2
	case 4, AlteringCave_EventScript_WildChangeDeclined
	case MULTI_B_PRESSED, AlteringCave_EventScript_WildChangeDeclined

AlteringCave_EventScript_WildChangeZubat::
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
	msgbox AlteringCave_Text_ChangedToZubat, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangeMareep::
	setvar VAR_ALTERING_CAVE_WILD_SET, 1
	msgbox AlteringCave_Text_ChangedToMareep, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangePineco::
	setvar VAR_ALTERING_CAVE_WILD_SET, 2
	msgbox AlteringCave_Text_ChangedToPineco, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangeHoundour::
	setvar VAR_ALTERING_CAVE_WILD_SET, 3
	msgbox AlteringCave_Text_ChangedToHoundour, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangeTeddiursa::
	setvar VAR_ALTERING_CAVE_WILD_SET, 4
	msgbox AlteringCave_Text_ChangedToTeddiursa, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangeAipom::
	setvar VAR_ALTERING_CAVE_WILD_SET, 5
	msgbox AlteringCave_Text_ChangedToAipom, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangeShuckle::
	setvar VAR_ALTERING_CAVE_WILD_SET, 6
	msgbox AlteringCave_Text_ChangedToShuckle, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangeStantler::
	setvar VAR_ALTERING_CAVE_WILD_SET, 7
	msgbox AlteringCave_Text_ChangedToStantler, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangeSmeargle::
	setvar VAR_ALTERING_CAVE_WILD_SET, 8
	msgbox AlteringCave_Text_ChangedToSmeargle, MSGBOX_AUTOCLOSE
	end

AlteringCave_EventScript_WildChangeDeclined::
	lockall
	msgbox AlteringCave_Text_ChangeDeclined, MSGBOX_AUTOCLOSE
	releaseall
	end

AlteringCave_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 40, ITEM_DRAGON_GEM
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_EventScript_DefeatedRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_EventScript_RanFromRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_EventScript_RanFromRegidrago
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

AlteringCave_EventScript_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

AlteringCave_EventScript_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end

AlteringCave_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40, ITEM_ELECTRIC_GEM
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_EventScript_DefeatedRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_EventScript_RanFromRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_EventScript_RanFromRegieleki
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

AlteringCave_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

AlteringCave_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end

AlteringCave_Text_Change:
	.string "Do you want to change the Pokémon\n"
	.string "that can be found here?$"

AlteringCave_Text_ChangeDeclined:
	.string "So, you don't want to change the\n"
	.string "Pokémon that can be found here.$"

AlteringCave_Text_ChangedToZubat:
	.string "Zubats can now be found.$"

AlteringCave_Text_ChangedToMareep:
	.string "Mareeps can now be found.$"

AlteringCave_Text_ChangedToPineco:
	.string "Pinecos can now be found.$"

AlteringCave_Text_ChangedToHoundour:
	.string "Houndours can now be found.$"

AlteringCave_Text_ChangedToTeddiursa:
	.string "Teddiursas can now be found.$"

AlteringCave_Text_ChangedToAipom:
	.string "Aipoms can now be found.$"

AlteringCave_Text_ChangedToShuckle:
	.string "Shuckles can now be found.$"

AlteringCave_Text_ChangedToStantler:
	.string "Stantlers can now be found.$"

AlteringCave_Text_ChangedToSmeargle:
	.string "Smeargles can now be found.$"
