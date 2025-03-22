.set LOCALID_OW_MON, 1
.set LOCALID_OW_MON2, 2
.set LOCALID_OW_MON3, 3

Terrarium_NorthWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terrarium_NorthWest_OnTransition
	.byte 0

Terrarium_NorthWest_OnTransition:
    setobjectaswildencounter LOCALID_OW_MON, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON2, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON3, ENCOUNTER_SURF
    end
