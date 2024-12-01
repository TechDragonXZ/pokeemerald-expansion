.set NUM_OPPONENTS, VAR_0x8009

Terrarium_Lobby_MapScripts::
	.byte 0

Terrarium_Lobby_EventScript_TerrariumAttendant::
	lock
	faceplayer
	msgbox Terrarium_Lobby_Text_TerrariumWelcome, MSGBOX_DEFAULT
	waitbuttonpress
	goto Terrarium_Lobby_EventScript_TerrariumGroups
	release
	end

Terrarium_Lobby_EventScript_TerrariumGroups::
	msgbox Terrarium_Lobby_Text_TerrariumGroups, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Terrarium_Lobby_EventScript_Zones
	goto_if_eq VAR_RESULT, NO, Terrarium_Lobby_EventScript_ChangeDeclined
	closemessage
	release
	end

Terrarium_Lobby_EventScript_ChangeDeclined::
	msgbox Terrarium_Lobby_Text_ChangeDeclined, MSGBOX_DEFAULT
	release
	end

Terrarium_Lobby_EventScript_Zones::
	msgbox Terrarium_Lobby_Text_TerrariumGroups, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_TERRARIUM_ZONES, TRUE
	switch VAR_RESULT
	case 0, Terrarium_Lobby_EventScript_TerrariumMain
	case 1, Terrarium_Lobby_EventScript_TerrariumSub
	case MULTI_B_PRESSED, Terrarium_Lobby_EventScript_TerrariumGroups
	closemessage
	release
	end

Terrarium_Lobby_EventScript_TerrariumMain::
	buffernumberstring STR_VAR_1, VAR_TERRARIUM_MAIN_WILD_SET
	msgbox Terrarium_Lobby_Text_CurrentGroup, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_TERRARIUM_GROUPS, TRUE
	switch VAR_RESULT
	case 0, Terrarium_Lobby_EventScript_TerrariumMainGroup0
	case 1, Terrarium_Lobby_EventScript_TerrariumMainGroup1
	case 2, Terrarium_Lobby_EventScript_TerrariumMainGroup2
	case 3, Terrarium_Lobby_EventScript_TerrariumGroups
	case MULTI_B_PRESSED, Terrarium_Lobby_EventScript_TerrariumGroups
	closemessage
	release
	end

Terrarium_Lobby_EventScript_TerrariumMainGroup0::
	setvar VAR_TERRARIUM_MAIN_WILD_SET, 0
	closemessage
	end

Terrarium_Lobby_EventScript_TerrariumMainGroup1::
	setvar VAR_TERRARIUM_MAIN_WILD_SET, 1
	closemessage
	end

Terrarium_Lobby_EventScript_TerrariumMainGroup2::
	setvar VAR_TERRARIUM_MAIN_WILD_SET, 2
	closemessage
	end

Terrarium_Lobby_EventScript_TerrariumSub::
	buffernumberstring STR_VAR_1, VAR_TERRARIUM_SUB_WILD_SET
	msgbox Terrarium_Lobby_Text_CurrentGroup, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_TERRARIUM_GROUPS, TRUE
	switch VAR_RESULT
	case 0, Terrarium_Lobby_EventScript_TerrariumSubGroup0
	case 1, Terrarium_Lobby_EventScript_TerrariumSubGroup1
	case 2, Terrarium_Lobby_EventScript_TerrariumSubGroup2
	case 3, Terrarium_Lobby_EventScript_TerrariumGroups
	case MULTI_B_PRESSED, Terrarium_Lobby_EventScript_TerrariumGroups
	closemessage
	release
	end

Terrarium_Lobby_EventScript_TerrariumSubGroup0::
	setvar VAR_TERRARIUM_SUB_WILD_SET, 0
	closemessage
	end

Terrarium_Lobby_EventScript_TerrariumSubGroup1::
	setvar VAR_TERRARIUM_SUB_WILD_SET, 1
	closemessage
	end

Terrarium_Lobby_EventScript_TerrariumSubGroup2::
	setvar VAR_TERRARIUM_SUB_WILD_SET, 2
	closemessage
	end

Terrarium_Lobby_Text_TerrariumGroups:
	.string "From here, if you want, I can change the\n"
	.string "kind of Pokémon that can be found\p"
	.string "inside of the Terrarium.$"

Terrarium_Lobby_Text_TerrariumWelcome:
	.string "Welcome to the Terrarium!$"

Terrarium_Lobby_Text_TerrariumComeInAndEnjoy:
	.string "Come in and enjoy the Terrarium!$"

Terrarium_Lobby_Text_CurrentGroup:
	.string "This part of the Terrarium is currently\n"
	.string "spawning Pokémon from encounter\p"
	.string "group {STR_VAR_1}.$"

Terrarium_Lobby_Text_ChangeDeclined:
	.string "So, you don't want to change the\n"
	.string "Pokémon that can be found here.$"

Terrarium_Lobby_EventScript_AdvBerryBlender_Man::
	lockall
	faceplayer
	msgbox Terrarium_Lobby_Text_DidYouKnow, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Terrarium_Lobby_EventScript_AdvBerryBlender::
	lockall
	setvar NUM_OPPONENTS, 1
	msgbox Terrarium_Lobby_Text_UseAdvBerryBlender, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Terrarium_Lobby_EventScript_TryBlendWithAdvBlender
	msgbox Terrarium_Lobby_Text_NotNow, MSGBOX_DEFAULT
	end

Terrarium_Lobby_EventScript_DoBerryBlending:
	copyvar VAR_0x8004, NUM_OPPONENTS
	fadescreen FADE_TO_BLACK
	special DoBerryBlending
	waitstate
	releaseall
	end

Terrarium_Lobby_EventScript_AdvBlenderNoBerries:
	msgbox Terrarium_Lobby_Text_AdvBlenderNoBerries, MSGBOX_DEFAULT
	releaseall
	end

Terrarium_Lobby_EventScript_TryBlendWithAdvBlender:
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, FALSE, Terrarium_Lobby_EventScript_AdvBlenderNoBerries
	specialvar VAR_RESULT, GetFirstFreePokeblockSlot
	goto_if_ne VAR_RESULT, 65535, Terrarium_Lobby_EventScript_BlendWithAdvBlender
	goto_if_eq VAR_RESULT, 65535, Terrarium_Lobby_EventScript_AdvBlenderCaseFull
	end

Terrarium_Lobby_EventScript_BlendWithAdvBlender:
	msgbox Terrarium_Lobby_Text_AdvBlenderLetsBerryBlender, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_DoBerryBlending
	end

Terrarium_Lobby_EventScript_AdvBlenderCaseFull:
	msgbox Terrarium_Lobby_Text_AdvBlenderPokeblockCaseFull, MSGBOX_DEFAULT
	releaseall
	end

Terrarium_Lobby_Text_AdvBlenderPokeblockCaseFull:
	.string "Your {POKEBLOCK} CASE appears to be full!\n"
	.string "Use some {POKEBLOCK}S and come back!$"

Terrarium_Lobby_Text_AdvBlenderLetsBerryBlender:
	.string "Let's get started, then!\n"
	.string "let's Berry Blender!$"

Terrarium_Lobby_Text_UseAdvBerryBlender:
	.string "Do you want to use this Berry Blender?$"

Terrarium_Lobby_Text_NotNow:
	.string "Come back whenever!$"

Terrarium_Lobby_Text_AdvBlenderNoBerries:
	.string "You have no Berries!\n"
	.string "Come back with some Berries!$"

Terrarium_Lobby_Text_DidYouKnow:
	.string "Did you know that the Berry Blenders\n"
	.string "inside of the marked areas are highly\p"
	.string "advanced models that has its own berry\n"
	.string "supply and the skills of a\p"
	.string "Berry Blending Master!$"

Terrarium_Lobby_EventScript_DrinkVendingMachine::
	lockall
	message Terrarium_Lobby_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto Terrarium_Lobby_EventScript_ChooseDrink
	end

Terrarium_Lobby_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, Terrarium_Lobby_EventScript_FreshWater
	case 1, Terrarium_Lobby_EventScript_SodaPop
	case 2, Terrarium_Lobby_EventScript_Lemonade
	msgbox Terrarium_Lobby_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_ExitVendingMachine
	end

Terrarium_Lobby_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto Terrarium_Lobby_EventScript_TryBuyDrink
	end

Terrarium_Lobby_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto Terrarium_Lobby_EventScript_TryBuyDrink
	end

Terrarium_Lobby_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto Terrarium_Lobby_EventScript_TryBuyDrink
	end

Terrarium_Lobby_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

Terrarium_Lobby_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

Terrarium_Lobby_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

Terrarium_Lobby_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

Terrarium_Lobby_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

Terrarium_Lobby_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

Terrarium_Lobby_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, Terrarium_Lobby_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, Terrarium_Lobby_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, Terrarium_Lobby_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, Terrarium_Lobby_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, Terrarium_Lobby_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, Terrarium_Lobby_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, Terrarium_Lobby_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, Terrarium_Lobby_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox Terrarium_Lobby_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 16  @ 1/16 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, Terrarium_Lobby_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, Terrarium_Lobby_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox Terrarium_Lobby_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 16  @ 1/16 * the prev 1/16 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, Terrarium_Lobby_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, Terrarium_Lobby_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox Terrarium_Lobby_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_ChooseNewDrink
	end

Terrarium_Lobby_EventScript_ChooseNewDrink::
	message Terrarium_Lobby_Text_WhichDrinkWouldYouLike
	waitmessage
	goto Terrarium_Lobby_EventScript_ChooseDrink
	end

Terrarium_Lobby_EventScript_NotEnoughMoneyForDrink::
	msgbox Terrarium_Lobby_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_ExitVendingMachine
	end

Terrarium_Lobby_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_ExitVendingMachine
	end

Terrarium_Lobby_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

Terrarium_Lobby_Text_WhichDrinkWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which drink would you like?$"

Terrarium_Lobby_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

Terrarium_Lobby_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

Terrarium_Lobby_Text_NotEnoughMoney:
	.string "Not enough money…$"

Terrarium_Lobby_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"

Terrarium_Lobby_EventScript_PokeballVendingMachine::
	lockall
	message Terrarium_Lobby_Text_WhichPackWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto Terrarium_Lobby_EventScript_ChoosePokeball
	end

Terrarium_Lobby_EventScript_ChoosePokeball::
	multichoice 16, 0, MULTI_VENDING_MACHINE_POKEBALL, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, Terrarium_Lobby_EventScript_SafariBall
	case 1, Terrarium_Lobby_EventScript_SportBall
	case 2, Terrarium_Lobby_EventScript_ParkBall
	msgbox Terrarium_Lobby_Text_DecidedAgainstBuyingPokeballs, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_ExitVendingMachine
	end

Terrarium_Lobby_EventScript_SafariBall::
	setvar VAR_TEMP_0, ITEM_SAFARI_BALL
	goto Terrarium_Lobby_EventScript_TryBuyPack
	end

Terrarium_Lobby_EventScript_SportBall::
	setvar VAR_TEMP_0, ITEM_SPORT_BALL
	goto Terrarium_Lobby_EventScript_TryBuyPack
	end

Terrarium_Lobby_EventScript_ParkBall::
	setvar VAR_TEMP_0, ITEM_PARK_BALL
	goto Terrarium_Lobby_EventScript_TryBuyPack
	end

Terrarium_Lobby_EventScript_CheckMoneySafariBall::
	checkmoney 200
	return

Terrarium_Lobby_EventScript_CheckMoneySportBall::
	checkmoney 300
	return

Terrarium_Lobby_EventScript_CheckMoneyParkBall::
	checkmoney 350
	return

Terrarium_Lobby_EventScript_RemoveMoneySafariBall::
	removemoney 200
	return

Terrarium_Lobby_EventScript_RemoveMoneySportBall::
	removemoney 300
	return

Terrarium_Lobby_EventScript_RemoveMoneyParkBall::
	removemoney 350
	return

Terrarium_Lobby_EventScript_TryBuyPack::
	call_if_eq VAR_TEMP_1, 0, Terrarium_Lobby_EventScript_CheckMoneySafariBall
	call_if_eq VAR_TEMP_1, 1, Terrarium_Lobby_EventScript_CheckMoneySportBall
	call_if_eq VAR_TEMP_1, 2, Terrarium_Lobby_EventScript_CheckMoneyParkBall
	goto_if_eq VAR_RESULT, FALSE, Terrarium_Lobby_EventScript_NotEnoughMoneyForPokeball
	checkitemspace VAR_TEMP_0, 5
	goto_if_eq VAR_RESULT, FALSE, Terrarium_Lobby_EventScript_NoRoomForPokeball
	call_if_eq VAR_TEMP_1, 0, Terrarium_Lobby_EventScript_RemoveMoneySafariBall
	call_if_eq VAR_TEMP_1, 1, Terrarium_Lobby_EventScript_RemoveMoneySportBall
	call_if_eq VAR_TEMP_1, 2, Terrarium_Lobby_EventScript_RemoveMoneyParkBall
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox Terrarium_Lobby_Text_PackOfPokeballDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0, 5
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 16  @ 1/16 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, Terrarium_Lobby_EventScript_ChooseNewPokeball
	checkitemspace VAR_TEMP_0, 5
	goto_if_eq VAR_RESULT, FALSE, Terrarium_Lobby_EventScript_NoRoomForPokeball
	playse SE_VEND
	msgbox Terrarium_Lobby_Text_ExtraPackOfPokeballsDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0, 5
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 16  @ 1/16 * the prev 1/16 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, Terrarium_Lobby_EventScript_ChooseNewPokeball
	checkitemspace VAR_TEMP_0, 5
	goto_if_eq VAR_RESULT, 0, Terrarium_Lobby_EventScript_NoRoomForPokeball
	playse SE_VEND
	msgbox Terrarium_Lobby_Text_ExtraPackOfPokeballsDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0, 5
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_POKEBALLS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_ChooseNewPokeball
	end

Terrarium_Lobby_EventScript_ChooseNewPokeball::
	message Terrarium_Lobby_Text_WhichPackWouldYouLike
	waitmessage
	goto Terrarium_Lobby_EventScript_ChoosePokeball
	end

Terrarium_Lobby_EventScript_NotEnoughMoneyForPokeball::
	msgbox Terrarium_Lobby_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_ExitVendingMachine
	end

Terrarium_Lobby_EventScript_NoRoomForPokeball::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto Terrarium_Lobby_EventScript_ExitVendingMachine
	end

Terrarium_Lobby_Text_WhichPackWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which Pokéball Pack would you like?$"

Terrarium_Lobby_Text_PackOfPokeballDroppedDown:
	.string "Clang!\p"
	.string "A pack of {STR_VAR_1} dropped down.$"

Terrarium_Lobby_Text_ExtraPackOfPokeballsDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra pack of {STR_VAR_1}\n"
	.string "dropped down!$"

Terrarium_Lobby_Text_DecidedAgainstBuyingPokeballs:
	.string "Decided against buying\n"
	.string "a pack of Pokéballs.$"

Terrarium_Lobby_EventScript_Debug::
	msgbox Terrarium_Lobby_Text_Debug, MSGBOX_AUTOCLOSE
	setflag FLAG_SYS_DEXNAV_GET
	setflag FLAG_SYS_STATS_EDITOR_GET
	setflag FLAG_ENABLE_WILDMON_EVOLUTION
	end

Terrarium_Lobby_Text_Debug:
	.string "Given Dexnav and Stats Editor$"
