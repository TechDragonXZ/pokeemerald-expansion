RangerBase_MapScripts::
	.byte 0

RangerBase_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RANGER_BASE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
