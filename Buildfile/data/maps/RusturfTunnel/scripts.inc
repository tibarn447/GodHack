RusturfTunnel_MapScripts::
	.byte 0


RusturfTunnel_EventScript_Trainer::
# 4 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_single TRAINER_JOE_1, BoyIntroText, BoyOutroText
# 5 "data/maps/RusturfTunnel/scripts.pory"
	msgbox PostBattleBoy, MSGBOX_AUTOCLOSE
# 6 "data/maps/RusturfTunnel/scripts.pory"
	waitmessage
	end


PostBattleBoy::
# 12 "data/maps/RusturfTunnel/scripts.pory"
	.string "That was fun!$"

BoyIntroText::
# 16 "data/maps/RusturfTunnel/scripts.pory"
	.string "Hehe.\p"
	.string "I borrowed one of my dad's Pokemon and\n"
	.string "came out here to play.$"

BoyOutroText::
# 24 "data/maps/RusturfTunnel/scripts.pory"
	.string "That was fun!$"
