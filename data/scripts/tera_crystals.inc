TeraCrystals_EventScript_Interact::
	lock
	faceplayer
	msgbox TeraCrystals_Text_Battle, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, TeraCrystals_EventScript_Declined
	case YES, TeraCrystals_EventScript_Accepted
	case MULTI_B_PRESSED, TeraCrystals_EventScript_Declined
	release
	end

TeraCrystals_EventScript_Declined::
	msgbox TeraCrystals_Text_Declined, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

TeraCrystals_EventScript_Accepted::
	msgbox TeraCrystals_Text_Accepted, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

TeraCrystals_Text_Battle::
	.string "It's a strange glowing crystal,\n"
	.string "there seems to be a Pokémon inside.\p"
	.string "Do you want to battle it?$"

TeraCrystals_Text_Accepted::
	.string "Tera Crystal Battles not available yet.$"

TeraCrystals_Text_Declined::
	.string "You decided not to battle it.$"
