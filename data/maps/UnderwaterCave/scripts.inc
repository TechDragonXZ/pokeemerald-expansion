UnderwaterCave_MapScripts::
	.byte 0

UnderwaterCave_StrangeStone::
	msgbox UnderwaterCave_Text_StrangeStone, MSGBOX_DEFAULT
	closemessage
	multichoice 21, 8, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 1, UnderwaterCave_WalkAway
	case 0, UnderwaterCave_StrangeStoneWarp
	end

UnderwaterCave_StrangeStoneWarp::
	msgbox UnderwaterCave_Text_Warp, MSGBOX_DEFAULT
	closemessage
	warpspinenter MAP_STRANGE_SPACE, 20, 20
	end

UnderwaterCave_WalkAway::
	msgbox UnderwaterCave_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

UnderwaterCave_Text_WalkAway::
	.string "You walked away.$"

UnderwaterCave_Text_Warp::
	.string "Everything went dark.$"

UnderwaterCave_Text_StrangeStone::
	.string "It's a strange stone.\n"
	.string "The surrounding air feels warm.\p"
	.string "Do you want to touch it?$"
