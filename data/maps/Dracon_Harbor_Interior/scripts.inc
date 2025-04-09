Dracon_Harbor_Interior_MapScripts::
	.byte 0

Dracon_Harbor_Interior_EventScript_GateWorker::
	lockall
	faceplayer
	msgbox Dracon_Harbor_Interior_Text_SorryClosed, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Dracon_Harbor_Interior_Text_SorryClosed:
	.string "Sorry, the road ahead is currently\n"
	.string "closed. Come back another time.$"

Dracon_Harbor_Interior_EventScript_DeskWorker::
	lockall
	faceplayer
	msgbox Dracon_Harbor_Interior_Text_Areas, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Dracon_Harbor_Interior_Text_Areas:
	.string "Welcome to the Dracon Region!\n"
	.string "The road to the left is currently.\p"
	.string "closed. However, the elevator to the\n"
	.string "Terrarium is available for access.$"

Dracon_Harbor_Interior_EventScript_Merchant::
	lock
	faceplayer
	msgbox Dracon_Harbor_Interior_Text_Sales, MSGBOX_DEFAULT
	waitmessage
	pokemart Dracon_Harbor_Interior_Pokemart_SpecialItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Dracon_Harbor_Interior_Pokemart_SpecialItems::
	.2byte ITEM_AIR_BALLOON
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_HEAVY_DUTY_BOOTS
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_ABILITY_SHIELD
	.2byte ITEM_LOADED_DICE
	.2byte ITEM_CLEAR_AMULET
	pokemartlistend

Dracon_Harbor_Interior_Text_Sales:
	.string "I came to the Dracon Region in order to\n"
	.string "sell some of my special items. Sadly the\p"
	.string "road to the outer parts of the region.\n"
	.string "is currently closed so profits aren't\p"
	.string "very high for me. Though, would you like\n"
	.string "to buy some items yourself?$"
