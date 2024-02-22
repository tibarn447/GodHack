LaulevTown_MapScripts::
	.byte 0


LaulevTown_EventScript_SignTest::
# 4 "data/maps/LaulevTown/scripts.pory"
	lock
# 5 "data/maps/LaulevTown/scripts.pory"
	msgbox LaulevTown_EventScript_SignTest_Text_0
# 6 "data/maps/LaulevTown/scripts.pory"
	release
	end


LaulevTown_EventScript_IntFlags::
# 11 "data/maps/LaulevTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 12 "data/maps/LaulevTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 13 "data/maps/LaulevTown/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 14 "data/maps/LaulevTown/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 15 "data/maps/LaulevTown/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 16 "data/maps/LaulevTown/scripts.pory"
	special EnableNationalPokedex
# 17 "data/maps/LaulevTown/scripts.pory"
	setvar VAR_LAULEV_TOWN_STATE, 1
	return


LaulevTown_EventScript_FreeShit::
# 21 "data/maps/LaulevTown/scripts.pory"
	lock
# 22 "data/maps/LaulevTown/scripts.pory"
	giveitem ITEM_ORAN_BERRY, 3
# 23 "data/maps/LaulevTown/scripts.pory"
	giveitem ITEM_PECHA_BERRY, 2
# 24 "data/maps/LaulevTown/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 25 "data/maps/LaulevTown/scripts.pory"
	release
	return


LaulevTown_EventScript_SignTest_Text_0:
# 5 "data/maps/LaulevTown/scripts.pory"
	.string "Hello Gamers$"
