StrangeSpace_IceCavern_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, StrangeSpace_IceCavern_ChamberState
	.byte 0

StrangeSpace_IceCavern_ChamberState::
	goto_if_set FLAG_REGIELEKI_ACTIVE, StrangeSpace_IceCavern_OpenChamber
	goto_if_unset FLAG_REGIELEKI_ACTIVE, StrangeSpace_IceCavern_CloseChamber
	end

StrangeSpace_IceCavern_Chamber::
	msgbox StrangeSpace_IceCavern_Text_Regis, MSGBOX_AUTOCLOSE
	delay 30
	showmonpic SPECIES_REGICE, 10, 3
	setvar 0x8005, SPECIES_REGICE
	special CheckSpecies
	delay 30
	hidemonpic
	delay 30
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_IceCavern_Chamber_Two
	msgbox StrangeSpace_IceCavern_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_IceCavern_Chamber_Two::
	showmonpic SPECIES_REGIROCK, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGIROCK
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_IceCavern_Chamber_Three
	msgbox StrangeSpace_IceCavern_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_IceCavern_Chamber_Three::
	showmonpic SPECIES_REGISTEEL, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGISTEEL
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_IceCavern_Chamber_Four
	msgbox StrangeSpace_IceCavern_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_IceCavern_Chamber_Four::
	showmonpic SPECIES_REGIDRAGO, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGIDRAGO
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_IceCavern_OpeningChamber
	msgbox StrangeSpace_IceCavern_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_IceCavern_OpeningChamber::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	delay 30
	setmetatile 11, 2, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 11, 3, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 12, 2, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 12, 3, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 13, 2, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 13, 3, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	releaseall
	setflag FLAG_REGIELEKI_ACTIVE
	end

StrangeSpace_IceCavern_OpenChamber::
	setmetatile 11, 2, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 11, 3, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 12, 2, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 12, 3, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 13, 2, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 13, 3, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	end

StrangeSpace_IceCavern_CloseChamber::
	setmetatile 11, 2, METATILE_Cave_EntranceCover, TRUE
	setmetatile 11, 3, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 12, 2, METATILE_Cave_EntranceCover, TRUE
	setmetatile 12, 3, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 13, 2, METATILE_Cave_EntranceCover, TRUE
	setmetatile 13, 3, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	special DrawWholeMapView
	end

StrangeSpace_IceCavern_Text_CantOpenChamber::
	.string "You don't have the required\nPokémon to open this chamber!$"

StrangeSpace_IceCavern_Text_Regis::
	.string "This chamber only opens once all\nfour Regis are gathered here.$"
