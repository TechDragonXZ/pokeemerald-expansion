StrangeSpaceVolcano_MapScripts::
	.byte 0

StrangeSpaceVolcano_ChangeWildMons::
	msgbox StrangeSpaceVolcano_Text_ChangeWildMons, MSGBOX_DEFAULT
	closemessage
	multichoice 18, 8, MULTI_WILD_POKEMON_GROUPS, TRUE
	switch VAR_RESULT
	case 3, StrangeSpaceVolcano_WalkAway
	case 2, StrangeSpaceVolcano_Group3
	case 1, StrangeSpaceVolcano_Group2
	case 0, StrangeSpaceVolcano_Group1
	end

StrangeSpaceVolcano_Group1::
	msgbox StrangeSpaceVolcano_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_VOLCANO_TABLES, 0
	end

StrangeSpaceVolcano_Group2::
	msgbox StrangeSpaceVolcano_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_VOLCANO_TABLES, 1
	end

StrangeSpaceVolcano_Group3::
	msgbox StrangeSpaceVolcano_Text_Changed, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STRANGE_SPACE_VOLCANO_TABLES, 2
	end

StrangeSpaceVolcano_WalkAway::
	msgbox StrangeSpaceVolcano_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpaceVolcano_Text_WalkAway::
	.string "You walked away.$"

StrangeSpaceVolcano_Text_Changed::
	.string "Several different types of Pokémon\n"
	.string "have appeared in the surrounding area!$"

StrangeSpaceVolcano_Text_ChangeWildMons::
	.string "This sign says that the species of wild\n"
	.string "Pokémon that can be found here can be\p"
	.string "changed. Do you want to change it?$"
