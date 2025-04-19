.set LOCALID_BC_WAITER, 1

@ Prices
.set TERA_PRICE, 500
.set VSC_PRICE,  1000
.set MC_PRICE,   2500
.set MRB_PRICE,  5000

MauvilleCity_BattleCafe_MapScripts::
	.byte 0

MauvilleCity_BattleCafe_EventScript_LeftWaiter::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_BattleCafe_Shop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_BattleCafe_Shop:
	.2byte ITEM_PEWTER_CRUNCHIES
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_OLD_GATEAU
	.2byte ITEM_JUBILIFE_MUFFIN
	.2byte ITEM_CASTELIACONE
	.2byte ITEM_LUMIOSE_GALETTE
	.2byte ITEM_SHALOUR_SABLE
	.2byte ITEM_BIG_MALASADA
	pokemartlistend

MauvilleCity_BattleCafe_EventScript_CenterWaiter::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_BattleCafe_Shop2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_BattleCafe_Shop2:
	.2byte ITEM_OCCA_BERRY
	.2byte ITEM_PASSHO_BERRY
	.2byte ITEM_WACAN_BERRY
	.2byte ITEM_RINDO_BERRY
	.2byte ITEM_YACHE_BERRY
	.2byte ITEM_CHOPLE_BERRY
	.2byte ITEM_KEBIA_BERRY
	.2byte ITEM_SHUCA_BERRY
	.2byte ITEM_COBA_BERRY
	.2byte ITEM_PAYAPA_BERRY
	.2byte ITEM_TANGA_BERRY
	.2byte ITEM_CHARTI_BERRY
	.2byte ITEM_KASIB_BERRY
	.2byte ITEM_HABAN_BERRY
	.2byte ITEM_COLBUR_BERRY
	.2byte ITEM_BABIRI_BERRY
	.2byte ITEM_CHILAN_BERRY
	.2byte ITEM_ROSELI_BERRY
	pokemartlistend

MauvilleCity_BattleCafe_EventScript_RightWaiter::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_TeraMeal, MSGBOX_DEFAULT
	dynmultipush MauvilleCity_BattleCafe_Text_Normal, 0
	dynmultipush MauvilleCity_BattleCafe_Text_Fighting, 1
	dynmultipush MauvilleCity_BattleCafe_Text_Ghost, 2
	dynmultipush MauvilleCity_BattleCafe_Text_Fire, 3
	dynmultipush MauvilleCity_BattleCafe_Text_Water, 4
	dynmultipush MauvilleCity_BattleCafe_Text_Grass, 5
	dynmultipush MauvilleCity_BattleCafe_Text_Bug, 6
	dynmultipush MauvilleCity_BattleCafe_Text_Flying, 7
	dynmultipush MauvilleCity_BattleCafe_Text_Ground, 8
	dynmultipush MauvilleCity_BattleCafe_Text_Rock, 9
	dynmultipush MauvilleCity_BattleCafe_Text_Psychic, 10
	dynmultipush MauvilleCity_BattleCafe_Text_Dark, 11
	dynmultipush MauvilleCity_BattleCafe_Text_Steel, 12
	dynmultipush MauvilleCity_BattleCafe_Text_Dragon, 13
	dynmultipush MauvilleCity_BattleCafe_Text_Fairy, 14
	dynmultipush MauvilleCity_BattleCafe_Text_Electric, 15
	dynmultipush MauvilleCity_BattleCafe_Text_Poison, 16
	dynmultipush MauvilleCity_BattleCafe_Text_Ice, 17
	dynmultipush MauvilleCity_BattleCafe_Text_Stellar, 18
	dynmultipush MauvilleCity_BattleCafe_Text_Decline, 19
	dynmultistack 19, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MauvilleCity_BattleCafe_EventScript_TeraNormal
	case 1, MauvilleCity_BattleCafe_EventScript_TeraFighting
	case 2, MauvilleCity_BattleCafe_EventScript_TeraGhost
	case 3, MauvilleCity_BattleCafe_EventScript_TeraFire
	case 4, MauvilleCity_BattleCafe_EventScript_TeraWater
	case 5, MauvilleCity_BattleCafe_EventScript_TeraGrass
	case 6, MauvilleCity_BattleCafe_EventScript_TeraBug
	case 7, MauvilleCity_BattleCafe_EventScript_TeraFlying
	case 8, MauvilleCity_BattleCafe_EventScript_TeraGround
	case 9, MauvilleCity_BattleCafe_EventScript_TeraRock
	case 10, MauvilleCity_BattleCafe_EventScript_TeraPsychic
	case 11, MauvilleCity_BattleCafe_EventScript_TeraDark
	case 12, MauvilleCity_BattleCafe_EventScript_TeraSteel
	case 13, MauvilleCity_BattleCafe_EventScript_TeraDragon
	case 14, MauvilleCity_BattleCafe_EventScript_TeraFairy
	case 15, MauvilleCity_BattleCafe_EventScript_TeraElectric
	case 16, MauvilleCity_BattleCafe_EventScript_TeraPoison
	case 17, MauvilleCity_BattleCafe_EventScript_TeraIce
	case 18, MauvilleCity_BattleCafe_EventScript_TeraStellar
	case 19, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	case MULTI_B_PRESSED, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	closemessage
	release
	end

MauvilleCity_BattleCafe_EventScript_TeraNormal::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_NORMAL, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_NORMAL, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_NORMAL_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraFire::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_FIRE, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_FIRE, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_FIRE_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraWater::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_WATER, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_WATER, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_WATER_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraGrass::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_GRASS, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_GRASS, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GRASS_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraElectric::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_ELECTRIC, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_ELECTRIC, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_ELECTRIC_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraRock::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_ROCK, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_ROCK, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_ROCK_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraGround::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_GROUND, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_GROUND, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GROUND_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraFighting::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_FIGHTING, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_FIGHTING, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_FIGHTING_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraFlying::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_FLYING, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_FLYING, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_FLYING_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraGhost::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_GHOST, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_GHOST, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_GHOST_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraBug::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_BUG, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_BUG, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_BUG_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraPsychic::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_PSYCHIC, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_PSYCHIC, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_PSYCHIC_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraPoison::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_POISON, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_POISON, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_POISON_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraIce::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_ICE, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_ICE, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_ICE_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraDragon::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_DRAGON, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_DRAGON, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_DRAGON_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraDark::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_DARK, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_DARK, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_DARK_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraSteel::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_STEEL, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_STEEL, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_STEEL_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraFairy::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_FAIRY, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_FAIRY, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_FAIRY_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraStellar::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_BattleCafe_EventScript_TeraDeclined
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType
	checkteratype VAR_0x8004
	goto_if_eq VAR_RESULT, TYPE_STELLAR, MauvilleCity_BattleCafe_EventScript_AlreadyTeraType
	setteratype TYPE_STELLAR, VAR_0x8004
	msgbox MauvilleCity_BattleCafe_Text_TeraTypeChanged, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_STELLAR_TERA_SHARD, 20
	removemoney TERA_PRICE
	end

MauvilleCity_BattleCafe_EventScript_TeraDeclined::
	msgbox MauvilleCity_BattleCafe_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_EggCantChangeTeraType::
	msgbox MauvilleCity_BattleCafe_Text_EggCantChangeTeraType, MSGBOX_DEFAULT
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_AlreadyTeraType::
	msgbox MauvilleCity_BattleCafe_Text_AlreadyTeraType, MSGBOX_DEFAULT
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_BattleCourseWaiterTrigger::
	goto_if_eq VAR_BATTLE_COURSE_STATE, 0, MauvilleCity_BattleCafe_EventScript_BCWaiterCall
	goto_if_eq VAR_BATTLE_COURSE_STATE, 1, MauvilleCity_BattleCafe_EventScript_Enter
	goto_if_eq VAR_BATTLE_COURSE_STATE, 2, MauvilleCity_BattleCafe_EventScript_Exit
	end

MauvilleCity_BattleCafe_EventScript_BCWaiterCall::
	applymovement LOCALID_BC_WAITER, MauvilleCity_BattleCafe_Movement_Jump
	msgbox MauvilleCity_BattleCafe_Text_OverHere, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_ToLeftCounter
	waitmovement OBJ_EVENT_ID_PLAYER
	end

MauvilleCity_BattleCafe_EventScript_Enter::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_Forwards
	waitmovement OBJ_EVENT_ID_PLAYER
	end

MauvilleCity_BattleCafe_EventScript_Exit::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_ToRightCounter
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_BATTLE_COURSE_STATE, 0
	clearflag FLAG_IN_BATTLE_COURSE
	end

MauvilleCity_BattleCafe_EventScript_BattleCourseWaiter::
	goto_if_lt VAR_BADGES, 4, MauvilleCity_BattleCafe_EventScript_BattleCourseOptions1
	goto_if_le VAR_BADGES, 7, MauvilleCity_BattleCafe_EventScript_BattleCourseOptions2
	goto_if_ge VAR_BADGES, 8, MauvilleCity_BattleCafe_EventScript_BattleCourseOptions3
	end

MauvilleCity_BattleCafe_EventScript_BattleCourseOptions1::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_BattleCourse, MSGBOX_DEFAULT
	dynmultipush MauvilleCity_BattleCafe_Text_VillageSubCombo, 0
	dynmultipush MauvilleCity_BattleCafe_Text_DeclineMealCourse, 1
	dynmultistack 19, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MauvilleCity_BattleCafe_EventScript_VillageSubCombo
	case 1, MauvilleCity_BattleCafe_EventScript_MealCourseDeclined
	case MULTI_B_PRESSED, MauvilleCity_BattleCafe_EventScript_MealCourseDeclined
	closemessage
	release
	end

MauvilleCity_BattleCafe_EventScript_BattleCourseOptions2::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_BattleCourse, MSGBOX_DEFAULT
	dynmultipush MauvilleCity_BattleCafe_Text_VillageSubCombo, 0
	dynmultipush MauvilleCity_BattleCafe_Text_MagnemiteCroquette, 1
	dynmultipush MauvilleCity_BattleCafe_Text_DeclineMealCourse, 2
	dynmultistack 19, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MauvilleCity_BattleCafe_EventScript_VillageSubCombo
	case 1, MauvilleCity_BattleCafe_EventScript_MagnemiteCroquette
	case 2, MauvilleCity_BattleCafe_EventScript_MealCourseDeclined
	case MULTI_B_PRESSED, MauvilleCity_BattleCafe_EventScript_MealCourseDeclined
	closemessage
	release
	end

MauvilleCity_BattleCafe_EventScript_BattleCourseOptions3::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_BattleCourse, MSGBOX_DEFAULT
	dynmultipush MauvilleCity_BattleCafe_Text_VillageSubCombo, 0
	dynmultipush MauvilleCity_BattleCafe_Text_MagnemiteCroquette, 1
	dynmultipush MauvilleCity_BattleCafe_Text_MauvilleRamenBowl, 2
	dynmultipush MauvilleCity_BattleCafe_Text_DeclineMealCourse, 3
	dynmultistack 19, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, MauvilleCity_BattleCafe_EventScript_VillageSubCombo
	case 1, MauvilleCity_BattleCafe_EventScript_MagnemiteCroquette
	case 2, MauvilleCity_BattleCafe_EventScript_MauvilleRamenBowl
	case 3, MauvilleCity_BattleCafe_EventScript_MealCourseDeclined
	case MULTI_B_PRESSED, MauvilleCity_BattleCafe_EventScript_MealCourseDeclined
	closemessage
	release
	end

MauvilleCity_BattleCafe_EventScript_VillageSubCombo::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_ToArena
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MauvilleCity_BattleCafe_Text_Enjoy, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_IN_BATTLE_COURSE
	setvar VAR_BATTLE_COURSE_STATE, 1
	removemoney VSC_PRICE
	end

MauvilleCity_BattleCafe_EventScript_MagnemiteCroquette::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_ToArena
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MauvilleCity_BattleCafe_Text_Enjoy, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_IN_BATTLE_COURSE
	setvar VAR_BATTLE_COURSE_STATE, 2
	removemoney MC_PRICE
	end

MauvilleCity_BattleCafe_EventScript_MauvilleRamenBowl::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_BattleCafe_Movement_Walk_ToArena
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MauvilleCity_BattleCafe_Text_Enjoy, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_IN_BATTLE_COURSE
	setvar VAR_BATTLE_COURSE_STATE, 3
	removemoney MRB_PRICE
	end

MauvilleCity_BattleCafe_EventScript_MealCourseDeclined::
	msgbox MauvilleCity_BattleCafe_Text_Declined, MSGBOX_DEFAULT
	closemessage
	setvar VAR_BATTLE_COURSE_STATE, 0
	end

MauvilleCity_BattleCafe_EventScript_RewardWaiter::
	msgbox MauvilleCity_BattleCafe_Text_Rewards, MSGBOX_DEFAULT
	waitmessage
	delay 5
	goto_if_eq VAR_BATTLE_COURSE_STATE, 4, MauvilleCity_BattleCafe_EventScript_Uncompleted
	goto_if_eq VAR_BATTLE_COURSE_STATE, 5, MauvilleCity_BattleCafe_EventScript_Completed_VillageSubCombo
	goto_if_eq VAR_BATTLE_COURSE_STATE, 6, MauvilleCity_BattleCafe_EventScript_Completed_MagnemiteCroquette
	goto_if_eq VAR_BATTLE_COURSE_STATE, 7, MauvilleCity_BattleCafe_EventScript_Completed_MauvilleRamenBowl
	end

MauvilleCity_BattleCafe_EventScript_Uncompleted::
	msgbox MauvilleCity_BattleCafe_Text_Uncompleted, MSGBOX_DEFAULT
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_Completed_VillageSubCombo::
	random 5
	switch VAR_RESULT
	case 0, MauvilleCity_BattleCafe_EventScript_VSC_FigyBerry
	case 1, MauvilleCity_BattleCafe_EventScript_VSC_WikiBerry
	case 2, MauvilleCity_BattleCafe_EventScript_VSC_MagoBerry
	case 3, MauvilleCity_BattleCafe_EventScript_VSC_AguavBerry
	case 4, MauvilleCity_BattleCafe_EventScript_VSC_IapapaBerry
	return
	end

MauvilleCity_BattleCafe_EventScript_VSC_FigyBerry::
	msgbox MauvilleCity_BattleCafe_Text_Completed, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_NUGGET, 1
	giveitem ITEM_FIGY_BERRY, 1
	setvar VAR_BATTLE_COURSE_STATE, 0
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_VSC_WikiBerry::
	msgbox MauvilleCity_BattleCafe_Text_Completed, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_NUGGET, 1
	giveitem ITEM_WIKI_BERRY, 1
	setvar VAR_BATTLE_COURSE_STATE, 0
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_VSC_MagoBerry::
	msgbox MauvilleCity_BattleCafe_Text_Completed, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_NUGGET, 1
	giveitem ITEM_MAGO_BERRY, 1
	setvar VAR_BATTLE_COURSE_STATE, 0
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_VSC_AguavBerry::
	msgbox MauvilleCity_BattleCafe_Text_Completed, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_NUGGET, 1
	giveitem ITEM_AGUAV_BERRY, 1
	setvar VAR_BATTLE_COURSE_STATE, 0
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_VSC_IapapaBerry::
	msgbox MauvilleCity_BattleCafe_Text_Completed, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_NUGGET, 1
	giveitem ITEM_IAPAPA_BERRY, 1
	setvar VAR_BATTLE_COURSE_STATE, 0
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_Completed_MagnemiteCroquette::
	msgbox MauvilleCity_BattleCafe_Text_Completed, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_PEARL_STRING, 1
	giveitem ITEM_METAL_POWDER, 1
	setvar VAR_BATTLE_COURSE_STATE, 0
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_Completed_MauvilleRamenBowl::
	msgbox MauvilleCity_BattleCafe_Text_Completed, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BIG_NUGGET, 2
	giveitem ITEM_DEEP_SEA_TOOTH, 1
	giveitem ITEM_DEEP_SEA_SCALE, 1
	setvar VAR_BATTLE_COURSE_STATE, 0
	closemessage
	end

MauvilleCity_BattleCafe_EventScript_Trashcan::
	lock
	call_if_unset FLAG_DAILY_BATTLE_CAFE_TRASH_CAN, MauvilleCity_BattleCafe_EventScript_Trashcan_NotEmpty
	call_if_set FLAG_DAILY_BATTLE_CAFE_TRASH_CAN, MauvilleCity_BattleCafe_EventScript_Trashcan_Empty
	release
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_NotEmpty::
	random 7
	switch VAR_RESULT
	case 0, MauvilleCity_BattleCafe_EventScript_Trashcan_Leftovers
	case 1, MauvilleCity_BattleCafe_EventScript_Trashcan_MicleBerry
	case 2, MauvilleCity_BattleCafe_EventScript_Trashcan_CustapBerry
	case 3, MauvilleCity_BattleCafe_EventScript_Trashcan_JabocaBerry
	case 4, MauvilleCity_BattleCafe_EventScript_Trashcan_RowapBerry
	case 5, MauvilleCity_BattleCafe_EventScript_Trashcan_KeeBerry
	case 6, MauvilleCity_BattleCafe_EventScript_Trashcan_MarangaBerry
	return
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_Leftovers::
	bufferitemname STR_VAR_1, ITEM_LEFTOVERS
	msgbox MauvilleCity_BattleCafe_Text_Trashcan_NotEmpty, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_LEFTOVERS, 1
	setflag FLAG_DAILY_BATTLE_CAFE_TRASH_CAN
	return
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_MicleBerry::
	bufferitemname STR_VAR_1, ITEM_MICLE_BERRY
	msgbox MauvilleCity_BattleCafe_Text_Trashcan_NotEmpty, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_MICLE_BERRY, 1
	setflag FLAG_DAILY_BATTLE_CAFE_TRASH_CAN
	return
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_CustapBerry::
	bufferitemname STR_VAR_1, ITEM_CUSTAP_BERRY
	msgbox MauvilleCity_BattleCafe_Text_Trashcan_NotEmpty, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_CUSTAP_BERRY, 1
	setflag FLAG_DAILY_BATTLE_CAFE_TRASH_CAN
	return
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_JabocaBerry::
	bufferitemname STR_VAR_1, ITEM_JABOCA_BERRY
	msgbox MauvilleCity_BattleCafe_Text_Trashcan_NotEmpty, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_JABOCA_BERRY, 1
	setflag FLAG_DAILY_BATTLE_CAFE_TRASH_CAN
	return
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_RowapBerry::
	bufferitemname STR_VAR_1, ITEM_ROWAP_BERRY
	msgbox MauvilleCity_BattleCafe_Text_Trashcan_NotEmpty, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_ROWAP_BERRY, 1
	setflag FLAG_DAILY_BATTLE_CAFE_TRASH_CAN
	return
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_KeeBerry::
	bufferitemname STR_VAR_1, ITEM_KEE_BERRY
	msgbox MauvilleCity_BattleCafe_Text_Trashcan_NotEmpty, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_KEE_BERRY, 1
	setflag FLAG_DAILY_BATTLE_CAFE_TRASH_CAN
	return
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_MarangaBerry::
	bufferitemname STR_VAR_1, ITEM_MARANGA_BERRY
	msgbox MauvilleCity_BattleCafe_Text_Trashcan_NotEmpty, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_MARANGA_BERRY, 1
	setflag FLAG_DAILY_BATTLE_CAFE_TRASH_CAN
	return
	end

MauvilleCity_BattleCafe_EventScript_Trashcan_Empty::
	msgbox MauvilleCity_BattleCafe_Text_Trashcan_Empty, MSGBOX_DEFAULT
	closemessage
	return
	end

MauvilleCity_BattleCafe_EventScript_Steenee::
	lock
	faceplayer
	playmoncry SPECIES_STEENEE, CRY_MODE_NORMAL
	waitmoncry
	msgbox MauvilleCity_BattleCafe_Text_Steenee, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_Smeargle::
	lock
	faceplayer
	playmoncry SPECIES_SMEARGLE, CRY_MODE_NORMAL
	waitmoncry
	msgbox MauvilleCity_BattleCafe_Text_Smeargle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_OldMan, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_OldWoman::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_OldWoman, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_LittleBoy, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_Boy::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_Boy, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_Boy2::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_Boy2, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_Waiter::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_Waiter, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_Steenee2::
	lock
	faceplayer
	playmoncry SPECIES_STEENEE, CRY_MODE_NORMAL
	waitmoncry
	msgbox MauvilleCity_BattleCafe_Text_Steenee2, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_Woman2::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_Woman2, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_Woman, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_EventScript_Artist::
	lock
	faceplayer
	msgbox MauvilleCity_BattleCafe_Text_Artist, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BattleCafe_Movement_Step_Aside::
	walk_up
	face_down
	step_end

MauvilleCity_BattleCafe_Movement_Jump::
	jump_in_place_down
	step_end

MauvilleCity_BattleCafe_Movement_Walk_Forwards::
	walk_up
	step_end

MauvilleCity_BattleCafe_Movement_Walk_ToRightCounter::
	walk_down
	walk_right
	walk_right
	face_up
	step_end

MauvilleCity_BattleCafe_Movement_Walk_ToLeftCounter::
	walk_down
	walk_left
	walk_left
	face_up
	step_end

MauvilleCity_BattleCafe_Movement_Walk_ToArena::
	walk_right
	walk_right
	walk_up
	walk_up
	face_up
	step_end

MauvilleCity_BattleCafe_Text_Trashcan_NotEmpty::
	.string "There is something in the trashcan!\p"
	.string "You found {STR_VAR_1}!$"

MauvilleCity_BattleCafe_Text_Trashcan_Empty::
	.string "This trashcan is empty.$"

MauvilleCity_BattleCafe_Text_Steenee::
	.string "Stee Steenee!\n"
	.string "This Pokémon is busy working.$"

MauvilleCity_BattleCafe_Text_Steenee2::
	.string "Stee Steenee!\n"
	.string "This Pokémon is eating.$"

MauvilleCity_BattleCafe_Text_Smeargle::
	.string "Smear Smeargle!\n"
	.string "This Pokémon is happily eating.$"

MauvilleCity_BattleCafe_Text_OldMan::
	.string "This restaurant is pretty nice.\n"
	.string "My wife likes the food here.$"

MauvilleCity_BattleCafe_Text_OldWoman::
	.string "There's a battle course in the back.\p"
	.string "My husband likes to battle there\n"
	.string "while we wait for our food.$"

MauvilleCity_BattleCafe_Text_LittleBoy::
	.string "My big brother is treating me for\n"
	.string "my 6th birthday today!$"

MauvilleCity_BattleCafe_Text_Boy::
	.string "Today is my little brother's birthday.\p"
	.string "Our family is setting up his surprise\n"
	.string "party at our house.$"

MauvilleCity_BattleCafe_Text_Boy2::
	.string "I'm waiting for someone to arrive.\n"
	.string "Hopefully they show up soon.$"

MauvilleCity_BattleCafe_Text_Woman::
	.string "This is our first time seeing each other\n"
	.string "in years. Ever since my cousin moved to\p"
	.string "the Kanto region, we have been sending\n"
	.string "mail to each other to keep in touch.$"

MauvilleCity_BattleCafe_Text_Woman2::
	.string "I haven't seen my cousin ever since I\n"
	.string "moved to the Kanto region. But being\p"
	.string "back in Hoenn feels nostalgic.$"

MauvilleCity_BattleCafe_Text_Artist::
	.string "I'm feeding my Smeargle a meal here\n"
	.string "before we head out to get some\p"
	.string "inspiration for our next art piece.$"

MauvilleCity_BattleCafe_Text_Waiter::
	.string "Sorry, we are currently on our\n"
	.string "lunch break at the moment.$"

MauvilleCity_BattleCafe_Text_BattleCourse::
	.string "Welcome, behind me is the entrance to\n"
	.string "the Battle Course. Here you can engage\p"
	.string "in battles while you wait for your meal.\n"
	.string "We offer a variety of different meals,\p"
	.string "which one would you like to have?$"

MauvilleCity_BattleCafe_Text_Enjoy::
	.string "Enjoy your Battle Course meal!$"

MauvilleCity_BattleCafe_Text_Declined::
	.string "Understood, see you next time.$"

MauvilleCity_BattleCafe_Text_VillageSubCombo::
	.string "Village Sub Combo{CLEAR_TO 0x48}¥1000$"

MauvilleCity_BattleCafe_Text_MagnemiteCroquette::
	.string "Magnemite Croquette{CLEAR_TO 0x48}¥2500$"

MauvilleCity_BattleCafe_Text_MauvilleRamenBowl::
	.string "Mauville Ramen Bowl{CLEAR_TO 0x48}¥5000$"

MauvilleCity_BattleCafe_Text_DeclineMealCourse::
	.string "Decline Meal Course$"

MauvilleCity_BattleCafe_Text_TeraMeal::
	.string "Welcome, I can make a meal that changes\n"
	.string "the Tera Type of your chosen Pokémon.\p"
	.string "All meals cost{CLEAR_TO 0x48}¥500. So,\n"
	.string "which Type do you want to change to?$"

MauvilleCity_BattleCafe_Text_TeraTypeChanged::
	.string "Your Pokémon's Tera Type has changed.$"

MauvilleCity_BattleCafe_Text_ComeAgain::
	.string "Come back, when you want to\n"
	.string "change your Pokémon's Tera Type.$"

MauvilleCity_BattleCafe_Text_EggCantChangeTeraType::
	.string "Eggs can't change their Tera Type.$"

MauvilleCity_BattleCafe_Text_AlreadyTeraType::
	.string "Your Pokémon is already this Tera Type.$"

MauvilleCity_BattleCafe_Text_OverHere::
	.string "Excuse me! Come over here please.$"

MauvilleCity_BattleCafe_Text_Rewards::
	.string "Welcome, this is the rewards counter\n"
	.string "for the Mauville City Battle Café's\p"
	.string "Battle Courses. Let me see if you have\n"
	.string "any rewards to claim.$"

MauvilleCity_BattleCafe_Text_Uncompleted::
	.string "Sorry, it seems that you haven't\n"
	.string "completed any of the battle courses.$"

MauvilleCity_BattleCafe_Text_Completed::
	.string "Congratulations! You have completed a\n"
	.string "battle course, here are your rewards.$"

MauvilleCity_BattleCafe_Text_Normal::
	.string "Normal$"

MauvilleCity_BattleCafe_Text_Fighting::
	.string "Fighting$"

MauvilleCity_BattleCafe_Text_Ghost::
	.string "Ghost$"

MauvilleCity_BattleCafe_Text_Fire::
	.string "Fire$"

MauvilleCity_BattleCafe_Text_Water::
	.string "Water$"

MauvilleCity_BattleCafe_Text_Grass::
	.string "Grass$"

MauvilleCity_BattleCafe_Text_Ground::
	.string "Ground$"

MauvilleCity_BattleCafe_Text_Rock::
	.string "Rock$"

MauvilleCity_BattleCafe_Text_Bug::
	.string "Bug$"

MauvilleCity_BattleCafe_Text_Poison::
	.string "Poison$"

MauvilleCity_BattleCafe_Text_Ice::
	.string "Ice$"

MauvilleCity_BattleCafe_Text_Dragon::
	.string "Dragon$"

MauvilleCity_BattleCafe_Text_Flying::
	.string "Flying$"

MauvilleCity_BattleCafe_Text_Psychic::
	.string "Psychic$"

MauvilleCity_BattleCafe_Text_Electric::
	.string "Electric$"

MauvilleCity_BattleCafe_Text_Steel::
	.string "Steel$"

MauvilleCity_BattleCafe_Text_Dark::
	.string "Dark$"

MauvilleCity_BattleCafe_Text_Fairy::
	.string "Fairy$"

MauvilleCity_BattleCafe_Text_Stellar::
	.string "Stellar$"

MauvilleCity_BattleCafe_Text_Decline::
	.string "Decline$"
