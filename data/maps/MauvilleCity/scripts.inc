MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	call_if_unset FLAG_HELPED_NIGHT_MAN, MauvilleCity_EventScript_NightManSetup
	call_if_unset FLAG_HELPED_YOUNG_MAN, MauvilleCity_EventScript_YoungManSetup
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "UNCLE: It's because of POKéMON that\n"
	.string "this boy's got more pep, I suppose…\l"
	.string "But he's become a bit too peppy…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY: Aww, UNCLE, please?\p"
	.string "I want to challenge this GYM and see\n"
	.string "how much better I've become.\p"
	.string "Please? May I, please?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "UNCLE: Now hold on, WALLY.\p"
	.string "Since you started living with POKéMON,\n"
	.string "you have grown quite a lot stronger.\p"
	.string "But don't you think you're pushing it\n"
	.string "to suddenly challenge a GYM?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY: I'm not pushing it.\p"
	.string "If I combine forces with RALTS,\n"
	.string "we can beat anyone!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY: Oh! Hi, {PLAYER}!\p"
	.string "I've gotten a lot stronger since\n"
	.string "we met.\p"
	.string "{PLAYER}, I want you and my UNCLE to\n"
	.string "understand that.\p"
	.string "{PLAYER}, please, will you have\n"
	.string "a battle with me?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY: Oh… If you won't battle me,\n"
	.string "{PLAYER}, my UNCLE won't know that I've\l"
	.string "become really strong.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "UNCLE: {PLAYER}{KUN}, was it?\n"
	.string "On WALLY's behalf, can I ask you to\l"
	.string "battle with him just this once?\p"
	.string "I don't think he's going to listen to\n"
	.string "any reason the way he is now.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY: {PLAYER}, please!\n"
	.string "Battle with me, please.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY: {PLAYER}, thank you.\p"
	.string "Okay… Here I come!$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "I lost…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY: UNCLE…\n"
	.string "I'll go back to VERDANTURF…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, thank you.\n"
	.string "Being a TRAINER is tough, isn't it?\p"
	.string "It's not enough just to have POKéMON\n"
	.string "and make them battle. That isn't what\l"
	.string "being a real TRAINER is about.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "UNCLE: WALLY, there's no need to be so\n"
	.string "down on yourself.\p"
	.string "Why, what's keeping you from becoming\n"
	.string "stronger and stronger?\p"
	.string "Come on, let's go home.\n"
	.string "Everyone's waiting for you.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "UNCLE: {PLAYER}{KUN}, it just dawned on me\n"
	.string "that you must be the TRAINER who kept\l"
	.string "an eye out for WALLY when he caught\l"
	.string "his POKéMON.\p"
	.string "Why don't you visit us in VERDANTURF\n"
	.string "sometime?\l"
	.string "I'm sure WALLY would enjoy it.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "WALLY: Oh, hello, {PLAYER}!\p"
	.string "I just wanted to tell you that\n"
	.string "my uncle bought me a POKéNAV!\p"
	.string "Now I can get in touch with you\n"
	.string "anytime, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MauvilleCity_Text_RegisteredWally:
	.string "Registered WALLY\n"
	.string "in the POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Hehe…\n"
	.string "I was watching that match!\p"
	.string "You're friends with that boy WALLY,\n"
	.string "aren't you?\p"
	.string "But you didn't hold anything back\n"
	.string "and beat him impressively.\p"
	.string "Yeah! That's what a real POKéMON\n"
	.string "battle is all about!\p"
	.string "I idolize TRAINERS like that!\p"
	.string "… … … … … …\n"
	.string "I'll be cheering for you!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: Oh, {PLAYER}{KUN}!\n"
	.string "You look like you have a lot of zip!\l"
	.string "That's a good thing, wahahahaha!\p"
	.string "Fine! I've decided!\n"
	.string "I need a favor, {PLAYER}{KUN}!\p"
	.string "MAUVILLE CITY has an underground\n"
	.string "sector called NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
	.string "switch off the GENERATOR.\p"
	.string "The GENERATOR has been running a bit\n"
	.string "haywire. It's getting unsafe.\p"
	.string "Here, this is the KEY to get into\n"
	.string "NEW MAUVILLE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Don't you worry about it.\n"
	.string "It won't be a challenge to you.\p"
	.string "The entrance to NEW MAUVILLE is just\n"
	.string "a short SURF away from ROUTE 110.\p"
	.string "That's it, then, you have my trust!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "I knew it, {PLAYER}{KUN}! I knew I'd made\n"
	.string "the right choice asking you!\p"
	.string "This is my thanks--a TM containing\n"
	.string "THUNDERBOLT!\p"
	.string "Go on, you've earned it!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "It pleases me to no end to see\n"
	.string "the young step up and take charge!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "You know, it's cool to have POKéMON\n"
	.string "battles and stuff…\p"
	.string "But if your POKéMON gets hurt,\n"
	.string "you have to nurse it back to health.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "The roads of this town stretch north\n"
	.string "and south, and east and west.\p"
	.string "Because of that, we get all sorts of\n"
	.string "people coming through.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Have you been to RYDEL'S CYCLES yet?\p"
	.string "RYDEL, the owner, is a very generous\n"
	.string "man.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Even if you're riding a BIKE,\n"
	.string "wild POKéMON could jump you.$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE CITY\n"
	.string "“The bright and shiny city of fun!”$"

MauvilleCity_Text_GymSign:
	.string "MAUVILLE CITY POKéMON GYM\n"
	.string "LEADER: WATTSON\l"
	.string "“The cheerfully electrifying man!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Ride in gravel and shake up your\n"
	.string "soul!”\l"
	.string "RYDEL'S CYCLES$"

MauvilleCity_Text_GameCornerSign:
	.string "“The play spot for all!”\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_ExplainTV:
	.string "Hi, do you check out TV at all?\p"
	.string "They've added a bunch of cool new\n"
	.string "shows recently.\p"
	.string "TV is so cool. I've seen my friends on\n"
	.string "TV just out of the blue.\p"
	.string "And, sometimes, they even put you on TV\n"
	.string "without telling you.\p"
	.string "I wish I would be on TV sometime.\p"
	.string "That's why I think you should check\n"
	.string "out TVs whenever you can.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Hi, have you been checking out TVs?$"

MauvilleCity_Movement_NightMan_EnterGamecorner:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MauvilleCity_Movement_NightMan_EnterGamecorner_Player:
	walk_up
	walk_right
	face_left
	step_end

MauvilleCity_Movement_NightMan_ExitsGamecorner:
	walk_down
	walk_down
	face_player
	step_end

MauvilleCity_Movement_NightMan_ReenterGamecorner:
	walk_up
	walk_up
	step_end

MauvilleCity_EventScript_NightManSetup::
	gettimeofday
	call_if_eq VAR_0x8000, 3, MauvilleCity_EventScript_NightManAppears
	call_if_ne VAR_0x8000, 3, MauvilleCity_EventScript_NightManDisappears
	return

MauvilleCity_EventScript_NightManAppears::
	setobjectxy LOCALID_MAUVILLE_NIGHT_MAN, 8, 17
	clearflag FLAG_HIDE_MAUVILLE_NIGHT_MAN
	return

MauvilleCity_EventScript_NightManDisappears::
	removeobject LOCALID_MAUVILLE_NIGHT_MAN
	setflag FLAG_HIDE_MAUVILLE_NIGHT_MAN
	return

MauvilleCity_EventScript_NightMan::
	lock
	faceplayer
	msgbox MauvilleCity_Text_NightMan_LowOnMoney, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MauvilleCity_EventScript_NightMan_Declined
	case YES, MauvilleCity_EventScript_NightMan_Accepted
	case MULTI_B_PRESSED, MauvilleCity_EventScript_NightMan_Declined
	release
	end

MauvilleCity_EventScript_NightMan_Declined::
	lock
	faceplayer
	msgbox MauvilleCity_Text_NightMan_ItsAlright, MSGBOX_DEFAULT
	closemessage
	release
	end

MauvilleCity_EventScript_NightMan_Accepted::
	lock
	faceplayer
	msgbox MauvilleCity_Text_NightMan_YouSure, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MauvilleCity_EventScript_NightMan_Declined
	case YES, MauvilleCity_EventScript_NightMan_GiveMoney
	case MULTI_B_PRESSED, MauvilleCity_EventScript_NightMan_Declined
	closemessage
	release
	end

MauvilleCity_EventScript_NightMan_GiveMoney::
	lock
	faceplayer
	showmoneybox 0, 0
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_EventScript_NightMan_NotEnoughMoney
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_EventScript_NightMan_NoCoinCase
	msgbox MauvilleCity_Text_NightMan_ThankYou, MSGBOX_DEFAULT
	closemessage
	removemoney 5000
	updatemoneybox
	msgbox MauvilleCity_Text_NightMan_StayHere, MSGBOX_DEFAULT
	waitmessage
	closemessage
	hidemoneybox
	hidefollower
	applymovement VAR_LAST_TALKED, MauvilleCity_Movement_NightMan_EnterGamecorner
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_NightMan_EnterGamecorner_Player
	waitmovement
	playse SE_DOOR
	fadescreenswapbuffers FADE_TO_BLACK
	hideobjectat VAR_LAST_TALKED, MAP_MAUVILLE_CITY
	delay 5
	playse SE_DOOR
	fadescreenswapbuffers FADE_FROM_BLACK
	addhours 3
	msgbox MauvilleCity_Text_NightMan_HoursLater, MSGBOX_DEFAULT
	closemessage
	delay 5
	showobjectat VAR_LAST_TALKED, MAP_MAUVILLE_CITY
	applymovement VAR_LAST_TALKED, MauvilleCity_Movement_NightMan_ExitsGamecorner
	showmoneybox 0, 0
	showcoinsbox 1, 5
	msgbox MauvilleCity_Text_NightMan_ImBack, MSGBOX_DEFAULT
	waitmessage
	closemessage
	addmoney 15000
	addcoins 1000
	updatemoneybox
	updatecoinsbox 1, 5
	givemon SPECIES_GIMMIGHOUL_ROAMING, 20, ITEM_AMULET_COIN, ITEM_LUXURY_BALL, NATURE_ADAMANT, 0, MON_GENDERLESS, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HEX, MOVE_PAY_DAY, MOVE_TERA_BLAST, MOVE_CELEBRATE, FALSE, FALSE, TYPE_STEEL
	msgbox MauvilleCity_Text_NightMan_GoodLuck, MSGBOX_DEFAULT
	waitmessage
	hidecoinsbox 1, 5
	hidemoneybox
	closemessage
	applymovement VAR_LAST_TALKED, MauvilleCity_Movement_NightMan_ReenterGamecorner
	waitmovement
	removeobject VAR_LAST_TALKED, MAP_MAUVILLE_CITY
	setflag FLAG_HIDE_MAUVILLE_NIGHT_MAN
	setflag FLAG_HELPED_NIGHT_MAN
	release
	end

MauvilleCity_EventScript_NightMan_GoodLuck::
	lock
	faceplayer
	msgbox MauvilleCity_Text_NightMan_GoodLuck, MSGBOX_DEFAULT
	closemessage
	release
	end

MauvilleCity_EventScript_NightMan_NotEnoughMoney::
	lock
	faceplayer
	msgbox MauvilleCity_Text_NightMan_Sorry, MSGBOX_DEFAULT
	closemessage
	release
	end

MauvilleCity_EventScript_NightMan_NoCoinCase::
	lock
	faceplayer
	msgbox MauvilleCity_Text_NightMan_NoCoinCase, MSGBOX_DEFAULT
	closemessage
	release
	end

MauvilleCity_Text_NightMan_LowOnMoney:
	.string "Sigh, this day has been terrible for me.\n"
	.string "Say, you wouldn't mind lending me some\p"
	.string "money? Say ¥5000?\n"
	.string "I'll pay you back as soon as possible.$"

MauvilleCity_Text_NightMan_ItsAlright:
	.string "Sigh, I guess I'll call it a night.$"

MauvilleCity_Text_NightMan_ThankYou:
	.string "Really!?\n"
	.string "I can't thank you enough young man!$"

MauvilleCity_Text_NightMan_StayHere:
	.string "Young man, I feel as if my luck has\n"
	.string "improved. Stay here for a minute and I'm\p"
	.string "going to win enough to pay you back!$"

MauvilleCity_Text_NightMan_ImBack:
	.string "Young man, thanks to your donation, my\n"
	.string "luck has definitely improved! As\p"
	.string "promised, here's your payment and a\n"
	.string "Pokémon that I found in my Coin Case.$"

MauvilleCity_Text_NightMan_GoodLuck:
	.string "Young man, I hope that you have good\n"
	.string "luck as you continue on your journey.$"

MauvilleCity_Text_NightMan_YouSure:
	.string "Thank you. But are you sure?$"

MauvilleCity_Text_NightMan_Sorry:
	.string "Sorry, but you don't have enough money…$"

MauvilleCity_Text_NightMan_NoCoinCase:
	.string "Sorry, but you don't have a Coin Case…$"

MauvilleCity_Text_NightMan_HoursLater:
	.string "3 Hours Later…$"

MauvilleCity_Movement_YoungMan_Nervous::
	walk_in_place_fast_up
	delay_16
	walk_in_place_fast_left
	delay_16
	walk_in_place_fast_down
	delay_16
	walk_in_place_fast_right
	delay_16
	face_player
	step_end

MauvilleCity_EventScript_YoungManSetup::
	call_if_set FLAG_HELPED_YOUNG_MAN, MauvilleCity_EventScript_YoungManDisappears
	checkflag FLAG_BADGE06_GET
	call_if TRUE, MauvilleCity_EventScript_YoungManAppears
	call_if FALSE, MauvilleCity_EventScript_YoungManDisappears
	return
	end

MauvilleCity_EventScript_YoungManAppears::
	clearflag FLAG_HIDE_MAUVILLE_YOUNG_MAN
	addobject LOCALID_MAUVILLE_YOUNG_MAN
	return
	end

MauvilleCity_EventScript_YoungManDisappears::
	removeobject LOCALID_MAUVILLE_YOUNG_MAN
	setflag FLAG_HIDE_MAUVILLE_YOUNG_MAN
	return
	end

MauvilleCity_EventScript_YoungMan::
	lock
	faceplayer
	goto_if_eq VAR_HIDDEN_LAB_STATE, 1, MauvilleCity_EventScript_YoungMan_HelpingMe
	msgbox MauvilleCity_Text_YoungMan_MissingId, MSGBOX_DEFAULT
	waitmessage
	applymovement VAR_LAST_TALKED, MauvilleCity_Movement_YoungMan_Nervous
	waitmovement
	msgbox MauvilleCity_Text_YoungMan_TooYoung, MSGBOX_DEFAULT
	waitmessage
	hidefollower
	setflag FLAG_NO_WHITEOUT
	trainerbattle_single TRAINER_MAUVILLE_YOUNG_MAN, MauvilleCity_Text_YoungMan_BattleIntro, MauvilleCity_Text_YoungMan_BattleStuned, MauvilleCity_EventScript_YoungMan_PostBattle
	release
	end

MauvilleCity_EventScript_YoungMan_PostBattle::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MauvilleCity_EventScript_YoungMan_PostBattle_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, MauvilleCity_EventScript_YoungMan_PostBattle_Lost
	end

MauvilleCity_EventScript_YoungMan_PostBattle_Won::
	lock
	faceplayer
	hidefollower
	setvar VAR_HIDDEN_LAB_STATE, 1
	clearflag FLAG_NO_WHITEOUT
	msgbox MauvilleCity_Text_YoungMan_BattleLost, MSGBOX_DEFAULT
	waitmessage
	msgbox MauvilleCity_Text_YoungMan_HealTeam, MSGBOX_DEFAULT
	special HealPlayerParty
	closemessage
	goto MauvilleCity_EventScript_YoungMan_HelpingMe
	release
	end

MauvilleCity_EventScript_YoungMan_PostBattle_Lost::
	lock
	faceplayer
	hidefollower
	setvar VAR_HIDDEN_LAB_STATE, 1
	clearflag FLAG_NO_WHITEOUT
	msgbox MauvilleCity_Text_YoungMan_BattleWon, MSGBOX_DEFAULT
	waitmessage
	msgbox MauvilleCity_Text_YoungMan_HealTeam, MSGBOX_DEFAULT
	special HealPlayerParty
	closemessage
	goto MauvilleCity_EventScript_YoungMan_HelpingMe
	release
	end

MauvilleCity_EventScript_YoungMan_HelpingMe::
	lock
	faceplayer
	msgbox MauvilleCity_Text_YoungMan_HelpingMe, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MauvilleCity_EventScript_YoungMan_Declined
	case YES, MauvilleCity_EventScript_YoungMan_Accepted
	case MULTI_B_PRESSED, MauvilleCity_EventScript_YoungMan_Declined
	release
	end

MauvilleCity_EventScript_YoungMan_Accepted::
	lock
	faceplayer
	msgbox MauvilleCity_Text_YoungMan_ThankYou, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setfollowernpc 13, FNPC_LEAVE_ROUTE, FollowingNPCs_EventScript_Follower, PARTNER_YOUNG_MAN
	release
	end

MauvilleCity_EventScript_YoungMan_Declined::
	lock
	faceplayer
	msgbox MauvilleCity_Text_YoungMan_Declined, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

MauvilleCity_Text_YoungMan_MissingId:
	.string "Hi, have you seen a Trainer ID?\n"
	.string "I think that I might have dropped it.\p"
	.string "I can't get into the Game Corner if I\n"
	.string "don't have it with me for the ID Check.$"

MauvilleCity_Text_YoungMan_TooYoung:
	.string "You think that I look too young to\n"
	.string "enter the Game Corner?\p"
	.string "… … …\p"
	.string "I guess that without my ID, I'll have to\n"
	.string "prove it the old-fashioned way!$"

MauvilleCity_Text_YoungMan_BattleIntro:
	.string "I won't be holding anything back!$"

MauvilleCity_Text_YoungMan_BattleStuned:
	.string "… … …$"

MauvilleCity_Text_YoungMan_BattleLost:
	.string "You're good!\n"
	.string "But now you see that I'm not young!$"

MauvilleCity_Text_YoungMan_BattleWon:
	.string "You're pretty good yourself!\n"
	.string "But I was just better!$"

MauvilleCity_Text_YoungMan_HealTeam:
	.string "But let me heal your Pokémon for you.$"

MauvilleCity_Text_YoungMan_HelpingMe:
	.string "Now, would you be willing to help me?\n"
	.string "I'll make it worth your time.$"

MauvilleCity_Text_YoungMan_ThankYou:
	.string "Thank you! As it seems to not be here in\n"
	.string "MAUVILLE CITY. We need to go over to\p"
	.string "RUSTURF TUNNEL, where I bought it from.\p"
	.string "… … …\p"
	.string "Sorry, misspoke there, but I had walked\n"
	.string "through the tunnel to get here.$"

MauvilleCity_Text_YoungMan_Declined:
	.string "Oh, hopefully you'll change your mind.$"
