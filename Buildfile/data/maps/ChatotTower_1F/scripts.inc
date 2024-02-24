ChatotTower1F_MapScripts::
	.byte 0


Give_Monke::
# 7 "data/maps/ChatotTower_1F/scripts.pory"
	goto_if_unset FLAG_MONKE_CHOSEN, Give_Monke_1
	return

Give_Monke_1:
# 9 "data/maps/ChatotTower_1F/scripts.pory"
	lock
# 10 "data/maps/ChatotTower_1F/scripts.pory"
	faceplayer
# 16 "data/maps/ChatotTower_1F/scripts.pory"
	call PansearChosen
	end


PansearChosen::
# 27 "data/maps/ChatotTower_1F/scripts.pory"
	showmonpic SPECIES_PANSEAR, 10, 3
# 29 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox PansearChosen_Text_0, MSGBOX_YESNO
# 31 "data/maps/ChatotTower_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq PansearChosen_2
# 51 "data/maps/ChatotTower_1F/scripts.pory"
	hidemonpic
# 52 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox Monke_NotChosen
PansearChosen_1:
# 54 "data/maps/ChatotTower_1F/scripts.pory"
	waitmessage
# 55 "data/maps/ChatotTower_1F/scripts.pory"
	releaseall
	return

PansearChosen_2:
# 32 "data/maps/ChatotTower_1F/scripts.pory"
	givemon SPECIES_PANSEAR, 6, ITEM_ORAN_BERRY
# 33 "data/maps/ChatotTower_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq PansearChosen_5
# 39 "data/maps/ChatotTower_1F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PansearChosen_6
# 46 "data/maps/ChatotTower_1F/scripts.pory"
	hidemonpic
# 47 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox PansearChosen_Text_2
	goto PansearChosen_1

PansearChosen_5:
# 34 "data/maps/ChatotTower_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 35 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox PansearChosen_Text_1
# 36 "data/maps/ChatotTower_1F/scripts.pory"
	setflag FLAG_MONKE_CHOSEN
# 37 "data/maps/ChatotTower_1F/scripts.pory"
	call ChatotTower_NicknamePartyMon
	goto PansearChosen_1

PansearChosen_6:
# 40 "data/maps/ChatotTower_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 41 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox PansearChosen_Text_1
# 42 "data/maps/ChatotTower_1F/scripts.pory"
	setflag FLAG_MONKE_CHOSEN
# 43 "data/maps/ChatotTower_1F/scripts.pory"
	call ChatotTower_NicknameBoxMon
	goto PansearChosen_1


ChatotTower_NicknameBoxMon::
# 60 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox ChatotTower_NicknameBoxMon_Text_0, MSGBOX_YESNO
# 61 "data/maps/ChatotTower_1F/scripts.pory"
	hidemonpic
# 62 "data/maps/ChatotTower_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChatotTower_NicknameBoxMon_2
ChatotTower_NicknameBoxMon_1:
# 65 "data/maps/ChatotTower_1F/scripts.pory"
	call Common_EventScript_TransferredToPC
	return

ChatotTower_NicknameBoxMon_2:
# 63 "data/maps/ChatotTower_1F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto ChatotTower_NicknameBoxMon_1


Chatot_Tower_EventScript_Grunt1::
# 75 "data/maps/ChatotTower_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, Grunt1_IntroText, Grunt1_OutroText
# 76 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox Grunt1_PostBattle, MSGBOX_AUTOCLOSE
# 77 "data/maps/ChatotTower_1F/scripts.pory"
	waitmessage
	end


Chatot_Tower_EventScript_Grunt2::
# 82 "data/maps/ChatotTower_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, Grunt2_IntroText, Grunt2_OutroText
# 83 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox Grunt2_PostBattle, MSGBOX_AUTOCLOSE
# 84 "data/maps/ChatotTower_1F/scripts.pory"
	waitmessage
	end


Chatot_Tower_EventScript_Jeigan::
# 90 "data/maps/ChatotTower_1F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_AQUA_HIDEOUT_4, Jeigan_IntroText, Jeigan_OutroText, Jeigan_NotEnoughPokemon
# 91 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox Jeigan_PostBattle, MSGBOX_AUTOCLOSE
# 92 "data/maps/ChatotTower_1F/scripts.pory"
	waitmessage
	end


ChatotTower_NicknamePartyMon::
# 144 "data/maps/ChatotTower_1F/scripts.pory"
	msgbox ChatotTower_NicknameBoxMon_Text_0, MSGBOX_YESNO
# 145 "data/maps/ChatotTower_1F/scripts.pory"
	hidemonpic
# 146 "data/maps/ChatotTower_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChatotTower_NicknamePartyMon_1
	return

ChatotTower_NicknamePartyMon_1:
# 147 "data/maps/ChatotTower_1F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 148 "data/maps/ChatotTower_1F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


PansearChosen_Text_0:
# 29 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Do you want to choose Pansear?$"

PansearChosen_Text_1:
# 35 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Recieved Pansear.$"

PansearChosen_Text_2:
# 47 "data/maps/ChatotTower_1F/scripts.pory"
	.string "No More Room.$"

ChatotTower_NicknameBoxMon_Text_0:
# 60 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Give it a nickname?$"

Monke_NotChosen::
# 69 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Later Perhaps$"

Jeigan_NotEnoughPokemon::
# 96 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Come back when you have some more Pokemon$"

Jeigan_IntroText::
# 100 "data/maps/ChatotTower_1F/scripts.pory"
	.string "That fire in your eyes...$"

Jeigan_OutroText::
# 104 "data/maps/ChatotTower_1F/scripts.pory"
	.string "placeholder text!$"

Jeigan_PostBattle::
# 107 "data/maps/ChatotTower_1F/scripts.pory"
	.string "you will never be epic$"

Grunt1_IntroText::
# 111 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Who are you?"
	.string "Stay outta the way!$"

Grunt1_OutroText::
# 116 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Damn...$"

Grunt1_PostBattle::
# 120 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Hehe, you'll never make it to the top.$"

Grunt2_IntroText::
# 123 "data/maps/ChatotTower_1F/scripts.pory"
	.string "What did you do to my buddy??$"

Grunt2_OutroText::
# 128 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Oh...I see now.$"

Grunt2_PostBattle::
# 132 "data/maps/ChatotTower_1F/scripts.pory"
	.string "Hehe, you won't stand a chance against the boss$"
