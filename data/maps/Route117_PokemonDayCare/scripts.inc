Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_Man::
	goto_if_set FLAG_HAS_ADPOTED_PKMN, Route117_PokemonDayCare_EventScript_ManCantAdpot
	goto_if_unset FLAG_HAS_ADPOTED_PKMN, Route117_PokemonDayCare_EventScript_ManCanAdpot
	end

Route117_PokemonDayCare_EventScript_ManCanAdpot::
	lock
	faceplayer
	msgbox Route117_PokemonDayCare_Text_AdoptAPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route117_PokemonDayCare_EventScript_CancelMonSelect
	release
	end

Route117_PokemonDayCare_EventScript_ManCantAdpot::
	lock
	faceplayer
	msgbox Route117_PokemonDayCare_Text_CantAdoptAPokemon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GMaxEevee::
	lockall
	setvar VAR_TEMP_1, 1
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	goto Route117_PokemonDayCare_EventScript_ConfirmPokemon

Route117_PokemonDayCare_EventScript_GMaxPikachu::
	lockall
	setvar VAR_TEMP_1, 2
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU
	goto Route117_PokemonDayCare_EventScript_ConfirmPokemon

Route117_PokemonDayCare_EventScript_GMaxMeowth::
	lockall
	setvar VAR_TEMP_1, 3
	bufferspeciesname STR_VAR_1, SPECIES_MEOWTH
	goto Route117_PokemonDayCare_EventScript_ConfirmPokemon

Route117_PokemonDayCare_EventScript_ConfirmPokemon::
	msgbox Route117_PokemonDayCare_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route117_PokemonDayCare_EventScript_CancelMonSelect
	switch VAR_TEMP_1
	case 1, Route117_PokemonDayCare_EventScript_ChooseGMaxEevee
	case 2, Route117_PokemonDayCare_EventScript_ChooseGMaxPikachu
	case 3, Route117_PokemonDayCare_EventScript_ChooseGMaxMeowth
	end

Route117_PokemonDayCare_EventScript_ChooseGMaxEevee::
	setflag FLAG_ADOPTED_PKMN_ONE
	setflag FLAG_HAS_ADPOTED_PKMN
	givemon SPECIES_EEVEE, 20, ITEM_SILK_SCARF, ITEM_PREMIER_BALL, NATURE_SERIOUS, 0, MALE, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_LAST_RESORT, MOVE_BADDY_BAD, MOVE_SHADOW_BALL, MOVE_TERA_BLAST, FALSE, TRUE, TYPE_STELLAR
	msgbox Route117_PokemonDayCare_Text_TakeCare, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_EventScript_ChooseGMaxPikachu::
	setflag FLAG_ADOPTED_PKMN_TWO
	setflag FLAG_HAS_ADPOTED_PKMN
	givemon SPECIES_PIKACHU, 20, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_SERIOUS, 0, MALE, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_VOLT_TACKLE, MOVE_FLY, MOVE_SURF, MOVE_TERA_BLAST, FALSE, TRUE, TYPE_STELLAR
	msgbox Route117_PokemonDayCare_Text_TakeCare, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_EventScript_ChooseGMaxMeowth::
	setflag FLAG_ADOPTED_PKMN_THREE
	setflag FLAG_HAS_ADPOTED_PKMN
	givemon SPECIES_MEOWTH, 20, ITEM_SILK_SCARF, ITEM_PREMIER_BALL, NATURE_SERIOUS, 0, MALE, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_PAY_DAY, MOVE_BITE, MOVE_SLASH, MOVE_TERA_BLAST, FALSE, TRUE, TYPE_STELLAR
	msgbox Route117_PokemonDayCare_Text_TakeCare, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_EventScript_CancelMonSelect::
	msgbox Route117_PokemonDayCare_Text_DontWantToAdopt, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_Quick::
	givemon SPECIES_ABSOL, 20, ITEM_ABSOLITE, ITEM_PREMIER_BALL, NATURE_SERIOUS, 0, MALE, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_NIGHT_SLASH, MOVE_MYSTIC_SLASH, MOVE_DISASTER_BLADE, MOVE_TERA_BLAST, FALSE, FALSE, TYPE_FAIRY
	givemon SPECIES_YANMEGA, 20, ITEM_DRAGON_FANG, ITEM_PREMIER_BALL, NATURE_SERIOUS, 0, MALE, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_BUG_BUZZ, MOVE_DRAGON_TAIL, MOVE_DRAKE_SWARM, MOVE_TERA_BLAST, FALSE, FALSE, TYPE_FLYING
	givemon SPECIES_PAWMOT, 20, ITEM_MAGNET, ITEM_PREMIER_BALL, NATURE_SERIOUS, 0, MALE, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_DOUBLE_SHOCK, MOVE_CLOSE_COMBAT, MOVE_FINAL_BLOW, MOVE_TERA_BLAST, FALSE, FALSE, TYPE_FIRE
	msgbox Route117_PokemonDayCare_Text_TakeCare, MSGBOX_DEFAULT
	releaseall
	end

Route117_PokemonDayCare_Text_DontWantToAdopt:
	.string "Oh… You don't want to adopt, then?\n"
	.string "Good luck on your adventure!$"

Route117_PokemonDayCare_Text_AdoptAPokemon:
	.string "Greetings.\p"
	.string "I have a variety of Pokémon up\n"
	.string "for adoption here.\p"
	.string "Would you like to adopt?$"

Route117_PokemonDayCare_Text_CantAdoptAPokemon:
	.string "Welcome back, {PLAYER}.\p"
	.string "However, you have already adopted a\n"
	.string "Pokémon today, and company policy is\p"
	.string "only one adoption per day per trainer.$"

Route117_PokemonDayCare_Text_TakeCare:
	.string "Take good care of that {STR_VAR_1}!$"

Route117_PokemonDayCare_Text_SoYourChoiceIsX:
	.string "So, your choice is {STR_VAR_1}?$"
