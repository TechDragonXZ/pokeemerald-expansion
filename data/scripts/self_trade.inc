EventScript_SelfTrade::
	lock
	faceplayer
	msgbox SelfTrade_Text_TradeMachine, MSGBOX_YESNO
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
	msgbox SelfTrade_Text_Success, MSGBOX_DEFAULT
	release
	end

SelfTrade_EventScript_DeclineTrade::
	msgbox SelfTrade_Text_Denied, MSGBOX_DEFAULT
	release
	end

SelfTrade_Text_TradeMachine:
	.string "It's a self trade machine.\n"
	.string "Do you want to trade using it?$"

SelfTrade_Text_Success:
	.string "Trade successful!$"

SelfTrade_Text_Denied:
	.string "You decied to walk away.$"
