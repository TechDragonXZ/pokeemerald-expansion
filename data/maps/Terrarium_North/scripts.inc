.set LOCALID_OW_MON, 1
.set LOCALID_OW_MON2, 2
.set LOCALID_OW_MON3, 3

Terrarium_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terrarium_North_OnTransition
	.byte 0

Terrarium_North_OnTransition:
    setobjectaswildencounter LOCALID_OW_MON, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON2, ENCOUNTER_LAND
    setobjectaswildencounter LOCALID_OW_MON3, ENCOUNTER_LAND
    end
