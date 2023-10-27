.set LOCALID_BOND, 1
.set LOCALID_SCIENTIST_1, 2
.set LOCALID_SCIENTIST_2, 5
.set LOCALID_BALL_PIKACHU, 6
.set LOCALID_BALL_EEVEE, 7

BondLab_MapScripts::
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
	call_if_unset FLAG_BOND_DEFEATED_INITAL, BondLab_Scientist_Bond_Battle
	call_if_set FLAG_BOND_DEFEATED_INITAL, BondLab_Scientist_Bond_PostBattle
	call_if_set FLAG_BOND_DEFEATED_EEVEE, BondLab_Scientist_Bond_PostGift2
	call_if_set FLAG_BOND_DEFEATED_PIKACHU, BondLab_Scientist_Bond_PostGift2
	end

BondLab_Scientist_Bond_Battle::
	lock
	faceplayer
	trainerbattle_single TRAINER_BOND_1, BondLab_Text_BondIntro, BondLab_Text_BondDefeated
	setflag FLAG_BOND_DEFEATED_INITAL
	msgbox BondLab_Text_BondPostBattle, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

BondLab_Scientist_Bond_PostBattle::
	goto_if_unset FLAG_PARTNER_PICKED, BondLab_Scientist_Bond_Gift
	goto_if_set FLAG_PARTNER_PICKED, BondLab_Scientist_Bond_PostGift
	end

BondLab_Scientist_Bond_Gift::
	lock
	faceplayer
	msgbox BondLab_Text_BondGift, MSGBOX_AUTOCLOSE
	closemessage
	setflag FLAG_PARTNER_CAN_BE_PICKED
	release
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
	msgbox BondLab_Text_PartnerEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BondLab_Select_Eevee
	goto_if_eq VAR_RESULT, NO, BondLab_WalkAway
	end

BondLab_TablePokeball_Pikachu_Choice::
	showmonpic SPECIES_PIKACHU 10, 3
	playmoncry SPECIES_PIKACHU CRY_MODE_NORMAL
	delay 50
	hidemonpic
	msgbox BondLab_Text_PartnerPikachu, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BondLab_Select_Pikachu
	goto_if_eq VAR_RESULT, NO, BondLab_WalkAway
	end

BondLab_Select_Pikachu::
	playmoncry SPECIES_PIKACHU CRY_MODE_NORMAL
	givemon SPECIES_PIKACHU_PARTNER, 5, ITEM_LIGHT_BALL
	delay 30
	msgbox BondLab_Text_PickedPartnerPikachu, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_PARTNER_PICKED
	setflag FLAG_PARTNER_PIKACHU_PICKED
	removeobject LOCALID_BALL_PIKACHU
	end

BondLab_Select_Eevee::
	playmoncry SPECIES_EEVEE CRY_MODE_NORMAL
	givemon SPECIES_EEVEE_PARTNER, 5, ITEM_SILK_SCARF
	delay 30
	msgbox BondLab_Text_PickedPartnerEevee, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_PARTNER_PICKED
	setflag FLAG_PARTNER_EEVEE_PICKED
	removeobject LOCALID_BALL_EEVEE
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
	lock
	faceplayer
	msgbox BondLab_Text_BondPostGift, MSGBOX_AUTOCLOSE
	closemessage
	goto_if_set FLAG_BADGE06_GET, BondLab_Scientist_Check_For_Partner
	goto_if_unset FLAG_BADGE06_GET, BondLab_Scientist_Teach_Partner
	release
	end

BondLab_Scientist_Bond_PostGift2::
	lock
	faceplayer
	goto BondLab_Scientist_Teach_Partner
	release
	end

BondLab_Scientist_Teach_Partner::
	lock
	faceplayer
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BondLab_Scientist_Bond_NoPartner
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EEVEE_PARTNER, BondLab_Scientist_Bond_TeachPartnerEevee
	goto_if_eq VAR_RESULT, SPECIES_PIKACHU_PARTNER, BondLab_Scientist_Bond_TeachPartnerPikachu
	release
	end

BondLab_Scientist_Check_For_Partner_Short::
	lock
	faceplayer
	msgbox BondLab_Text_PartnerFront, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_Set_Partner_Front
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BondLab_Scientist_Bond_NoPartner
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EEVEE_PARTNER, BondLab_Scientist_Bond_CheckPartnerEevee
	goto_if_eq VAR_RESULT, SPECIES_PIKACHU_PARTNER, BondLab_Scientist_Bond_CheckPartnerPikachu
	release
	end

BondLab_Scientist_Check_For_Partner::
	lock
	faceplayer
	msgbox BondLab_Text_CheckFriendship, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Teach_Partner
	msgbox BondLab_Text_PartnerFront, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_Set_Partner_Front
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BondLab_Scientist_Bond_NoPartner
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EEVEE_PARTNER, BondLab_Scientist_Bond_CheckPartnerEevee
	goto_if_eq VAR_RESULT, SPECIES_PIKACHU_PARTNER, BondLab_Scientist_Bond_CheckPartnerPikachu
	release
	end

BondLab_Scientist_Bond_CheckPartnerEevee::
	lock
	faceplayer
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_le VAR_RESULT, FRIENDSHIP_100_TO_149, BondLab_Scientist_Bond_ComeBackLater
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, BondLab_Scientist_Bond_BattlePartnerEevee
	release
	end

BondLab_Scientist_Bond_BattlePartnerEevee::
	lock
	faceplayer
	trainerbattle_single TRAINER_BOND_2_PIKACHU, BondLab_Text_BondIntro2, BondLab_Text_BondDefeated2
	setflag FLAG_BOND_DEFEATED_EEVEE
	msgbox BondLab_Text_BondPostBattle2, MSGBOX_AUTOCLOSE
	closemessage
	giveitem ITEM_Z_POWER_RING, 1
	giveitem ITEM_EEVIUM_Z, 1
	setflag FLAG_GOT_Z_RING
	setflag FLAG_RECIEVED_EEVIUM_Z
	release
	end

BondLab_Scientist_Bond_CheckPartnerPikachu::
	lock
	faceplayer
	bufferspeciesname STR_VAR_2, SPECIES_PIKACHU_PARTNER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_le VAR_RESULT, FRIENDSHIP_100_TO_149, BondLab_Scientist_Bond_ComeBackLater
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, BondLab_Scientist_Bond_BattlePartnerPikachu
	release
	end

BondLab_Scientist_Bond_BattlePartnerPikachu::
	lock
	faceplayer
	trainerbattle_single TRAINER_BOND_2_EEVEE, BondLab_Text_BondIntro2, BondLab_Text_BondDefeated2
	setflag FLAG_BOND_DEFEATED_PIKACHU
	msgbox BondLab_Text_BondPostBattle2, MSGBOX_AUTOCLOSE
	closemessage
	giveitem ITEM_Z_POWER_RING, 1
	giveitem ITEM_PIKASHUNIUM_Z, 1
	setflag FLAG_GOT_Z_RING
	setflag FLAG_RECIEVED_PIKASHUNIUM_Z
	release
	end

BondLab_Scientist_Bond_Set_Partner_Front::
	lock
	faceplayer
	msgbox BondLab_Text_SetPartnerFront, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

BondLab_Scientist_Bond_ComeBackLater::
	lock
	faceplayer
	msgbox BondLab_Text_ComeBackLater, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

BondLab_Scientist_Bond_NoPartner::
	lock
	faceplayer
	msgbox BondLab_Text_NoPartner, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

BondLab_Scientist_Bond_TeachPartnerEevee::
	lock
	faceplayer
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_TeachPartner, MSGBOX_DEFAULT
	closemessage
	multichoice 21, 0, MULTI_PARTNER_EEVEE_MOVES, TRUE
	switch VAR_RESULT
	case 0, BondLab_Scientist_Bond_Baddy_Bad
	case 1, BondLab_Scientist_Bond_Bouncy_Bubble
	case 2, BondLab_Scientist_Bond_Buzzy_Buzz
	case 3, BondLab_Scientist_Bond_Freezy_Frost
	case 4, BondLab_Scientist_Bond_Glitzy_Glow
	case 5, BondLab_Scientist_Bond_Sappy_Seed
	case 6, BondLab_Scientist_Bond_Sizzly_Slide
	case 7, BondLab_Scientist_Bond_Veevee_Volley
	case 8, BondLab_Scientist_Bond_TeachingDeclined
	release
	end

BondLab_Scientist_Bond_Baddy_Bad::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_BADDY_BAD
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_BADDY_BAD
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Bouncy_Bubble::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_BOUNCY_BUBBLE
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_BOUNCY_BUBBLE
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Buzzy_Buzz::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_BUZZY_BUZZ
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_BUZZY_BUZZ
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Freezy_Frost::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_FREEZY_FROST
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FREEZY_FROST
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Glitzy_Glow::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_GLITZY_GLOW
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_GLITZY_GLOW
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Sappy_Seed::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_SAPPY_SEED
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SAPPY_SEED
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Sizzly_Slide::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_SIZZLY_SLIDE
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SIZZLY_SLIDE
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Veevee_Volley::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_VEEVEE_VOLLEY
	bufferspeciesname STR_VAR_2, SPECIES_EEVEE_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_VEEVEE_VOLLEY
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_TeachPartnerPikachu::
	lock
	faceplayer
	bufferspeciesname STR_VAR_2, SPECIES_PIKACHU_PARTNER
	msgbox BondLab_Text_TeachPartner, MSGBOX_DEFAULT
	closemessage
	multichoice 21, 0, MULTI_PARTNER_PIKACHU_MOVES, TRUE
	switch VAR_RESULT
	case 0, BondLab_Scientist_Bond_Floaty_Fall
	case 1, BondLab_Scientist_Bond_Pika_Papow
	case 2, BondLab_Scientist_Bond_Splishy_Splash
	case 3, BondLab_Scientist_Bond_Zippy_Zap
	case 4, BondLab_Scientist_Bond_TeachingDeclined
	release
	end

BondLab_Scientist_Bond_Floaty_Fall::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_FLOATY_FALL
	bufferspeciesname STR_VAR_2, SPECIES_PIKACHU_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FLOATY_FALL
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Pika_Papow::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_PIKA_PAPOW
	bufferspeciesname STR_VAR_2, SPECIES_PIKACHU_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_PIKA_PAPOW
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Splishy_Splash::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_SPLISHY_SPLASH
	bufferspeciesname STR_VAR_2, SPECIES_PIKACHU_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SPLISHY_SPLASH
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_Zippy_Zap::
	lock
	faceplayer
	buffermovename STR_VAR_1, MOVE_ZIPPY_ZAP
	bufferspeciesname STR_VAR_2, SPECIES_PIKACHU_PARTNER
	msgbox BondLab_Text_MoveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BondLab_Scientist_Bond_MoveDeclined
	msgbox BondLab_Text_WhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_ZIPPY_ZAP
	call BondLab_Scientist_Bond_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BondLab_Scientist_Bond_MoveDeclined
	goto BondLab_Scientist_Bond_MoveTaught
	end

BondLab_Scientist_Bond_MoveTaught::
	lock
	faceplayer
	msgbox BondLab_Text_MoveTaught, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

BondLab_Scientist_Bond_MoveDeclined::
	lock
	faceplayer
	msgbox BondLab_Text_MoveDeclined, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

BondLab_Scientist_Bond_TeachingDeclined::
	lock
	faceplayer
	msgbox BondLab_Text_TeachingDeclined, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

BondLab_Scientist_Bond_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

BondLab_Scientist1::
	lock
	faceplayer
	msgbox BondLab_Text_Scientist1, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

BondLab_Scientist2::
	msgbox BondLab_Text_Scientist2, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Scientist3::
	msgbox BondLab_Text_Scientist3, MSGBOX_AUTOCLOSE
	closemessage
	end

BondLab_Scientist4::
	lock
	faceplayer
	msgbox BondLab_Text_Scientist4, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

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
	.string "place below the lake here, with my two\p"
	.string "partners here. After funding this small\n"
	.string "group of scientists, we started our\p"
	.string "research on the connections between,\n"
	.string "people, Pokémon, locations,\p"
	.string "and the evolution of Pokémon.$"

BondLab_Text_BondIntro2::
	.string "Watch and learn! I'm going to really\n"
	.string "show you the power of our bonds!$"

BondLab_Text_BondDefeated2::
	.string "Wow... I guess the power of your bonds\n"
	.string "are really strong.$"

BondLab_Text_BondPostBattle2::
	.string "I recently received these from a friend\n"
	.string "who visited the Alola region, they are\p"
	.string "called Z-CRYSTALS. As a reward for\n"
	.string "helping our research, I want you to\p"
	.string "have this Z POWER RING and this\n"
	.string "Z-CRYSTAL for your PARTNER Pokémon.$"

BondLab_Text_BondGift::
	.string "Ah, speaking of bonds.\n"
	.string "There's something I want you to have.\p"
	.string "Over on the table you can pick one.$"

BondLab_Text_BondPostGift::
	.string "If you have your PARTNER Pokémon with\nyou. I can teach it some new moves.$"

BondLab_Text_NoPartner::
	.string "You don't have your PARTNER Pokémon\nwith you?$"

BondLab_Text_TeachPartner::
	.string "Which move do you want to\nteach your PARTNER {STR_VAR_2}?$"

BondLab_Text_MoveTeach::
	.string "Do you want to teach your\nPARTNER {STR_VAR_2} {STR_VAR_1}?$"

BondLab_Text_MoveKnown::
	.string "Your PARTNER {STR_VAR_2} already\nknows {STR_VAR_1}!$"

BondLab_Text_MoveTaught::
	.string "Your PARTNER Pokémon\nhas learned {STR_VAR_2}!$"

BondLab_Text_MoveDeclined::
	.string "You declined to teaching your\nPARTNER {STR_VAR_2} {STR_VAR_1}.$"

BondLab_Text_WhichMon::
	.string "Show me which Pokémon I should teach.$"

BondLab_Text_TeachingDeclined::
	.string "You declined to teaching your\nPARTNER {STR_VAR_2} a new move.$"

BondLab_Text_CheckFriendship::
	.string "Or do you want to check your PARTNER\nPokémon friendship levels?$"

BondLab_Text_PartnerFront::
	.string "Do you have your PARTNER Pokémon at\nthe front of your party?$"

BondLab_Text_SetPartnerFront::
	.string "Please have your PARTNER Pokémon at\nthe front of your party.$"

BondLab_Text_ComeBackLater::
	.string "You and your PARTNER {STR_VAR_2}\nfriendship level isn't high enough.$"
