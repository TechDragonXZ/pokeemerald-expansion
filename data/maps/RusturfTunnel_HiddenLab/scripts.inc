RusturfTunnel_HiddenLab_MapScripts::
	.byte 0

RusturfTunnel_HiddenLab_Trigger_Alert::
    setflag FLAG_CODE_MODE
    removeobject LOCALID_RANGER_LEADER
	call_if_eq VAR_HIDDEN_LAB_STATE, 2, RusturfTunnel_HiddenLab_EventScript_ScientistAlert
	end

RusturfTunnel_HiddenLab_Movement_Alert::
    emote_question_mark
    delay_16
    delay_16
    face_player
    delay_16
    delay_16
    emote_exclamation_mark
    delay_16
    delay_16
    jump_in_place_down
    delay_16
    delay_16
    step_end

RusturfTunnel_HiddenLab_Movement_Run::
    walk_fast_down
    walk_faster_down
    walk_fast_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_down
    walk_faster_down
    walk_faster_down
    walk_faster_down
    walk_faster_down
    walk_fast_down
    walk_fast_left
    walk_left
    face_up
    step_end

RusturfTunnel_HiddenLab_Movement_Enter::
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

RusturfTunnel_HiddenLab_EventScript_ScientistAlert::
	lockall
    hidefollowernpc
    applymovement LOCALID_PLAYER, RusturfTunnel_HiddenLab_Movement_Enter
    waitmovement
    delay 2
    applymovement LOCALID_MAIN_SCIENTIST, RusturfTunnel_HiddenLab_Movement_Alert
    waitmovement
    msgbox RusturfTunnel_HiddenLab_Text_HowDid, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement LOCALID_MAIN_SCIENTIST, RusturfTunnel_HiddenLab_Movement_Run
    waitmovement
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
    special ShakeCamera
    playse SE_BANG
    setmetatile 20, 9, METATILE_Lab_DoorFrame_Locked, TRUE
    setmetatile 21, 9, METATILE_Lab_DoorFrame_Locked, TRUE
    setmetatile 20, 10, METATILE_Lab_Door_Locked, TRUE
    setmetatile 21, 10, METATILE_Lab_Door_Locked, TRUE
    msgbox RusturfTunnel_HiddenLab_Text_Sound, MSGBOX_DEFAULT
    setobjectxyperm LOCALID_MAIN_SCIENTIST, 18, 13
	special DrawWholeMapView
    waitmessage
    closemessage
    setvar VAR_HIDDEN_LAB_STATE, 3
    releaseall
    end

RusturfTunnel_HiddenLab_Text_HowDid::
    .string "How did you get in here?!\p"
    .string "… … …\p"
    .string "That no good guard I should've hired\n"
    .string "a better one!\p"
    .string "Everyone emergency procedures!$"

RusturfTunnel_HiddenLab_Text_Sound::
    .string "It sounds like a door was closed.$"

RusturfTunnel_HiddenLab_Movement_PlayerLackiesApproach::
    walk_right
    face_right
    step_end

RusturfTunnel_HiddenLab_Movement_TopApproach::
    walk_down
    walk_right
    walk_right
    face_right
    step_end

RusturfTunnel_HiddenLab_Movement_BottomApproach::
    walk_up
    walk_right
    walk_right
    face_right
    step_end

RusturfTunnel_HiddenLab_Movement_Lacky1Approach::
    walk_down
    face_left
    step_end

RusturfTunnel_HiddenLab_Movement_Lacky1StepBack::
    walk_up
    face_down
    step_end

RusturfTunnel_HiddenLab_Movement_Lacky2Approach::
    walk_up
    walk_up
    face_left
    step_end

RusturfTunnel_HiddenLab_Movement_Lacky2StepBack::
    walk_down
    walk_down
    face_up
    step_end

RusturfTunnel_HiddenLab_Movement_LackyTalk::
    jump_in_place_left
    face_left
    step_end

RusturfTunnel_HiddenLab_Trigger_LackiesTop::
    goto_if_eq VAR_HIDDEN_LAB_STATE, 3, RusturfTunnel_HiddenLab_EventScript_Lackies_TopApproach
    end

RusturfTunnel_HiddenLab_EventScript_Lackies_TopApproach::
    lock
    applymovement LOCALID_PLAYER, RusturfTunnel_HiddenLab_Movement_PlayerLackiesApproach
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_TopApproach
    waitmovement
    goto RusturfTunnel_HiddenLab_EventScript_LackiesBattle
    release
    end

RusturfTunnel_HiddenLab_Trigger_LackiesBottom::
    goto_if_eq VAR_HIDDEN_LAB_STATE, 3, RusturfTunnel_HiddenLab_EventScript_Lackies_BottomApproach
    end

RusturfTunnel_HiddenLab_EventScript_Lackies_BottomApproach::
    lock
    applymovement LOCALID_PLAYER, RusturfTunnel_HiddenLab_Movement_PlayerLackiesApproach
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_BottomApproach
    waitmovement
    goto RusturfTunnel_HiddenLab_EventScript_LackiesBattle
    release
    end

RusturfTunnel_HiddenLab_EventScript_LackiesBattle::
    lock
    applymovement LOCALID_LACKY_1, RusturfTunnel_HiddenLab_Movement_Lacky1Approach
    applymovement LOCALID_LACKY_2, RusturfTunnel_HiddenLab_Movement_Lacky2Approach
    waitmovement
    delay 2
    applymovement LOCALID_LACKY_1, RusturfTunnel_HiddenLab_Movement_LackyTalk
    waitmovement
    msgbox RusturfTunnel_HiddenLab_Text_Lacky1Intro, MSGBOX_DEFAULT
    waitmessage
    closemessage
    delay 2
    applymovement LOCALID_LACKY_2, RusturfTunnel_HiddenLab_Movement_LackyTalk
    waitmovement
    msgbox RusturfTunnel_HiddenLab_Text_Lacky2Intro, MSGBOX_DEFAULT
    waitmessage
    closemessage
    trainerbattle_two_trainers TRAINER_HIDDEN_LAB_LACKY_1, RusturfTunnel_HiddenLab_Text_Lacky1Lost, TRAINER_HIDDEN_LAB_LACKY_2, RusturfTunnel_HiddenLab_Text_Lacky2Lost
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RusturfTunnel_HiddenLab_EventScript_LackiesLost
    release
    end

RusturfTunnel_HiddenLab_EventScript_Lacky1::
	lock
	faceplayer
    msgbox RusturfTunnel_HiddenLab_Text_Lacky1Lost, MSGBOX_DEFAULT
    waitmessage
    closemessage
    release
    end
    end

RusturfTunnel_HiddenLab_Text_Lacky1Intro::
    .string "Are you the intruder?\n"
    .string "No matter that door needs a code.$"

RusturfTunnel_HiddenLab_Text_Lacky1Lost::
    .string "I…I… I failed?\p"
    .string "I probably shouldn't be saying this\n"
    .string "but… the code contains a 5 and a 7.$"

RusturfTunnel_HiddenLab_EventScript_Lacky2::
	lock
	faceplayer
    msgbox RusturfTunnel_HiddenLab_Text_Lacky2Lost, MSGBOX_DEFAULT
    waitmessage
    closemessage
    release
    end

RusturfTunnel_HiddenLab_Text_Lacky2Intro::
    .string "You aren't taking this job away from me!\n"
    .string "It's the only place I like working at!$"

RusturfTunnel_HiddenLab_Text_Lacky2Lost::
    .string "It's not like I liked this job anyways!\p"
    .string "If it's the end, no point in holding on\n"
    .string "to this, the code contains a 9 and a 2.$"

RusturfTunnel_HiddenLab_EventScript_LackiesLost::
    lock
    applymovement LOCALID_LACKY_1, RusturfTunnel_HiddenLab_Movement_Lacky1StepBack
    applymovement LOCALID_LACKY_2, RusturfTunnel_HiddenLab_Movement_Lacky2StepBack
    waitmovement
    delay 2
    setvar VAR_HIDDEN_LAB_STATE, 4
    release
    end    

RusturfTunnel_HiddenLab_Trigger_ConfrontLeft::
    goto_if_eq VAR_HIDDEN_LAB_STATE, 5, RusturfTunnel_HiddenLab_EventScript_EnterRoomLeft
    end

RusturfTunnel_HiddenLab_Trigger_ConfrontRight::
    goto_if_eq VAR_HIDDEN_LAB_STATE, 5, RusturfTunnel_HiddenLab_EventScript_EnterRoomRight
    end

RusturfTunnel_HiddenLab_Movement_PlayerEnterRoomLeft::
    walk_down
    walk_down
    walk_left
    face_left
    step_end

RusturfTunnel_HiddenLab_Movement_EnterRoomLeft::
    walk_down
    walk_down
    walk_down
    face_left
    step_end

RusturfTunnel_HiddenLab_EventScript_EnterRoomLeft::
    lock
    applymovement LOCALID_PLAYER, RusturfTunnel_HiddenLab_Movement_PlayerEnterRoomLeft
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_EnterRoomLeft
    waitmovement
    goto RusturfTunnel_HiddenLab_EventScript_Scientist
    release
    end

RusturfTunnel_HiddenLab_Movement_PlayerEnterRoomRight::
    walk_down
    walk_down
    walk_left
    walk_left
    face_left
    step_end

RusturfTunnel_HiddenLab_Movement_EnterRoomRight::
    walk_down
    walk_down
    walk_down
    walk_left
    face_left
    step_end

RusturfTunnel_HiddenLab_EventScript_EnterRoomRight::
    lock
    applymovement LOCALID_PLAYER, RusturfTunnel_HiddenLab_Movement_PlayerEnterRoomRight
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_EnterRoomRight
    waitmovement
    goto RusturfTunnel_HiddenLab_EventScript_Scientist
    release
    end

RusturfTunnel_HiddenLab_Movement_OnGuard::
    face_player
    delay_16
    emote_exclamation_mark
    jump_in_place_up
    delay_8
    face_up
    walk_in_place_fast_up
    delay_16
    face_player
    step_end

RusturfTunnel_HiddenLab_EventScript_Scientist::
    removeobject LOCALID_LACKY_1
    removeobject LOCALID_LACKY_2
    applymovement LOCALID_MAIN_SCIENTIST, RusturfTunnel_HiddenLab_Movement_OnGuard
    msgbox RusturfTunnel_HiddenLab_Text_HowDidDoor, MSGBOX_DEFAULT
    waitmessage
    closemessage
    setweather WEATHER_DROUGHT
    doweather
    trainerbattle_double TRAINER_HIDDEN_LAB_BOSS, RusturfTunnel_HiddenLab_Text_BossBattleIntro, RusturfTunnel_HiddenLab_Text_BossBattleLost, RusturfTunnel_HiddenLab_Text_NotEnoughMons, RusturfTunnel_HiddenLab_EventScript_Scientist_PostBattle
    end

RusturfTunnel_HiddenLab_EventScript_Scientist_PostBattle::
    setvar VAR_HIDDEN_LAB_STATE, 6
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RusturfTunnel_HiddenLab_EventScript_ScientistArrested
	end

RusturfTunnel_HiddenLab_Text_HowDidDoor::
    .string "How did you get past the door?!\p"
    .string "… … …\n"
    .string "… … …\p"
    .string "Looks like I'll have to deal with you\n"
    .string "myself!$"

RusturfTunnel_HiddenLab_Text_BossBattleIntro::
    .string "Time to unveil my latest invention!\n"
    .string "Behold my Paradox POKéMON!$"

RusturfTunnel_HiddenLab_Text_BossBattleLost::
    .string "No way! I lost!$"

RusturfTunnel_HiddenLab_Movement_RangerEnter::
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_down
    walk_down
    walk_down
    step_end

RusturfTunnel_HiddenLab_Movement_PlayerMove::
    walk_up
    face_down
    step_end

RusturfTunnel_HiddenLab_Movement_FollowerMove::
    walk_right
    face_left
    step_end

RusturfTunnel_HiddenLab_Movement_MoveClose::
    walk_up
    walk_left
    face_player
    step_end

RusturfTunnel_HiddenLab_Movement_FaceRanger::
    face_up
    step_end

RusturfTunnel_HiddenLab_Movement_PlayerFaceRanger::
    emote_question_mark
    face_up
    step_end

RusturfTunnel_HiddenLab_Movement_ScientistFaceRanger::
    jump_in_place_up
    emote_double_exclamation_mark
    face_up
    step_end

RusturfTunnel_HiddenLab_Movement_RangerExit::
    face_down
    face_down
    face_right
    face_up
    walk_up
    walk_up
    walk_up
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

RusturfTunnel_HiddenLab_Movement_CaptiveExit::
    walk_right
    walk_right
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
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    step_end

RusturfTunnel_HiddenLab_Movement_FacePlayer::
    face_player
    step_end

RusturfTunnel_HiddenLab_EventScript_ScientistArrested::
    addobject LOCALID_RANGER_LEADER, MAP_RUSTURF_TUNNEL_HIDDEN_LAB
    lock
    setweather WEATHER_SUNNY
    doweather
    msgbox RusturfTunnel_HiddenLab_Text_ScientistShocked, MSGBOX_DEFAULT
    waitmessage
    closemessage
    showobjectat LOCALID_RANGER_LEADER, MAP_RUSTURF_TUNNEL_HIDDEN_LAB
    delay 2
    applymovement LOCALID_RANGER_LEADER, RusturfTunnel_HiddenLab_Movement_RangerEnter
    waitmovement
    applymovement LOCALID_PLAYER, RusturfTunnel_HiddenLab_Movement_PlayerFaceRanger
    applymovement LOCALID_MAIN_SCIENTIST, RusturfTunnel_HiddenLab_Movement_ScientistFaceRanger
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_FaceRanger
    waitmovement
    msgbox RusturfTunnel_HiddenLab_Text_RangerAnnounce, MSGBOX_DEFAULT
    waitmessage
    closemessage
    facefollowernpc
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_FacePlayer
    waitmovement
    msgbox RusturfTunnel_HiddenLab_Text_YoungManAnnounce, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement LOCALID_PLAYER, RusturfTunnel_HiddenLab_Movement_FaceRanger
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_FaceRanger
    waitmovement
    msgbox RusturfTunnel_HiddenLab_Text_RangerLetsGo, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement LOCALID_PLAYER, RusturfTunnel_HiddenLab_Movement_PlayerMove
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_FollowerMove
    waitmovement
    goto RusturfTunnel_HiddenLab_EventScript_Exiting
    release
    end

RusturfTunnel_HiddenLab_EventScript_Exiting::
    lock
    applymovement LOCALID_RANGER_LEADER, RusturfTunnel_HiddenLab_Movement_RangerExit
    applymovement LOCALID_MAIN_SCIENTIST, RusturfTunnel_HiddenLab_Movement_CaptiveExit
    waitmovement
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_MoveClose
    waitmovement
    facefollowernpc
    applymovement OBJ_EVENT_ID_NPC_FOLLOWER, RusturfTunnel_HiddenLab_Movement_FacePlayer
    waitmovement
    msgbox RusturfTunnel_HiddenLab_Text_YoungManSeeYa, MSGBOX_DEFAULT
    waitmessage
    closemessage
    giveitem ITEM_POKE_SCANNER
	fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_HIDDEN_LAB_PEOPLE
    setflag FLAG_HIDE_HIDDEN_LAB_POLICE
    setflag FLAG_HELPED_YOUNG_MAN
    clearflag FLAG_CODE_MODE
    destroyfollowernpc
    removeobject LOCALID_RANGER_LEADER
    removeobject LOCALID_MAIN_SCIENTIST
    setobjectxyperm LOCALID_TM51, 8, 4
    setobjectxyperm LOCALID_FAKE_ID_CARD, 14, 11
    setobjectxyperm LOCALID_HACKING_DEVICE, 21, 3
    setobjectxyperm LOCALID_BOOSTER_ENERGY, 5, 2
    playse SE_DOOR
    delay 10
	fadescreenswapbuffers FADE_FROM_BLACK
	special DrawWholeMapView
    release
    end

RusturfTunnel_HiddenLab_Text_ScientistShocked::
    .string "M…M… My latest invention!\p"
    .string "It was beaten? I guess this operation\n"
    .string "and my life's work are both finished.$"

RusturfTunnel_HiddenLab_Text_RangerAnnounce::
    .string "Good work, Rookie and {PLAYER}!\p"
    .string "… … …\p"
    .string "Oh, you seem a bit confused, but I'm\n"
    .string "with the POKéMON Rangers, and so is he.\p"
    .string "… … … Oh, what we're doing here?\p"
    .string "We came to shut down this lab which was\n"
    .string "producing fake TRAINER IDs and\p"
    .string "something else from the look of things.$"

RusturfTunnel_HiddenLab_Text_YoungManAnnounce::
    .string "Sorry for not telling you sooner,\n"
    .string "{PLAYER}. This was an undercover\p"
    .string "mission and I couldn't risk too much\n"
    .string "information about it getting out.$"

RusturfTunnel_HiddenLab_Text_RangerLetsGo::
    .string "With that cleared up, let's bring this\n"
    .string "guy to the base. Everyone move out!$"

RusturfTunnel_HiddenLab_Text_YoungManSeeYa::
    .string "See you around {PLAYER}. You can\n"
    .string "always drop by the base on ROUTE 119.\p"
    .string "Until then here's something that you\n"
    .string "might like to have.$"

RusturfTunnel_HiddenLab_EventScript_Boxes::
    goto_if_eq VAR_HIDDEN_LAB_STATE, 6, RusturfTunnel_HiddenLab_EventScript_FakeBoxes
    msgbox RusturfTunnel_HiddenLab_Text_Boxes, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_FakeBoxes::
    msgbox RusturfTunnel_HiddenLab_Text_FakeBoxes, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_Shelf::
    goto_if_eq VAR_HIDDEN_LAB_STATE, 6, RusturfTunnel_HiddenLab_EventScript_FakeShelf
    msgbox RusturfTunnel_HiddenLab_Text_Shelf, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_FakeShelf::
    msgbox RusturfTunnel_HiddenLab_Text_FakeShelf, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_PC::
    goto_if_eq VAR_HIDDEN_LAB_STATE, 6, RusturfTunnel_HiddenLab_EventScript_FakePC
    msgbox RusturfTunnel_HiddenLab_Text_PC, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_FakePC::
    msgbox RusturfTunnel_HiddenLab_Text_FakePC, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_Machine::
    msgbox RusturfTunnel_HiddenLab_Text_Machine, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_Bed::
    msgbox RusturfTunnel_HiddenLab_Text_Bed, MSGBOX_DEFAULT
    waitmessage
    special HealPlayerParty
    closemessage
    end

RusturfTunnel_HiddenLab_Text_Bed::
    .string "It's a soft bed.\p"
    .string "Your POKéMON feel refreshed.$"

RusturfTunnel_HiddenLab_Text_Boxes::
    .string "It's a box full of IDs.$"

RusturfTunnel_HiddenLab_Text_FakeBoxes::
    .string "It's a box full of Fake IDs.$"

RusturfTunnel_HiddenLab_Text_Shelf::
    .string "It's a shelf full of Books.$"

RusturfTunnel_HiddenLab_Text_FakeShelf::
    .string "It's a shelf full of Books.\n"
    .string "There are names and pictures inside.$"

RusturfTunnel_HiddenLab_Text_PC::
    .string "It's a PC with ID pictures on it.$"

RusturfTunnel_HiddenLab_Text_FakePC::
    .string "It's a PC with Fake ID pictures on it.$"

RusturfTunnel_HiddenLab_Text_Machine::
    .string "It's a strange Machine.$"

RusturfTunnel_HiddenLab_EventScript_Door::
    goto_if_ge VAR_HIDDEN_LAB_STATE, 5, RusturfTunnel_HiddenLab_EventScript_DoorEnd
    checkitem ITEM_HACKING_DEVICE
	goto_if_eq VAR_RESULT, TRUE, RusturfTunnel_HiddenLab_EventScript_HackDoorCode
    goto_if_eq VAR_RESULT, FALSE, RusturfTunnel_HiddenLab_EventScript_AskCode
    end

RusturfTunnel_HiddenLab_EventScript_DoorEnd::
    end

RusturfTunnel_HiddenLab_EventScript_AskCode::
    msgbox RusturfTunnel_HiddenLab_Text_DoorCode, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, RusturfTunnel_HiddenLab_EventScript_ExitCode
	case YES, RusturfTunnel_HiddenLab_EventScript_EnterCode
	case MULTI_B_PRESSED, RusturfTunnel_HiddenLab_EventScript_ExitCode
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_HackDoorCode::
    msgbox RusturfTunnel_HiddenLab_Text_HackDoorCode, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, RusturfTunnel_HiddenLab_EventScript_AskCode
	case YES, RusturfTunnel_HiddenLab_EventScript_HackedDoor
	case MULTI_B_PRESSED, RusturfTunnel_HiddenLab_EventScript_AskCode
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_EnterCode::
    special EnterCode
    waitstate
    special GetCodeFeedback
    goto_if_eq VAR_RESULT, 0, RusturfTunnel_HiddenLab_EventScript_WrongCode
    goto_if_eq VAR_RESULT, 1, RusturfTunnel_HiddenLab_EventScript_RightCode
    end

RusturfTunnel_HiddenLab_EventScript_ExitCode::
    msgbox RusturfTunnel_HiddenLab_Text_DecidedNot, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_WrongCode::
    msgbox RusturfTunnel_HiddenLab_Text_WrongCode, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_RightCode::
    msgbox RusturfTunnel_HiddenLab_Text_RightCode, MSGBOX_DEFAULT
    waitmessage
    closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
    special ShakeCamera
    setmetatile 20, 9, METATILE_Lab_DoorFrame_Unlocked, FALSE
    setmetatile 21, 9, METATILE_Lab_DoorFrame_Unlocked, FALSE
    setmetatile 20, 10, METATILE_Lab_Door_Unlocked, FALSE
    setmetatile 21, 10, METATILE_Lab_Door_Unlocked, FALSE
	special DrawWholeMapView
    setvar VAR_HIDDEN_LAB_STATE, 5
    msgbox RusturfTunnel_HiddenLab_Text_DoorOpened, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_EventScript_HackedDoor::
    playse SE_PC_ON
    msgbox RusturfTunnel_HiddenLab_Text_HackedDoor, MSGBOX_DEFAULT
    waitmessage
    closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
    special ShakeCamera
    setmetatile 20, 9, METATILE_Lab_DoorFrame_Unlocked, FALSE
    setmetatile 21, 9, METATILE_Lab_DoorFrame_Unlocked, FALSE
    setmetatile 20, 10, METATILE_Lab_Door_Unlocked, FALSE
    setmetatile 21, 10, METATILE_Lab_Door_Unlocked, FALSE
	special DrawWholeMapView
    setvar VAR_HIDDEN_LAB_STATE, 5
    msgbox RusturfTunnel_HiddenLab_Text_DoorOpened, MSGBOX_DEFAULT
    waitmessage
    closemessage
    end

RusturfTunnel_HiddenLab_Text_DoorCode::
    .string "This door is locked with a code.\n"
    .string "Do you want to try entering one?$"

RusturfTunnel_HiddenLab_Text_HackDoorCode::
    .string "This door is locked with a code.\n"
    .string "Do you want to use the Hacking Device?$"

RusturfTunnel_HiddenLab_Text_DecidedNot::
    .string "You decied not to enter a code.$"

RusturfTunnel_HiddenLab_Text_WrongCode::
    .string "Wrong Code!$"

RusturfTunnel_HiddenLab_Text_RightCode::
    .string "Correct Code!$"

RusturfTunnel_HiddenLab_Text_DoorOpened::
    .string "The door opened!$"

RusturfTunnel_HiddenLab_Text_HackedDoor::
    .string "You used the Hacking Device.$"

RusturfTunnel_HiddenLab_Text_NotEnoughMons::
    .string "Not Enough POKéMON!$"
