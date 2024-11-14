@ Local IDs are the same for both players houses
.set LOCALID_MOM, 1
.set LOCALID_DAD, 5
.set LOCALID_MOM_2F, 14

PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet::
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	return

PlayersHouse_1F_EventScript_EnterHouseMovingIn::
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	call_if_eq VAR_0x8005, MALE, PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale
	call_if_eq VAR_0x8005, FEMALE, PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale
	msgbox PlayersHouse_1F_Text_MoversPokemonGoSetClock, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerWalkIn
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_Movement_PlayerWalkIn:
	walk_up
	step_end

PlayersHouse_1F_EventScript_MomGoSeeRoom::
	msgbox PlayersHouse_1F_Text_ArentYouInterestedInRoom, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MovePlayerAwayFromDoor
	waitmovement 0
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, MALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

LittlerootTown_MaysHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, FEMALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

PlayersHouse_2F_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_2F_EventScript_MomComesUpstairsMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_2F_EventScript_MomComesUpstairsFemale
	releaseall
	end

PlayersHouse_2F_EventScript_MomComesUpstairsMale::
	setvar VAR_0x8008, LOCALID_MOM_2F
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
	closemessage
	delay 10
	call PlayersHouse_2F_EventScript_GivePlayerPokenav
	end

PlayersHouse_2F_EventScript_MomComesUpstairsFemale::
	setvar VAR_0x8008, LOCALID_MOM_2F
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
	closemessage
	delay 10
	call PlayersHouse_2F_EventScript_GivePlayerPokenav
	end

PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayersHouse_2F_Movement_MomEntersMale:
	delay_8
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_8
	walk_left
	step_end

PlayersHouse_2F_Movement_MomExitsMale:
	walk_right
	walk_up
	delay_8
	step_end

PlayersHouse_2F_Movement_MomEntersFemale:
	delay_8
	walk_down
	walk_in_place_faster_right
	delay_16
	delay_8
	walk_right
	step_end

PlayersHouse_2F_Movement_MomExitsFemale:
	walk_left
	walk_up
	delay_8
	step_end

PlayersHouse_1F_EventScript_SetWatchedBroadcast::
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

PlayersHouse_1F_EventScript_PetalburgGymReportMale::
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymMale
	waitmovement 0
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVMale
	waitmovement 0
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatMale
	waitmovement 0
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
	end

PlayersHouse_1F_EventScript_PetalburgGymReportFemale::
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale
	waitmovement 0
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVFemale
	waitmovement 0
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatFemale
	waitmovement 0
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
	end

PlayersHouse_1F_EventScript_MomNoticeGymBroadcast::
	playse SE_PIN
	applymovement VAR_0x8005, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8005, Common_Movement_Delay48
	waitmovement 0
	msgbox PlayersHouse_1F_Text_OhComeQuickly, MSGBOX_DEFAULT
	closemessage
	return

PlayersHouse_1F_EventScript_WatchGymBroadcast::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ReportFromPetalburgGym, MSGBOX_DEFAULT
	fadedefaultbgm
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_HOME
	delay 35
	return

PlayersHouse_1F_Movement_MomApproachDadMale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomApproachDadFemale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerMale:
	walk_right
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerFemale:
	walk_left
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale:
	walk_in_place_faster_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale:
	walk_in_place_faster_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale:
	walk_up
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale:
	walk_up
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale:
	walk_left
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale:
	walk_right
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatMale:
	walk_left
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatFemale:
	walk_right
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
	goto_if_set FLAG_HAS_MATCH_CALL, PlayersHouse_1F_EventScript_TryRegisterMom
	goto_if_set FLAG_RESCUED_BIRCH, PlayersHouse_1F_EventScript_MomHealsParty
	goto_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_SeeYouHoney
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, PlayersHouse_1F_EventScript_DidYouMeetProfBirch
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_DontPushYourselfTooHard::
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_TryRegisterMom::
	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, PlayersHouse_1F_EventScript_CheckGiveAmuletCoin
	msgbox PlayersHouse_1F_Text_IsThatAPokenav, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	release
	end

PlayersHouse_1F_EventScript_CheckGiveAmuletCoin::
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_TryGiveAmuletCoin
	goto PlayersHouse_1F_EventScript_MomHealsParty

PlayersHouse_1F_EventScript_TryGiveAmuletCoin::
	goto_if_set FLAG_RECEIVED_AMULET_COIN, PlayersHouse_1F_EventScript_MomHealsParty
	msgbox PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom, MSGBOX_DEFAULT
	giveitem ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_AMULET_COIN
	release
	end

PlayersHouse_1F_EventScript_MomHealsParty::
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_HealParty
	end

PlayersHouse_1F_EventScript_SeeYouHoney::
	msgbox PlayersHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_HealParty::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox PlayersHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_DidYouMeetProfBirch::
	msgbox PlayersHouse_1F_Text_DidYouMeetProfBirch, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_Vigoroth1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
	msgbox PlayersHouse_1F_Text_Vigoroth1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_EventScript_Vigoroth2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
	msgbox PlayersHouse_1F_Text_Vigoroth2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_Movement_PlayerApproachTVForGymMale:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVMale:
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVFemale:
	walk_right
	step_end

PlayersHouse_1F_Movement_MovePlayerAwayFromDoor:
	walk_up
	step_end

PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerEnterRoomMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerEnterRoomFemale
	applymovement VAR_0x8009, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8009, Common_Movement_Delay48
	waitmovement 0
	delay 20
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadApproachPlayerMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadApproachPlayerFemale
	msgbox PlayersHouse_1F_Text_TicketFromBrineyCameForYou, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox PlayersHouse_1F_Text_PortsInSlateportLilycove, MSGBOX_DEFAULT
	closemessage
	delay 20
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachDadMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachDadFemale
	msgbox PlayersHouse_1F_Text_BetterGetBackToGym, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadExitsMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadExitsFemale
	playse SE_DOOR
	removeobject VAR_0x8009
	setflag FLAG_RECEIVED_SS_TICKET
	delay 30
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerFemale
	delay 20
	msgbox PlayersHouse_1F_Text_DadShouldStayLonger, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	special TurnOnTVScreen
	delay 60
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale
	msgbox PlayersHouse_1F_Text_IsThatABreakingStory, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale
	msgbox PlayersHouse_1F_Text_WhatColorDidTheySay, MSGBOX_DEFAULT
	multichoice 22, 8, MULTI_TV_LATI, TRUE
	copyvar VAR_0x8004, VAR_RESULT
	special InitRoamer
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	msgbox PlayersHouse_1F_Text_StillUnknownPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
	releaseall
	end

@ Never called.
PlayersHouse_1F_EventScript_AirLatiBroadcast::
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale::
	setvar VAR_0x8008, MALE
	setvar VAR_0x8009, LOCALID_DAD
	setvar VAR_0x800A, LOCALID_MOM
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale::
	setvar VAR_0x8008, FEMALE
	setvar VAR_0x8009, LOCALID_DAD
	setvar VAR_0x800A, LOCALID_MOM
	return

PlayersHouse_1F_EventScript_DadApproachPlayerMale::
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadApproachPlayerFemale::
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachDadMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadMale
	waitmovement 0
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachDadFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadFemale
	waitmovement 0
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadExitsMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadExitsFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_Movement_DadApproachPlayerMale:
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_DadApproachPlayerFemale:
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomMale:
	face_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomFemale:
	face_right
	step_end

PlayersHouse_1F_Movement_DadExitsMale:
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_DadExitsFemale:
	walk_down
	walk_left
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomMale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit:
	delay_8
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomFemale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	return
	end

PlayersHouse_2F_EventScript_GivePlayerPokenav::
	lockall
	msgbox PlayersHouse_2F_Text_GivePokeNav, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PlayersHouse_2F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	delay 10
	call PlayersHouse_2F_EventScript_SetupPokenav
	msgbox PlayersHouse_2F_Text_MomExplainPokenav, MSGBOX_DEFAULT
	closemessage
	releaseall
	return
	end

PlayersHouse_2F_EventScript_SetupPokenav::
	call_if_unset FLAG_SETUP_DONE, PlayersHouse_2F_EventScript_AskSetupPokenav
	call_if_set FLAG_SETUP_DONE, PlayersHouse_2F_EventScript_SetupPokenavFinish
	return
	end

PlayersHouse_2F_EventScript_AskSetupPokenav::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavWhich, MSGBOX_DEFAULT
	dynmultipush PlayersHouse_2F_Text_SetUpMonthSeason, 0
	dynmultipush PlayersHouse_2F_Text_SetUpDay, 1
	dynmultistack 19, 0, TRUE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, PlayersHouse_2F_EventScript_SetupPokenavMonth
	case 1, PlayersHouse_2F_EventScript_SetupPokenavDay
	case MULTI_B_PRESSED, PlayersHouse_2F_EventScript_CantLeave
	closemessage
	return
	end

PlayersHouse_2F_EventScript_SetupPokenavMonth::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavWhatMonth, MSGBOX_DEFAULT
	dynmultipush PlayersHouse_2F_Text_MonthDecember, 0
	dynmultipush PlayersHouse_2F_Text_MonthJanuary, 1
	dynmultipush PlayersHouse_2F_Text_MonthFebruary, 2
	dynmultipush PlayersHouse_2F_Text_MonthMarch, 3
	dynmultipush PlayersHouse_2F_Text_MonthApril, 4
	dynmultipush PlayersHouse_2F_Text_MonthMay, 5
	dynmultipush PlayersHouse_2F_Text_MonthJune, 6
	dynmultipush PlayersHouse_2F_Text_MonthJuly, 7
	dynmultipush PlayersHouse_2F_Text_MonthAugust, 8
	dynmultipush PlayersHouse_2F_Text_MonthSeptember, 9
	dynmultipush PlayersHouse_2F_Text_MonthOctober, 10
	dynmultipush PlayersHouse_2F_Text_MonthNovember, 11
	dynmultistack 19, 0, TRUE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, PlayersHouse_2F_EventScript_December
	case 1, PlayersHouse_2F_EventScript_January
	case 2, PlayersHouse_2F_EventScript_February
	case 3, PlayersHouse_2F_EventScript_March
	case 4, PlayersHouse_2F_EventScript_April
	case 5, PlayersHouse_2F_EventScript_May
	case 6, PlayersHouse_2F_EventScript_June
	case 7, PlayersHouse_2F_EventScript_July
	case 8, PlayersHouse_2F_EventScript_August
	case 9, PlayersHouse_2F_EventScript_September
	case 10, PlayersHouse_2F_EventScript_October
	case 11, PlayersHouse_2F_EventScript_November
	case MULTI_B_PRESSED, PlayersHouse_2F_EventScript_CantLeave
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetupPokenavDay::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavWhatDay, MSGBOX_DEFAULT
	dynmultipush PlayersHouse_2F_Text_ChoiceDay1, 0
	dynmultipush PlayersHouse_2F_Text_ChoiceDay2, 1
	dynmultipush PlayersHouse_2F_Text_ChoiceDay3, 2
	dynmultipush PlayersHouse_2F_Text_ChoiceDay4, 3
	dynmultipush PlayersHouse_2F_Text_ChoiceDay5, 4
	dynmultipush PlayersHouse_2F_Text_ChoiceDay6, 5
	dynmultipush PlayersHouse_2F_Text_ChoiceDay7, 6
	dynmultipush PlayersHouse_2F_Text_ChoiceDay8, 7
	dynmultipush PlayersHouse_2F_Text_ChoiceDay9, 8
	dynmultipush PlayersHouse_2F_Text_ChoiceDay10, 9
	dynmultipush PlayersHouse_2F_Text_ChoiceDay11, 10
	dynmultipush PlayersHouse_2F_Text_ChoiceDay12, 11
	dynmultipush PlayersHouse_2F_Text_ChoiceDay13, 12
	dynmultipush PlayersHouse_2F_Text_ChoiceDay14, 13
	dynmultipush PlayersHouse_2F_Text_ChoiceDay15, 14
	dynmultipush PlayersHouse_2F_Text_ChoiceDay16, 15
	dynmultipush PlayersHouse_2F_Text_ChoiceDay17, 16
	dynmultipush PlayersHouse_2F_Text_ChoiceDay18, 17
	dynmultipush PlayersHouse_2F_Text_ChoiceDay19, 18
	dynmultipush PlayersHouse_2F_Text_ChoiceDay20, 19
	dynmultipush PlayersHouse_2F_Text_ChoiceDay21, 20
	dynmultipush PlayersHouse_2F_Text_ChoiceDay22, 21
	dynmultipush PlayersHouse_2F_Text_ChoiceDay23, 22
	dynmultipush PlayersHouse_2F_Text_ChoiceDay24, 23
	dynmultipush PlayersHouse_2F_Text_ChoiceDay25, 24
	dynmultipush PlayersHouse_2F_Text_ChoiceDay26, 25
	dynmultipush PlayersHouse_2F_Text_ChoiceDay27, 26
	dynmultipush PlayersHouse_2F_Text_ChoiceDay28, 27
	dynmultistack 19, 0, TRUE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, PlayersHouse_2F_EventScript_SetDay1
	case 1, PlayersHouse_2F_EventScript_SetDay2
	case 2, PlayersHouse_2F_EventScript_SetDay3
	case 3, PlayersHouse_2F_EventScript_SetDay4
	case 4, PlayersHouse_2F_EventScript_SetDay5
	case 5, PlayersHouse_2F_EventScript_SetDay6
	case 6, PlayersHouse_2F_EventScript_SetDay7
	case 7, PlayersHouse_2F_EventScript_SetDay8
	case 8, PlayersHouse_2F_EventScript_SetDay9
	case 9, PlayersHouse_2F_EventScript_SetDay10
	case 10, PlayersHouse_2F_EventScript_SetDay11
	case 11, PlayersHouse_2F_EventScript_SetDay12
	case 12, PlayersHouse_2F_EventScript_SetDay13
	case 13, PlayersHouse_2F_EventScript_SetDay14
	case 14, PlayersHouse_2F_EventScript_SetDay15
	case 15, PlayersHouse_2F_EventScript_SetDay16
	case 16, PlayersHouse_2F_EventScript_SetDay17
	case 17, PlayersHouse_2F_EventScript_SetDay18
	case 18, PlayersHouse_2F_EventScript_SetDay19
	case 19, PlayersHouse_2F_EventScript_SetDay20
	case 20, PlayersHouse_2F_EventScript_SetDay21
	case 21, PlayersHouse_2F_EventScript_SetDay22
	case 22, PlayersHouse_2F_EventScript_SetDay23
	case 23, PlayersHouse_2F_EventScript_SetDay24
	case 24, PlayersHouse_2F_EventScript_SetDay25
	case 25, PlayersHouse_2F_EventScript_SetDay26
	case 26, PlayersHouse_2F_EventScript_SetDay27
	case 27, PlayersHouse_2F_EventScript_SetDay28
	case MULTI_B_PRESSED, PlayersHouse_2F_EventScript_CantLeave
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_CantLeave::
	lockall
	msgbox PlayersHouse_2F_Text_CantLeave, MSGBOX_DEFAULT
	closemessage
	call PlayersHouse_2F_EventScript_SetupPokenav
	return
	end

PlayersHouse_2F_EventScript_December::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthDecember, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthDecember
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_January::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthJanuary, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthJanuary
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_February::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthFebruary, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthFebruary
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_March::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthMarch, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthMarch
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_April::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthApril, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthApril
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_May::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthMay, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthMay
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_June::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthJune, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthJune
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_July::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthJuly, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthJuly
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_August::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthAugust, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthAugust
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_September::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthSeptember, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthSeptember
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_October::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthOctober, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthOctober
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_November::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavMonthNovember, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_SetMonthNovember
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavMonth
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetMonthDecember::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 3
	setmonth 12
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthJanuary::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 3
	setmonth 1
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthFebruary::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 3
	setmonth 2
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthMarch::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 0
	setmonth 3
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthApril::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 0
	setmonth 4
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthMay::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 0
	setmonth 5
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthJune::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 1
	setmonth 6
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthJuly::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 1
	setmonth 7
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthAugust::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 1
	setmonth 8
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthSeptember::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 2
	setmonth 9
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthOctober::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 2
	setmonth 10
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetMonthNovember::
	lockall
	msgbox PlayersHouse_2F_Text_MonthIsSet, MSGBOX_DEFAULT
	setflag FLAG_MONTH_SET
	@ setvar VAR_SEASON, 2
	setmonth 11
	closemessage
	call_if_set FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_DAY_SET, PlayersHouse_2F_EventScript_SetupPokenavDay
	return
	end

PlayersHouse_2F_EventScript_SetDay1::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet1
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay2::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet2
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay3::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet3
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay4::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay4, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet4
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay5::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay5, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet5
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay6::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay6, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet6
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay7::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay7, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet7
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay8::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay8, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet8
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay9::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay9, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet9
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay10::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay10, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet10
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay11::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay11, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet11
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay12::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay12, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet12
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay13::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay13, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet13
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay14::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay14, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet14
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay15::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay15, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet15
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay16::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay16, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet16
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay17::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay17, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet17
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay18::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay18, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet18
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay19::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay19, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet19
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay20::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay20, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet20
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay21::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay21, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet21
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay22::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay22, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet22
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay23::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay23, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet23
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay24::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay24, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet24
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay25::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay25, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet25
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay26::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay26, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet26
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay27::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay27, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet27
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_SetDay28::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavDay28, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, PlayersHouse_2F_EventScript_DaySet28
	call_if_eq VAR_RESULT, NO, PlayersHouse_2F_EventScript_SetupPokenavDay
	closemessage
	release
	return
	end

PlayersHouse_2F_EventScript_DaySet1::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 1
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet2::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 2
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet3::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 3
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet4::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 4
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet5::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 5
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet6::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 6
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet7::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 7
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet8::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 8
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet9::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 9
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet10::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 10
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet11::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 11
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet12::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 12
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet13::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 13
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet14::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 14
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet15::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 15
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet16::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 16
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet17::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 17
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet18::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 18
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet19::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 19
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet20::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 20
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet21::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 21
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet22::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 22
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet23::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 23
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet24::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 24
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet25::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 25
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet26::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 26
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet27::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 27
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_DaySet28::
	lockall
	msgbox PlayersHouse_2F_Text_DayIsSet, MSGBOX_DEFAULT
	setflag FLAG_DAY_SET
	setday 28
	closemessage
	call_if_set FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavFinish
	call_if_unset FLAG_MONTH_SET, PlayersHouse_2F_EventScript_SetupPokenavMonth
	return
	end

PlayersHouse_2F_EventScript_SetupPokenavFinish::
	lockall
	msgbox PlayersHouse_2F_Text_SetPokeNavFinished, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_2F_EventScript_MomGoesDownstairsMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_2F_EventScript_MomGoesDownstairsFemale
	end

PlayersHouse_2F_EventScript_MomGoesDownstairsMale::
	setvar VAR_0x8008, LOCALID_MOM_2F
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsMale
	waitmovement 0
	playse SE_EXIT
	removeobject VAR_0x8008
	end

PlayersHouse_2F_EventScript_MomGoesDownstairsFemale::
	setvar VAR_0x8008, LOCALID_MOM_2F
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsFemale
	waitmovement 0
	playse SE_EXIT
	removeobject VAR_0x8008
	end

PlayersHouse_2F_Text_SetPokeNavWhich:
	.string "MOM: What do you want to set first?\n"
	.string "The month or the day of the week?$"

PlayersHouse_2F_Text_SetPokeNavWhatMonth:
	.string "MOM: What month is it again?$"

PlayersHouse_2F_Text_SetPokeNavWhatDay:
	.string "MOM: What is today again?$"

PlayersHouse_2F_Text_SetPokeNavMonthDecember:
	.string "MOM: The month is December?$"

PlayersHouse_2F_Text_SetPokeNavMonthJanuary:
	.string "MOM: The month is January?$"

PlayersHouse_2F_Text_SetPokeNavMonthFebruary:
	.string "MOM: The month is February?$"

PlayersHouse_2F_Text_SetPokeNavMonthMarch:
	.string "MOM: The month is March?$"

PlayersHouse_2F_Text_SetPokeNavMonthApril:
	.string "MOM: The month is April?$"

PlayersHouse_2F_Text_SetPokeNavMonthMay:
	.string "MOM: The month is May?$"

PlayersHouse_2F_Text_SetPokeNavMonthJune:
	.string "MOM: The month is June?$"

PlayersHouse_2F_Text_SetPokeNavMonthJuly:
	.string "MOM: The month is July?$"

PlayersHouse_2F_Text_SetPokeNavMonthAugust:
	.string "MOM: The month is August?$"

PlayersHouse_2F_Text_SetPokeNavMonthSeptember:
	.string "MOM: The month is September?$"

PlayersHouse_2F_Text_SetPokeNavMonthOctober:
	.string "MOM: The month is October?$"

PlayersHouse_2F_Text_SetPokeNavMonthNovember:
	.string "MOM: The month is November?$"

PlayersHouse_2F_Text_MonthIsSet:
	.string "MOM: The month is now set!$"

PlayersHouse_2F_Text_SetPokeNavDay1:
	.string "MOM: Today is Sunday the 1st?$"

PlayersHouse_2F_Text_SetPokeNavDay2:
	.string "MOM: Today is Monday the 2nd?$"

PlayersHouse_2F_Text_SetPokeNavDay3:
	.string "MOM: Today is Tuesday the 3rd?$"

PlayersHouse_2F_Text_SetPokeNavDay4:
	.string "MOM: Today is Wednesday the 4th?$"

PlayersHouse_2F_Text_SetPokeNavDay5:
	.string "MOM: Today is Thursday the 5th?$"

PlayersHouse_2F_Text_SetPokeNavDay6:
	.string "MOM: Today is Friday the 6th?$"

PlayersHouse_2F_Text_SetPokeNavDay7:
	.string "MOM: Today is Saturday the 7th?$"

PlayersHouse_2F_Text_SetPokeNavDay8:
	.string "MOM: Today is Sunday the 8th?$"

PlayersHouse_2F_Text_SetPokeNavDay9:
	.string "MOM: Today is Monday the 9th?$"

PlayersHouse_2F_Text_SetPokeNavDay10:
	.string "MOM: Today is Tuesday the 10th?$"

PlayersHouse_2F_Text_SetPokeNavDay11:
	.string "MOM: Today is Wednesday the 11th?$"

PlayersHouse_2F_Text_SetPokeNavDay12:
	.string "MOM: Today is Thursday the 12th?$"

PlayersHouse_2F_Text_SetPokeNavDay13:
	.string "MOM: Today is Friday the 13th?$"

PlayersHouse_2F_Text_SetPokeNavDay14:
	.string "MOM: Today is Saturday the 14th?$"

PlayersHouse_2F_Text_SetPokeNavDay15:
	.string "MOM: Today is Sunday the 15th?$"

PlayersHouse_2F_Text_SetPokeNavDay16:
	.string "MOM: Today is Monday the 16th?$"

PlayersHouse_2F_Text_SetPokeNavDay17:
	.string "MOM: Today is Tuesday the 17th?$"

PlayersHouse_2F_Text_SetPokeNavDay18:
	.string "MOM: Today is Wednesday the 18th?$"

PlayersHouse_2F_Text_SetPokeNavDay19:
	.string "MOM: Today is Thursday the 19th?$"

PlayersHouse_2F_Text_SetPokeNavDay20:
	.string "MOM: Today is Friday the 20th?$"

PlayersHouse_2F_Text_SetPokeNavDay21:
	.string "MOM: Today is Saturday the 21st?$"

PlayersHouse_2F_Text_SetPokeNavDay22:
	.string "MOM: Today is Sunday the 22nd?$"

PlayersHouse_2F_Text_SetPokeNavDay23:
	.string "MOM: Today is Monday the 23rd?$"

PlayersHouse_2F_Text_SetPokeNavDay24:
	.string "MOM: Today is Tuesday the 24th?$"

PlayersHouse_2F_Text_SetPokeNavDay25:
	.string "MOM: Today is Wednesday the 25th?$"

PlayersHouse_2F_Text_SetPokeNavDay26:
	.string "MOM: Today is Thursday the 26th?$"

PlayersHouse_2F_Text_SetPokeNavDay27:
	.string "MOM: Today is Friday the 27th?$"

PlayersHouse_2F_Text_SetPokeNavDay28:
	.string "MOM: Today is Saturday the 28th?$"

PlayersHouse_2F_Text_DayIsSet:
	.string "MOM: The day is now set!$"

PlayersHouse_2F_Text_SetPokeNavFinished:
	.string "MOM: Your PokéNav is now set!$"

PlayersHouse_2F_Text_CantLeave:
	.string "MOM: Where are you going?\n"
	.string "We still need to set this up$"

PlayersHouse_2F_Text_MonthDecember:
	.string "December, Winter$"

PlayersHouse_2F_Text_MonthJanuary:
	.string "January, Winter$"

PlayersHouse_2F_Text_MonthFebruary:
	.string "February, Winter$"

PlayersHouse_2F_Text_MonthMarch:
	.string "March, Spring$"

PlayersHouse_2F_Text_MonthApril:
	.string "April, Spring$"

PlayersHouse_2F_Text_MonthMay:
	.string "May, Spring$"

PlayersHouse_2F_Text_MonthJune:
	.string "June, Summer$"

PlayersHouse_2F_Text_MonthJuly:
	.string "July, Summer$"

PlayersHouse_2F_Text_MonthAugust:
	.string "August, Summer$"

PlayersHouse_2F_Text_MonthSeptember:
	.string "September, Autumn$"

PlayersHouse_2F_Text_MonthOctober:
	.string "October, Autumn$"

PlayersHouse_2F_Text_MonthNovember:
	.string "November, Autumn$"

PlayersHouse_2F_Text_ChoiceDay1:
	.string "Sunday the 1st$"

PlayersHouse_2F_Text_ChoiceDay2:
	.string "Monday the 2nd$"

PlayersHouse_2F_Text_ChoiceDay3:
	.string "Tuesday the 3rd$"

PlayersHouse_2F_Text_ChoiceDay4:
	.string "Wednesday the 4th$"

PlayersHouse_2F_Text_ChoiceDay5:
	.string "Thursday the 5th$"

PlayersHouse_2F_Text_ChoiceDay6:
	.string "Friday the 6th$"

PlayersHouse_2F_Text_ChoiceDay7:
	.string "Saturday the 7th$"

PlayersHouse_2F_Text_ChoiceDay8:
	.string "Sunday the 8th$"

PlayersHouse_2F_Text_ChoiceDay9:
	.string "Monday the 9th$"

PlayersHouse_2F_Text_ChoiceDay10:
	.string "Tuesday the 10th$"

PlayersHouse_2F_Text_ChoiceDay11:
	.string "Wednesday the 11th$"

PlayersHouse_2F_Text_ChoiceDay12:
	.string "Thursday the 12th$"

PlayersHouse_2F_Text_ChoiceDay13:
	.string "Friday the 13th$"

PlayersHouse_2F_Text_ChoiceDay14:
	.string "Saturday the 14th$"

PlayersHouse_2F_Text_ChoiceDay15:
	.string "Sunday the 15th$"

PlayersHouse_2F_Text_ChoiceDay16:
	.string "Monday the 16th$"

PlayersHouse_2F_Text_ChoiceDay17:
	.string "Tuesday the 17th$"

PlayersHouse_2F_Text_ChoiceDay18:
	.string "Wednesday the 18th$"

PlayersHouse_2F_Text_ChoiceDay19:
	.string "Thursday the 19th$"

PlayersHouse_2F_Text_ChoiceDay20:
	.string "Friday the 20th$"

PlayersHouse_2F_Text_ChoiceDay21:
	.string "Saturday the 21st$"

PlayersHouse_2F_Text_ChoiceDay22:
	.string "Sunday the 22nd$"

PlayersHouse_2F_Text_ChoiceDay23:
	.string "Monday the 23rd$"

PlayersHouse_2F_Text_ChoiceDay24:
	.string "Tuesday the 24th$"

PlayersHouse_2F_Text_ChoiceDay25:
	.string "Wednesday the 25th$"

PlayersHouse_2F_Text_ChoiceDay26:
	.string "Thursday the 26th$"

PlayersHouse_2F_Text_ChoiceDay27:
	.string "Friday the 27th$"

PlayersHouse_2F_Text_ChoiceDay28:
	.string "Saturday the 28th$"

PlayersHouse_2F_Text_SetUpMonthSeason:
	.string "Month & Season$"

PlayersHouse_2F_Text_SetUpDay:
	.string "Day of the Week$"
