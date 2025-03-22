TrimFurfrou::
	checkspecies SPECIES_FURFROU, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Dummy
	end

TrimFurfrou_Dummy::
	checkspecies SPECIES_FURFROU_NATURAL, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Heart
	end

TrimFurfrou_Heart::
	checkspecies SPECIES_FURFROU_HEART, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Star
	end

TrimFurfrou_Star::
	checkspecies SPECIES_FURFROU_STAR, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Diamond
	end

TrimFurfrou_Diamond::
	checkspecies SPECIES_FURFROU_DIAMOND, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Debutante
	end

TrimFurfrou_Debutante::
	checkspecies SPECIES_FURFROU_DEBUTANTE, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Matron
	end

TrimFurfrou_Matron::
	checkspecies SPECIES_FURFROU_MATRON, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Dandy
	end

TrimFurfrou_Dandy::
	checkspecies SPECIES_FURFROU_DANDY, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_LaReine
	end

TrimFurfrou_LaReine::
	checkspecies SPECIES_FURFROU_LA_REINE, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Kabuki
	end

TrimFurfrou_Kabuki::
	checkspecies SPECIES_FURFROU_KABUKI, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_Pharaoh
	end

TrimFurfrou_Pharaoh::
	checkspecies SPECIES_FURFROU_PHARAOH, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, TrimFurfrou_Furfrou
	goto TrimFurfrou_NoFurfrou
	end

TrimFurfrou_NoFurfrou::
	lockall
	msgbox TrimFurfrou_Text_Beginning_NoFurfrou, MSGBOX_DEFAULT
	goto TrimFurfrou_End
	end

TrimFurfrou_Furfrou::
	lockall
	msgbox TrimFurfrou_Text_Beginning_Furfrou, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TrimFurfrou_Start
	goto TrimFurfrou_TrimCanceled
	end

TrimFurfrou_End::
	releaseall
	end

TrimFurfrou_TrimCanceled::
	msgbox TrimFurfrou_Text_Canceled, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

TrimFurfrou_Start::
	msgbox TrimFurfrou_Text_SelectTrim, MSGBOX_DEFAULT
	dynmultipush TrimFurfrou_Text_Natural, 0
	dynmultipush TrimFurfrou_Text_Dandy, 1
	dynmultipush TrimFurfrou_Text_Debutante, 2
	dynmultipush TrimFurfrou_Text_Diamond, 3
	dynmultipush TrimFurfrou_Text_Heart, 4
	dynmultipush TrimFurfrou_Text_Kabuki, 5
	dynmultipush TrimFurfrou_Text_LaReine, 6
	dynmultipush TrimFurfrou_Text_Matron, 7
	dynmultipush TrimFurfrou_Text_Pharaoh, 8
	dynmultipush TrimFurfrou_Text_Star, 9
	dynmultipush TrimFurfrou_Text_Cancel, 10
	dynmultistack 19, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, TrimFurfrou_TrimNatural
	case 1, TrimFurfrou_TrimDandy
	case 2, TrimFurfrou_TrimDebutante
	case 3, TrimFurfrou_TrimDiamond
	case 4, TrimFurfrou_TrimHeart
	case 5, TrimFurfrou_TrimKabuki
	case 6, TrimFurfrou_TrimLaReine
	case 7, TrimFurfrou_TrimMatron
	case 8, TrimFurfrou_TrimPharaoh
	case 9, TrimFurfrou_TrimStar
	case 10, TrimFurfrou_TrimCanceled
	case MULTI_B_PRESSED, TrimFurfrou_TrimCanceled
	end

TrimFurfrou_TrimNatural::
	setvar VAR_FURFROU_TRIM, 0
	goto TrimFurfrou_Select

TrimFurfrou_TrimDandy::
	setvar VAR_FURFROU_TRIM, 1
	goto TrimFurfrou_Select

TrimFurfrou_TrimDebutante::
	setvar VAR_FURFROU_TRIM, 2
	goto TrimFurfrou_Select

TrimFurfrou_TrimDiamond::
	setvar VAR_FURFROU_TRIM, 3
	goto TrimFurfrou_Select

TrimFurfrou_TrimHeart::
	setvar VAR_FURFROU_TRIM, 4
	goto TrimFurfrou_Select

TrimFurfrou_TrimKabuki::
	setvar VAR_FURFROU_TRIM, 5
	goto TrimFurfrou_Select

TrimFurfrou_TrimLaReine::
	setvar VAR_FURFROU_TRIM, 6
	goto TrimFurfrou_Select

TrimFurfrou_TrimMatron::
	setvar VAR_FURFROU_TRIM, 7
	goto TrimFurfrou_Select

TrimFurfrou_TrimPharaoh::
	setvar VAR_FURFROU_TRIM, 8
	goto TrimFurfrou_Select

TrimFurfrou_TrimStar::
	setvar VAR_FURFROU_TRIM, 9
	goto TrimFurfrou_Select

TrimFurfrou_Select::
	msgbox TrimFurfrou_Text_Select, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq TrimFurfrou_End
	special TryTrimFurfrou
	compare VAR_RESULT, TRUE
	goto_if_eq TrimFurfrou_Success
	goto TrimFurfrou_End

TrimFurfrou_Success::
	playmoncry SPECIES_FURFROU_NATURAL, CRY_MODE_NORMAL
	msgbox TrimFurfrou_Text_Success, MSGBOX_DEFAULT
	waitmoncry
	waitbuttonpress
	goto TrimFurfrou_End

TrimFurfrou_Text_Beginning_NoFurfrou::
	.string "It seems you don't have a Furfrou.$"

TrimFurfrou_Text_Beginning_Furfrou::
	.string "Furfrou is interested in the trims.\n"
	.string "Do you want to let it get trimmed?$"

TrimFurfrou_Text_Select::
	.string "Please select a Furfrou.$"

TrimFurfrou_Text_SelectTrim::
	.string "Please select a trim.$"

TrimFurfrou_Text_Success::
	.string "Your Furfrou has been trimmed!$"

TrimFurfrou_Text_Canceled::
	.string "You didn't want to trim your Furfrou.$"

TrimFurfrou_Text_Furfrou::
	.string "Furfrou: furrrrr!$"

TrimFurfrou_Text_Natural::
	.string "Natural$"

TrimFurfrou_Text_Dandy::
	.string "Dandy$"

TrimFurfrou_Text_Debutante::
	.string "Debutante$"

TrimFurfrou_Text_Diamond::
	.string "Diamond$"

TrimFurfrou_Text_Heart::
	.string "Heart$"

TrimFurfrou_Text_Kabuki::
	.string "Kabuki$"

TrimFurfrou_Text_LaReine::
	.string "La Reine$"

TrimFurfrou_Text_Matron::
	.string "Matron$"

TrimFurfrou_Text_Pharaoh::
	.string "Pharaoh$"

TrimFurfrou_Text_Star::
	.string "Star$"

TrimFurfrou_Text_Cancel::
	.string "Cancel$"

TrimFurfrou_FurfrouMon::
	lockall
	faceplayer
	playmoncry SPECIES_FURFROU_NATURAL, CRY_MODE_NORMAL
	msgbox TrimFurfrou_Text_Furfrou, MSGBOX_DEFAULT
	waitmoncry
	releaseall
	end
