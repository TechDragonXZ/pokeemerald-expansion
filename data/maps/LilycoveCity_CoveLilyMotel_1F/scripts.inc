.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Stone_Guy::
	lock
	faceplayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Text_Welcome, MSGBOX_DEFAULT
	waitmessage
	msgbox LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Text_Asks_Rings, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, 1, LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Checks_Rings
	goto_if_eq VAR_RESULT, 0, LilycoveCity_CoveLilyMotel_1F_WalkAway
	release
	end

LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Checks_Rings::
	checkitem ITEM_MEGA_RING, 1
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Notice_Mega_Ring
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Check_Z_Ring
	end

LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Check_Z_Ring::
	checkitem ITEM_Z_POWER_RING, 1
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Notice_Z_Ring
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_1F_Stone_Guy_No_Rings
	end

LilycoveCity_CoveLilyMotel_1F_Stone_Guy_No_Rings::
	lock
	faceplayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_No_Rings, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Notice_Mega_Ring::
	checkitem ITEM_Z_POWER_RING, 1
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Also_Have_Z_Ring
	goto_if_ge VAR_MEGASTONE_COUNT, 21, LilycoveCity_CoveLilyMotel_1F_Megastone_Advanced
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_Mega_Ring, MSGBOX_AUTOCLOSE
	closemessage
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_CoveLilyMotel_1F_Megastone_Shop_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Also_Have_Z_Ring::
	lock
	faceplayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_Both_Rings, MSGBOX_DEFAULT
	closemessage
	multichoice 21, 8, MULTI_MEGA_Z_SHOP, TRUE
	switch VAR_RESULT
	case 2, LilycoveCity_CoveLilyMotel_1F_WalkAway
	case 1, LilycoveCity_CoveLilyMotel_1F_Z_Crystals
	case 0, LilycoveCity_CoveLilyMotel_1F_Megastones
	release
	end

LilycoveCity_CoveLilyMotel_1F_Megastones::
	goto_if_ge VAR_MEGASTONE_COUNT, 21, LilycoveCity_CoveLilyMotel_1F_Megastone_Advanced
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_CoveLilyMotel_1F_Megastone_Shop_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_1F_Megastone_Advanced::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_CoveLilyMotel_1F_Megastone_Shop_Advanced
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_1F_Z_Crystals::
	goto_if_ge VAR_Z_CRYSTAL_COUNT, 11, LilycoveCity_CoveLilyMotel_1F_Z_Crystals_Advanced
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_CoveLilyMotel_1F_Z_Crystal_Shop_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_1F_Z_Crystals_Advanced::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_CoveLilyMotel_1F_Z_Crystal_Shop_Advanced
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_1F_WalkAway::
	lock
	faceplayer
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

	.align 2
LilycoveCity_CoveLilyMotel_1F_Megastone_Shop_Basic::
	.2byte ITEM_ABOMASITE
	.2byte ITEM_AGGRONITE
	.2byte ITEM_AMPHAROSITE
	.2byte ITEM_AUDINITE
	.2byte ITEM_BEEDRILLITE
	.2byte ITEM_GARCHOMPITE
	.2byte ITEM_GARDEVOIRITE
	.2byte ITEM_GENGARITE
	.2byte ITEM_HERACRONITE
	.2byte ITEM_LOPUNNITE
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_MAWILITE
	.2byte ITEM_PIDGEOTITE
	.2byte ITEM_PINSIRITE
	.2byte ITEM_SCIZORITE
	.2byte ITEM_STEELIXITE
	.2byte ITEM_TYRANITARITE
	.2byte ITEM_NONE
	release
	end

	.align 2
LilycoveCity_CoveLilyMotel_1F_Megastone_Shop_Advanced::
	.2byte ITEM_ABOMASITE
	.2byte ITEM_AGGRONITE
	.2byte ITEM_AMPHAROSITE
	.2byte ITEM_AUDINITE
	.2byte ITEM_BEEDRILLITE
	.2byte ITEM_GARCHOMPITE
	.2byte ITEM_GARDEVOIRITE
	.2byte ITEM_GENGARITE
	.2byte ITEM_HERACRONITE
	.2byte ITEM_LOPUNNITE
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_MAWILITE
	.2byte ITEM_PIDGEOTITE
	.2byte ITEM_PINSIRITE
	.2byte ITEM_SABLENITE
	.2byte ITEM_SCIZORITE
	.2byte ITEM_STEELIXITE
	.2byte ITEM_TYRANITARITE
	.2byte ITEM_ABSOLITE
	.2byte ITEM_AERODACTYLITE
	.2byte ITEM_ALAKAZITE
	.2byte ITEM_ALTARIANITE
	.2byte ITEM_BANETTITE
	.2byte ITEM_BLASTOISINITE
	.2byte ITEM_BLAZIKENITE
	.2byte ITEM_CAMERUPTITE
	.2byte ITEM_CHARIZARDITE_X
	.2byte ITEM_CHARIZARDITE_Y
	.2byte ITEM_GALLADITE
	.2byte ITEM_GLALITITE
	.2byte ITEM_GYARADOSITE
	.2byte ITEM_HOUNDOOMINITE
	.2byte ITEM_KANGASKHANITE
	.2byte ITEM_MANECTITE
	.2byte ITEM_MEDICHAMITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_SALAMENCITE
	.2byte ITEM_SCEPTILITE
	.2byte ITEM_SHARPEDONITE
	.2byte ITEM_SLOWBRONITE
	.2byte ITEM_SWAMPERTITE
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_NONE
	release
	end

LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Notice_Z_Ring::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_Z_Ring, MSGBOX_AUTOCLOSE
	closemessage
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_CoveLilyMotel_1F_Z_Crystal_Shop_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_CoveLilyMotel_1F_Z_Crystal_Shop_Basic::
	.2byte ITEM_NORMALIUM_Z
	.2byte ITEM_WATERIUM_Z
	.2byte ITEM_FIRIUM_Z
	.2byte ITEM_GRASSIUM_Z
	.2byte ITEM_ELECTRIUM_Z
	.2byte ITEM_GROUNDIUM_Z
	.2byte ITEM_ROCKIUM_Z
	.2byte ITEM_DARKINIUM_Z
	.2byte ITEM_BUGINIUM_Z
	.2byte ITEM_PSYCHIUM_Z
	.2byte ITEM_GHOSTIUM_Z
	.2byte ITEM_FIGHTINIUM_Z
	.2byte ITEM_STEELIUM_Z
	.2byte ITEM_FAIRIUM_Z
	.2byte ITEM_POISONIUM_Z
	.2byte ITEM_DRAGONIUM_Z
	.2byte ITEM_ICIUM_Z
	.2byte ITEM_NONE
	release
	end

	.align 2
LilycoveCity_CoveLilyMotel_1F_Z_Crystal_Shop_Advanced::
	.2byte ITEM_NORMALIUM_Z
	.2byte ITEM_WATERIUM_Z
	.2byte ITEM_FIRIUM_Z
	.2byte ITEM_GRASSIUM_Z
	.2byte ITEM_ELECTRIUM_Z
	.2byte ITEM_GROUNDIUM_Z
	.2byte ITEM_ROCKIUM_Z
	.2byte ITEM_DARKINIUM_Z
	.2byte ITEM_BUGINIUM_Z
	.2byte ITEM_PSYCHIUM_Z
	.2byte ITEM_GHOSTIUM_Z
	.2byte ITEM_FIGHTINIUM_Z
	.2byte ITEM_STEELIUM_Z
	.2byte ITEM_FAIRIUM_Z
	.2byte ITEM_POISONIUM_Z
	.2byte ITEM_DRAGONIUM_Z
	.2byte ITEM_ICIUM_Z
	.2byte ITEM_ALORAICHIUM_Z
	.2byte ITEM_DECIDIUM_Z
	.2byte ITEM_EEVIUM_Z
	.2byte ITEM_INCINIUM_Z
	.2byte ITEM_KOMMONIUM_Z
	.2byte ITEM_LYCANIUM_Z
	.2byte ITEM_MIMIKIUM_Z
	.2byte ITEM_PIKANIUM_Z
	.2byte ITEM_PIKASHUNIUM_Z
	.2byte ITEM_PRIMARIUM_Z
	.2byte ITEM_SNORLIUM_Z
	.2byte ITEM_NONE
	release
	end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, so they doubled the guests by\n"
	.string "using Pokémon as attractions?\p"
	.string "Hm, well, maybe I should make a cute\n"
	.string "Pokémon our inn's mascot.\p"
	.string "I wonder if that will attract more\n"
	.string "guests to stay with us?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "Since that Team Aqua came to town,\n"
	.string "the tourists have been staying away.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hey, down in front!\n"
	.string "I can't see the TV!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem: @ 82183C3
	.string "Amazing! You're telling me a Pokémon\n"
	.string "found someone's lost item?\p"
	.string "That's something. If we had some smart\n"
	.string "Pokémon like that…\p"
	.string "We could recover anything that our\n"
	.string "guests mislaid…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "I heard that someone busted\n"
	.string "the Team Aqua Hideout.\p"
	.string "Thanks to that, we just booked\n"
	.string "a reservation from a big group.\p"
	.string "It was a company called… Uh…\n"
	.string "Game something…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar: @ 8218544
	.string "Amazing! A house-sitting Pokémon\n"
	.string "caught a burglar?\p"
	.string "That's something. If we had a tough\n"
	.string "Pokémon as a security guard…\p"
	.string "We would be able to provide our guests\n"
	.string "with greater safety.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV.\p"
	.string "Oh, yes. A big group of guests arrived\n"
	.string "a little while ago.\p"
	.string "They booked in as Game Freak,\n"
	.string "so I guess they must make games.\p"
	.string "Uh-oh, I'd better get working on\n"
	.string "their dinner!$"

LilycoveCity_CoveLilyMotel_1F_Text_WalkAway::
	.string "You walked away.$"

LilycoveCity_CoveLilyMotel_1F_Text_No_Rings::
	.string "You don't have any special rings.$"

LilycoveCity_CoveLilyMotel_1F_Text_Mega_Ring::
	.string "You do have a MEGA RING!$"

LilycoveCity_CoveLilyMotel_1F_Text_Z_Ring::
	.string "You do have a Z POWER RING!$"

LilycoveCity_CoveLilyMotel_1F_Text_Both_Rings::
	.string "You have both a MEGA RING and\na Z POWER RING!\pWhich set do you want to buy from?$"

LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Text_Welcome::
	.string "Greetings, I run a little shop where I\nsell special stones and crystals.$"

LilycoveCity_CoveLilyMotel_1F_Stone_Guy_Text_Asks_Rings::
	.string "You wouldn't happen to have\nany special rings, would ya?$"

