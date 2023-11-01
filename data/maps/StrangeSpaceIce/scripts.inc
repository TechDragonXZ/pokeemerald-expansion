StrangeSpaceIce_MapScripts::
	.byte 0

StrangeSpaceIce_ChangeWildMons::
	msgbox StrangeSpaceIce_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 8, MULTI_WILD_POKEMON_GROUPS_TWO, TRUE
	switch VAR_RESULT
	case 2, StrangeSpaceIce_WalkAway
	case 1, StrangeSpaceIce_Group2
	case 0, StrangeSpaceIce_Group1
	end

StrangeSpaceIce_Group1::
	msgbox StrangeSpaceIce_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_ICE_TABLES, 0
	end

StrangeSpaceIce_Group2::
	msgbox StrangeSpaceIce_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_ICE_TABLES, 1
	end

StrangeSpaceIce_WalkAway::
	msgbox StrangeSpaceIce_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpaceIce_Text_WalkAway::
	.string "You walked away.$"

StrangeSpaceIce_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpaceIce_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
