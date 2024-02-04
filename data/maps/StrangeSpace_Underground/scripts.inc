StrangeSpace_Underground_MapScripts::
	.byte 0

StrangeSpace_Underground_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 40
	setflag FLAG_HIDE_REGIDRAGO
	special StartRegiBattle
	waitstate
	clearflag FLAG_HIDE_REGIDRAGO
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, StrangeSpace_Underground_DefeatedRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, StrangeSpace_Underground_RanFromRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, StrangeSpace_Underground_RanFromRegidrago
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

StrangeSpace_Underground_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

StrangeSpace_Underground_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end

StrangeSpace_Underground_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40
	setflag FLAG_HIDE_REGIELEKI
	special StartRegiBattle
	waitstate
	clearflag FLAG_HIDE_REGIELEKI
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, StrangeSpace_Underground_DefeatedRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, StrangeSpace_Underground_RanFromRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, StrangeSpace_Underground_RanFromRegieleki
	setflag FLAG_DEFEATED_REGIELEKI
	release
	end

StrangeSpace_Underground_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

StrangeSpace_Underground_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end

StrangeSpace_Underground_Regigigas::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 40
	setflag FLAG_HIDE_REGIGIGAS
	special StartRegiBattle
	waitstate
	clearflag FLAG_HIDE_REGIGIGAS
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, StrangeSpace_Underground_DefeatedRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, StrangeSpace_Underground_RanFromRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, StrangeSpace_Underground_RanFromRegigigas
	setflag FLAG_DEFEATED_REGIGIGAS
	release
	end

StrangeSpace_Underground_DefeatedRegigigas::
	setflag FLAG_DEFEATED_REGIGIGAS
	goto Common_EventScript_RemoveStaticPokemon
	end

StrangeSpace_Underground_RanFromRegigigas::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end
