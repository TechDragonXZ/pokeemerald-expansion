LilycoveCity_DepartmentStoreRooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
	.byte 0

LilycoveCity_DepartmentStoreRooftop_OnTransition:
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman::
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman::
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale:
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
	lock
	faceplayer
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_THIRSTY_MAN, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManQuenched
	goto_if_eq VAR_LILYCOVE_CITY_STATE, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManDrink
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManDeclined
	case YES, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManAccepted
	case MULTI_B_PRESSED, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManDeclined
	closemessage
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
	lockall
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink::
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales:
	.string "Don't they have set dates for their\n"
	.string "clear-out sales?\p"
	.string "I watch TV, but they never show any\n"
	.string "commercials.$"

LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale:
	.string "Yes! I've been waiting a long time for\n"
	.string "this clear-out sale.\p"
	.string "They have items that you can only get\n"
	.string "here. I'm going to load up, that I am!$"

LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty:
	.string "Ohh… I'm bone-dry thirsty!\n"
	.string "… … …\p"
	.string "Say, you wouldn't mind buying me a soda?\n"
	.string "I'll make it worth your time if you do.$"

LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which drink would you like?$"

LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney:
	.string "Not enough money…$"

LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManAccepted::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_Thankful, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LILYCOVE_CITY_STATE, 1
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManDeclined::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_OhThatsFine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LILYCOVE_CITY_STATE, 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManDrink::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_YoureBack, MSGBOX_DEFAULT
	closemessage
	chooseitem POCKET_MEDICINE
	goto_if_eq VAR_ITEM_ID, ITEM_SODA_POP, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManQuenched
	goto_if_eq VAR_ITEM_ID, ITEM_LEMONADE, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManWrongDrink
	goto_if_eq VAR_ITEM_ID, ITEM_FRESH_WATER, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManWrongDrink
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotDrink, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManQuenched::
	lock
	faceplayer
	removeitem ITEM_SODA_POP, 1
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_Greatful, MSGBOX_DEFAULT
	closemessage
	goto_if_unset FLAG_DAILY_THIRSTY_MAN, LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManReward
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManReward::
	lock
	faceplayer
	setflag FLAG_DAILY_THIRSTY_MAN
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_Reward, MSGBOX_DEFAULT
	closemessage
	random 2
	switch VAR_RESULT
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_SilverReward
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_GoldReward
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SilverReward::
	lock
	faceplayer
	bufferitemname STR_VAR_2, ITEM_BOTTLE_CAP
	giveitem ITEM_BOTTLE_CAP, 1
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_FromCollection, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_GoldReward::
	lock
	faceplayer
	bufferitemname STR_VAR_2, ITEM_GOLD_BOTTLE_CAP
	giveitem ITEM_GOLD_BOTTLE_CAP, 1
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_FromCollection, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyManWrongDrink::
	lock
	faceplayer
	bufferitemname STR_VAR_2, VAR_ITEM_ID
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotRightDrink, MSGBOX_DEFAULT
	closemessage
	release
	end

LilycoveCity_DepartmentStoreRooftop_Text_Thankful::
	.string "Thank you!\p"
	.string "You can get a bottle of Soda Pop\n"
	.string "from the vending machines over there.$"

LilycoveCity_DepartmentStoreRooftop_Text_OhThatsFine::
	.string "Oh, it's fine, you don't have to.$"

LilycoveCity_DepartmentStoreRooftop_Text_YoureBack::
	.string "You're back. Did you bring it?$"

LilycoveCity_DepartmentStoreRooftop_Text_NotDrink::
	.string "Sorry, but this isn't a drink.$"

LilycoveCity_DepartmentStoreRooftop_Text_NotRightDrink::
	.string "Sorry, but this isn't the right drink.\n"
	.string "I wanted a Soda Pop not {STR_VAR_2}.$"

LilycoveCity_DepartmentStoreRooftop_Text_Greatful::
	.string "Once again thank you for this drink!\p"
	.string "Gulp Gulp\p"
	.string "That hit the sopt!$"

LilycoveCity_DepartmentStoreRooftop_Text_Reward::
	.string "As promised, here's your reward.$"

LilycoveCity_DepartmentStoreRooftop_Text_FromCollection::
	.string "It's a {STR_VAR_2} from my collection,\n"
	.string "I heard that there's a guy who accepts\p"
	.string "them for some kind of service right\n"
	.string "here in LILYCOVE CITY.$"
