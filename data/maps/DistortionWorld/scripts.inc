DistortionWorld_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DistortionWorld_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, DistortionWorld_OnResume
	map_script MAP_SCRIPT_ON_LOAD, DistortionWorld_OnLoad
	.byte 0

DistortionWorld_OnLoad::
	setvar VAR_CURRENT_MAP, MAP_DISTORTION_WORLD
	end

DistortionWorld_OnTransition::
	call_if_unset FLAG_DEFEATED_GIRATINA, DistortionWorld_EventScript_ShowGiratina
	end

DistortionWorld_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DistortionWorld_EventScript_TryRemoveGiratina
	end

DistortionWorld_EventScript_ShowGiratina::
	clearflag FLAG_HIDE_GIRATINA
	return

DistortionWorld_EventScript_TryRemoveGiratina::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

DistortionWorld_EventScript_Giratina::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GIRATINA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_GIRATINA, 40, ITEM_GRISEOUS_CORE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DistortionWorld_EventScript_DefeatedGiratina
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DistortionWorld_EventScript_RanFromGiratina
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DistortionWorld_EventScript_RanFromGiratina
	setflag FLAG_DEFEATED_GIRATINA
	release
	end

DistortionWorld_EventScript_DefeatedGiratina::
	setflag FLAG_DEFEATED_GIRATINA
	goto Common_EventScript_RemoveStaticPokemon
	end

DistortionWorld_EventScript_RanFromGiratina::
	setvar VAR_0x8004, SPECIES_GIRATINA
	goto Common_EventScript_LegendaryFlewAway
	end
