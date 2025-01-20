UltraWormhole_EventScript_Interact::
	msgbox UltraWormhole_Text_Interacted, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UltraWormhole_EventScript_GoThrough
	goto_if_eq VAR_RESULT, NO, UltraWormhole_EventScript_DontGoThrough
	end

UltraWormhole_EventScript_GoThrough::
	switch VAR_CURRENT_MAP
	case MAP_DISTORTION_WORLD, DistortionWorld_Exit
	case MAP_TERRARIUM_ICY_CAVE, DistortionWorld_Enter

DistortionWorld_Enter::
	warpspinenter MAP_DISTORTION_WORLD, 28, 28
	end

DistortionWorld_Exit::
	warpspinenter MAP_TERRARIUM_ICY_CAVE, 58, 31
	end

UltraWormhole_EventScript_DontGoThrough::
	msgbox UltraWormhole_Text_DidntEnter, MSGBOX_DEFAULT
	closemessage
	end

UltraWormhole_Text_Interacted::
	.string "It's a strange wormhole.\n"
	.string "Do you want to go through?$"

UltraWormhole_Text_DidntEnter::
	.string "You decided not to go through?$"
