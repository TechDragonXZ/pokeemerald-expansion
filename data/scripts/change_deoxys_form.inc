ChangeDeoxysForm::
	checkspecies SPECIES_DEOXYS, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm_Deoxys
	goto ChangeDeoxysForm_NoDeoxys
	end

ChangeDeoxysForm_NoDeoxys::
	lockall
	msgbox ChangeDeoxysForm_Text_Beginning_NoDeoxys, MSGBOX_DEFAULT
	goto ChangeDeoxysForm_End
	end

ChangeDeoxysForm_Deoxys::
	lockall
	msgbox ChangeDeoxysForm_Text_Beginning_Deoxys, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChangeDeoxysForm_Start
	end

ChangeDeoxysForm_End::
	releaseall
	end

ChangeDeoxysForm_Start::
	msgbox ChangeDeoxysForm_Text_Select, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq ChangeDeoxysForm_End
	special TryChangeDeoxysForm
	compare VAR_RESULT, TRUE
	goto_if_eq ChangeDeoxysForm_Success
	goto ChangeDeoxysForm_End

ChangeDeoxysForm_Success::
	playmoncry SPECIES_DEOXYS, CRY_MODE_NORMAL
	msgbox ChangeDeoxysForm_Text_Success, MSGBOX_DEFAULT
	waitmoncry
	waitbuttonpress
	goto ChangeDeoxysForm_End

ChangeDeoxysForm_Text_Beginning_NoDeoxys::
	.string "It's a meteorite!\n"
	.string "It seems to radiate a strange energy.$"

ChangeDeoxysForm_Text_Beginning_Deoxys::
	.string "Deoxys is interested in the meteorite.\n"
	.string "Do you want to allow it to get closer?$"

ChangeDeoxysForm_Text_Select::
	.string "Please select a Deoxys.$"

ChangeDeoxysForm_Text_Success::
	.string "Your Deoxys has transformed!$"
