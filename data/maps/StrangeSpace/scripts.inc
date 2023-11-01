StrangeSpace_MapScripts::
	.byte 0

StrangeSpace_StrangeStone::
	msgbox StrangeSpace_Text_StrangeStone, MSGBOX_DEFAULT
	closemessage
	multichoice 21, 8, MULTI_YESNO, TRUE
	switch VAR_RESULT
	case 1, StrangeSpace_WalkAway
	case 0, StrangeSpace_StrangeStoneWarp
	end

StrangeSpace_StrangeStoneWarp::
	msgbox StrangeSpace_Text_Warp, MSGBOX_DEFAULT
	closemessage
	warp MAP_UNDERWATER_CAVE, 3, 4
	end

StrangeSpace_WalkAway::
	msgbox StrangeSpace_Text_WalkAway, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpace_NoFossil::
	msgbox StrangeSpace_Text_NoFossil, MSGBOX_AUTOCLOSE
	closemessage
	end

StrangeSpace_StrangePillar::
	msgbox StrangeSpace_Text_StrangePillar, MSGBOX_DEFAULT
	closemessage
	multichoice 21, 0, MULTI_STRANGE_PILLAR1, TRUE
	switch VAR_RESULT
	case 0, StrangeSpace_HelixFossil
	case 1, StrangeSpace_DomeFossil
	case 2, StrangeSpace_OldAmber
	case 3, StrangeSpace_RootFossil
	case 4, StrangeSpace_StrangePillar2
	case 5, StrangeSpace_WalkAway
	end

StrangeSpace_StrangePillar2::
	multichoice 21, 0, MULTI_STRANGE_PILLAR2, TRUE
	switch VAR_RESULT
	case 0, StrangeSpace_ClawFossil
	case 1, StrangeSpace_ArmorFossil
	case 2, StrangeSpace_SkullFossil
	case 3, StrangeSpace_OddKeystone
	case 4, StrangeSpace_StrangePillar3
	case 5, StrangeSpace_StrangePillar1
	case 6, StrangeSpace_WalkAway
	end

StrangeSpace_StrangePillar3::
	multichoice 21, 0, MULTI_STRANGE_PILLAR3, TRUE
	switch VAR_RESULT
	case 0, StrangeSpace_CoverFossil
	case 1, StrangeSpace_PlumeFossil
	case 2, StrangeSpace_JawFossil
	case 3, StrangeSpace_SailFossil
	case 4, StrangeSpace_StrangePillar4
	case 5, StrangeSpace_StrangePillar2
	case 6, StrangeSpace_WalkAway
	end

StrangeSpace_StrangePillar4::
	multichoice 21, 0, MULTI_STRANGE_PILLAR4, TRUE
	switch VAR_RESULT
	case 0, StrangeSpace_FossilizedBird
	case 1, StrangeSpace_FossilizedDino
	case 2, StrangeSpace_FossilizedDrake
	case 3, StrangeSpace_FossilizedFish
	case 4, StrangeSpace_StrangePillar3
	case 5, StrangeSpace_WalkAway
	end

StrangeSpace_StrangePillar1::
	multichoice 21, 0, MULTI_STRANGE_PILLAR1, TRUE
	switch VAR_RESULT
	case 0, StrangeSpace_HelixFossil
	case 1, StrangeSpace_DomeFossil
	case 2, StrangeSpace_OldAmber
	case 3, StrangeSpace_RootFossil
	case 4, StrangeSpace_StrangePillar2
	case 5, StrangeSpace_WalkAway
	end

StrangeSpace_HelixFossil::
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Omanyte
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_DomeFossil::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Kabuto
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_OldAmber::
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Aerodactyl
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_RootFossil::
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Lileep
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_ClawFossil::
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Anorith
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_ArmorFossil::
	checkitem ITEM_ARMOR_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Shieldon
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_SkullFossil::
	checkitem ITEM_SKULL_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Cranidos
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_OddKeystone::
	checkitem ITEM_ODD_KEYSTONE
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Spiritomb
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_CoverFossil::
	checkitem ITEM_COVER_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Tirtouga
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_PlumeFossil::
	checkitem ITEM_PLUME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Archen
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_JawFossil::
	checkitem ITEM_JAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Tyrunt
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_SailFossil::
	checkitem ITEM_SAIL_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Amaura
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_FossilizedBird::
	checkitem ITEM_FOSSILIZED_BIRD
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Dracozolt
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_FossilizedDino::
	checkitem ITEM_FOSSILIZED_DINO
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Arctozolt
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_FossilizedDrake::
	checkitem ITEM_FOSSILIZED_DRAKE
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Dracovish
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_FossilizedFish::
	checkitem ITEM_FOSSILIZED_FISH
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Arctovish
	goto_if_eq VAR_RESULT, FALSE, StrangeSpace_NoFossil
	end

StrangeSpace_Omanyte::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_HELIX_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_OMANYTE, 20, ITEM_MYSTIC_WATER, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Kabuto::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_DOME_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_KABUTO, 20, ITEM_MYSTIC_WATER, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Aerodactyl::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_OLD_AMBER
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_AERODACTYL, 20, ITEM_SHARP_BEAK, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Lileep::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_ROOT_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_LILEEP, 20, ITEM_MIRACLE_SEED, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Anorith::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_CLAW_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	msgbox StrangeSpace_Text_StrangePillar_SpawnedAn, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_ANORITH, 20, ITEM_SILVER_POWDER, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Shieldon::
	bufferitemname STR_VAR_1, ITEM_ARMOR_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_ARMOR_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_SHIELDON
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_SHIELDON, 20, ITEM_METAL_COAT, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Cranidos::
	bufferitemname STR_VAR_1, ITEM_SKULL_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_SKULL_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_CRANIDOS
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_CRANIDOS, 20, ITEM_HARD_STONE, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Spiritomb::
	bufferitemname STR_VAR_1, ITEM_ODD_KEYSTONE
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_ODD_KEYSTONE
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_SPIRITOMB
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_SPIRITOMB, 20, ITEM_BLACK_GLASSES, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Tirtouga::
	bufferitemname STR_VAR_1, ITEM_COVER_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_COVER_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_TIRTOUGA
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_TIRTOUGA, 20, ITEM_MYSTIC_WATER, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Archen::
	bufferitemname STR_VAR_1, ITEM_PLUME_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_PLUME_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_ARCHEN
	msgbox StrangeSpace_Text_StrangePillar_SpawnedAn, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_ARCHEN, 20, ITEM_SHARP_BEAK, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Tyrunt::
	bufferitemname STR_VAR_1, ITEM_JAW_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_JAW_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_TYRUNT
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_TYRUNT, 20, ITEM_DRAGON_FANG, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Amaura::
	bufferitemname STR_VAR_1, ITEM_SAIL_FOSSIL
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_SAIL_FOSSIL
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_AMAURA
	msgbox StrangeSpace_Text_StrangePillar_SpawnedAn, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_AMAURA, 20, ITEM_NEVER_MELT_ICE, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Dracozolt::
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_BIRD
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_FOSSILIZED_BIRD
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_DRACOZOLT
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_DRACOZOLT, 20, ITEM_MAGNET, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Arctozolt::
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_DINO
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_FOSSILIZED_DINO
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_ARCTOZOLT
	msgbox StrangeSpace_Text_StrangePillar_SpawnedAn, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_ARCTOZOLT, 20, ITEM_NEVER_MELT_ICE, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Dracovish::
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_DRAKE
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_FOSSILIZED_DRAKE
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_DRACOVISH
	msgbox StrangeSpace_Text_StrangePillar_Spawned, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_DRACOVISH, 20, ITEM_DRAGON_FANG, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Arctovish::
	bufferitemname STR_VAR_1, ITEM_FOSSILIZED_FISH
	msgbox StrangeSpace_Text_StrangePillar_Placed, MSGBOX_DEFAULT
	closemessage
	removeitem ITEM_FOSSILIZED_FISH
	delay 30
	bufferspeciesname STR_VAR_2, SPECIES_ARCTOVISH
	msgbox StrangeSpace_Text_StrangePillar_SpawnedAn, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_ARCTOVISH, 20, ITEM_MYSTIC_WATER, SPECIES_NONE
	dowildbattle
	release
	end

StrangeSpace_Text_WalkAway::
	.string "You walked away.$"

StrangeSpace_Text_NoFossil::
	.string "You don't have that item.$"

StrangeSpace_Text_Warp::
	.string "Everything went dark.$"

StrangeSpace_Text_StrangeStone::
	.string "It's a strange stone.\n"
	.string "The surrounding air feels cool.\p"
	.string "Do you want to touch it?$"

StrangeSpace_Text_StrangePillar::
	.string "It's a strange pillar.\n"
	.string "There's an empty slot at the top.\p"
	.string "What do you want to put in it?$"

StrangeSpace_Text_StrangePillar_Placed:
	.string "You placed the {STR_VAR_1} into\n"
	.string "the pillar's empty slot.$"

StrangeSpace_Text_StrangePillar_Spawned:
	.string "A {STR_VAR_2} appeared from the\n"
	.string "top of the Strange Pillar.$"

StrangeSpace_Text_StrangePillar_SpawnedAn:
	.string "An {STR_VAR_2} appeared from the\n"
	.string "top of the Strange Pillar.$"
