StrangeSpaceVoid_MapScripts::
	.byte 0

StrangeSpaceVoid_ChangeWildMons::
	msgbox StrangeSpaceVoid_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 2, MULTI_WILD_POKEMON_GROUPS, TRUE
	switch VAR_RESULT
	case 3, StrangeSpaceVoid_WalkAway
	case 2, StrangeSpaceVoid_Group3
	case 1, StrangeSpaceVoid_Group2
	case 0, StrangeSpaceVoid_Group1
	end

StrangeSpaceVoid_Group1::
	msgbox StrangeSpaceVoid_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_VOID_TABLES, 0
	end

StrangeSpaceVoid_Group2::
	msgbox StrangeSpaceVoid_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_VOID_TABLES, 1
	end

StrangeSpaceVoid_Group3::
	msgbox StrangeSpaceVoid_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_VOID_TABLES, 2
	end

StrangeSpaceVoid_WalkAway::
	msgbox StrangeSpaceVoid_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpaceVoid_Text_WalkAway::
	.string "You walked away.$"

StrangeSpaceVoid_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpaceVoid_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
