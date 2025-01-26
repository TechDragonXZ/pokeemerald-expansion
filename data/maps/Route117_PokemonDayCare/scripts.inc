Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_Judge::
	goto_if_set FLAG_GOT_COSPLAY_PIKACHU, Route117_PokemonDayCare_EventScript_Judge_NotClaimedPikachu
	goto_if_unset FLAG_GOT_COSPLAY_PIKACHU, Route117_PokemonDayCare_EventScript_Judge_ClaimedPikachu
	end

Route117_PokemonDayCare_EventScript_Judge_NotClaimedPikachu::
	lockall
	faceplayer
	msgbox Route117_PokemonDayCare_Text_Judge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_JudgeAccepted
	goto_if_eq VAR_RESULT, NO, Route117_PokemonDayCare_EventScript_JudgeDeclined
	releaseall
	end

Route117_PokemonDayCare_EventScript_Judge_ClaimedPikachu::
	lockall
	faceplayer
	msgbox Route117_PokemonDayCare_Text_JudgePikachu, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route117_PokemonDayCare_EventScript_JudgeAccepted::
	lockall
	faceplayer
	msgbox Route117_PokemonDayCare_Text_JudgeAccepted, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_FASHION_CASE, 1
	givemon SPECIES_PIKACHU_COSPLAY, 20, ITEM_LIGHT_BALL, ITEM_CHERISH_BALL, NATURE_QUIRKY, 2, FEMALE, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_THUNDERSHOCK, MOVE_VOLT_TACKLE, MOVE_FLY, MOVE_SURF, FALSE, FALSE, TYPE_WATER
	setflag FLAG_GOT_COSPLAY_PIKACHU
	closemessage
	releaseall
	end

Route117_PokemonDayCare_EventScript_JudgeDeclined::
	lockall
	faceplayer
	msgbox Route117_PokemonDayCare_Text_JudgeDeclined, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route117_PokemonDayCare_Text_Judge::
	.string "Hey, do you know about Pokémon\n"
	.string "Contests? I used to be a contestant\p"
	.string "for them, but I've recently decided to\n"
	.string "retire. However, my star Pokémon,\p"
	.string "Pikachu still longs to participate.\n"
	.string "Would you like to take it with you?$"

Route117_PokemonDayCare_Text_JudgeDeclined::
	.string "Oh, so you don't want\n"
	.string "to take it with you?$"

Route117_PokemonDayCare_Text_JudgeAccepted::
	.string "Thank you for allowing Pikachu to\n"
	.string "continue to participate in Pokémon\p"
	.string "Contests. Here's another item for you.\n"
	.string "It's a Fasion Case, which will let you\p"
	.string "change the costume of Pikachu.$"

Route117_PokemonDayCare_Text_JudgePikachu::
	.string "How's my Pikachu doing?$"
