StrangeSpaceDesert_MapScripts::
	.byte 0

StrangeSpaceDesert_ChangeWildMons::
	msgbox StrangeSpaceDesert_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 8, MULTI_WILD_POKEMON_GROUPS, TRUE
	switch VAR_RESULT
	case 3, StrangeSpaceDesert_WalkAway
	case 2, StrangeSpaceDesert_Group3
	case 1, StrangeSpaceDesert_Group2
	case 0, StrangeSpaceDesert_Group1
	end

StrangeSpaceDesert_Group1::
	msgbox StrangeSpaceDesert_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_DESERT_TABLES, 0
	end

StrangeSpaceDesert_Group2::
	msgbox StrangeSpaceDesert_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_DESERT_TABLES, 1
	end

StrangeSpaceDesert_Group3::
	msgbox StrangeSpaceDesert_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_DESERT_TABLES, 2
	end

StrangeSpaceDesert_WalkAway::
	msgbox StrangeSpaceDesert_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpaceDesert_Text_WalkAway::
	.string "You walked away.$"

StrangeSpaceDesert_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpaceDesert_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
