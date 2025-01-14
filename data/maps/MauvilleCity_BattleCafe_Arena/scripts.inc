.set LOCALID_BATTLE_BOT, 1

@ Prices
.set VSC_PRICE,  1000
.set MC_PRICE,   2500
.set MRB_PRICE,  5000

MauvilleCity_BattleCafe_Arena_MapScripts::
	.byte 0

MauvilleCity_BattleCafe_Arena_EventScript_BattleBot::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_NORTH, MauvilleCity_BattleCafe_Arena_EventScript_BattleBot_North
	goto_if_eq VAR_RESULT, DIR_EAST, MauvilleCity_BattleCafe_Arena_EventScript_BattleBot_East
	goto_if_eq VAR_RESULT, DIR_SOUTH, MauvilleCity_BattleCafe_Arena_EventScript_BattleBot_South
	goto_if_eq VAR_RESULT, DIR_WEST, MauvilleCity_BattleCafe_Arena_EventScript_BattleBot_West
	end

MauvilleCity_BattleCafe_Arena_EventScript_BattleBot_North::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Arena_Movement_Walk_ToLeftSide_North
	applymovement LOCALID_BATTLE_BOT, MauvilleCity_BattleCafe_Arena_Movement_Walk_ToRightSide
	waitmovement OBJ_EVENT_ID_PLAYER
	lockall
	faceplayer
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 1, MauvilleCity_BattleCafe_Arena_EventScript_VillageSubCombo
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 2, MauvilleCity_BattleCafe_Arena_EventScript_MagnemiteCroquette
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 3, MauvilleCity_BattleCafe_Arena_EventScript_MauvilleRamenBowl
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_BattleBot_East::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Arena_Movement_Walk_ToLeftSide_East
	applymovement LOCALID_BATTLE_BOT, MauvilleCity_BattleCafe_Arena_Movement_Walk_ToRightSide
	waitmovement OBJ_EVENT_ID_PLAYER
	lockall
	faceplayer
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 1, MauvilleCity_BattleCafe_Arena_EventScript_VillageSubCombo
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 2, MauvilleCity_BattleCafe_Arena_EventScript_MagnemiteCroquette
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 3, MauvilleCity_BattleCafe_Arena_EventScript_MauvilleRamenBowl
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_BattleBot_South::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Arena_Movement_Walk_ToLeftSide_South
	applymovement LOCALID_BATTLE_BOT, MauvilleCity_BattleCafe_Arena_Movement_Walk_ToRightSide
	waitmovement OBJ_EVENT_ID_PLAYER
	lockall
	faceplayer
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 1, MauvilleCity_BattleCafe_Arena_EventScript_VillageSubCombo
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 2, MauvilleCity_BattleCafe_Arena_EventScript_MagnemiteCroquette
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 3, MauvilleCity_BattleCafe_Arena_EventScript_MauvilleRamenBowl
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_BattleBot_West::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Arena_Movement_Walk_ToLeftSide_West
	applymovement LOCALID_BATTLE_BOT, MauvilleCity_BattleCafe_Arena_Movement_Walk_ToRightSide_West
	waitmovement OBJ_EVENT_ID_PLAYER
	lockall
	faceplayer
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 1, MauvilleCity_BattleCafe_Arena_EventScript_VillageSubCombo
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 2, MauvilleCity_BattleCafe_Arena_EventScript_MagnemiteCroquette
	call_if_eq VAR_BATTLE_COURSE_SELECTED, 3, MauvilleCity_BattleCafe_Arena_EventScript_MauvilleRamenBowl
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_VillageSubCombo::
	trainerbattle_no_whiteout_continue_script TRAINER_VSC, MauvilleCity_BattleCafe_Arena_Text_VSCIntro, MauvilleCity_BattleCafe_Arena_Text_BattleBot_Defeat, MauvilleCity_BattleCafe_Arena_EventScript_VillageSubCombo_Outcome
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_VillageSubCombo_Outcome::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_RightToCenter
	applymovement LOCALID_BATTLE_BOT, MauvilleCity_BattleCafe_Movement_Walk_LeftToCenter
	waitmovement LOCALID_BATTLE_BOT
	special HealPlayerParty
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_WON, MauvilleCity_BattleCafe_Arena_EventScript_Defeat_VillageSubCombo
	call_if_eq VAR_RESULT, B_OUTCOME_LOST, MauvilleCity_BattleCafe_Arena_EventScript_Lost_VillageSubCombo
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_Defeat_VillageSubCombo::
	msgbox MauvilleCity_BattleCafe_Arena_Text_BattleBot_PostBattle_Win, MSGBOX_AUTOCLOSE
	setvar VAR_BATTLE_COURSE_COMPLETED, 1
	setvar VAR_BATTLE_COURSE_SELECTED, 0
	setvar VAR_BATTLE_COURSE_STATE, 2
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_Lost_VillageSubCombo::
	msgbox MauvilleCity_BattleCafe_Arena_Text_BattleBot_PostBattle_Lose, MSGBOX_AUTOCLOSE
	setvar VAR_BATTLE_COURSE_COMPLETED, 0
	setvar VAR_BATTLE_COURSE_SELECTED, 0
	setvar VAR_BATTLE_COURSE_STATE, 2
	addmoney VSC_PRICE
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_MagnemiteCroquette::
	trainerbattle_no_whiteout_continue_script TRAINER_MC, MauvilleCity_BattleCafe_Arena_Text_MCIntro, MauvilleCity_BattleCafe_Arena_Text_BattleBot_Defeat, MauvilleCity_BattleCafe_Arena_EventScript_MagnemiteCroquette_Outcome
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_MagnemiteCroquette_Outcome::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_RightToCenter
	applymovement LOCALID_BATTLE_BOT, MauvilleCity_BattleCafe_Movement_Walk_LeftToCenter
	waitmovement LOCALID_BATTLE_BOT
	special HealPlayerParty
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_WON, MauvilleCity_BattleCafe_Arena_EventScript_Defeat_MagnemiteCroquette
	call_if_eq VAR_RESULT, B_OUTCOME_LOST, MauvilleCity_BattleCafe_Arena_EventScript_Lost_MagnemiteCroquette
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_Defeat_MagnemiteCroquette::
	msgbox MauvilleCity_BattleCafe_Arena_Text_BattleBot_PostBattle_Win, MSGBOX_AUTOCLOSE
	setvar VAR_BATTLE_COURSE_COMPLETED, 2
	setvar VAR_BATTLE_COURSE_SELECTED, 0
	setvar VAR_BATTLE_COURSE_STATE, 2
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_Lost_MagnemiteCroquette::
	msgbox MauvilleCity_BattleCafe_Arena_Text_BattleBot_PostBattle_Lose, MSGBOX_AUTOCLOSE
	setvar VAR_BATTLE_COURSE_COMPLETED, 0
	setvar VAR_BATTLE_COURSE_SELECTED, 0
	setvar VAR_BATTLE_COURSE_STATE, 2
	addmoney MC_PRICE
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_MauvilleRamenBowl::
	setflag FLAG_INVERSE_BATTLE
	trainerbattle_no_whiteout_continue_script TRAINER_MRB, MauvilleCity_BattleCafe_Arena_Text_MRBIntro, MauvilleCity_BattleCafe_Arena_Text_BattleBot_Defeat, MauvilleCity_BattleCafe_Arena_EventScript_MauvilleRamenBowl_Outcome
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_MauvilleRamenBowl_Outcome::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_RightToCenter
	applymovement LOCALID_BATTLE_BOT, MauvilleCity_BattleCafe_Movement_Walk_LeftToCenter
	waitmovement LOCALID_BATTLE_BOT
	special HealPlayerParty
	clearflag FLAG_INVERSE_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_WON, MauvilleCity_BattleCafe_Arena_EventScript_Defeat_MauvilleRamenBowl
	call_if_eq VAR_RESULT, B_OUTCOME_LOST, MauvilleCity_BattleCafe_Arena_EventScript_Lost_MauvilleRamenBowl
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_Defeat_MauvilleRamenBowl::
	msgbox MauvilleCity_BattleCafe_Arena_Text_BattleBot_PostBattle_Win, MSGBOX_AUTOCLOSE
	setvar VAR_BATTLE_COURSE_COMPLETED, 3
	setvar VAR_BATTLE_COURSE_SELECTED, 0
	setvar VAR_BATTLE_COURSE_STATE, 2
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_EventScript_Lost_MauvilleRamenBowl::
	msgbox MauvilleCity_BattleCafe_Arena_Text_BattleBot_PostBattle_Lose, MSGBOX_AUTOCLOSE
	setvar VAR_BATTLE_COURSE_COMPLETED, 0
	setvar VAR_BATTLE_COURSE_SELECTED, 0
	setvar VAR_BATTLE_COURSE_STATE, 2
	addmoney MRB_PRICE
	releaseall
	return
	end

MauvilleCity_BattleCafe_Arena_Movement_Walk_ToLeftSide_North::
	walk_left
	walk_up
	walk_left
	walk_left
	face_right
	step_end

MauvilleCity_BattleCafe_Arena_Movement_Walk_ToLeftSide_East::
	walk_left
	walk_left
	face_right
	step_end

MauvilleCity_BattleCafe_Arena_Movement_Walk_ToLeftSide_South::
	walk_left
	walk_down
	walk_left
	walk_left
	face_right
	step_end

MauvilleCity_BattleCafe_Arena_Movement_Walk_ToLeftSide_West::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	step_end

MauvilleCity_BattleCafe_Arena_Movement_Walk_ToRightSide::
	walk_right
	walk_right
	face_left
	step_end

MauvilleCity_BattleCafe_Arena_Movement_Walk_ToRightSide_West::
	delay_2
	walk_right
	walk_right
	face_left
	step_end

MauvilleCity_BattleCafe_Movement_Walk_RightToCenter::
	walk_right
	walk_right
	step_end

MauvilleCity_BattleCafe_Movement_Walk_LeftToCenter::
	walk_left
	walk_left
	step_end

MauvilleCity_BattleCafe_Arena_Text_VSCIntro:
	.string "BATTLE-BOT: Getting your order…\n"
	.string "Battle Course: Village Sub Combo…\p"
	.string "Starting Battle!$"

MauvilleCity_BattleCafe_Arena_Text_MCIntro:
	.string "BATTLE-BOT: Getting your order…\n"
	.string "Battle Course: Magnemite Croquette…\p"
	.string "Starting Battle!$"

MauvilleCity_BattleCafe_Arena_Text_MRBIntro:
	.string "BATTLE-BOT: Getting your order…\n"
	.string "Battle Course: Mauville Ramen Bowl…\p"
	.string "Starting Battle!$"

MauvilleCity_BattleCafe_Arena_Text_BattleBot_Defeat:
	.string "BATTLE-BOT: Getting your results…\n"
	.string "Battle Course: Battle Over!$"

MauvilleCity_BattleCafe_Arena_Text_BattleBot_PostBattle_Win:
	.string "BATTLE-BOT: Head out front for\n"
	.string "your rewards and meal.$"

MauvilleCity_BattleCafe_Arena_Text_BattleBot_PostBattle_Lose:
	.string "BATTLE-BOT: Head out front for\n"
	.string "your refund.$"
