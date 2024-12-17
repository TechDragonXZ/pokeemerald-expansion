PokeballRecluse_House_MapScripts::
	.byte 0

PokeballRecluse_House_EventScript_Smoliv::
	lockall
	faceplayer
	playmoncry SPECIES_SMOLIV, CRY_MODE_NORMAL
	releaseall
	end

PokeballRecluse_House_EventScript_TalkToRecluse::
	lockall
	faceplayer
	msgbox PokeballRecluse_House_Text_RecluseIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokeballRecluse_House_EventScript_CheckPlayerHasApricorn
	goto_if_eq VAR_RESULT, NO, PokeballRecluse_House_EventScript_RequestDeclined
	releaseall
	end

PokeballRecluse_House_EventScript_RequestDeclined::
	lockall
	faceplayer
	msgbox PokeballRecluse_House_Text_RequestDeclined, MSGBOX_DEFAULT
	releaseall
	end

PokeballRecluse_House_EventScript_CheckPlayerHasApricorn::
	call PokeballRecluse_House_EventScript_GetPlayersApricorns
	goto_if_eq VAR_TEMP_1, 0, PokeballRecluse_House_EventScript_NoApricorns
	goto PokeballRecluse_House_EventScript_HasApricorn
	end

PokeballRecluse_House_EventScript_GetPlayersApricorns::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_RED_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_HasRedApricorn
	checkitem ITEM_BLUE_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_HasBlueApricorn
	checkitem ITEM_PINK_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_HasPinkApricorn
	checkitem ITEM_GREEN_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_HasGreenApricorn
	checkitem ITEM_BLACK_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_HasBlackApricorn
	checkitem ITEM_WHITE_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_HasWhiteApricorn
	checkitem ITEM_YELLOW_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_HasYellowApricorn
	return

PokeballRecluse_House_EventScript_NoApricorns::
	lockall
	faceplayer
	msgbox PokeballRecluse_House_Text_NoApricorns, MSGBOX_DEFAULT
	releaseall
	end

PokeballRecluse_House_EventScript_HasRedApricorn::
	addvar VAR_TEMP_1, 1
	return

PokeballRecluse_House_EventScript_HasBlueApricorn::
	addvar VAR_TEMP_1, 1
	return

PokeballRecluse_House_EventScript_HasPinkApricorn::
	addvar VAR_TEMP_1, 1
	return

PokeballRecluse_House_EventScript_HasGreenApricorn::
	addvar VAR_TEMP_1, 1
	return

PokeballRecluse_House_EventScript_HasBlackApricorn::
	addvar VAR_TEMP_1, 1
	return

PokeballRecluse_House_EventScript_HasWhiteApricorn::
	addvar VAR_TEMP_1, 1
	return

PokeballRecluse_House_EventScript_HasYellowApricorn::
	addvar VAR_TEMP_1, 1
	return

PokeballRecluse_House_EventScript_HasApricorn::
	goto PokeballRecluse_House_EventScript_ShowTradeOptions
	end

PokeballRecluse_House_EventScript_ShowTradeOptions::
	lockall
	faceplayer
	message PokeballRecluse_House_Text_RequestAccepted
	waitmessage
	goto_if_ge VAR_TEMP_1, 1, PokeballRecluse_House_EventScript_ApriBallsOptions
	releaseall
	end

PokeballRecluse_House_EventScript_ApriBallsOptions::
	lockall
	faceplayer
	dynmultipush PokeballRecluse_House_Text_RedApricorn, 0
	dynmultipush PokeballRecluse_House_Text_BlueApricorn, 1
	dynmultipush PokeballRecluse_House_Text_PinkApricorn, 2
	dynmultipush PokeballRecluse_House_Text_GreenApricorn, 3
	dynmultipush PokeballRecluse_House_Text_BlackApricorn, 4
	dynmultipush PokeballRecluse_House_Text_WhiteApricorn, 5
	dynmultipush PokeballRecluse_House_Text_YellowApricorn, 6
	dynmultipush PokeballRecluse_House_Text_Cancel, 7
	dynmultistack 19, 0, TRUE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, PokeballRecluse_House_EventScript_LevelBall
	case 1, PokeballRecluse_House_EventScript_LureBall
	case 2, PokeballRecluse_House_EventScript_LoveBall
	case 3, PokeballRecluse_House_EventScript_FriendBall
	case 4, PokeballRecluse_House_EventScript_HeavyBall
	case 5, PokeballRecluse_House_EventScript_FastBall
	case 6, PokeballRecluse_House_EventScript_MoonBall
	case 7, PokeballRecluse_House_EventScript_RequestDeclined
	goto PokeballRecluse_House_EventScript_RequestDeclined
	releaseall
	end

PokeballRecluse_House_EventScript_LevelBall::
	bufferitemname STR_VAR_2, ITEM_LEVEL_BALL
	setvar VAR_0x8009, ITEM_LEVEL_BALL
	setvar VAR_0x800A, ITEM_RED_APRICORN
	checkitem ITEM_RED_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_Confirm
	call_if_eq VAR_RESULT, FALSE, PokeballRecluse_House_EventScript_NoKindApricorns
	end

PokeballRecluse_House_EventScript_LureBall::
	bufferitemname STR_VAR_2, ITEM_LURE_BALL
	setvar VAR_0x8009, ITEM_LURE_BALL
	setvar VAR_0x800A, ITEM_BLUE_APRICORN
	checkitem ITEM_BLUE_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_Confirm
	call_if_eq VAR_RESULT, FALSE, PokeballRecluse_House_EventScript_NoKindApricorns
	end

PokeballRecluse_House_EventScript_LoveBall::
	bufferitemname STR_VAR_2, ITEM_LOVE_BALL
	setvar VAR_0x8009, ITEM_LOVE_BALL
	setvar VAR_0x800A, ITEM_PINK_APRICORN
	checkitem ITEM_PINK_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_Confirm
	call_if_eq VAR_RESULT, FALSE, PokeballRecluse_House_EventScript_NoKindApricorns
	end

PokeballRecluse_House_EventScript_FriendBall::
	bufferitemname STR_VAR_2, ITEM_FRIEND_BALL
	setvar VAR_0x8009, ITEM_FRIEND_BALL
	setvar VAR_0x800A, ITEM_GREEN_APRICORN
	checkitem ITEM_GREEN_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_Confirm
	call_if_eq VAR_RESULT, FALSE, PokeballRecluse_House_EventScript_NoKindApricorns
	end

PokeballRecluse_House_EventScript_HeavyBall::
	bufferitemname STR_VAR_2, ITEM_HEAVY_BALL
	setvar VAR_0x8009, ITEM_HEAVY_BALL
	setvar VAR_0x800A, ITEM_BLACK_APRICORN
	checkitem ITEM_BLACK_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_Confirm
	call_if_eq VAR_RESULT, FALSE, PokeballRecluse_House_EventScript_NoKindApricorns
	end

PokeballRecluse_House_EventScript_FastBall::
	bufferitemname STR_VAR_2, ITEM_FAST_BALL
	setvar VAR_0x8009, ITEM_FAST_BALL
	setvar VAR_0x800A, ITEM_WHITE_APRICORN
	checkitem ITEM_WHITE_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_Confirm
	call_if_eq VAR_RESULT, FALSE, PokeballRecluse_House_EventScript_NoKindApricorns
	end

PokeballRecluse_House_EventScript_MoonBall::
	bufferitemname STR_VAR_2, ITEM_MOON_BALL
	setvar VAR_0x8009, ITEM_MOON_BALL
	setvar VAR_0x800A, ITEM_YELLOW_APRICORN
	checkitem ITEM_YELLOW_APRICORN
	call_if_eq VAR_RESULT, TRUE, PokeballRecluse_House_EventScript_Confirm
	call_if_eq VAR_RESULT, FALSE, PokeballRecluse_House_EventScript_NoKindApricorns
	end

PokeballRecluse_House_EventScript_NoKindApricorns::
	lockall
	faceplayer
	msgbox PokeballRecluse_House_Text_NoKindApricorns, MSGBOX_AUTOCLOSE
	closemessage
	goto PokeballRecluse_House_EventScript_ApriBallsOptions
	releaseall
	end

PokeballRecluse_House_EventScript_Confirm::
	lockall
	faceplayer
	msgbox PokeballRecluse_House_Text_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokeballRecluse_House_EventScript_GivePlayerBall
	goto_if_eq VAR_RESULT, NO, PokeballRecluse_House_EventScript_RequestDeclined
	releaseall
	end

PokeballRecluse_House_EventScript_GivePlayerBall::
	lockall
	faceplayer
	msgbox PokeballRecluse_House_Text_Finished, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	giveitem VAR_0x8009, 1
	removeitem VAR_0x800A, 1
	closemessage
	releaseall
	end

PokeballRecluse_House_Text_RecluseIntro:
	.string "Welcome trainer!\n"
	.string "Do you have any Apricorns\p"
	.string "that you want me to craft\n"
	.string "into Pokéballs?$"

PokeballRecluse_House_Text_RequestAccepted:
	.string "Ok, so which Apricorns do you\n"
	.string "want me to craft into Pokéballs?$"

PokeballRecluse_House_Text_NoApricorns:
	.string "Oh, you don't have any Apricorns\n"
	.string "for me to craft into Pokéballs.$"

PokeballRecluse_House_Text_NoKindApricorns:
	.string "Oh, you don't have any\n"
	.string "Apricorns of this kind.$"

PokeballRecluse_House_Text_RequestDeclined:
	.string "Oh, you don't want me\n"
	.string "to craft any Pokéballs.$"

PokeballRecluse_House_Text_Finished:
	.string "Here's your {STR_VAR_2}!$"

PokeballRecluse_House_Text_Confirm:
	.string "Are you sure that you want this?$"

PokeballRecluse_House_Text_RedApricorn:
	.string "Red Apricorn$"

PokeballRecluse_House_Text_BlueApricorn:
	.string "Blue Apricorn$"

PokeballRecluse_House_Text_PinkApricorn:
	.string "Pink Apricorn$"

PokeballRecluse_House_Text_GreenApricorn:
	.string "Green Apricorn$"

PokeballRecluse_House_Text_BlackApricorn:
	.string "Black Apricorn$"

PokeballRecluse_House_Text_WhiteApricorn:
	.string "White Apricorn$"

PokeballRecluse_House_Text_YellowApricorn:
	.string "Yellow Apricorn$"

PokeballRecluse_House_Text_Cancel:
	.string "Cancel$"
