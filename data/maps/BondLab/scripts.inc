.set LOCALID_BOND, 1
.set LOCALID_SCIENTIST_1, 2
.set LOCALID_SCIENTIST_2, 5
.set LOCALID_BALL_PIKACHU, 6
.set LOCALID_BALL_EEVEE, 7
.set LOCALID_MON_PIKACHU, 8

BondLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD BondLab_Stairs_State
	.byte 0

BondLab_DailyPC::
	goto_if_unset FLAG_ROTOM_PC_USED, BondLab_RotomPC
	goto_if_set FLAG_ROTOM_PC_USED, BondLab_NoRotomPC

BondLab_RotomPC::
	msgbox BondLab_Text_RotomPC, MSGBOX_AUTOCLOSE
	closemessage
	setwildbattle SPECIES_ROTOM, 20, ITEM_MAGNET, SPECIES_NONE
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 2, 0, 0, 0
	setflag FLAG_ROTOM_PC_USED
	dowildbattle
	end

BondLab_NoRotomPC::
	msgbox BondLab_Text_NoRotomPC, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Scientist_Bond::
	call_if_unset FLAG_BOND_DEFEATED, BondLab_Scientist_Bond_Battle
	call_if_set FLAG_BOND_DEFEATED, BondLab_Scientist_Bond_PostBattle
	end

BondLab_Scientist_Bond_Battle::
	trainerbattle_single TRAINER_BOND, BondLab_Text_BondIntro, BondLab_Text_BondDefeated
	setflag FLAG_BOND_DEFEATED
	msgbox BondLab_Text_BondPostBattle, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Scientist_Bond_PostBattle::
	goto_if_unset FLAG_PARTNER_PICKED, BondLab_Scientist_Bond_Gift
	goto_if_set FLAG_PARTNER_PICKED, BondLab_Scientist_Bond_PostGift
	end

BondLab_Scientist_Bond_Gift::
	setobjectmovementtype LOCALID_BOND, MOVEMENT_ACTION_FACE_PLAYER
	msgbox BondLab_Text_BondGift, MSGBOX_AUTOCLOSE
	closemessage
	setflag FLAG_PARTNER_CAN_BE_PICKED
	end

BondLab_TablePokeball_Eevee::
	goto_if_unset FLAG_PARTNER_CAN_BE_PICKED, BondLab_DontTouch
	goto_if_unset FLAG_PARTNER_PIKACHU_PICKED, BondLab_TablePokeball_Eevee_Choice
	goto_if_set FLAG_PARTNER_PIKACHU_PICKED, BondLab_LeaveIt
	end

BondLab_TablePokeball_Pikachu::
	goto_if_unset FLAG_PARTNER_CAN_BE_PICKED, BondLab_DontTouch
	goto_if_unset FLAG_PARTNER_EEVEE_PICKED, BondLab_TablePokeball_Pikachu_Choice
	goto_if_set FLAG_PARTNER_EEVEE_PICKED, BondLab_LeaveIt
	end

BondLab_TablePokeball_Eevee_Choice::
	showmonpic SPECIES_EEVEE 10, 3
	playmoncry SPECIES_EEVEE CRY_MODE_NORMAL
	delay 50
	hidemonpic
	msgbox BondLab_Text_PartnerEevee, MSGBOX_DEFAULT
	closemessage
	multichoice 21, 8, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 1, BondLab_WalkAway
	case 0, BondLab_Select_Eevee
	end

BondLab_TablePokeball_Pikachu_Choice::
	showmonpic SPECIES_PIKACHU 10, 3
	playmoncry SPECIES_PIKACHU CRY_MODE_NORMAL
	delay 50
	hidemonpic
	msgbox BondLab_Text_PartnerPikachu, MSGBOX_DEFAULT
	closemessage
	multichoice 21, 8, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 1, BondLab_WalkAway
	case 0, BondLab_Select_Pikachu
	end

BondLab_Select_Pikachu::
	showmonpic SPECIES_PIKACHU 10, 3
	playmoncry SPECIES_PIKACHU CRY_MODE_NORMAL
	givemon SPECIES_PIKACHU_PARTNER, 5, ITEM_LIGHT_BALL
	delay 30
	hidemonpic
	msgbox BondLab_Text_PickedPartnerPikachu, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_PARTNER_PICKED
	setflag FLAG_PARTNER_PIKACHU_PICKED
	removeobject LOCALID_BALL_PIKACHU
	end

BondLab_Select_Eevee::
	showmonpic SPECIES_EEVEE 10, 3
	playmoncry SPECIES_EEVEE CRY_MODE_NORMAL
	givemon SPECIES_EEVEE_PARTNER, 5, ITEM_SILK_SCARF
	delay 30
	hidemonpic
	msgbox BondLab_Text_PickedPartnerEevee, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_PARTNER_PICKED
	setflag FLAG_PARTNER_EEVEE_PICKED
	removeobject LOCALID_BALL_EEVEE
	end

BondLab_Stairs_Pikachu::
	call_if_unset FLAG_BOND_DEFEATED, BondLab_Stairs_Pikachu_PreBattle
	call_if_set FLAG_BOND_DEFEATED, BondLab_Stairs_Pikachu_PostBattle
	end

BondLab_WalkAway::
	msgbox BondLab_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_LeaveIt::
	msgbox BondLab_Text_LeaveIt, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Scientist_Bond_PostGift::
	setobjectmovementtype LOCALID_BOND, MOVEMENT_ACTION_FACE_PLAYER
	msgbox BondLab_Text_BondPostGift, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Scientist1::
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_ACTION_FACE_PLAYER
	msgbox BondLab_Text_Scientist1, MSGBOX_AUTOCLOSE
	closemessage
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_ACTION_FACE_RIGHT
	end

BondLab_Scientist2::
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_ACTION_FACE_PLAYER
	msgbox BondLab_Text_Scientist2, MSGBOX_AUTOCLOSE
	closemessage
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_ACTION_FACE_LEFT
	end

BondLab_Scientist3::
	msgbox BondLab_Text_Scientist3, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Scientist4::
	msgbox BondLab_Text_Scientist4, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Stairs_Pikachu_PreBattle::
	msgbox BondLab_Text_Stairs_Pikachu, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Stairs_Pikachu_PostBattle::
	call_if_unset FLAG_PIKACHU_MOVED, BondLab_Stairs_Pikachu_MovesAside
	call_if_set FLAG_PIKACHU_MOVED, BondLab_Stairs_Pikachu_MovedAside
	end

BondLab_Stairs_State::
	call_if_unset FLAG_PIKACHU_MOVED, BondLab_Stairs_Blocked
	call_if_set FLAG_PIKACHU_MOVED, BondLab_Stairs_Unblocked
	end

BondLab_Stairs_Blocked::
	setobjectxyperm LOCALID_MON_PIKACHU, 9, 2
	end

BondLab_Stairs_Unblocked::
	setobjectxyperm LOCALID_MON_PIKACHU, 8, 2
	end

BondLab_Stairs_Pikachu_MovesAside::
	applymovement LOCALID_MON_PIKACHU, BondLab_Pikachu_Moves
	waitmovement 0
	msgbox BondLab_Text_Stairs_Pikachu_Moved, MSGBOX_AUTOCLOSE
	closemessage
	setobjectxyperm LOCALID_MON_PIKACHU, 8, 2
	setflag FLAG_PIKACHU_MOVED
	end

BondLab_Stairs_Pikachu_MovedAside::
	msgbox BondLab_Text_Stairs_Pikachu_Moved, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Pikachu_Moves::
	walk_slow_left
	face_down
	step_end

BondLab_RotomBox::
	call Rotom_Appliances_Main
	end

BondLab_Paper::
	msgbox BondLab_Text_Paper, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_DontTouch::
	msgbox BondLab_Text_DontTouch, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_WorkingPC::
	msgbox BondLab_Text_WorkingPC, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_BrokenPC::
	msgbox BondLab_Text_BrokenPC, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Books::
	msgbox BondLab_Text_Books, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_BookShelf::
	msgbox BondLab_Text_BookShelf, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Machine::
	msgbox BondLab_Text_Machine, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Text_NoRotomPC::
	.string "There's nothing here.$"

BondLab_Text_RotomPC::
	.string "There's something here!$"

BondLab_Text_Stairs_Pikachu::
	.string "It's blocking the stairs.$"

BondLab_Text_Stairs_Pikachu_Moved::
	.string "It's allowing you to enter\n"
	.string "the basement of the lab.$"

BondLab_Text_Machine::
	.string "A strange machine!$"

BondLab_Text_BrokenPC::
	.string "The computer seems broken.$"

BondLab_Text_LeaveIt::
	.string "It's the other Pokémon.\n"
	.string "I should leave it alone.$"

BondLab_Text_PartnerEevee::
	.string "That is a very special Eevee.\n"
	.string "Are you sure that you want it?$"

BondLab_Text_PartnerPikachu::
	.string "That is a very special Pikachu.\n"
	.string "Are you sure that you want it?$"

BondLab_Text_PickedPartnerEevee::
	.string "Good choice, take care of Eevee!$"

BondLab_Text_PickedPartnerPikachu::
	.string "Good choice, take care of Pikachu!$"

BondLab_Text_DontTouch::
	.string "There is a Pokéball on the table!\n"
	.string "It's best to leave it alone.$"

BondLab_Text_WorkingPC::
	.string "The computer is being used.$"

BondLab_Text_Books::
	.string "A stack of complicated books.$"

BondLab_Text_BookShelf::
	.string "A shelf full of books on bonds.$"

BondLab_Text_WalkAway::
	.string "You walked away.$"

BondLab_Text_Scientist1::
	.string "We were recently given the funds for\n" 
	.string "this project by the guy over there.\p"
	.string "Other than that, I can't tell you much\n" 
	.string "of what our research has found yet.$"

BondLab_Text_Scientist2::
	.string "He seems to be busy.$"

BondLab_Text_Scientist3::
	.string "He seems to be trying\n"
	.string "to fix the computer.$"

BondLab_Text_Scientist4::
	.string "Do you have a Rotom?\n"
	.string "If so, have it look\p"
	.string "in this box here.\n"
	.string "It might want something.$"

BondLab_Text_Paper::
	.string "A scrap of paper.$"

BondLab_Text_BondIntro::
	.string "W-W-W-Wha... H-How did you get in?\p"
	.string "No matter, time to show you\n"
	.string "the results of our research!$"

BondLab_Text_BondDefeated::
	.string "Wow... I guess there really are\n"
	.string "different kinds of bonds?$"

BondLab_Text_BondPostBattle::
	.string "I recently discovered this strange\n"
	.string "place deeper in the woods, with my two\p"
	.string "partners here. After funding this small\n"
	.string "group of scientists, we started our\p"
	.string "research on the connections between,\n"
	.string "people, Pokémon, locations,\p"
	.string "and the evolution of Pokémon.$"

BondLab_Text_BondGift::
	.string "Ah, speaking of bonds.\n"
	.string "There's something I want you to have.\p"
	.string "Over on the table you can pick one.$"

BondLab_Text_BondPostGift::
	.string "If you have your PARTNER with you.\n"
	.string "I can teach it some new moves.$"

