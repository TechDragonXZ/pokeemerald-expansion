FollowingNPCs_EventScript_Follower::
	lock
	faceplayer
	msgbox FollowingNPCs_Text_WhatIsIt, MSGBOX_DEFAULT
	waitmessage
	closemessage
	dynmultipush FollowingNPCs_Text_Heal, 0
	dynmultipush FollowingNPCs_Text_Battle, 1
	dynmultipush FollowingNPCs_Text_Leave, 2
	dynmultipush FollowingNPCs_Text_Nvm, 3
	dynmultistack 19, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, FollowingNPCs_EventScript_Follower_Healing
	case 1, FollowingNPCs_EventScript_Follower_Battles
	case 2, FollowingNPCs_EventScript_Follower_Leave
	case 3, FollowingNPCs_EventScript_Follower_Nevermind
	case MULTI_B_PRESSED, FollowingNPCs_EventScript_Follower_Nevermind
	release
	end

FollowingNPCs_EventScript_Follower_Healing::
	checkflag FLAG_HEAL_AFTER_FOLLOWER_BATTLE
	goto_if FALSE, FollowingNPCs_EventScript_Follower_HealingOn
	goto_if TRUE, FollowingNPCs_EventScript_Follower_HealingOff
	end

FollowingNPCs_EventScript_Follower_HealingOn::
	setflag FLAG_HEAL_AFTER_FOLLOWER_BATTLE
	msgbox FollowingNPCs_Text_Healing_Enabled, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

FollowingNPCs_EventScript_Follower_HealingOff::
	clearflag FLAG_HEAL_AFTER_FOLLOWER_BATTLE
	msgbox FollowingNPCs_Text_Healing_Disabled, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

FollowingNPCs_EventScript_Follower_Battles::
	checkflag FLAG_PARTNER_WILD_BATTLES
	goto_if FALSE, FollowingNPCs_EventScript_Follower_BattlesOn
	goto_if TRUE, FollowingNPCs_EventScript_Follower_BattlesOff
	end

FollowingNPCs_EventScript_Follower_BattlesOn::
	setflag FLAG_PARTNER_WILD_BATTLES
	msgbox FollowingNPCs_Text_Battles_Enabled, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

FollowingNPCs_EventScript_Follower_BattlesOff::
	clearflag FLAG_PARTNER_WILD_BATTLES
	msgbox FollowingNPCs_Text_Battles_Disabled, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

FollowingNPCs_EventScript_Follower_Leave::
	lock
	faceplayer
	msgbox FollowingNPCs_Text_FollowerLeft, MSGBOX_DEFAULT
	waitmessage
	closemessage
	destroyfollowernpc
	release
	end

FollowingNPCs_EventScript_Follower_Nevermind::
	lock
	faceplayer
	release
	end

FollowingNPCs_Text_WhatIsIt::
	.string "What is it?$"

FollowingNPCs_Text_WantMeToLeave::
	.string "Want me to leave?$"

FollowingNPCs_Text_WantMeToHeal::
	.string "Want me to heal your POKéMON?$"

FollowingNPCs_Text_WantMeToBattleWild::
	.string "Want me to battle wild\n"
	.string "POKéMON with you?$"

FollowingNPCs_Text_Heal::
	.string "Heal$"

FollowingNPCs_Text_Healing_Enabled::
	.string "Healing: Enabled$"

FollowingNPCs_Text_Healing_Disabled::
	.string "Healing: Disabled$"

FollowingNPCs_Text_Battle::
	.string "Battle$"

FollowingNPCs_Text_Battles_Enabled::
	.string "Battles: Enabled$"

FollowingNPCs_Text_Battles_Disabled::
	.string "Battles: Disabled$"

FollowingNPCs_Text_TalkNotReady::
	.string "Not Ready$"

FollowingNPCs_Text_Leave::
	.string "Leave$"

FollowingNPCs_Text_FollowerLeft::
	.string "Your follower returned home.$"

FollowingNPCs_Text_Nvm::
	.string "Nevermind$"
