StrangeSpaceCave_MapScripts::
	.byte 0

StrangeSpaceCave_ChangeWildMons::
	msgbox StrangeSpaceCave_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 8, MULTI_WILD_POKEMON_GROUPS_TWO, TRUE
	switch VAR_RESULT
	case 2, StrangeSpaceCave_WalkAway
	case 1, StrangeSpaceCave_Group2
	case 0, StrangeSpaceCave_Group1
	end

StrangeSpaceCave_Group1::
	msgbox StrangeSpaceCave_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_CAVE_TABLES, 0
	end

StrangeSpaceCave_Group2::
	msgbox StrangeSpaceCave_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_CAVE_TABLES, 1
	end

StrangeSpaceCave_WalkAway::
	msgbox StrangeSpaceCave_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpaceCave_Text_WalkAway::
	.string "You walked away.$"

StrangeSpaceCave_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpaceCave_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
