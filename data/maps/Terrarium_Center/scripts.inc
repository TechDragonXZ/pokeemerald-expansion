.set LOCALID_OW_MON, 1
.set LOCALID_OW_MON2, 2

Terrarium_Center_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terrarium_Center_OnTransition
	.byte 0

Terrarium_Center_OnTransition:
    setobjectaswildencounter LOCALID_OW_MON, ENCOUNTER_RARE
    setobjectaswildencounter LOCALID_OW_MON2, ENCOUNTER_RARE
    end

Terrarium_Center_EventScript_RareMon::
	random 10
    lock
	faceplayer
    callnative GetOverworldMonSpecies
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox OverworldMon_Text_StandardWildMon, MSGBOX_DEFAULT
    closemessage
    startoverworldencounter VAR_RESULT
    release
    end
	
Terrarium_Center_EventScript_StrongRareMon::
	random 10
	addvar VAR_RESULT, 10
    lock
	faceplayer
    callnative GetOverworldMonSpecies
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox OverworldMon_Text_StrongWildMon, MSGBOX_DEFAULT
    closemessage
    startoverworldencounter VAR_RESULT
    release
    end