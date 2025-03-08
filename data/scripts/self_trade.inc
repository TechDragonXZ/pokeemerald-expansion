EventScript_SelfTrade::
	lock
	faceplayer
	msgbox EventScript_SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SelfTrade_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq EventScript_SelfTrade_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 6
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox EventScript_SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

EventScript_SelfTrade_DeclineTrade::
	msgbox EventScript_SelfTrade_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

EventScript_SelfTrade_Text_IllTradeIfYouWant:
	.string "I will help you to\n"
	.string "trade a pokemon\p"
	.string "with yourself!$"

EventScript_SelfTrade_Text_ComeBack:
	.string "Come back anytime.$"

EventScript_SelfTrade_Text_YouDontWantToThatsOkay:
	.string "You dont want to?\n"
    .string "Okay come back anytime$"
