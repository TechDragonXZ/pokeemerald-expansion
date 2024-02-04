DeepPetalburgWoods_Pond_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DeepPetalburgWoods_Pond_OnTransition
	.byte 0

DeepPetalburgWoods_Pond_OnTransition::
	setflag FLAG_DYNAMAX_BATTLE
	end

DeepPetalburgWoods_Pond_Person_Plans::
	lockall
	faceplayer
	msgbox DeepPetalburgWoods_Pond_Text_Plans, MSGBOX_DEFAULT
	releaseall
	end

DeepPetalburgWoods_Pond_Text_Plans:
	.string "We are currently in the process of\nbuilding an research center for the\pDynamax phenonmom that has spread\nfrom the Galar region to the Hoenn\pregion. This location is the result of\nthe spread. As such Pokémon may\pDynamax here.$"
