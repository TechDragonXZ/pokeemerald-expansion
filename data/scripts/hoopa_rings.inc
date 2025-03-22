HoopaRing_EventScript_Interact::
	msgbox HoopaRing_Text_Interacted, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, HoopaRing_EventScript_Touched
	goto_if_eq VAR_RESULT, NO, HoopaRing_EventScript_DontTouch
	end

HoopaRing_EventScript_DontTouch::
	msgbox HoopaRing_Text_DidntTouch, MSGBOX_DEFAULT
	closemessage
	end

HoopaRing_EventScript_Touched::
	switch VAR_CURRENT_MAP
	case MAP_TERRARIUM_ICY_CAVE, HoopaRing_Kyurem

HoopaRing_Kyurem::
	lock
	bufferspeciesname STR_VAR_1, SPECIES_KYUREM
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KYUREM, 40, ITEM_ICE_GEM
	msgbox HoopaRing_Text_SomethingJumpedThrough, MSGBOX_DEFAULT
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	setvar VAR_0x8004, SPECIES_KYUREM
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, HoopaRing_EventScript_DefeatedMon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, HoopaRing_EventScript_RanFromMon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, HoopaRing_EventScript_RanFromMon
	release
	end

HoopaRing_EventScript_DefeatedMon::
	goto Common_EventScript_RemoveStaticPokemon
	end

HoopaRing_EventScript_RanFromMon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox HoopaRing_Text_WentBackThrough, MSGBOX_DEFAULT
	release
	end

HoopaRing_Text_Interacted::
	.string "It's a strange ring\n"
	.string "Do you want to touch it?$"

HoopaRing_Text_SomethingJumpedThrough::
	.string "You reached out to the ring…\n"
	.string "A {STR_VAR_1} jumped through!$"

HoopaRing_Text_DidntTouch::
	.string "You decided not to touch it.$"

HoopaRing_Text_WentBackThrough::
	.string "The {STR_VAR_1} went back through!$"
