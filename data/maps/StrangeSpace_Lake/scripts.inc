StrangeSpace_Lake_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, StrangeSpace_Lake_ChamberState
	.byte 0

StrangeSpace_Lake_Chamber::
	msgbox StrangeSpace_Lake_Text_Regis, MSGBOX_AUTOCLOSE
	delay 30
	showmonpic SPECIES_REGICE, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGICE
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Lake_Chamber_Two
	msgbox StrangeSpace_Lake_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_Lake_Chamber_Two::
	showmonpic SPECIES_REGIROCK, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGIROCK
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Lake_Chamber_Three
	msgbox StrangeSpace_Lake_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_Lake_Chamber_Three::
	showmonpic SPECIES_REGISTEEL, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGISTEEL
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Lake_OpeningChamber
	msgbox StrangeSpace_Lake_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_Lake_ChamberState::
	goto_if_set FLAG_REGIDRAGO_ACTIVE, StrangeSpace_Lake_OpenChamber
	goto_if_unset FLAG_REGIDRAGO_ACTIVE, StrangeSpace_Lake_CloseChamber
	end

StrangeSpace_Lake_OpeningChamber::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	delay 30
	setmetatile 17, 34, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 17, 35, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 18, 34, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 18, 35, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 19, 34, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 19, 35, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	releaseall
	setflag FLAG_REGIDRAGO_ACTIVE
	end

StrangeSpace_Lake_OpenChamber::
	setmetatile 17, 34, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 17, 35, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 18, 34, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 18, 35, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 19, 34, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 19, 35, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	end

StrangeSpace_Lake_CloseChamber::
	setmetatile 17, 34, METATILE_Cave_SandyChamber_Top, TRUE
	setmetatile 17, 35, METATILE_Cave_SandyChamberBraille_BottomLeft, TRUE
	setmetatile 18, 34, METATILE_Cave_SandyChamber_Top, TRUE
	setmetatile 18, 35, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 19, 34, METATILE_Cave_SandyChamber_Top, TRUE
	setmetatile 19, 35, METATILE_Cave_SandyChamberBraille_BottomRight, TRUE
	special DrawWholeMapView
	end

StrangeSpace_Lake_Text_CantOpenChamber::
	.string "You don't have the required\nPokémon to open this chamber!$"

StrangeSpace_Lake_Text_Regis::
	.string "This chamber only opens once all\nthree Regis are gathered here.$"
