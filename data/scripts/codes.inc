EventScript_CodePad::
    lockall
    msgbox CodePad_Welcome_Text, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, CodePad_Exit
	case YES, CodePad_EnterCode
	case MULTI_B_PRESSED, CodePad_Exit
	closemessage
	releaseall
	end

CodePad_FirstTime::
    lockall
    msgbox CodePad_FirstTime_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
	return
	releaseall
	end

CodePad_EnterCode::
    lockall
    special EnterCode
    waitstate
    special GetCodeFeedback
    goto_if_eq VAR_RESULT, 0, CodePad_CodeFailed
    goto_if_eq VAR_RESULT, 1, CodePad_OriginalCapPikachu
    goto_if_eq VAR_RESULT, 2, CodePad_HoennCapPikachu
    goto_if_eq VAR_RESULT, 3, CodePad_SinnohCapPikachu
    goto_if_eq VAR_RESULT, 4, CodePad_UnovaCapPikachu
    goto_if_eq VAR_RESULT, 5, CodePad_KalosCapPikachu
    goto_if_eq VAR_RESULT, 6, CodePad_AlolaCapPikachu
    goto_if_eq VAR_RESULT, 7, CodePad_PartnerCapPikachu
    goto_if_eq VAR_RESULT, 8, CodePad_WorldCapPikachu
    goto_if_eq VAR_RESULT, 9, CodePad_EonTicket
    goto_if_eq VAR_RESULT, 10, CodePad_AuroraTicket
    goto_if_eq VAR_RESULT, 11, CodePad_MysticTicket
    goto_if_eq VAR_RESULT, 12, CodePad_OldSeaMap
	releaseall
    end

CodePad_Exit::
    lockall
    msgbox CodePad_ComeAgain_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
    releaseall
    end

CodePad_CodeFailed::
    lockall
    msgbox CodePad_Failed_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
    releaseall
    end

CodePad_OriginalCapPikachu::
	goto_if_set FLAG_ORIGINAL_CAP_OBTAINED, CodePad_OriginalCapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_OriginalCapPikachu_Text, MSGBOX_DEFAULT
	givemon SPECIES_PIKACHU_ORIGINAL, 25, ITEM_LIGHT_BALL, ITEM_STRANGE_BALL, NATURE_HARDY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_QUICK_ATTACK, FALSE, FALSE, TYPE_ELECTRIC, 0
	setflag FLAG_ORIGINAL_CAP_OBTAINED
	waitmessage
	closemessage
    releaseall
    end

CodePad_HoennCapPikachu::
	goto_if_set FLAG_HOENN_CAP_OBTAINED, CodePad_HoennCapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_HoennCapPikachu_Text, MSGBOX_DEFAULT
	givemon SPECIES_PIKACHU_HOENN, 25, ITEM_LIGHT_BALL, ITEM_STRANGE_BALL, NATURE_HARDY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_QUICK_ATTACK, FALSE, FALSE, TYPE_ELECTRIC, 0
	setflag FLAG_HOENN_CAP_OBTAINED
	waitmessage
	closemessage
    releaseall
    end

CodePad_SinnohCapPikachu::
	goto_if_set FLAG_SINNOH_CAP_OBTAINED, CodePad_SinnohCapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_SinnohCapPikachu_Text, MSGBOX_DEFAULT
	givemon SPECIES_PIKACHU_SINNOH, 25, ITEM_LIGHT_BALL, ITEM_STRANGE_BALL, NATURE_HARDY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_QUICK_ATTACK, FALSE, FALSE, TYPE_ELECTRIC, 0
	setflag FLAG_SINNOH_CAP_OBTAINED
	waitmessage
	closemessage
    releaseall
    end

CodePad_UnovaCapPikachu::
	goto_if_set FLAG_UNOVA_CAP_OBTAINED, CodePad_UnovaCapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_UnovaCapPikachu_Text, MSGBOX_DEFAULT
	givemon SPECIES_PIKACHU_UNOVA, 25, ITEM_LIGHT_BALL, ITEM_STRANGE_BALL, NATURE_HARDY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_QUICK_ATTACK, FALSE, FALSE, TYPE_ELECTRIC, 0
	setflag FLAG_UNOVA_CAP_OBTAINED
	waitmessage
	closemessage
    releaseall
    end

CodePad_KalosCapPikachu::
	goto_if_set FLAG_KALOS_CAP_OBTAINED, CodePad_KalosCapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_KalosCapPikachu_Text, MSGBOX_DEFAULT
	givemon SPECIES_PIKACHU_KALOS, 25, ITEM_LIGHT_BALL, ITEM_STRANGE_BALL, NATURE_HARDY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_QUICK_ATTACK, FALSE, FALSE, TYPE_ELECTRIC, 0
	setflag FLAG_KALOS_CAP_OBTAINED
	waitmessage
	closemessage
    releaseall
    end

CodePad_AlolaCapPikachu::
	goto_if_set FLAG_ALOLA_CAP_OBTAINED, CodePad_AlolaCapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_AlolaCapPikachu_Text, MSGBOX_DEFAULT
	givemon SPECIES_PIKACHU_ALOLA, 25, ITEM_PIKASHUNIUM_Z, ITEM_STRANGE_BALL, NATURE_HARDY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_QUICK_ATTACK, FALSE, FALSE, TYPE_ELECTRIC, 0
	setflag FLAG_ALOLA_CAP_OBTAINED
	waitmessage
	closemessage
    releaseall
    end

CodePad_PartnerCapPikachu::
	goto_if_set FLAG_PARTNER_CAP_OBTAINED, CodePad_PartnerCapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_PartnerCapPikachu_Text, MSGBOX_DEFAULT
	givemon SPECIES_PIKACHU_PARTNER, 25, ITEM_LIGHT_BALL, ITEM_STRANGE_BALL, NATURE_HARDY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_QUICK_ATTACK, FALSE, FALSE, TYPE_ELECTRIC, 0
	setflag FLAG_PARTNER_CAP_OBTAINED
	waitmessage
	closemessage
    releaseall
    end

CodePad_WorldCapPikachu::
	goto_if_set FLAG_WORLD_CAP_OBTAINED, CodePad_WorldCapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_WorldCapPikachu_Text, MSGBOX_DEFAULT
	givemon SPECIES_PIKACHU_WORLD, 25, ITEM_LIGHT_BALL, ITEM_STRANGE_BALL, NATURE_HARDY, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_TACKLE, MOVE_IRON_TAIL, MOVE_QUICK_ATTACK, FALSE, FALSE, TYPE_ELECTRIC, 0
	setflag FLAG_WORLD_CAP_OBTAINED
	waitmessage
	closemessage
    releaseall
    end

CodePad_EonTicket::
	goto_if_set FLAG_EON_TICKET_OBTAINED, CodePad_EonTicketCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_SpecialItem_Text, MSGBOX_DEFAULT
	call MysteryGiftScript_EonTicket
	waitmessage
	closemessage
    releaseall
    end

CodePad_AuroraTicket::
	goto_if_set FLAG_AURORA_TICKET_OBTAINED, CodePad_AuroraTicketCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_SpecialItem_Text, MSGBOX_DEFAULT
	call MysteryGiftScript_AuroraTicket
	waitmessage
	closemessage
    releaseall
    end

CodePad_MysticTicket::
	goto_if_set FLAG_MYSTIC_TICKET_OBTAINED, CodePad_MysticTicketCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_SpecialItem_Text, MSGBOX_DEFAULT
	call MysteryGiftScript_MysticTicket
	waitmessage
	closemessage
    releaseall
    end

CodePad_OldSeaMap::
	goto_if_set FLAG_OLD_SEA_MAP_OBTAINED, CodePad_OldSeaMapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodePad_Succeeded_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodePad_SpecialItem_Text, MSGBOX_DEFAULT
	call MysteryGiftScript_OldSeaMap
	waitmessage
	closemessage
    releaseall
    end

CodePad_Welcome_Text:
    .string "Welcome to the Mystery Codes Counter.\n"
    .string "Would you like to enter a code?$"

CodePad_ComeAgain_Text:
    .string "Alright, you're welcome to come back\n"
    .string "when you're ready to enter a code.$"

CodePad_FirstTime_Text:
    .string "Welcome, is this your first time here at\n"
    .string "the Mystery Codes Counter?\p"
    .string "All first-time users receive this\n"
    .string "Code Logger. Which allows you to view\p"
    .string "both used and unused codes.$"

CodePad_Failed_Text:
    .string "...nothing happened.$"

CodePad_Succeeded_Text:
    .string "The code worked!$"

CodePad_OriginalCapPikachu_Text:
    .string "It's a Special Pikachu!\n"
	.string "It's wearing an Original Cap!$"

CodePad_HoennCapPikachu_Text:
    .string "It's a Special Pikachu!\n"
	.string "It's wearing an Hoenn Cap!$"

CodePad_SinnohCapPikachu_Text:
    .string "It's a Special Pikachu!\n"
	.string "It's wearing an Sinnoh Cap!$"

CodePad_UnovaCapPikachu_Text:
    .string "It's a Special Pikachu!\n"
	.string "It's wearing an Unova Cap!$"

CodePad_KalosCapPikachu_Text:
    .string "It's a Special Pikachu!\n"
	.string "It's wearing an Kalos Cap!$"

CodePad_AlolaCapPikachu_Text:
    .string "It's a Special Pikachu!\n"
	.string "It's wearing an Alola Cap!$"

CodePad_PartnerCapPikachu_Text:
    .string "It's a Special Pikachu!\n"
	.string "It's wearing an Partner Cap!$"

CodePad_WorldCapPikachu_Text:
    .string "It's a Special Pikachu!\n"
	.string "It's wearing an World Cap!$"

CodePad_SpecialItem_Text:
    .string "It's a Special Item!$"

CodePad_OriginalCapDesc_Text:
    .string "This code was for a Special Pikachu!\n"
	.string "Which was wearing an Original Cap!$"

CodePad_HoennCapDesc_Text:
    .string "This code was for a Special Pikachu!\n"
	.string "Which was wearing a Hoenn Cap!$"

CodePad_SinnohCapDesc_Text:
    .string "This code was for a Special Pikachu!\n"
	.string "Which was wearing a Sinnoh Cap!$"

CodePad_UnovaCapDesc_Text:
    .string "This code was for a Special Pikachu!\n"
	.string "Which was wearing an Unova Cap!$"

CodePad_KalosCapDesc_Text:
    .string "This code was for a Special Pikachu!\n"
	.string "Which was wearing a Kalos Cap!$"

CodePad_AlolaCapDesc_Text:
    .string "This code was for a Special Pikachu!\n"
	.string "Which was wearing an Alola Cap!$"

CodePad_PartnerCapDesc_Text:
    .string "This code was for a Special Pikachu!\n"
	.string "Which was wearing a Partner Cap!$"

CodePad_WorldCapDesc_Text:
    .string "This code was for a Special Pikachu!\n"
	.string "Which was wearing a World Cap!$"

CodePad_GenItemDesc_Text:
    .string "This code was for the {STR_VAR_1}!$"

CodePad_GenMonDesc_Text:
    .string "This code was for a Special {STR_VAR_1}!$"

CodePad_OriginalCapCode::
	msgbox CodePad_OriginalCapDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_HoennCapCode::
	msgbox CodePad_HoennCapDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_SinnohCapCode::
	msgbox CodePad_SinnohCapDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_UnovaCapCode::
	msgbox CodePad_UnovaCapDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_KalosCapCode::
	msgbox CodePad_KalosCapDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_AlolaCapCode::
	msgbox CodePad_AlolaCapDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_PartnerCapCode::
	msgbox CodePad_PartnerCapDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_WorldCapCode::
	msgbox CodePad_WorldCapDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_EonTicketCode::
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	msgbox CodePad_GenItemDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_AuroraTicketCode::
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	msgbox CodePad_GenItemDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_MysticTicketCode::
	bufferitemname STR_VAR_1, ITEM_MYSTIC_TICKET
	msgbox CodePad_GenItemDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodePad_OldSeaMapCode::
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	msgbox CodePad_GenItemDesc_Text, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end
