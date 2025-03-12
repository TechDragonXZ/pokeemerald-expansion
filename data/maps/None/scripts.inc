None_MapScripts::
	.byte 0

None_EventScripts_SendHome::
	warp MAP_LITTLEROOT_TOWN, 10, 10
	end

None_EventScripts_BattleBot::
	trainerbattle_no_intro TRAINER_BATTLEBOT, None_Text_BattleBot_Lose
	end

None_Text_BattleBot_Lose::
	.string "I lost!$"
