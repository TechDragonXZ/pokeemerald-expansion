StrangeSpaceForest_MapScripts::
	.byte 0

StrangeSpaceForest_ChangeWildMons::
	msgbox StrangeSpaceForest_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 2, MULTI_WILD_POKEMON_GROUPS, TRUE
	switch VAR_RESULT
	case 3, StrangeSpaceForest_WalkAway
	case 2, StrangeSpaceForest_Group3
	case 1, StrangeSpaceForest_Group2
	case 0, StrangeSpaceForest_Group1
	end

StrangeSpaceForest_Group1::
	msgbox StrangeSpaceForest_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_FOREST_TABLES, 0
	end

StrangeSpaceForest_Group2::
	msgbox StrangeSpaceForest_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_FOREST_TABLES, 1
	end

StrangeSpaceForest_Group3::
	msgbox StrangeSpaceForest_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_FOREST_TABLES, 2
	end

StrangeSpaceForest_WalkAway::
	msgbox StrangeSpaceForest_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpaceForest_Text_WalkAway::
	.string "You walked away.$"

StrangeSpaceForest_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpaceForest_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
