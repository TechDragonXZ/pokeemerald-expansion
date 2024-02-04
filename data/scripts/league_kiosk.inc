Common_EventScript_LeagueKiosk::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_KioskMainMenu
	end

EventScript_KioskMainMenu::
	message gText_WhichFunctionShouldBeAccessed
	waitmessage
	multichoice 19, 4, MULTI_KIOSK, TRUE
	switch VAR_RESULT
	case 0, EventScript_AccessMoveReminder
	case 1, EventScript_AccessMoveDeleter
	case 2, EventScript_AccessLeagueRewards
	case 3, EventScript_TurnOffKiosk
	case MULTI_B_PRESSED, EventScript_TurnOffKiosk
	end

EventScript_AccessMoveReminder::
	playse SE_PC_LOGIN
	msgbox gText_AccessedMoveReminder, MSGBOX_DEFAULT
	waitmessage
	msgbox LeagueKiosk_Text_RemindWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LeagueKiosk_EventScript_ComeBackLater
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LeagueKiosk_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, LeagueKiosk_EventScript_NoMoveToTeachMon
	goto LeagueKiosk_EventScript_ChooseMove
	end

LeagueKiosk_EventScript_ChooseMove::
	msgbox LeagueKiosk_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, EventScript_AccessMoveReminder
	goto LeagueKiosk_EventScript_ComeBackLater
	end

EventScript_AccessMoveDeleter::
	playse SE_PC_LOGIN
	msgbox gText_AccessedMoveDeleter, MSGBOX_DEFAULT
	msgbox LeagueKiosk_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LeagueKiosk_Text_ComeBackLater
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LeagueKiosk_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LeagueKiosk_EventScript_MonOnlyKnowsOneMove
	msgbox LeagueKiosk_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LeagueKiosk_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LeagueKiosk_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LeagueKiosk_EventScript_TryForgetMove
	case NO, LeagueKiosk_EventScript_ComeBackLater
	goto EventScript_PCMainMenu
	end

EventScript_TurnOffKiosk::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessLeagueRewards::
	playse SE_PC_LOGIN
	goto_if_unset FLAG_ENTERED_HALL_OF_FAME, LeagueKiosk_LeagueRewards_GoDefeatChampion
	goto_if_set FLAG_CAN_GET_REWARDS, League_Rewards_List
	goto_if_set FLAG_ENTERED_HALL_OF_FAME, LeagueKiosk_LeagueRewards_DefeatedChampion
	waitstate
	goto EventScript_AccessPC
	end

LeagueKiosk_LeagueRewards_GoDefeatChampion::
	msgbox LeagueKiosk_LeagueRewards_Text_GoDefeatChampion, MSGBOX_AUTOCLOSE
	closemessage
	end

LeagueKiosk_LeagueRewards_DefeatedChampion::
	msgbox LeagueKiosk_LeagueRewards_Text_DefeatedChampion, MSGBOX_AUTOCLOSE
	closemessage
	setflag FLAG_CAN_GET_REWARDS
	goto League_Rewards_List
	end

League_Rewards_List::
	clearflag FLAG_OBTAINED_REWARD
	goto_if_eq VAR_HALL_OF_FAME, 1, LeagueKiosk_LeagueRewards_FirstVictory
	goto_if_eq VAR_HALL_OF_FAME, 2, LeagueKiosk_LeagueRewards_SecondVictory
	goto_if_eq VAR_HALL_OF_FAME, 3, LeagueKiosk_LeagueRewards_ThirdVictory
	goto_if_eq VAR_HALL_OF_FAME, 4, LeagueKiosk_LeagueRewards_FourthVictory
	goto_if_eq VAR_HALL_OF_FAME, 5, LeagueKiosk_LeagueRewards_FifthVictory
	goto_if_eq VAR_HALL_OF_FAME, 6, LeagueKiosk_LeagueRewards_SixthVictory
	goto_if_eq VAR_HALL_OF_FAME, 7, LeagueKiosk_LeagueRewards_SeventhVictory
	goto_if_eq VAR_HALL_OF_FAME, 8, LeagueKiosk_LeagueRewards_EighthVictory
	goto_if_eq VAR_HALL_OF_FAME, 9, LeagueKiosk_LeagueRewards_NinthVictory
	goto_if_eq VAR_HALL_OF_FAME, 10, LeagueKiosk_LeagueRewards_TenthVictory
	goto_if_ge VAR_HALL_OF_FAME, VAR_HALL_OF_FAME_OLD, LeagueKiosk_LeagueRewards_PlusVictories
	end

LeagueKiosk_LeagueRewards_WalkAway::
	msgbox LeagueKiosk_LeagueRewards_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

LeagueKiosk_LeagueRewards_GotReward::
	msgbox LeagueKiosk_LeagueRewards_Text_GotReward, MSGBOX_AUTOCLOSE
	closemessage
	end

LeagueKiosk_LeagueRewards_GotPlusReward::
	setflag FLAG_OBTAINED_REWARD
	msgbox LeagueKiosk_LeagueRewards_Text_GotReward, MSGBOX_AUTOCLOSE
	closemessage
	end

LeagueKiosk_LeagueRewards_PlusVictories::
	clearflag FLAG_OBTAINED_REWARD
	goto_if_eq VAR_HALL_OF_FAME, VAR_HALL_OF_FAME_OLD LeagueKiosk_LeagueRewards_GotPlusReward
	goto_if_gt VAR_HALL_OF_FAME, VAR_HALL_OF_FAME_OLD LeagueKiosk_LeagueRewards_PlusVictory
	end

LeagueKiosk_LeagueRewards_FirstVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_FirstReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_SecondVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_SecondReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_ThirdVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_ThirdReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_FourthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_FourthReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_FifthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_FifthReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_SixthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_SixthReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_SeventhVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_SeventhReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_EighthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_EighthReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_NinthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_NinthReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_TenthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_TenthReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_PlusVictory::
	goto_if_unset FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_PlusReward
	goto_if_set FLAG_OBTAINED_REWARD, LeagueKiosk_LeagueRewards_GotReward
	end

LeagueKiosk_LeagueRewards_FirstReward::
	msgbox LeagueKiosk_LeagueRewards_Text_FirstTime, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_FirstReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_CATCHING_CHARM, 1
	delay 30
	giveitem ITEM_MASTER_BALL, 1
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_SecondReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_SecondReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_KANTO_STARTERS, TRUE
	switch VAR_RESULT
	case 0, LeagueKiosk_LeagueRewards_Bulbasaur
	case 1, LeagueKiosk_LeagueRewards_Charmander
	case 2, LeagueKiosk_LeagueRewards_Squirtle
	case 3, LeagueKiosk_LeagueRewards_WalkAway
	end

LeagueKiosk_LeagueRewards_Bulbasaur::
	showmonpic SPECIES_BULBASAUR 10, 3
	playmoncry SPECIES_BULBASAUR CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	msgbox LeagueKiosk_LeagueRewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, LeagueKiosk_LeagueRewards_GiveBulbasaur
	case 1, LeagueKiosk_LeagueRewards_WalkAway
	end

LeagueKiosk_LeagueRewards_GiveBulbasaur::
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	msgbox LeagueKiosk_LeagueRewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_BULBASAUR, 5, ITEM_VENUSAURITE
	setflag FLAG_OBTAINED_REWARD
	end

LeagueKiosk_LeagueRewards_Charmander::
	showmonpic SPECIES_CHARMANDER 10, 3
	playmoncry SPECIES_CHARMANDER CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	msgbox LeagueKiosk_LeagueRewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, LeagueKiosk_LeagueRewards_GiveCharmander
	case 1, LeagueKiosk_LeagueRewards_WalkAway
	end

LeagueKiosk_LeagueRewards_GiveCharmander::
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	msgbox LeagueKiosk_LeagueRewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_CHARMANDER, 5, ITEM_CHARIZARDITE_Y
	setflag FLAG_OBTAINED_REWARD
	end

LeagueKiosk_LeagueRewards_Squirtle::
	showmonpic SPECIES_SQUIRTLE 10, 3
	playmoncry SPECIES_SQUIRTLE CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	msgbox LeagueKiosk_LeagueRewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, LeagueKiosk_LeagueRewards_GiveSquirtle
	case 1, LeagueKiosk_LeagueRewards_WalkAway
	end

LeagueKiosk_LeagueRewards_GiveSquirtle::
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	msgbox LeagueKiosk_LeagueRewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_SQUIRTLE, 5, ITEM_BLASTOISINITE
	setflag FLAG_OBTAINED_REWARD
	end

LeagueKiosk_LeagueRewards_ThirdReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_ThirdReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_FIRE_GEM, 3
	delay 30
	giveitem ITEM_WATER_GEM, 3
	delay 30
	giveitem ITEM_GRASS_GEM, 3
	delay 30
	giveitem ITEM_GROUND_GEM, 3
	delay 30
	giveitem ITEM_ROCK_GEM, 3
	delay 30
	giveitem ITEM_ICE_GEM, 3
	delay 30
	giveitem ITEM_FLYING_GEM, 3
	delay 30
	giveitem ITEM_POISON_GEM, 3
	delay 30
	giveitem ITEM_STEEL_GEM, 3
	delay 30
	giveitem ITEM_FAIRY_GEM, 3
	delay 30
	giveitem ITEM_BUG_GEM, 3
	delay 30
	giveitem ITEM_PSYCHIC_GEM, 3
	delay 30
	giveitem ITEM_NORMAL_GEM, 3
	delay 30
	giveitem ITEM_FIGHTING_GEM, 3
	delay 30
	giveitem ITEM_DRAGON_GEM, 3
	delay 30
	giveitem ITEM_ELECTRIC_GEM, 3
	delay 30
	giveitem ITEM_GHOST_GEM, 3
	delay 30
	giveitem ITEM_DARK_GEM, 3
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_FourthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_FourthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_SHINY_CHARM, 1
	delay 30
	giveitem ITEM_EXP_CANDY_XS, 10
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_FifthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_FifthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_EXP_CANDY_S, 10
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_SixthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_SixthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_EXP_CANDY_M, 10
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_SeventhReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_SeventhReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_EXP_CHARM, 1
	delay 30
	giveitem ITEM_MASTER_BALL, 1
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_EighthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_EighthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_ALOLA_STARTERS, TRUE
	switch VAR_RESULT
	case 0, LeagueKiosk_LeagueRewards_Rowlet
	case 1, LeagueKiosk_LeagueRewards_Litten
	case 2, LeagueKiosk_LeagueRewards_Popplio
	case 3, LeagueKiosk_LeagueRewards_WalkAway
	end

LeagueKiosk_LeagueRewards_Rowlet::
	showmonpic SPECIES_ROWLET 10, 3
	playmoncry SPECIES_ROWLET CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_ROWLET
	msgbox LeagueKiosk_LeagueRewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, LeagueKiosk_LeagueRewards_GiveRowlet
	case 1, LeagueKiosk_LeagueRewards_WalkAway
	end

LeagueKiosk_LeagueRewards_GiveRowlet::
	bufferspeciesname STR_VAR_1, SPECIES_ROWLET
	msgbox LeagueKiosk_LeagueRewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_ROWLET, 5, ITEM_DECIDIUM_Z
	setflag FLAG_OBTAINED_REWARD
	end

LeagueKiosk_LeagueRewards_Litten::
	showmonpic SPECIES_LITTEN 10, 3
	playmoncry SPECIES_LITTEN CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_LITTEN
	msgbox LeagueKiosk_LeagueRewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, LeagueKiosk_LeagueRewards_GiveLitten
	case 1, LeagueKiosk_LeagueRewards_WalkAway
	end

LeagueKiosk_LeagueRewards_GiveLitten::
	bufferspeciesname STR_VAR_1, SPECIES_LITTEN
	msgbox LeagueKiosk_LeagueRewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_LITTEN, 5, ITEM_INCINIUM_Z
	setflag FLAG_OBTAINED_REWARD
	end

LeagueKiosk_LeagueRewards_Popplio::
	showmonpic SPECIES_POPPLIO 10, 3
	playmoncry SPECIES_POPPLIO CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_POPPLIO
	msgbox LeagueKiosk_LeagueRewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, LeagueKiosk_LeagueRewards_GivePopplio
	case 1, LeagueKiosk_LeagueRewards_WalkAway
	end

LeagueKiosk_LeagueRewards_GivePopplio::
	bufferspeciesname STR_VAR_1, SPECIES_POPPLIO
	msgbox LeagueKiosk_LeagueRewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_POPPLIO, 5, ITEM_PRIMARIUM_Z
	setflag FLAG_OBTAINED_REWARD
	end

LeagueKiosk_LeagueRewards_NinthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_NinthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_EXP_CANDY_L, 10
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_TenthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_TenthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_OVAL_CHARM, 1
	delay 30
	giveitem ITEM_EXP_CANDY_XL, 10
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_PlusReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox LeagueKiosk_LeagueRewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox LeagueKiosk_LeagueRewards_Text_EleventhReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_MASTER_BALL, 1
	addvar VAR_HALL_OF_FAME_OLD, 1
	setflag FLAG_OBTAINED_REWARD
	closemessage
	end

LeagueKiosk_LeagueRewards_Text_GoDefeatChampion::
	.string "PKMN. LEAGUE KIOSK: Come back and see\nme after you defeat the Champion and\penter the Hall of Fame.$"

LeagueKiosk_LeagueRewards_Text_DefeatedChampion::
	.string "PKMN. LEAGUE KIOSK: You've did it\n{PLAYER}, you defeated the\pChampion and entered the Hall of Fame.\nPKMN. LEAGUE KIOSK: I'm Hoenn Pokémon\pLeague's automated delivery and\nacknowledgement system, my job is to\pgive you your rewards for entering the\nHall of Fame.$"

LeagueKiosk_LeagueRewards_Text_FirstTime::
	.string "PKMN. LEAGUE KIOSK: {PLAYER},\ncongratulations on defeating the\pChampion and entering the Hall of Fame\nfor the First time.$"

LeagueKiosk_LeagueRewards_Text_ManyTimes::
	.string "PKMN. LEAGUE KIOSK: {PLAYER},\ncongratulations on defeating the\pChampion and entering the Hall of Fame\n{STR_VAR_1} times.$"

LeagueKiosk_LeagueRewards_Text_FirstReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are one Catching Charm and one\pMaster Ball.$"

LeagueKiosk_LeagueRewards_Text_SecondReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nreward is one of the starter Pokémon\pfrom the Kanto region.$"

LeagueKiosk_LeagueRewards_Text_ThirdReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are three of every Type Gem.$"

LeagueKiosk_LeagueRewards_Text_FourthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are one Shiny Charm and ten XS\pEXP Candies.$"

LeagueKiosk_LeagueRewards_Text_FifthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are ten S EXP Candies.$"

LeagueKiosk_LeagueRewards_Text_SixthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are ten M EXP Candies.$"

LeagueKiosk_LeagueRewards_Text_SeventhReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are one EXP Charm and one\pMaster Ball.$"

LeagueKiosk_LeagueRewards_Text_EighthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nreward is one of the starter Pokémon\pfrom the Alola region.$"

LeagueKiosk_LeagueRewards_Text_NinthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are ten L EXP Candies.$"

LeagueKiosk_LeagueRewards_Text_TenthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are one Oval Charm and ten XL\pEXP Candies.$"

LeagueKiosk_LeagueRewards_Text_EleventhReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nreward is one Master Ball.$"

LeagueKiosk_LeagueRewards_Text_Starter::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, this\nPokémon is called {STR_VAR_1}. Are you\psure this is the Pokémon you want?$"

LeagueKiosk_LeagueRewards_Text_GotReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, you have\nalready received your Hall of Fame\preward. Come back after beating the\nElite 4 and Champion again.$"

LeagueKiosk_LeagueRewards_Text_ChooseStarter::
	.string "You choose {STR_VAR_1}!$"

LeagueKiosk_LeagueRewards_Text_WalkAway::
	.string "You delcined the offer.$"

LeagueKiosk_EventScript_NoMoveToTeachMon::
	msgbox LeagueKiosk_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto EventScript_AccessMoveReminder
	end

LeagueKiosk_EventScript_CantTeachEgg::
	msgbox LeagueKiosk_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto EventScript_AccessMoveReminder
	end

LeagueKiosk_EventScript_ComeBackLater::
	msgbox LeagueKiosk_Text_ComeBackLater, MSGBOX_DEFAULT
	releaseall
	end

LeagueKiosk_EventScript_TryForgetMove::
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LeagueKiosk_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LeagueKiosk_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LeagueKiosk_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox LeagueKiosk_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LeagueKiosk_EventScript_EggCantForgetMoves::
	msgbox LeagueKiosk_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LeagueKiosk_EventScript_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox LeagueKiosk_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LeagueKiosk_EventScript_ChooseMonAndMoveToForget::
	msgbox LeagueKiosk_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LeagueKiosk_Text_ComeBackLater
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LeagueKiosk_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, LeagueKiosk_EventScript_MonOnlyKnowsOneMove
	msgbox LeagueKiosk_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LeagueKiosk_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LeagueKiosk_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LeagueKiosk_EventScript_TryForgetMove
	case NO, LeagueKiosk_Text_ComeBackLater
	releaseall
	end

LeagueKiosk_Text_RemindWhichMon:
	.string "Which POKéMON needs reminding?$"

LeagueKiosk_Text_TeachWhichMove:
	.string "Which move should I teach?$"

LeagueKiosk_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "That POKéMON doesn't have any teachable moves.$"

LeagueKiosk_Text_ComeBackLater:
	.string "If your POKéMON needs to learn or\n"
	.string "forget a move, come back later.$"

LeagueKiosk_Text_CantTeachEgg:
	.string "Hunh? EGGs can't learn any moves.$"

LeagueKiosk_Text_WhichMonShouldForget:
	.string "Which POKéMON should forget a move?$"

LeagueKiosk_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

LeagueKiosk_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

LeagueKiosk_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

LeagueKiosk_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

LeagueKiosk_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

LeagueKiosk_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No EGG should know any moves.$"

LeagueKiosk_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"
