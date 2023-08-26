MysteriousHouse_MapScripts::
	.byte 0

MysteriousHouse_DailyPC0::
	goto_if_set FLAG_ROTOM_PC0_USED, MysteriousHouse_RotomPC0
	goto_if_unset FLAG_ROTOM_PC0_USED, MysteriousHouse_NoRotomPC

MysteriousHouse_DailyPC1::
	goto_if_set FLAG_ROTOM_PC1_USED, MysteriousHouse_RotomPC1
	goto_if_unset FLAG_ROTOM_PC1_USED, MysteriousHouse_NoRotomPC

MysteriousHouse_RotomPC0::
	msgbox MysteriousHouse_Text_RotomPC, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_ROTOM, 20, ITEM_MAGNET, SPECIES_NONE
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 2, 0, 0, 0
	setflag FLAG_ROTOM_PC0_USED
	dowildbattle
	end

MysteriousHouse_RotomPC1::
	msgbox MysteriousHouse_Text_RotomPC, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_ROTOM, 20, ITEM_MAGNET, SPECIES_NONE
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 2, 0, 0, 0
	setflag FLAG_ROTOM_PC1_USED
	dowildbattle
	end

MysteriousHouse_NoRotomPC::
	msgbox MysteriousHouse_Text_NoRotomPC, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_Scientist_Bond::
	trainerbattle_single TRAINER_BOND, MysteriousHouse_Text_BondIntro, MysteriousHouse_Text_BondDefeated
	msgbox MysteriousHouse_Text_BondPostBattle, MSGBOX_AUTOCLOSE
	delay 50
	msgbox MysteriousHouse_Text_BondGift, MSGBOX_AUTOCLOSE
	givemon SPECIES_PIKACHU_PARTNER, 5, ITEM_PIKANIUM_Z
	delay 50
	givemon SPECIES_EEVEE_PARTNER, 5, ITEM_EEVIUM_Z
	end

MysteriousHouse_Scientist1::
	msgbox MysteriousHouse_Text_Scientist1, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_Scientist2::
	msgbox MysteriousHouse_Text_Scientist2, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_Scientist3::
	msgbox MysteriousHouse_Text_Scientist3, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_Scientist4::
	msgbox MysteriousHouse_Text_Scientist4, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_RotomBox::
	msgbox MysteriousHouse_Text_RotomBox, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_Paper::
	msgbox MysteriousHouse_Text_Paper, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_BrokenPC::
	msgbox MysteriousHouse_Text_BrokenPC, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_Books::
	msgbox MysteriousHouse_Text_Books, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_Machine::
	msgbox MysteriousHouse_Text_Machine, MSGBOX_AUTOCLOSE
	end

MysteriousHouse_Text_NoRotomPC::
	.string "There's nothing here.$"

MysteriousHouse_Text_RotomPC::
	.string "There's something here!$"

MysteriousHouse_Text_RotomBox::
	.string "This box is full of motors!$"

MysteriousHouse_Text_Machine::
	.string "A strange machine!$"

MysteriousHouse_Text_BrokenPC::
	.string "The computer seems broken.$"

MysteriousHouse_Text_Books::
	.string "A stack of complicated books.$"

MysteriousHouse_Text_Scientist1::
	.string "We were recently given\n"
	.string "the funds for this project\p"
	.string "by the guy over there.\p"
	.string "Other than that I can't\n"
	.string "tell you much of what we\p"
	.string "found yet.$"

MysteriousHouse_Text_Scientist2::
	.string "He seems to be busy.$"

MysteriousHouse_Text_Scientist3::
	.string "He seems to be trying\n"
	.string "to fix the computer.$"

MysteriousHouse_Text_Scientist4::
	.string "Do you have a Rotom?\n"
	.string "If so, have it look\p"
	.string "in this box here.\n"
	.string "It might want something.$"

MysteriousHouse_Text_Paper::
	.string "A scrap of paper.$"

MysteriousHouse_Text_BondIntro::
	.string "W-W-W-Wha... H-How\n"
	.string "did you get in?\p"
	.string "No matter, time to see\n"
	.string "the results of my research$"

MysteriousHouse_Text_BondDefeated::
	.string "Wow... I guess there\n"
	.string "realy are different\p"
	.string "kinds of bonds?$"

MysteriousHouse_Text_BondPostBattle::
	.string "I recently discovered this\n"
	.string "place with my two partners.\p"
	.string "It makes for an really\n"
	.string "great training area.$"

MysteriousHouse_Text_BondGift::
	.string "Ah, my partners have\n"
	.string "something they want me\p"
	.string "to give to you.$"

