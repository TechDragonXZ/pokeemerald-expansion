AerowayIsland_MapScripts::
	.byte 0

AerowayIsland_Sign_EntrySign::
	msgbox AerowayIsland_Text_EntrySign, MSGBOX_SIGN
	end

AerowayIsland_Sign_AirPortSign::
	msgbox AerowayIsland_Text_AirPortSign, MSGBOX_SIGN
	end

AerowayIsland_Sign_CafeSign::
	msgbox AerowayIsland_Text_CafeSign, MSGBOX_SIGN
	end

AerowayIsland_Person_InterregionFlight::
	lock
	faceplayer
	msgbox AerowayIsland_Text_NotReady, MSGBOX_AUTOCLOSE
	closemessage
	releaseall
	end

AerowayIsland_Text_EntrySign:
	.string "AEROWAY ISLAND\n"
	.string "“The Interregional flying company.”$"

AerowayIsland_Text_CafeSign:
	.string "AEROWAY ISLAND CAFÉ\n"
	.string "“The Interregional café.”$"

AerowayIsland_Text_AirPortSign:
	.string "AEROWAY ISLAND AIR PORT\n"
	.string "“Traveling around the world!”$"

AerowayIsland_Text_NotReady:
	.string "I'm sorry this flight isn't ready yet.$"
