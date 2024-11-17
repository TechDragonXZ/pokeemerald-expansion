
SelfTrade_EventScript_ShowPlayer::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SelfTrade_EventScript_ShowMale
	call_if_eq VAR_RESULT, FEMALE, SelfTrade_EventScript_ShowFemale
	call SelfTrade_EventScript_ShowMale
	end

SelfTrade_EventScript_ShowMale::
	call_if_set FLAG_HIDE_POKEMON_CENTER_MALE, SelfTrade_EventScript_Male
	goto SelfTrade_EventScript_Male
	end

SelfTrade_EventScript_Male::
	clearflag FLAG_HIDE_POKEMON_CENTER_MALE
	return

SelfTrade_EventScript_ShowFemale::
	call_if_set FLAG_HIDE_POKEMON_CENTER_FEMALE, SelfTrade_EventScript_Female
	goto SelfTrade_EventScript_Female
	end

SelfTrade_EventScript_Female::
	clearflag FLAG_HIDE_POKEMON_CENTER_FEMALE
	return

SelfTrade_EventScript_V1::
	lock
	faceplayer
	msgbox SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SelfTrade_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SelfTrade_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 6
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

SelfTrade_EventScript_V2::
	lock
	faceplayer
	msgbox SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SelfTrade_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SelfTrade_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 7
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setvar VAR_0x8004, 8
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

SelfTrade_EventScript_DeclineTrade::
	msgbox SelfTrade_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

SelfTrade_Text_IllTradeIfYouWant:
	.string "{PLAYER}: Hi {PLAYER}, I'm {PLAYER}!\n"
	.string "I know that you may have a lot of\p"
	.string "questions, but in short, I'm you from an\n"
	.string "alternate universe. I came to this\p"
	.string "universe to help you evolve Pokémon\n"
	.string "that have trade-based evolutions.\p"
	.string "So, do you want to trade with me?$"

SelfTrade_Text_ComeBack:
	.string "{PLAYER}: Come back at any time!$"

SelfTrade_Text_YouDontWantToThatsOkay:
	.string "{PLAYER}: Oh, you don't want to trade?\n"
    .string "Okay, you can come back at any time!$"
