MeteorFalls_Peak_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_Peak_Visited
	.byte 0

MeteorFalls_Peak_DeoxysFormChange::
	call ChangeDeoxysForm
	end

MeteorFalls_Peak_Visited::
	setflag FLAG_VISITED_METEOR_FALLS_PEAK
	end
