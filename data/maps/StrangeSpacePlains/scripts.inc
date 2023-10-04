
StrangeSpacePlains_MapScripts::
	.byte 0

StrangeSpacePlains_ChangeWildMons::
	msgbox StrangeSpacePlains_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 2, MULTI_WILD_POKEMON_GROUPS_SIX, TRUE
	switch VAR_RESULT
	case 6, StrangeSpacePlains_WalkAway
	case 5, StrangeSpacePlains_Group6
	case 4, StrangeSpacePlains_Group5
	case 3, StrangeSpacePlains_Group4
	case 2, StrangeSpacePlains_Group3
	case 1, StrangeSpacePlains_Group2
	case 0, StrangeSpacePlains_Group1
	end

StrangeSpacePlains_Group1::
	msgbox StrangeSpacePlains_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_PLAINS_TABLES, 0
	end

StrangeSpacePlains_Group2::
	msgbox StrangeSpacePlains_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_PLAINS_TABLES, 1
	end

StrangeSpacePlains_Group3::
	msgbox StrangeSpacePlains_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_PLAINS_TABLES, 2
	end

StrangeSpacePlains_Group4::
	msgbox StrangeSpacePlains_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_PLAINS_TABLES, 3
	end

StrangeSpacePlains_Group5::
	msgbox StrangeSpacePlains_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_PLAINS_TABLES, 4
	end

StrangeSpacePlains_Group6::
	msgbox StrangeSpacePlains_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_PLAINS_TABLES, 5
	end

StrangeSpacePlains_WalkAway::
	msgbox StrangeSpacePlains_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpacePlains_Text_WalkAway::
	.string "You walked away.$"

StrangeSpacePlains_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpacePlains_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
