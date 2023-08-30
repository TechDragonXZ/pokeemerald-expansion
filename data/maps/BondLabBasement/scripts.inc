BondLabBasement_MapScripts::
	.byte 0

BondLabBasement_OldMachineTower::
	msgbox BondLabBasement_Text_OldMachineTower MSGBOX_DEFAULT
	closemessage
	end

BondLabBasement_Bed::
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox BondLabBasement_Text_Heal MSGBOX_DEFAULT
	closemessage
	end

BondLabBasement_OldMachine::
	msgbox BondLabBasement_Text_OldMachine MSGBOX_DEFAULT
	closemessage
	multichoice 21, 8, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 1, BondLabBasement_WalkAway
	case 0, BondLabBasement_PoweredOn
	end

BondLabBasement_PoweredOn::
	msgbox BondLabBasement_Text_Warp MSGBOX_DEFAULT
	closemessage
	delay 30
	warpteleport MAP_STRANGE_SPACE, 10, 14
	end

BondLabBasement_WalkAway::
	msgbox BondLabBasement_Text_WalkAway MSGBOX_DEFAULT
	closemessage
	end

BondLabBasement_Lights::
	setflashlevel 0
	msgbox BondLabBasement_Text_Lights MSGBOX_DEFAULT
	closemessage
	end

BondLabBasement_Text_WalkAway::
	.string "You walked away.$"

BondLabBasement_Text_Lights::
	.string "The room lit up!$"

BondLabBasement_Text_Warp::
	.string "The room went pitch black!$"

BondLabBasement_Text_OldMachineTower::
	.string "It's connected to the machine.$"

BondLabBasement_Text_OldMachine::
	.string "It's an old super computer.\n"
	.string "There's still power, turn it on?$"

BondLabBasement_Text_Heal::
	.string "Your Pokémon were healed!$"

