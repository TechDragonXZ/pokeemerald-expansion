StrangeSpaceMountain_MapScripts::
	.byte 0

StrangeSpaceMountain_ChangeWildMons::
	msgbox StrangeSpaceMountain_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 2, MULTI_WILD_POKEMON_GROUPS, TRUE
	switch VAR_RESULT
	case 3, StrangeSpaceMountain_WalkAway
	case 2, StrangeSpaceMountain_Group3
	case 1, StrangeSpaceMountain_Group2
	case 0, StrangeSpaceMountain_Group1
	end

StrangeSpaceMountain_Group1::
	msgbox StrangeSpaceMountain_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_MOUNTAIN_TABLES, 0
	end

StrangeSpaceMountain_Group2::
	msgbox StrangeSpaceMountain_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_MOUNTAIN_TABLES, 1
	end

StrangeSpaceMountain_Group3::
	msgbox StrangeSpaceMountain_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_MOUNTAIN_TABLES, 2
	end

StrangeSpaceMountain_WalkAway::
	msgbox StrangeSpaceMountain_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpaceMountain_Text_WalkAway::
	.string "You walked away.$"

StrangeSpaceMountain_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpaceMountain_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
