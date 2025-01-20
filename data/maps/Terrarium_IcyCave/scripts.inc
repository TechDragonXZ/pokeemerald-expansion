Terrarium_IcyCave_MapScripts::
	.byte 0

Terrarium_IcyCave_EventScript_UltraWormhole::
	msgbox Terrarium_IcyCave_Text_UltraWormhole, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Terrarium_IcyCave_EventScript_GoThrough_UltraWormhole
	goto_if_eq VAR_RESULT, NO, Terrarium_IcyCave_EventScript_DontGoThrough_UltraWormhole
	end

Terrarium_IcyCave_EventScript_GoThrough_UltraWormhole::
	warpspinenter MAP_DISTORTION_WORLD, 28, 28
	end

Terrarium_IcyCave_EventScript_DontGoThrough_UltraWormhole::
	msgbox Terrarium_IcyCave_Text_DidntEnterUltraWormhole, MSGBOX_DEFAULT
	closemessage
	end

Terrarium_IcyCave_Text_UltraWormhole::
	.string "It's a strange wormhole.\n"
	.string "Do you want to go through?$"

Terrarium_IcyCave_Text_DidntEnterUltraWormhole::
	.string "You decided not to go through.$"

Terrarium_IcyCave_EventScript_HoopaRing::
	msgbox Terrarium_IcyCave_Text_HoopaRing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Terrarium_IcyCave_EventScript_Touch_HoopaRing
	goto_if_eq VAR_RESULT, NO, Terrarium_IcyCave_EventScript_DontTouch_HoopaRing
	end

Terrarium_IcyCave_EventScript_Touch_HoopaRing::
	bufferspeciesname STR_VAR_1, SPECIES_KYUREM
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KYUREM, 40
	msgbox Terrarium_IcyCave_Text_SomethingJumpsThrough, MSGBOX_DEFAULT
	waitmessage
	dowildbattle
	end

Terrarium_IcyCave_EventScript_DontTouch_HoopaRing::
	msgbox Terrarium_IcyCave_Text_DidntTouchHoopaRing, MSGBOX_DEFAULT
	closemessage
	end

Terrarium_IcyCave_Text_HoopaRing::
	.string "It's a strange ring\n"
	.string "Do you want to touch it?$"

Terrarium_IcyCave_Text_SomethingJumpsThrough::
	.string "A {STR_VAR_1} jumped through!$"

Terrarium_IcyCave_Text_DidntTouchHoopaRing::
	.string "You decided not to touch it.$"
