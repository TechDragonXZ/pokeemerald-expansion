None_MapScripts::
	.byte 0

None_EventScript_BattleBotTest::
	trainerbattle_single TRAINER_TEST, None_Text_TestIntro, None_Text_BattleBotTest_Defeat
	releaseall
	return
	end

None_Text_TestIntro:
	.string "BATTLE-BOT: Starting Battle!$"

None_Text_BattleBotTest_Defeat:
	.string "BATTLE-BOT: Battle Over!$"
