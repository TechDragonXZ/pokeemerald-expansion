AerowayIsland_Cafe_MapScripts::
	.byte 0

AerowayIsland_Cafe_Shop_RegionalTreats::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart AerowayIsland_Cafe_Shop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
AerowayIsland_Cafe_Shop:
	.2byte ITEM_PEWTER_CRUNCHIES
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_OLD_GATEAU
	.2byte ITEM_CASTELIACONE
	.2byte ITEM_LUMIOSE_GALETTE
	.2byte ITEM_SHALOUR_SABLE
	.2byte ITEM_BIG_MALASADA
	.2byte ITEM_NONE
	release
	end

AerowayIsland_Cafe_Person_Waitress::
	lock
	faceplayer
	msgbox AerowayIsland_Cafe_Text_Waitress, MSGBOX_DEFAULT
	release
	end

AerowayIsland_Cafe_Person_Lass::
	lock
	faceplayer
	msgbox AerowayIsland_Cafe_Text_Lass, MSGBOX_DEFAULT
	release
	end

AerowayIsland_Cafe_Person_OldMan::
	lock
	faceplayer
	msgbox AerowayIsland_Cafe_Text_OldMan, MSGBOX_DEFAULT
	release
	end

AerowayIsland_Cafe_Person_OldWoman::
	lock
	faceplayer
	msgbox AerowayIsland_Cafe_Text_OldWoman, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, AerowayIsland_Cafe_Action_Accept
	goto_if_eq VAR_RESULT, NO, AerowayIsland_Cafe_Action_WalkAway
	release
	end

AerowayIsland_Cafe_Action_Accept::
	lock
	faceplayer
	msgbox AerowayIsland_Cafe_Text_OldWoman_Accepted, MSGBOX_AUTOCLOSE
	closemessage
	delay 10
	giveegg SPECIES_BASCULIN_WHITE_STRIPED
	release
	end

AerowayIsland_Cafe_Action_WalkAway::
	lock
	faceplayer
	msgbox AerowayIsland_Cafe_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

AerowayIsland_Cafe_Battle_Gentleman_Rob::
	lock
	faceplayer
	trainerbattle_single TRAINER_ROB, AerowayIsland_Cafe_Text_RobIntro, AerowayIsland_Cafe_Text_RobDefeated
	setflag FLAG_ROB_DEFEATED
	msgbox AerowayIsland_Cafe_Text_RobPostBattle, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

AerowayIsland_Cafe_Text_Waitress:
	.string "Sorry, we just opened and its sort of\nhectic here, so I don't have much time\pto freely talk with anyone else yet.$"

AerowayIsland_Cafe_Text_Lass:
	.string "I'm heading to the Sinnoh region\nfor my vacation later today.$"

AerowayIsland_Cafe_Text_OldMan:
	.string "We've just returned from our son's\nhouse in the Unova region.\p"
	.string "Our grandson has begun his Pokémon\njourney there as well.$"

AerowayIsland_Cafe_Text_OldWoman:
	.string "Our son has given us a couple of his\nPokémon, but it seems that one of them\p"
	.string "layed an egg, however we can't take\ncare of them at our age.\p"
	.string "Would you be willing to take it off of\nour hands and raise it?$"

AerowayIsland_Cafe_Text_OldWoman_Accepted:
	.string "You want to take this\nPokémon egg right now?$"
	.string "I thank you for helping us.$"

AerowayIsland_Cafe_Text_OldWoman_WalkAway:
	.string "Oh, you aren't able to take this\nPokémon egg right now?$"
	.string "I apologize for taking up your time.$"

AerowayIsland_Cafe_Text_WalkAway::
	.string "You declined and walked away.$"

AerowayIsland_Cafe_Text_RobIntro::
	.string "I've just returned from a family\nreunion in the Alola region.\p"
	.string "And have been itching to battle\nsomeone, after winning my family's\pyearly battle tournament.$"

AerowayIsland_Cafe_Text_RobDefeated::
	.string "Wow... I really let my victory there\ngo to my head, didn't I?$"

AerowayIsland_Cafe_Text_RobPostBattle::
	.string "I normaly travel alot for my work, and\nas a result I'm always using this\pairport."
	.string "So, come back tommorow if you\nwant to battle me again.$"
