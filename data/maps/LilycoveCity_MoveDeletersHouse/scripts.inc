LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
	.string "Uh…\n"
	.string "Oh, yes, I'm the MOVE DELETER.\p"
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
	.string "Which POKéMON should forget a move?$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No EGG should know any moves.$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer::
	lockall
	applymovement LOCALID_HYPER_TRAINER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanHyperTrainMon, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndStatToHyperTrain
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndStatToHyperTrain::
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_MoveDeletersHouse_EventScript_ComeBackWithBottleCaps
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichStatShouldBeHyperTrained, MSGBOX_DEFAULT
	dynmultipush LilycoveCity_MoveDeletersHouse_Text_StatHP, 0
	dynmultipush LilycoveCity_MoveDeletersHouse_Text_StatATK, 1
	dynmultipush LilycoveCity_MoveDeletersHouse_Text_StatDEF, 2
	dynmultipush LilycoveCity_MoveDeletersHouse_Text_StatSPATK, 3
	dynmultipush LilycoveCity_MoveDeletersHouse_Text_StatSPDEF, 4
	dynmultipush LilycoveCity_MoveDeletersHouse_Text_StatSpeed, 5
	dynmultipush LilycoveCity_MoveDeletersHouse_Text_Nevermind, 6
	dynmultistack 19, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainHP
	case 1, LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainATK
	case 2, LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainDEF
	case 3, LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainSPATK
	case 4, LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainSPDEF
	case 5, LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainSpeed
	case 6, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	case MULTI_B_PRESSED, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	closemessage
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainHP::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldBeHyperTrained, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	special BufferMonNickname
	bufferstring STR_VAR_2, LilycoveCity_MoveDeletersHouse_Text_StatHP
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantHyperTrain
	canhypertrain STAT_HP, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_MoveDeletersHouse_EventScript_AlreadyHyperTrained
	msgbox LilycoveCity_MoveDeletersHouse_Text_ThatStatShouldBeHyperTrained, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	hypertrain STAT_HP, VAR_0x8004
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasBeenHyperTrained, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP, 1
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainATK::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldBeHyperTrained, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	special BufferMonNickname
	bufferstring STR_VAR_2, LilycoveCity_MoveDeletersHouse_Text_StatATK
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantHyperTrain
	canhypertrain STAT_ATK, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_MoveDeletersHouse_EventScript_AlreadyHyperTrained
	msgbox LilycoveCity_MoveDeletersHouse_Text_ThatStatShouldBeHyperTrained, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	hypertrain STAT_ATK, VAR_0x8004
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasBeenHyperTrained, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP, 1
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainDEF::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldBeHyperTrained, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	special BufferMonNickname
	bufferstring STR_VAR_2, LilycoveCity_MoveDeletersHouse_Text_StatDEF
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantHyperTrain
	canhypertrain STAT_DEF, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_MoveDeletersHouse_EventScript_AlreadyHyperTrained
	msgbox LilycoveCity_MoveDeletersHouse_Text_ThatStatShouldBeHyperTrained, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	hypertrain STAT_DEF, VAR_0x8004
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasBeenHyperTrained, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP, 1
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainSPATK::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldBeHyperTrained, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	special BufferMonNickname
	bufferstring STR_VAR_2, LilycoveCity_MoveDeletersHouse_Text_StatSPATK
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantHyperTrain
	canhypertrain STAT_SPATK, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_MoveDeletersHouse_EventScript_AlreadyHyperTrained
	msgbox LilycoveCity_MoveDeletersHouse_Text_ThatStatShouldBeHyperTrained, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	hypertrain STAT_SPATK, VAR_0x8004
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasBeenHyperTrained, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP, 1
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainSPDEF::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldBeHyperTrained, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	special BufferMonNickname
	bufferstring STR_VAR_2, LilycoveCity_MoveDeletersHouse_Text_StatSPDEF
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantHyperTrain
	canhypertrain STAT_SPDEF, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_MoveDeletersHouse_EventScript_AlreadyHyperTrained
	msgbox LilycoveCity_MoveDeletersHouse_Text_ThatStatShouldBeHyperTrained, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	hypertrain STAT_SPDEF, VAR_0x8004
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasBeenHyperTrained, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP, 1
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryHyperTrainSpeed::
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldBeHyperTrained, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	special BufferMonNickname
	bufferstring STR_VAR_2, LilycoveCity_MoveDeletersHouse_Text_StatSpeed
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantHyperTrain
	canhypertrain STAT_SPEED, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_MoveDeletersHouse_EventScript_AlreadyHyperTrained
	msgbox LilycoveCity_MoveDeletersHouse_Text_ThatStatShouldBeHyperTrained, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT
	hypertrain STAT_SPEED, VAR_0x8004
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasBeenHyperTrained, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP, 1
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_AlreadyHyperTrained::
	special BufferMonNickname
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonAlreadyHyperTrained, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantHyperTrain::
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantHyperTrain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgainHT::
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgainHT, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeBackWithBottleCaps::
	msgbox LilycoveCity_MoveDeletersHouse_Text_NoBottleCaps, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ComeAgainHT:
	.string "Come again if there are POKéMON that\n"
	.string "need to be hyper trained.$"

LilycoveCity_MoveDeletersHouse_Text_EggCantHyperTrain:
	.string "What?\n"
	.string "No EGG can be hyper trained.$"

LilycoveCity_MoveDeletersHouse_Text_ICanHyperTrainMon:
	.string "Welcome, I'm the HYPER TRAINER.\n"
	.string "I can hyper train one of your POKéMON's\p"
	.string "stats to their limit, for a bottle cap.\n"
	.string "Would you like me to do that?$"

LilycoveCity_MoveDeletersHouse_Text_NoBottleCaps:
	.string "Oh, you don't have any bottle caps.\n"
	.string "Come back later when you do.$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldBeHyperTrained:
	.string "Which POKéMON should be hyper trained?$"

LilycoveCity_MoveDeletersHouse_Text_WhichStatShouldBeHyperTrained:
	.string "Which stat should be trained?$"

LilycoveCity_MoveDeletersHouse_Text_MonAlreadyHyperTrained:
	.string "{STR_VAR_1}'s {STR_VAR_2} stat?\n"
	.string "It already has been trained before.$"

LilycoveCity_MoveDeletersHouse_Text_ThatStatShouldBeHyperTrained:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2} stat?\n"
	.string "That stat should be trained?$"

LilycoveCity_MoveDeletersHouse_Text_MonHasBeenHyperTrained:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has hyper trained\n"
	.string "it's {STR_VAR_2} stat completely.$"

LilycoveCity_MoveDeletersHouse_Text_StatHP:
	.string "Health$"

LilycoveCity_MoveDeletersHouse_Text_StatATK:
	.string "Attack$"

LilycoveCity_MoveDeletersHouse_Text_StatDEF:
	.string "Defense$"

LilycoveCity_MoveDeletersHouse_Text_StatSPATK:
	.string "Special Attack$"

LilycoveCity_MoveDeletersHouse_Text_StatSPDEF:
	.string "Special Defense$"

LilycoveCity_MoveDeletersHouse_Text_StatSpeed:
	.string "Speed$"

LilycoveCity_MoveDeletersHouse_Text_Nevermind:
	.string "Nevermind$"

LilycoveCity_MoveDeletersHouse_EventScript_OldLady::
	msgbox LilycoveCity_MoveDeletersHouse_Text_SonFollowingFootsteps, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_SonFollowingFootsteps:
	.string "Our son has returned home from abroad.\n"
	.string "He was out learning a new POKéMON\p"
	.string "training technique to follow in his\n"
	.string "Father's footsteps.$"
