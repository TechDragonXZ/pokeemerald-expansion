DeepPetalburgWoods_MapScripts::
	.byte 0

Found_Megastone::
	finditem ITEM_BEEDRILLITE
	end

DeepPetalburgWoods_Stuck_Scientist::
	lock
	faceplayer
	msgbox DeepPetalburgWoods_Text_Stuck, MSGBOX_AUTOCLOSE
	closemessage
	release
	end

DeepPetalburgWoods_Text_Stuck::
	.string "I forgot to bring a Pokémon with Surf.\n"
	.string "I'll have to call someone over.$"
