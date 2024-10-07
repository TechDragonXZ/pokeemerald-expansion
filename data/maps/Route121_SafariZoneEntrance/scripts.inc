Route121_SafariZoneEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_OnFrame
	.byte 0

Route121_SafariZoneEntrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, Route121_SafariZoneEntrance_EventScript_ExitSafariZone
	.2byte 0

Route121_SafariZoneEntrance_EventScript_ExitSafariZone::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route121_SafariZoneEntrance_EventScript_WelcomeAttendant::
	msgbox Route121_SafariZoneEntrance_Text_WelcomeToSafariZone, MSGBOX_NPC
	end

Route121_SafariZoneEntrance_EventScript_InfoAttendant::
	lock
	faceplayer
	msgbox Route121_SafariZoneEntrance_Text_WelcomeFirstTime, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_FirstTimeInfo
	msgbox Route121_SafariZoneEntrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_FirstTimeInfo::
	msgbox Route121_SafariZoneEntrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NoPokeblockCase
	call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NotEnoughMoney
	playse SE_SHOP
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_SOUTH, 32, 33
	waitstate
	end

Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

Route121_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_right
	step_end

Route121_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	delay_16
	step_end

Route121_SafariZoneEntrance_EventScript_TrainerTipSign::
	msgbox Route121_SafariZoneEntrance_Text_TrainerTip, MSGBOX_SIGN
	end


Route121_SafariZoneEntrance_EventScript_TryEntry::
	lockall
	goto_if_unset FLAG_TERRARIUM_ACCESS, Route121_SafariZoneEntrance_EventScript_LetterCheck
	releaseall
	end

Route121_SafariZoneEntrance_EventScript_ToggleEntry::
	lockall
	goto_if_unset FLAG_IN_TERRARIUM, Route121_SafariZoneEntrance_EventScript_SetInside
	goto_if_set FLAG_IN_TERRARIUM, Route121_SafariZoneEntrance_EventScript_SetNotInside
	releaseall
	end

Route121_SafariZoneEntrance_EventScript_SetInside::
	setflag FLAG_IN_TERRARIUM
	end

Route121_SafariZoneEntrance_EventScript_SetNotInside::
	clearflag FLAG_IN_TERRARIUM
	end

Route121_SafariZoneEntrance_EventScript_LetterCheck::
	lockall
	checkitem ITEM_LETTER 1
	call_if_eq VAR_RESULT, TRUE, Route121_SafariZoneEntrance_EventScript_HasLetter
	goto_if_eq VAR_RESULT, FALSE, Route121_SafariZoneEntrance_EventScript_NoLetter
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route121_SafariZoneEntrance_EventScript_NoLetter::
	msgbox Route121_SafariZoneEntrance_Text_NotAllowed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route121_SafariZoneEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route121_SafariZoneEntrance_EventScript_HasLetter::
	msgbox Route121_SafariZoneEntrance_Text_Allowed, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TERRARIUM_ACCESS
	removeitem ITEM_LETTER 1
	releaseall
	end

Route121_SafariZoneEntrance_Movement_PushPlayerBackFromCounter:
	walk_left
	step_end

Route121_SafariZoneEntrance_EventScript_TerrariumAttendant::
	lock
	faceplayer
	msgbox Route121_SafariZoneEntrance_Text_TerrariumWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_NOT_FIRST_TIME, Route121_SafariZoneEntrance_EventScript_FirstTimeInfo_Terrarium
	goto_if_set FLAG_NOT_FIRST_TIME, Route121_SafariZoneEntrance_EventScript_TerrariumGroups
	release
	end

Route121_SafariZoneEntrance_EventScript_FirstTimeInfo_Terrarium::
	setflag FLAG_NOT_FIRST_TIME
	msgbox Route121_SafariZoneEntrance_Text_FirstTimeInfo_Terrarium, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_TerrariumGroups::
	msgbox Route121_SafariZoneEntrance_Text_TerrariumGroups, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_Zones
	goto_if_eq VAR_RESULT, NO, Route121_SafariZoneEntrance_EventScript_ChangeDeclined
	closemessage
	release
	end

Route121_SafariZoneEntrance_EventScript_ChangeDeclined::
	msgbox Route121_SafariZoneEntrance_Text_ChangeDeclined, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_Zones::
	msgbox Route121_SafariZoneEntrance_Text_TerrariumGroups, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_TERRARIUM_ZONES, TRUE
	switch VAR_RESULT
	case 0, Route121_SafariZoneEntrance_EventScript_TerrariumMain
	case 1, Route121_SafariZoneEntrance_EventScript_TerrariumSub
	case MULTI_B_PRESSED, Route121_SafariZoneEntrance_EventScript_TerrariumGroups
	closemessage
	release
	end

Route121_SafariZoneEntrance_EventScript_TerrariumMain::
	buffernumberstring STR_VAR_1, VAR_TERRARIUM_MAIN_WILD_SET
	msgbox Route121_SafariZoneEntrance_Text_CurrentGroup, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_TERRARIUM_GROUPS, TRUE
	switch VAR_RESULT
	case 0, Route121_SafariZoneEntrance_EventScript_TerrariumMainGroup0
	case 1, Route121_SafariZoneEntrance_EventScript_TerrariumMainGroup1
	case 2, Route121_SafariZoneEntrance_EventScript_TerrariumMainGroup2
	case 3, Route121_SafariZoneEntrance_EventScript_TerrariumGroups
	case MULTI_B_PRESSED, Route121_SafariZoneEntrance_EventScript_TerrariumGroups
	closemessage
	release
	end

Route121_SafariZoneEntrance_EventScript_TerrariumMainGroup0::
	setvar VAR_TERRARIUM_MAIN_WILD_SET, 0
	closemessage
	end

Route121_SafariZoneEntrance_EventScript_TerrariumMainGroup1::
	setvar VAR_TERRARIUM_MAIN_WILD_SET, 1
	closemessage
	end

Route121_SafariZoneEntrance_EventScript_TerrariumMainGroup2::
	setvar VAR_TERRARIUM_MAIN_WILD_SET, 2
	closemessage
	end

Route121_SafariZoneEntrance_EventScript_TerrariumSub::
	buffernumberstring STR_VAR_1, VAR_TERRARIUM_SUB_WILD_SET
	msgbox Route121_SafariZoneEntrance_Text_CurrentGroup, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_TERRARIUM_GROUPS, TRUE
	switch VAR_RESULT
	case 0, Route121_SafariZoneEntrance_EventScript_TerrariumSubGroup0
	case 1, Route121_SafariZoneEntrance_EventScript_TerrariumSubGroup1
	case 2, Route121_SafariZoneEntrance_EventScript_TerrariumSubGroup2
	case 3, Route121_SafariZoneEntrance_EventScript_TerrariumGroups
	case MULTI_B_PRESSED, Route121_SafariZoneEntrance_EventScript_TerrariumGroups
	closemessage
	release
	end

Route121_SafariZoneEntrance_EventScript_TerrariumSubGroup0::
	setvar VAR_TERRARIUM_SUB_WILD_SET, 0
	closemessage
	end

Route121_SafariZoneEntrance_EventScript_TerrariumSubGroup1::
	setvar VAR_TERRARIUM_SUB_WILD_SET, 1
	closemessage
	end

Route121_SafariZoneEntrance_EventScript_TerrariumSubGroup2::
	setvar VAR_TERRARIUM_SUB_WILD_SET, 2
	closemessage
	end

Route121_SafariZoneEntrance_Text_Allowed:
	.string "Is that a letter of approval? It is!\n"
	.string "With this you can freely enter the\p"
	.string "Terrarium whenever you want.$"

Route121_SafariZoneEntrance_Text_NotAllowed:
	.string "Sorry, you can't enter the Terrarium\n"
	.string "without bringing a letter of approval.$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo_Terrarium:
	.string "Below us is the Terrarium,\n"
	.string "an underground research facility that\p"
	.string "houses a wide range of Pokémon within\n"
	.string "various different biomes.$"

Route121_SafariZoneEntrance_Text_TerrariumGroups:
	.string "From here, if you want, I can change the\n"
	.string "kind of Pokémon that can be found\p"
	.string "inside of the Terrarium.$"

Route121_SafariZoneEntrance_Text_TerrariumWelcome:
	.string "Welcome to the Terrarium!$"

Route121_SafariZoneEntrance_Text_TerrariumComeInAndEnjoy:
	.string "Come in and enjoy the Terrarium!$"

Route121_SafariZoneEntrance_Text_CurrentGroup:
	.string "This part of the Terrarium is currently\n"
	.string "spawning Pokémon from encounter\p"
	.string "group {STR_VAR_1}.$"

Route121_SafariZoneEntrance_Text_ChangeDeclined:
	.string "So, you don't want to change the\n"
	.string "Pokémon that can be found here.$"
