
OverworldMon_EventScript_Standard::
	lock
	faceplayer
    callnative GetOverworldMonSpecies
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox OverworldMon_Text_StandardWildMon, MSGBOX_DEFAULT
    closemessage
    startwildoverworldencounter
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, OverworldMon_EventScript_DefeatedMon1
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, OverworldMon_EventScript_DefeatedMon1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, OverworldMon_EventScript_RanFromMon1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, OverworldMon_EventScript_RanFromMon1
	setflag FLAG_TEMP_1
    release
    end
	
OverworldMon_EventScript_Standard2::
	lock
	faceplayer
    callnative GetOverworldMonSpecies
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox OverworldMon_Text_StandardWildMon, MSGBOX_DEFAULT
    closemessage
    startwildoverworldencounter
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, OverworldMon_EventScript_DefeatedMon2
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, OverworldMon_EventScript_DefeatedMon2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, OverworldMon_EventScript_RanFromMon2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, OverworldMon_EventScript_RanFromMon2
	setflag FLAG_TEMP_2
    release
    end
	
OverworldMon_EventScript_Strong::
	random 20
	addvar VAR_RESULT, 15
    lock
	faceplayer
    callnative GetOverworldMonSpecies
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox OverworldMon_Text_StrongWildMon, MSGBOX_DEFAULT
    closemessage
    startoverworldencounter VAR_RESULT
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, OverworldMon_EventScript_DefeatedMon3
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, OverworldMon_EventScript_DefeatedMon3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, OverworldMon_EventScript_RanFromMon3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, OverworldMon_EventScript_RanFromMon3
	setflag FLAG_TEMP_3
    release
    end

OverworldMon_EventScript_DefeatedMon1::
	setflag FLAG_TEMP_1
	goto OverworldMon_EventScript_RemoveMon
	end

OverworldMon_EventScript_RanFromMon1::
	goto OverworldMon_EventScript_MonRanAway
	end

OverworldMon_EventScript_DefeatedMon2::
	setflag FLAG_TEMP_2
	goto OverworldMon_EventScript_RemoveMon
	end

OverworldMon_EventScript_RanFromMon2::
	goto OverworldMon_EventScript_MonRanAway
	end

OverworldMon_EventScript_DefeatedMon3::
	setflag FLAG_TEMP_3
	goto OverworldMon_EventScript_RemoveMon
	end

OverworldMon_EventScript_RanFromMon3::
	goto OverworldMon_EventScript_MonRanAway
	end

OverworldMon_EventScript_RemoveMon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

OverworldMon_EventScript_MonRanAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox OverworldMon_Text_RanFromMon, MSGBOX_DEFAULT
	release
	end

OverworldMon_Text_StandardWildMon:
	.string "It's a wild {STR_VAR_1}!$"

OverworldMon_Text_StrongWildMon:
	.string "It's a strong looking wild {STR_VAR_1}!$"

OverworldMon_Text_RanFromMon::
	.string "The {STR_VAR_1} ran away!$"
