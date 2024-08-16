.set LOCAL_VAR_SPRAY, VAR_0x8004
.set LOCAL_VAR_NUM_SPRAY_STRENGTH, VAR_0x8005
.set LOCAL_VAR_SPRAY_TYPE, VAR_0x8009
.set LOCAL_VAR_NEW_SPRAY, VAR_0x8007

EventScript_BufferSprayName::
.if VAR_LAST_REPEL_LURE_USED != 0
	bufferitemname STR_VAR_1, VAR_LAST_REPEL_LURE_USED
	return
.endif
	specialvar LOCAL_VAR_SPRAY_TYPE, GetLastUsedSprayType
	compare LOCAL_VAR_SPRAY_TYPE, ITEM_REPEL
	goto_if_eq EventScript_BufferSprayName_2
	bufferitemname STR_VAR_1, ITEM_LURE
EventScript_BufferSprayName_1:
	return

EventScript_BufferSprayName_2:
	bufferitemname STR_VAR_1, ITEM_REPEL
	goto EventScript_BufferSprayName_1


EventScript_SprayWoreOff::
	lock
	call EventScript_BufferSprayName
	specialvar LOCAL_VAR_NUM_SPRAY_STRENGTH, GetNumberSprayStrength
	switch LOCAL_VAR_NUM_SPRAY_STRENGTH
	case 0, EventScript_SprayWoreOffMessage
	case 1, EventScript_UseSingleSpray
	goto EventScript_HandleMultipleSprays
	return

EventScript_HandleMultipleSprays::
.if I_REPEL_LURE_MENU == TRUE
	goto EventScript_ChooseWhichSpray
.else
	goto EventScript_UseSingleSpray
.endif
	return


EventScript_SprayWoreOffMessage::
	msgbox Text_SprayWoreOff, MSGBOX_SIGN
	releaseall
	end

Text_RepelWoreOff: @ 82A4B33
	.string "Repel's effect wore off…$"
