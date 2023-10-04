.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"


Hall_Of_Fame_Rewards_PokemonLeagueKiosk::
	goto_if_unset FLAG_ENTERED_HALL_OF_FAME, Hall_Of_Fame_Rewards_LeagueKiosk_GoDefeatChampion
	goto_if_set FLAG_USED_LEAGUE_KIOSK, Hall_Of_Fame_Rewards_Reward_List
	goto_if_set FLAG_ENTERED_HALL_OF_FAME, Hall_Of_Fame_Rewards_LeagueKiosk_DefeatedChampion
	end

Hall_Of_Fame_Rewards_LeagueKiosk_GoDefeatChampion::
	msgbox Hall_Of_Fame_Rewards_LeagueKiosk_Text_GoDefeatChampion, MSGBOX_AUTOCLOSE
	closemessage
	end

Hall_Of_Fame_Rewards_LeagueKiosk_DefeatedChampion::
	msgbox Hall_Of_Fame_Rewards_LeagueKiosk_Text_DefeatedChampion, MSGBOX_AUTOCLOSE
	closemessage
	setflag FLAG_USED_LEAGUE_KIOSK
	goto Hall_Of_Fame_Rewards_Reward_List
	end

Hall_Of_Fame_Rewards_Reward_List::
	goto_if_eq VAR_HALL_OF_FAME, 1, Hall_Of_Fame_Rewards_FirstVictory
	goto_if_eq VAR_HALL_OF_FAME, 2, Hall_Of_Fame_Rewards_SecondVictory
	goto_if_eq VAR_HALL_OF_FAME, 3, Hall_Of_Fame_Rewards_ThirdVictory
	goto_if_eq VAR_HALL_OF_FAME, 4, Hall_Of_Fame_Rewards_FourthVictory
	goto_if_eq VAR_HALL_OF_FAME, 5, Hall_Of_Fame_Rewards_FifthVictory
	goto_if_eq VAR_HALL_OF_FAME, 6, Hall_Of_Fame_Rewards_SixthVictory
	goto_if_eq VAR_HALL_OF_FAME, 7, Hall_Of_Fame_Rewards_SeventhVictory
	goto_if_eq VAR_HALL_OF_FAME, 8, Hall_Of_Fame_Rewards_EighthVictory
	goto_if_eq VAR_HALL_OF_FAME, 9, Hall_Of_Fame_Rewards_NinthVictory
	goto_if_eq VAR_HALL_OF_FAME, 10, Hall_Of_Fame_Rewards_TenthVictory
	goto_if_ge VAR_HALL_OF_FAME, VAR_HALL_OF_FAME_OLD, Hall_Of_Fame_Rewards_PlusVictories
	end

Hall_Of_Fame_Rewards_WalkAway::
	msgbox Hall_Of_Fame_Rewards_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

Hall_Of_Fame_Rewards_GotReward::
	msgbox Hall_Of_Fame_Rewards_Text_GotReward, MSGBOX_AUTOCLOSE
	closemessage
	end

Hall_Of_Fame_Rewards_GotPlusReward::
	setflag FLAG_OBTAINED_REWARD_PLUS
	msgbox Hall_Of_Fame_Rewards_Text_GotReward, MSGBOX_AUTOCLOSE
	closemessage
	end

Hall_Of_Fame_Rewards_PlusVictories::
	clearflag FLAG_OBTAINED_REWARD_PLUS
	goto_if_eq VAR_HALL_OF_FAME, VAR_HALL_OF_FAME_OLD Hall_Of_Fame_Rewards_GotPlusReward
	goto_if_gt VAR_HALL_OF_FAME, VAR_HALL_OF_FAME_OLD Hall_Of_Fame_Rewards_PlusVictory
	end

Hall_Of_Fame_Rewards_FirstVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_1, Hall_Of_Fame_Rewards_FirstReward
	goto_if_set FLAG_OBTAINED_REWARD_1, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_SecondVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_2, Hall_Of_Fame_Rewards_SecondReward
	goto_if_set FLAG_OBTAINED_REWARD_2, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_ThirdVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_3, Hall_Of_Fame_Rewards_ThirdReward
	goto_if_set FLAG_OBTAINED_REWARD_3, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_FourthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_4, Hall_Of_Fame_Rewards_FourthReward
	goto_if_set FLAG_OBTAINED_REWARD_4, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_FifthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_5, Hall_Of_Fame_Rewards_FifthReward
	goto_if_set FLAG_OBTAINED_REWARD_5, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_SixthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_6, Hall_Of_Fame_Rewards_SixthReward
	goto_if_set FLAG_OBTAINED_REWARD_6, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_SeventhVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_7, Hall_Of_Fame_Rewards_SeventhReward
	goto_if_set FLAG_OBTAINED_REWARD_7, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_EighthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_8, Hall_Of_Fame_Rewards_EighthReward
	goto_if_set FLAG_OBTAINED_REWARD_8, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_NinthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_9, Hall_Of_Fame_Rewards_NinthReward
	goto_if_set FLAG_OBTAINED_REWARD_9, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_TenthVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_10, Hall_Of_Fame_Rewards_TenthReward
	goto_if_set FLAG_OBTAINED_REWARD_10, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_PlusVictory::
	goto_if_unset FLAG_OBTAINED_REWARD_PLUS, Hall_Of_Fame_Rewards_PlusReward
	goto_if_set FLAG_OBTAINED_REWARD_PLUS, Hall_Of_Fame_Rewards_GotReward
	end

Hall_Of_Fame_Rewards_FirstReward::
	msgbox Hall_Of_Fame_Rewards_Text_FirstTime, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_FirstReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_CATCHING_CHARM, 1
	delay 30
	giveitem ITEM_MASTER_BALL, 1
	setflag FLAG_OBTAINED_REWARD_1
	closemessage
	end

Hall_Of_Fame_Rewards_SecondReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_SecondReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_KANTO_STARTERS, TRUE
	switch VAR_RESULT
	case 0, Hall_Of_Fame_Rewards_Bulbasaur
	case 1, Hall_Of_Fame_Rewards_Charmander
	case 2, Hall_Of_Fame_Rewards_Squirtle
	case 3, Hall_Of_Fame_Rewards_WalkAway
	end

Hall_Of_Fame_Rewards_Bulbasaur::
	showmonpic SPECIES_BULBASAUR 10, 3
	playmoncry SPECIES_BULBASAUR CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	msgbox Hall_Of_Fame_Rewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, Hall_Of_Fame_Rewards_GiveBulbasaur
	case 1, Hall_Of_Fame_Rewards_WalkAway
	end

Hall_Of_Fame_Rewards_GiveBulbasaur::
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	msgbox Hall_Of_Fame_Rewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_BULBASAUR, 5, ITEM_VENUSAURITE
	setflag FLAG_OBTAINED_REWARD_2
	end

Hall_Of_Fame_Rewards_Charmander::
	showmonpic SPECIES_CHARMANDER 10, 3
	playmoncry SPECIES_CHARMANDER CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	msgbox Hall_Of_Fame_Rewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, Hall_Of_Fame_Rewards_GiveCharmander
	case 1, Hall_Of_Fame_Rewards_WalkAway
	end

Hall_Of_Fame_Rewards_GiveCharmander::
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	msgbox Hall_Of_Fame_Rewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_CHARMANDER, 5, ITEM_CHARIZARDITE_Y
	setflag FLAG_OBTAINED_REWARD_2
	end

Hall_Of_Fame_Rewards_Squirtle::
	showmonpic SPECIES_SQUIRTLE 10, 3
	playmoncry SPECIES_SQUIRTLE CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	msgbox Hall_Of_Fame_Rewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, Hall_Of_Fame_Rewards_GiveSquirtle
	case 1, Hall_Of_Fame_Rewards_WalkAway
	end

Hall_Of_Fame_Rewards_GiveSquirtle::
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	msgbox Hall_Of_Fame_Rewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_SQUIRTLE, 5, ITEM_BLASTOISINITE
	setflag FLAG_OBTAINED_REWARD_2
	end

Hall_Of_Fame_Rewards_ThirdReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_ThirdReward, MSGBOX_DEFAULT
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
	setflag FLAG_OBTAINED_REWARD_3
	closemessage
	end

Hall_Of_Fame_Rewards_FourthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_FourthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_SHINY_CHARM, 1
	delay 30
	giveitem ITEM_EXP_CANDY_XS, 10
	setflag FLAG_OBTAINED_REWARD_4
	closemessage
	end

Hall_Of_Fame_Rewards_FifthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_FifthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_EXP_CANDY_S, 10
	setflag FLAG_OBTAINED_REWARD_5
	closemessage
	end

Hall_Of_Fame_Rewards_SixthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_SixthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_EXP_CANDY_M, 10
	setflag FLAG_OBTAINED_REWARD_6
	closemessage
	end

Hall_Of_Fame_Rewards_SeventhReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_SeventhReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_EXP_CHARM, 1
	delay 30
	giveitem ITEM_MASTER_BALL, 1
	setflag FLAG_OBTAINED_REWARD_7
	closemessage
	end

Hall_Of_Fame_Rewards_EighthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_EighthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_ALOLA_STARTERS, TRUE
	switch VAR_RESULT
	case 0, Hall_Of_Fame_Rewards_Rowlet
	case 1, Hall_Of_Fame_Rewards_Litten
	case 2, Hall_Of_Fame_Rewards_Popplio
	case 3, Hall_Of_Fame_Rewards_WalkAway
	end

Hall_Of_Fame_Rewards_Rowlet::
	showmonpic SPECIES_ROWLET 10, 3
	playmoncry SPECIES_ROWLET CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_ROWLET
	msgbox Hall_Of_Fame_Rewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, Hall_Of_Fame_Rewards_GiveRowlet
	case 1, Hall_Of_Fame_Rewards_WalkAway
	end

Hall_Of_Fame_Rewards_GiveRowlet::
	bufferspeciesname STR_VAR_1, SPECIES_ROWLET
	msgbox Hall_Of_Fame_Rewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_ROWLET, 5, ITEM_DECIDIUM_Z
	setflag FLAG_OBTAINED_REWARD_8
	end

Hall_Of_Fame_Rewards_Litten::
	showmonpic SPECIES_LITTEN 10, 3
	playmoncry SPECIES_LITTEN CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_LITTEN
	msgbox Hall_Of_Fame_Rewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, Hall_Of_Fame_Rewards_GiveLitten
	case 1, Hall_Of_Fame_Rewards_WalkAway
	end

Hall_Of_Fame_Rewards_GiveLitten::
	bufferspeciesname STR_VAR_1, SPECIES_LITTEN
	msgbox Hall_Of_Fame_Rewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_LITTEN, 5, ITEM_INCINIUM_Z
	setflag FLAG_OBTAINED_REWARD_8
	end

Hall_Of_Fame_Rewards_Popplio::
	showmonpic SPECIES_POPPLIO 10, 3
	playmoncry SPECIES_POPPLIO CRY_MODE_NORMAL
	delay 50
	hidemonpic
	bufferspeciesname STR_VAR_1, SPECIES_POPPLIO
	msgbox Hall_Of_Fame_Rewards_Text_Starter, MSGBOX_DEFAULT
	closemessage
	delay 30
	multichoice 18, 2, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 0, Hall_Of_Fame_Rewards_GivePopplio
	case 1, Hall_Of_Fame_Rewards_WalkAway
	end

Hall_Of_Fame_Rewards_GivePopplio::
	bufferspeciesname STR_VAR_1, SPECIES_POPPLIO
	msgbox Hall_Of_Fame_Rewards_Text_ChooseStarter, MSGBOX_DEFAULT
	closemessage
	givemon SPECIES_POPPLIO, 5, ITEM_PRIMARIUM_Z
	setflag FLAG_OBTAINED_REWARD_8
	end

Hall_Of_Fame_Rewards_NinthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_NinthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_EXP_CANDY_L, 10
	setflag FLAG_OBTAINED_REWARD_9
	closemessage
	end

Hall_Of_Fame_Rewards_TenthReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_TenthReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_OVAL_CHARM, 1
	delay 30
	giveitem ITEM_EXP_CANDY_XL, 10
	setflag FLAG_OBTAINED_REWARD_10
	closemessage
	end

Hall_Of_Fame_Rewards_PlusReward::
	buffernumberstring STR_VAR_1, VAR_HALL_OF_FAME
	msgbox Hall_Of_Fame_Rewards_Text_ManyTimes, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Hall_Of_Fame_Rewards_Text_EleventhReward, MSGBOX_DEFAULT
	closemessage
	delay 30
	giveitem ITEM_MASTER_BALL, 1
	addvar VAR_HALL_OF_FAME_OLD, 1
	setflag FLAG_OBTAINED_REWARD_PLUS
	closemessage
	end

Hall_Of_Fame_Rewards_LeagueKiosk_Text_GoDefeatChampion::
	.string "PKMN. LEAGUE KIOSK: Come back and see\nme after you defeat the Champion and\penter the Hall of Fame.$"

Hall_Of_Fame_Rewards_LeagueKiosk_Text_DefeatedChampion::
	.string "PKMN. LEAGUE KIOSK: You've did it\n{PLAYER}, you defeated the\pChampion and entered the Hall of Fame.\nPKMN. LEAGUE KIOSK: I'm Hoenn Pokémon\pLeague's automated delivery and\nacknowledgement system, my job is to\pgive you your rewards for entering the\nHall of Fame.$"

Hall_Of_Fame_Rewards_Text_FirstTime::
	.string "PKMN. LEAGUE KIOSK: {PLAYER},\ncongratulations on defeating the\pChampion and entering the Hall of Fame\nfor the First time.$"

Hall_Of_Fame_Rewards_Text_ManyTimes::
	.string "PKMN. LEAGUE KIOSK: {PLAYER},\ncongratulations on defeating the\pChampion and entering the Hall of Fame\n{STR_VAR_1} times.$"

Hall_Of_Fame_Rewards_Text_FirstReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are one Catching Charm and one\pMaster Ball.$"

Hall_Of_Fame_Rewards_Text_SecondReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nreward is one of the starter Pokémon\pfrom the Kanto region.$"

Hall_Of_Fame_Rewards_Text_ThirdReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are three of every Type Gem.$"

Hall_Of_Fame_Rewards_Text_FourthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are one Shiny Charm and ten XS\pEXP Candies.$"

Hall_Of_Fame_Rewards_Text_FifthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are ten S EXP Candies.$"

Hall_Of_Fame_Rewards_Text_SixthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are ten M EXP Candies.$"

Hall_Of_Fame_Rewards_Text_SeventhReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are one EXP Charm and one\pMaster Ball.$"

Hall_Of_Fame_Rewards_Text_EighthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nreward is one of the starter Pokémon\pfrom the Alola region.$"

Hall_Of_Fame_Rewards_Text_NinthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are ten L EXP Candies.$"

Hall_Of_Fame_Rewards_Text_TenthReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nrewards are one Oval Charm and ten XL\pEXP Candies.$"

Hall_Of_Fame_Rewards_Text_EleventhReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, your\nreward is one Master Ball.$"

Hall_Of_Fame_Rewards_Text_Starter::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, this\nPokémon is called {STR_VAR_1}. Are you\psure this is the Pokémon you want?$"

Hall_Of_Fame_Rewards_Text_GotReward::
	.string "PKMN. LEAGUE KIOSK: {PLAYER}, you have\nalready received your Hall of Fame\preward. Come back after beating the\nElite 4 and Champion again.$"

Hall_Of_Fame_Rewards_Text_ChooseStarter::
	.string "You choose {STR_VAR_1}!$"

Hall_Of_Fame_Rewards_Text_WalkAway::
	.string "You delcined the offer.$"
