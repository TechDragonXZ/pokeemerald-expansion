StrangeSpace_Chamber_MapScripts::
	.byte 0

StrangeSpace_Chamber_ChangeWildMons::
	msgbox StrangeSpace_Chamber_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 2, MULTI_WILD_POKEMON_GROUPS, TRUE
	switch VAR_RESULT
	case 4, StrangeSpace_Chamber_WalkAway
	case 2, StrangeSpace_Chamber_Group3
	case 1, StrangeSpace_Chamber_Group2
	case 0, StrangeSpace_Chamber_Group1
	end

StrangeSpace_Chamber_Group1::
	msgbox StrangeSpace_Chamber_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_WILD_GROUPS, 0
	end

StrangeSpace_Chamber_Group2::
	msgbox StrangeSpace_Chamber_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_WILD_GROUPS, 1
	end

StrangeSpace_Chamber_Group3::
	msgbox StrangeSpace_Chamber_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_WILD_GROUPS, 2
	end

StrangeSpace_Chamber_Group4::
	msgbox StrangeSpace_Chamber_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_WILD_GROUPS, 3
	end

StrangeSpace_Chamber_Group5::
	msgbox StrangeSpace_Chamber_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_WILD_GROUPS, 4
	end

StrangeSpace_Chamber_Group6::
	msgbox StrangeSpace_Chamber_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_WILD_GROUPS, 5
	end

StrangeSpace_Chamber_WalkAway::
	msgbox StrangeSpace_Chamber_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpace_Chamber_Text_WalkAway::
	.string "You walked away.$"

StrangeSpace_Chamber_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpace_Chamber_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
