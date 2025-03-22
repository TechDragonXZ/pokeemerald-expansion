.set LOCALID_OW_MON, 1
.set LOCALID_OW_MON2, 2
.set LOCALID_OW_MON3, 3

Terrarium_East_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terrarium_East_OnTransition
	.byte 0

Terrarium_East_OnTransition:
    setobjectaswildencounter LOCALID_OW_MON, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON2, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON3, ENCOUNTER_LAND
    end

Terrarium_East_EventScript_NoFishingSign::
	msgbox Terrarium_East_Text_NoFishing, MSGBOX_SIGN
	end

Terrarium_East_Text_NoFishing:
	.string "No Fishing Allowed!\n"
	.string "There's no Pokémon!$"
