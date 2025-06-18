MiningSpots_EventScript_MiningSpot::
	lockall
	checkitem ITEM_MINING_KIT
	goto_if_eq VAR_RESULT, FALSE, MiningSpots_EventScript_NoMiningKit
	msgbox MiningSpots_Text_WantToMine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelMine
	msgbox MiningSpots_Text_PlayerUsedMiningKit, MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	special StartMining
	incrementgamestat GAME_STAT_TIMES_MINING
	removeobject VAR_LAST_TALKED
	releaseall
	end

EventScript_CancelMine::
	msgbox MiningSpots_Text_CanceledMining, MSGBOX_AUTOCLOSE
	closemessage
	releaseall
	end

MiningSpots_EventScript_NoMiningKit::
	msgbox MiningSpots_Text_NoMiningKit, MSGBOX_AUTOCLOSE
	closemessage
	releaseall
	end

MiningSpots_Text_NoMiningKit::
	.string "You don't have a Mining Kit.$"

MiningSpots_Text_CanceledMining::
	.string "You decided not to use your Mining Kit.$"

MiningSpots_Text_WantToMine::
	.string "Do you want to use your Mining Kit?$"

MiningSpots_Text_PlayerUsedMiningKit::
	.string "{PLAYER} started mining.$"
