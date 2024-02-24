LaulevWoods_MapScripts::
	.byte 0


LaulevWoods_EventScript_Rival::
# 6 "data/maps/LAULEVWOODS/scripts.pory"
	trainerbattle_single TRAINER_RIVAL_1, Rival_Intro_Text1, Rival_Outro1
# 7 "data/maps/LAULEVWOODS/scripts.pory"
	msgbox PostBattle_Rival1, MSGBOX_AUTOCLOSE
# 8 "data/maps/LAULEVWOODS/scripts.pory"
	waitmessage
	end


PostBattle_Rival1::
# 14 "data/maps/LAULEVWOODS/scripts.pory"
	.string "I'll see you back in town I suppose.$"

Rival_Intro_Text1::
# 18 "data/maps/LAULEVWOODS/scripts.pory"
	.string "Hello there, {PLAYER}.\p"
	.string "…I see you've got your first Pokemon. I\n"
	.string "also just got my first Pokemon. So what\l"
	.string "do you say, shall we battle?$"

Rival_Outro1::
# 27 "data/maps/LAULEVWOODS/scripts.pory"
	.string "Hehe, you're alright.$"
