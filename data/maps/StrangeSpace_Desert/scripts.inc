StrangeSpace_Desert_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, StrangeSpace_Desert_ChamberState
	.byte 0

StrangeSpace_Desert_ChamberState::
	goto_if_set FLAG_REGIGIGAS_ACTIVE, StrangeSpace_Desert_OpenChamber
	goto_if_unset FLAG_REGIGIGAS_ACTIVE, StrangeSpace_Desert_CloseChamber
	end

StrangeSpace_Desert_Chamber::
	msgbox StrangeSpace_Desert_Text_Regis, MSGBOX_AUTOCLOSE
	delay 30
	showmonpic SPECIES_REGICE, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGICE
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Desert_Chamber_Two
	msgbox StrangeSpace_Desert_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_Desert_Chamber_Two::
	showmonpic SPECIES_REGIROCK, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGIROCK
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Desert_Chamber_Three
	msgbox StrangeSpace_Desert_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_Desert_Chamber_Three::
	showmonpic SPECIES_REGISTEEL, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGISTEEL
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Desert_Chamber_Four
	msgbox StrangeSpace_Desert_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_Desert_Chamber_Four::
	showmonpic SPECIES_REGIDRAGO, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGIDRAGO
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Desert_Chamber_Five
	msgbox StrangeSpace_Desert_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_Desert_Chamber_Five::
	showmonpic SPECIES_REGIELEKI, 10, 3
	delay 30
	hidemonpic
	delay 30
	setvar 0x8005, SPECIES_REGIELEKI
	special CheckSpecies
	goto_if_eq VAR_RESULT, TRUE, StrangeSpace_Desert_OpeningChamber
	msgbox StrangeSpace_Desert_Text_CantOpenChamber, MSGBOX_AUTOCLOSE
	end

StrangeSpace_Desert_OpeningChamber::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	delay 30
	setmetatile 31, 42, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 31, 43, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 32, 42, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 32, 43, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 33, 42, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 33, 43, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	releaseall
	setflag FLAG_REGIDRAGO_ACTIVE
	end

StrangeSpace_Desert_OpenChamber::
	setmetatile 31, 42, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 31, 43, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 32, 42, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 32, 43, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 33, 42, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 33, 43, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	end

StrangeSpace_Desert_CloseChamber::
	setmetatile 31, 42, METATILE_Cave_SandyChamber_Top, TRUE
	setmetatile 31, 43, METATILE_Cave_SandyChamberBraille_BottomLeft, TRUE
	setmetatile 32, 42, METATILE_Cave_SandyChamber_Top, TRUE
	setmetatile 32, 43, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 33, 42, METATILE_Cave_SandyChamber_Top, TRUE
	setmetatile 33, 43, METATILE_Cave_SandyChamberBraille_BottomRight, TRUE
	special DrawWholeMapView
	end

StrangeSpace_Desert_Text_CantOpenChamber::
	.string "You don't have the required\nPokémon to open this chamber!$"

StrangeSpace_Desert_Text_Regis::
	.string "This chamber only opens once all\nfive Regis are gathered here.$"
