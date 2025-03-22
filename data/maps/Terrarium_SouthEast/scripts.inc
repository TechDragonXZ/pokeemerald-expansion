.set LOCALID_OW_MON, 1
.set LOCALID_OW_MON2, 2
.set LOCALID_OW_MON3, 3

Terrarium_SouthEast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terrarium_SouthEast_OnTransition
	.byte 0

Terrarium_SouthEast_OnTransition:
    setobjectaswildencounter LOCALID_OW_MON, ENCOUNTER_SURF
    setobjectaswildencounter LOCALID_OW_MON2, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON3, ENCOUNTER_LAND
    end
