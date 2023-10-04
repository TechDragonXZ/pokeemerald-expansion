StrangeSpaceLake_MapScripts::
	.byte 0

StrangeSpaceLake_ChangeWildMons::
	msgbox StrangeSpaceLake_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 2, MULTI_WILD_POKEMON_GROUPS, TRUE
	switch VAR_RESULT
	case 3, StrangeSpaceLake_WalkAway
	case 2, StrangeSpaceLake_Group3
	case 1, StrangeSpaceLake_Group2
	case 0, StrangeSpaceLake_Group1
	end

StrangeSpaceLake_Group1::
	msgbox StrangeSpaceLake_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_LAKE_TABLES, 0
	end

StrangeSpaceLake_Group2::
	msgbox StrangeSpaceLake_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_LAKE_TABLES, 1
	end

StrangeSpaceLake_Group3::
	msgbox StrangeSpaceLake_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_LAKE_TABLES, 2
	end

StrangeSpaceLake_WalkAway::
	msgbox StrangeSpaceLake_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpaceLake_Text_WalkAway::
	.string "You walked away.$"

StrangeSpaceLake_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpaceLake_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
