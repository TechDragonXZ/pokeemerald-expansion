StrangeSpace_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, StrangeSpace_Entrance_OnTransition
	.byte 0

StrangeSpace_Entrance_OnTransition::
	clearflag FLAG_DYNAMAX_BATTLE
	end
