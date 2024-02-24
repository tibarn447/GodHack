LaulevTownHall_MapScripts::
	.byte 0


# 3 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_AIDE, 1
# 4 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BIRCH, 2
# 5 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_RIVAL, 3
# 6 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_CYNDAQUIL, 4
# 7 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_TOTODILE, 5
# 8 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
.set LOCALID_BALL_CHIKORITA, 6
# 9 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 10 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_MapScripts::
# 11 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LaulevTown_ProfessorBirchsLab_OnTransition
# 12 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LaulevTown_ProfessorBirchsLab_OnWarp
# 13 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LaulevTown_ProfessorBirchsLab_OnFrame
# 14 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.byte 0
# 15 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 16 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
# 17 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Beat Elite Four, Dex upgrade ready
# 18 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Received National Dex
# 19 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Left lab after receiving National Dex
# 20 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Entered lab after catching all Hoenn mons
# 21 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Birch told player to choose Johto starter
# 22 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 6: Chose Johto starter
# 23 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 24 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ State descriptions for VAR_BIRCH_LAB_STATE
# 25 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 1: Never occurs
# 26 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 2: Chose starter
# 27 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 3: Received starter in lab
# 28 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 4: Defeated rival on Route 103
# 29 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	@ 5: Received pokedex
# 30 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 31 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_OnTransition:
# 32 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 33 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 34 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LaulevTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
# 35 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LaulevTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 36 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LaulevTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
# 37 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 38 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 39 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
# 40 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	specialvar VAR_RESULT, HasAllHoennMons
# 41 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LaulevTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
# 42 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 43 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 44 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 45 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 46 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
# 47 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
# 48 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
# 49 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 50 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
# 51 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LAULEV_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 52 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 53 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 54 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
# 55 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setmaplayoutindex LAYOUT_LAULEV_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
# 56 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
# 57 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 58 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 59 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 60 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_OnWarp:
# 61 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LaulevTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
# 62 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LaulevTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 63 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LaulevTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
# 64 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LaulevTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 65 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LaulevTown_ProfessorBirchsLab_EventScript_AddRivalObject
# 66 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LaulevTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 67 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LaulevTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
# 68 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 69 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 70 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
# 71 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 72 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 73 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 74 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
# 75 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 76 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BIRCH
# 77 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 78 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_RIVAL, DIR_NORTH
# 79 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_RIVAL, 5, 5
# 80 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCH, DIR_SOUTH
# 81 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCH, 6, 4
# 82 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_AIDE, DIR_EAST
# 83 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_AIDE, 10, 10
# 84 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 85 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 86 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_AddRivalObject::
# 87 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 88 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 89 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 90 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
# 91 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_CYNDAQUIL
# 92 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_TOTODILE
# 93 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_BALL_CHIKORITA
# 94 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	addobject LOCALID_RIVAL
# 95 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_CYNDAQUIL, DIR_SOUTH
# 96 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_CYNDAQUIL, 8, 4
# 97 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_TOTODILE, DIR_SOUTH
# 98 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_TOTODILE, 9, 4
# 99 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BALL_CHIKORITA, DIR_SOUTH
# 100 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BALL_CHIKORITA, 10, 4
# 101 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_BIRCH, DIR_SOUTH
# 102 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_BIRCH, 6, 4
# 103 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	turnobject LOCALID_RIVAL, DIR_EAST
# 104 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setobjectxy LOCALID_RIVAL, 5, 5
# 105 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 106 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 107 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_OnFrame:
# 108 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LaulevTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
# 109 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LaulevTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
# 110 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LaulevTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
# 111 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LaulevTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
# 112 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.2byte 0
# 113 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 114 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
@ The starter is technically given prior to this on Laulev Woods by special ChooseStarter
# 115 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
@ This is just where the game tells you its yours and lets you nickname it
# 116 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
# 117 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 118 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 119 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	message LaulevTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
# 120 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 121 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 122 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 123 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
# 124 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LaulevTown_ProfessorBirchsLab_EventScript_NicknameStarter
# 125 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 126 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 127 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 128 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_NicknameStarter::
# 129 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_0x8004, 0
# 130 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 131 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_GoSeeRival
# 132 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 133 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 134 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_GoSeeRival::
# 135 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
# 136 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LaulevTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 137 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 138 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 139 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 140 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
# 141 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
# 142 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 143 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 144 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 145 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 146 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 147 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
# 148 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
# 149 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, LaulevTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
# 150 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
# 151 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 152 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 153 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
# 154 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 155 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LaulevTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
# 156 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 157 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_GivePokedex
# 158 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 159 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 160 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
# 161 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 162 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 163 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 164 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 165 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 166 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 167 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 168 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 169 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 170 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
# 171 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 172 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 173 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
# 174 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 175 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, LaulevTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
# 176 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 177 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 178 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 179 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 180 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 181 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 182 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 183 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 10
# 184 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playse SE_CLICK
# 185 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 186 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
# 187 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 188 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 189 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 190 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LaulevTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
# 191 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LaulevTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
# 192 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playse SE_PC_ON
# 193 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitse
# 194 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 20
# 195 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, LaulevTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
# 196 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 197 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 198 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 199 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 200 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
# 201 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 202 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	message LaulevTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
# 203 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 204 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 205 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 206 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	special EnableNationalPokedex
# 207 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 208 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 209 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LAULEV_TOWN_BIRCH
# 210 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_HIDE_LAULEV_TOWN_RIVAL
# 211 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 212 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
# 213 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 214 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 215 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 216 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 217 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
# 218 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
# 219 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 220 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 221 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 222 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
# 223 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
# 224 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 225 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 226 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 227 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
# 228 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 229 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 230 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 231 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 232 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 233 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 234 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 235 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay_16
# 236 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 237 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 238 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 239 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 240 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 241 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 242 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 243 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_right
# 244 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_up
# 245 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 246 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 247 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
# 248 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 249 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 250 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 251 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 252 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 253 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 254 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 255 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_left
# 256 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_down
# 257 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 258 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 259 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
# 260 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 261 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LaulevTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
# 262 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 263 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
# 264 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
# 265 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 266 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 267 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 268 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
# 269 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 270 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 271 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 272 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 273 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 274 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 275 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_up
# 276 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 277 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 278 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Aide::
# 279 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lock
# 280 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 281 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LaulevTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
# 282 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_set FLAG_BIRCH_AIDE_MET, LaulevTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
# 283 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
# 284 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_BIRCH_AIDE_MET
# 285 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 286 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 287 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 288 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
# 289 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
# 290 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 291 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 292 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 293 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
# 294 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
# 295 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 296 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 297 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 298 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Cyndaquil::
# 299 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 300 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LaulevTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 301 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 302 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 303 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CYNDAQUIL, 10, 3
# 304 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
# 305 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 306 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
# 307 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 308 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 309 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Totodile::
# 310 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 311 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LaulevTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 312 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 313 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 314 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_TOTODILE, 10, 3
# 315 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
# 316 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 317 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_GiveTotodile
# 318 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 319 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 320 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Chikorita::
# 321 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 322 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LaulevTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
# 323 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 324 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 325 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_CHIKORITA, 10, 3
# 326 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
# 327 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_TakeYourTime
# 328 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_GiveChikorita
# 329 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 330 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 331 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
# 332 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
# 333 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 334 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 335 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 336 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_TakeYourTime::
# 337 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 338 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
# 339 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 340 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 341 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 342 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
# 343 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
# 344 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
# 345 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CYNDAQUIL, 5
# 346 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LaulevTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
# 347 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LaulevTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
# 348 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 349 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 350 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 351 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 352 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
# 353 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call LaulevTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 354 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CYNDAQUIL
# 355 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 356 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 357 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 358 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 359 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 360 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 361 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 362 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
# 363 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call LaulevTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 364 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CYNDAQUIL
# 365 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 366 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 367 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 368 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
# 369 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 370 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 371 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
# 372 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 373 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
# 374 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 375 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 376 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
# 377 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 378 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 379 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 380 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 381 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 382 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 383 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_GiveTotodile::
# 384 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
# 385 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
# 386 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_TOTODILE, 5
# 387 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LaulevTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
# 388 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LaulevTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
# 389 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 390 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 391 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 392 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 393 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
# 394 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call LaulevTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 395 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_TOTODILE
# 396 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 397 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 398 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 399 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 400 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 401 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 402 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 403 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
# 404 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call LaulevTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 405 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_TOTODILE
# 406 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 407 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 408 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 409 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
# 410 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 411 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 412 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
# 413 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 414 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
# 415 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 416 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 417 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
# 418 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 419 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 420 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 421 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 422 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 423 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 424 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_GiveChikorita::
# 425 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
# 426 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
# 427 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_CHIKORITA, 5
# 428 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LaulevTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
# 429 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LaulevTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
# 430 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 431 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 432 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 433 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 434 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
# 435 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call LaulevTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 436 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CHIKORITA
# 437 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 438 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 439 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 440 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 441 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 442 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 443 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 444 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
# 445 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call LaulevTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
# 446 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject LOCALID_BALL_CHIKORITA
# 447 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 448 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LaulevTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 449 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 450 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
# 451 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 452 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 453 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
# 454 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
# 455 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
# 456 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 457 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 458 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
# 459 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 460 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
# 461 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
# 462 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 463 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 464 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 465 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
# 466 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 467 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	message LaulevTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
# 468 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 469 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 470 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 471 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 472 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Birch::
# 473 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lock
# 474 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 475 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LaulevTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
# 476 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LaulevTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
# 477 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HAS_MATCH_CALL, LaulevTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 478 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 479 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto LaulevTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
# 480 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 481 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 482 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
# 483 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
# 484 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 485 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 486 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 487 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
# 488 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
# 489 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 490 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 491 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 492 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
# 493 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_HIDE_LAULEV_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
# 494 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
# 495 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
# 496 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LaulevTown_ProfessorBirchsLab_EventScript_PokemonAwait
# 497 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
# 498 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 499 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 500 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 501 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
EventScript_RegisterProfBirch::
# 502 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
# 503 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 504 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 505 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 506 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
# 507 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 508 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 509 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	delay 30
# 510 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 511 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 512 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 513 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 514 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 515 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_GivePokedex::
# 516 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
# 517 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call LaulevTown_ProfessorBirchsLab_EventScript_ReceivePokedex
# 518 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
# 519 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	closemessage
# 520 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement LOCALID_RIVAL, LaulevTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
# 521 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 522 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 523 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmovement 0
# 524 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 525 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LaulevTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
# 526 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LaulevTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
# 527 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 5
# 528 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 529 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 530 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LAULEV_RIVAL_STATE, 4
# 531 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_LAULEV_TOWN_STATE, 3
# 532 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 533 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 534 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 535 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
# 536 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 537 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 538 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LaulevTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
# 539 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
# 540 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 0
# 541 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 542 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 543 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
# 544 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
# 545 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 546 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LaulevTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
# 547 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
# 548 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_RESULT, 1
# 549 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 550 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 551 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
# 552 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 553 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	message LaulevTown_ProfessorBirchsLab_Text_ReceivedPokedex
# 554 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitfanfare
# 555 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 556 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 557 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 558 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 559 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 560 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 561 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_PokemonAwait::
# 562 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
# 563 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 564 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 565 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 566 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
# 567 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
# 568 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 569 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 570 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
# 571 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
# 572 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 573 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 574 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
# 575 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_down
# 576 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	walk_in_place_faster_left
# 577 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	step_end
# 578 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 579 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Machine::
# 580 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
# 581 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 582 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 583 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Rival::
# 584 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lock
# 585 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	faceplayer
# 586 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LaulevTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
# 587 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LaulevTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
# 588 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LaulevTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
# 589 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 590 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LaulevTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
# 591 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LaulevTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
# 592 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 593 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 594 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 595 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
# 596 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 597 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 598 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 599 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
# 600 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 601 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 602 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 603 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
# 604 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 605 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LaulevTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
# 606 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LaulevTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
# 607 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 608 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 609 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 610 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
# 611 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
# 612 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 613 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 614 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
# 615 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
# 616 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 617 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 618 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
# 619 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 620 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LaulevTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
# 621 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LaulevTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
# 622 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 623 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 624 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 625 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
# 626 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 627 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 628 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 629 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
# 630 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
# 631 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 632 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 633 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
# 634 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	checkplayergender
# 635 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LaulevTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
# 636 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LaulevTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
# 637 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	release
# 638 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 639 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 640 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
# 641 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 642 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 643 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 644 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
# 645 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
# 646 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	return
# 647 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 648 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_PC::
# 649 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
# 650 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 651 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 652 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Bookshelf::
# 653 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
# 654 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 655 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 656 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_Book::
# 657 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
# 658 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 659 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 660 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
# 661 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 662 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	pokenavcall LaulevTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
# 663 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 664 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
# 665 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
# 666 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	end
# 667 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 668 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
# 669 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Hunh? PROF. BIRCH?\p"
# 670 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF's away on fieldwork.\n"
# 671 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Ergo, he isn't here.\p"
# 672 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, let me explain what fieldwork is.\p"
# 673 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It is to study things in the natural\n"
# 674 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "environment, like fields and mountains,\l"
# 675 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "instead of a laboratory.\p"
# 676 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 677 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 678 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 679 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 680 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 681 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
# 682 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF isn't one for doing desk work.\n"
# 683 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "He's the type of person who would\l"
# 684 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "rather go outside and experience\l"
# 685 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "things than read about them here.$"
# 686 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 687 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
# 688 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH is studying the habitats\n"
# 689 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "and distribution of POKéMON.\p"
# 690 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
# 691 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "There's a lot of love there.$"
# 692 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 693 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
# 694 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: So, {PLAYER}{KUN}.\p"
# 695 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I've heard so much about you from\n"
# 696 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "your father.\p"
# 697 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I've heard that you don't have your\n"
# 698 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "own POKéMON yet.\p"
# 699 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "But the way you battled earlier,\n"
# 700 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "you pulled it off with aplomb!\p"
# 701 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I guess you have your father's blood\n"
# 702 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "in your veins after all!\p"
# 703 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, yes. As thanks for rescuing me,\n"
# 704 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'd like you to have the POKéMON you\l"
# 705 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "used earlier.\p"
# 706 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}!$"
# 707 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 708 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
# 709 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: While you're at it, why not\n"
# 710 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "give a nickname to that {STR_VAR_1}?$"
# 711 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 712 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
# 713 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: If you work at POKéMON\n"
# 714 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "and gain experience, I think you'll make\l"
# 715 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "an extremely good TRAINER.\p"
# 716 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, is also studying\n"
# 717 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON while helping me out.\p"
# 718 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
# 719 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "a good idea to go see {RIVAL}?$"
# 720 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 721 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
# 722 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Great!\n"
# 723 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} should be happy, too.\p"
# 724 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Get {RIVAL} to teach you what it\n"
# 725 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "means to be a TRAINER.$"
# 726 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 727 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_DontBeThatWay:
# 728 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, don't be that way.\n"
# 729 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You should go meet my kid.$"
# 730 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 731 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
# 732 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: {RIVAL}?\n"
# 733 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Gone home, I think.\p"
# 734 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Or maybe that kid's scrabbling around\n"
# 735 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "in tall grass again somewhere…\p"
# 736 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "If you or your POKéMON get tired,\n"
# 737 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "you should get some rest at home.$"
# 738 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 739 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
# 740 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, hi, {PLAYER}{KUN}!\p"
# 741 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I heard you beat {RIVAL} on\n"
# 742 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "your first try. That's excellent!\p"
# 743 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL}'s been helping with my research\n"
# 744 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "for a long time.\p"
# 745 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{RIVAL} has an extensive history as\n"
# 746 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "a TRAINER already.\p"
# 747 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
# 748 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "research, but I think you should have\l"
# 749 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéDEX.$"
# 750 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 751 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_ReceivedPokedex:
# 752 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the POKéDEX!$"
# 753 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 754 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_ExplainPokedex:
# 755 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The POKéDEX is a high-tech\n"
# 756 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "tool that automatically makes a record\l"
# 757 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "of any POKéMON you meet or catch.\p"
# 758 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "My kid, {RIVAL}, goes everywhere\n"
# 759 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "with it.\p"
# 760 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Whenever my kid catches a rare POKéMON\n"
# 761 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "and records its data in the POKéDEX,\l"
# 762 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "why, {RIVAL} looks for me while I'm out\l"
# 763 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "doing fieldwork, and shows me.$"
# 764 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 765 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
# 766 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Countless POKéMON\n"
# 767 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "await you!\p"
# 768 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Argh, I'm getting the itch to get out\n"
# 769 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "and do fieldwork again!$"
# 770 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 771 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
# 772 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
# 773 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You got a POKéDEX, too!\p"
# 774 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "That's great! Just like me!\n"
# 775 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I've got something for you, too!$"
# 776 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 777 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
# 778 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: It's fun if you can get a lot of\n"
# 779 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON!\p"
# 780 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to look all over the place\n"
# 781 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "because I want different POKéMON.\p"
# 782 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cute POKéMON, I'll catch\n"
# 783 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "them with POKé BALLS!$"
# 784 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 785 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_OhYourBagsFull:
# 786 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh? Your BAG's full.$"
# 787 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 788 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
# 789 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I wonder where I should go look\n"
# 790 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "for POKéMON next?$"
# 791 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 792 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
# 793 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Huh…\n"
# 794 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "So you got a POKéDEX, too.\p"
# 795 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Well then, here.\n"
# 796 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll give you these.$"
# 797 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 798 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
# 799 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: You know it's more fun to\n"
# 800 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "have a whole bunch of POKéMON.\p"
# 801 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm going to explore all over the place\n"
# 802 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "to find different POKéMON.\p"
# 803 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "If I find any cool POKéMON, you bet\n"
# 804 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll try to get them with POKé BALLS.$"
# 805 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 806 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
# 807 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Hey, your BAG's full.$"
# 808 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 809 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
# 810 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Where should I look for\n"
# 811 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON next…$"
# 812 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 813 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
# 814 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a serious-looking machine.\n"
# 815 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "The PROF must use this for research.$"
# 816 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 817 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_PCUsedForResearch:
# 818 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a PC used for research.\n"
# 819 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Better not mess around with it.$"
# 820 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 821 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
# 822 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It's crammed with books on POKéMON.$"
# 823 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 824 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BookTooHardToRead:
# 825 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It's a book that's too hard to read.$"
# 826 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 827 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
# 828 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Now…\p"
# 829 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
# 830 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "of you help me study POKéMON.\p"
# 831 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Thanks to your help, new facts\n"
# 832 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "are coming to light.\p"
# 833 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It appears that in the HOENN region,\n"
# 834 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "there are also POKéMON from other\l"
# 835 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "regions.\p"
# 836 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It goes to show how rich and varied\n"
# 837 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "the natural environments of HOENN\l"
# 838 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "happen to be.\p"
# 839 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "That's why I think it's necessary for\n"
# 840 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "me to upgrade your POKéDEX to\l"
# 841 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode.\p"
# 842 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Here, let me see your POKéDEX units.$"
# 843 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 844 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
# 845 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Eheheh!\p"
# 846 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It's so cool that even my POKéDEX\n"
# 847 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "is getting updated!\p"
# 848 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It's because you went out and caught\n"
# 849 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "so many POKéMON, {PLAYER}{KUN}!$"
# 850 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 851 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
# 852 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: I went out all over HOENN\n"
# 853 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "and checked out POKéMON.\p"
# 854 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You can thank me for getting\n"
# 855 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL Mode POKéDEX.\p"
# 856 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Yep, you're lucky, {PLAYER}!$"
# 857 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 858 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_OkayAllDone:
# 859 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Okay, all done!$"
# 860 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 861 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
# 862 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER}'s POKéDEX was upgraded\n"
# 863 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "to the NATIONAL Mode!$"
# 864 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 865 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
# 866 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: But listen.\n"
# 867 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You've become the CHAMPION,\l"
# 868 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 869 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 870 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 871 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 872 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 873 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 874 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
# 875 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: I think I'll take a short break\n"
# 876 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "from fieldwork.\p"
# 877 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I think I'll help the PROF here for\n"
# 878 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "a while.$"
# 879 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 880 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
# 881 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: For the time being,\n"
# 882 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm taking a break from fieldwork.\p"
# 883 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll be helping out the PROF here\n"
# 884 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "for a while.$"
# 885 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 886 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
# 887 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 888 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Let's have a look at your POKéDEX.\p"
# 889 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 890 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\p"
# 891 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Yes, there's no doubt about it.\p"
# 892 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You really have completed the HOENN\n"
# 893 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "region's POKéDEX.\p"
# 894 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "That's more than just impressive.\p"
# 895 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I have a gift for you.\p"
# 896 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Consider it my show of appreciation\n"
# 897 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "for the fantastic work you've done.\p"
# 898 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "My gift is a rare POKéMON only found\n"
# 899 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "in another region!\p"
# 900 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 901 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 902 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 903 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
# 904 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: These are rare POKéMON\n"
# 905 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "only found in another region!\p"
# 906 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You can have any one of these\n"
# 907 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "three POKéMON!$"
# 908 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 909 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
# 910 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The FIRE POKéMON\n"
# 911 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "CYNDAQUIL caught your eye!\p"
# 912 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You're as sharp as ever!\p"
# 913 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "So the CYNDAQUIL is your choice?$"
# 914 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 915 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
# 916 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The WATER POKéMON\n"
# 917 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "TOTODILE is your choice!\p"
# 918 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You know how to pick a good one.\p"
# 919 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the TOTODILE?$"
# 920 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 921 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
# 922 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: The GRASS POKéMON\n"
# 923 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "CHIKORITA is your choice!\p"
# 924 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You sure know what you're doing.\p"
# 925 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "So, you'll take the CHIKORITA?$"
# 926 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 927 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
# 928 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Take your time before\n"
# 929 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "you decide.\p"
# 930 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "They're all invaluable POKéMON.$"
# 931 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 932 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 933 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_PickedFinePokemon:
# 934 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: I see!\n"
# 935 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You picked a fine POKéMON!$"
# 936 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 937 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
# 938 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
# 939 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "from PROF. BIRCH!$"
# 940 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 941 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 942 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
# 943 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Want to give a nickname to\n"
# 944 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "the {STR_VAR_1} you received?$"
# 945 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 946 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
# 947 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
# 948 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You've completed the HOENN POKéDEX,\l"
# 949 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "but your POKéMON journey isn't over.\p"
# 950 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "There is no end to the road\n"
# 951 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "that is POKéMON.\p"
# 952 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Somewhere, there is a grassy patch\n"
# 953 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "that's waiting for you!$"
# 954 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 955 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
# 956 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You received the promised POKéMON.\n"
# 957 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Better leave the others alone.$"
# 958 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 959 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
@ Unused
# 960 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
# 961 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Oh, you don't have any room for\n"
# 962 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "this POKéMON.$"
# 963 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 964 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
# 965 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: {PLAYER}{KUN}, after this…\n"
# 966 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "What are you going to do?\p"
# 967 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Are you going to keep battling\n"
# 968 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "and sharpening your skills?\p"
# 969 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Or are you going to try filling\n"
# 970 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "the NATIONAL POKéDEX?\p"
# 971 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm staying here to help the PROF.$"
# 972 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 973 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
# 974 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Rather than collecting\n"
# 975 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "POKéMON, I prefer slowly and \l"
# 976 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "steadily raising the one I chose.$"
# 977 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 978 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
# 979 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
# 980 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone to that place,\l"
# 981 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 982 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 983 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
# 984 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "BRENDAN: Hey, {PLAYER}!\n"
# 985 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Have you gone out to that place,\l"
# 986 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "the BATTLE FRONTIER?$"
# 987 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"

# 988 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
LaulevTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
# 989 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 990 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Beep!\p"
# 991 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
# 992 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It's me, SCOTT.\p"
# 993 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'm aboard the S.S. TIDAL now.\n"
# 994 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "It feels great to be on the sea!\p"
# 995 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "By the way…\p"
# 996 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "There's this place that I'd like to\n"
# 997 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "invite you to for a visit.\p"
# 998 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "If you're interested, board a ferry\n"
# 999 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "at either SLATEPORT or LILYCOVE.\p"
# 1000 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "I'll fill you in on the details when\n"
# 1001 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "we meet. I'll be waiting!\p"
# 1002 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … …\n"
# 1003 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "… … … … … Click!$"

LaulevTownHall_EventScript_PokeballOne::
# 1009 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1010 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_STARTER_CHOSEN, LaulevTownHall_EventScript_PokeballOne_2
# 1043 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_3
LaulevTownHall_EventScript_PokeballOne_1:
# 1045 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 1046 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LaulevTownHall_EventScript_PokeballOne_2:
# 1011 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_POLIWAG, 10, 3
# 1012 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_0, MSGBOX_YESNO
# 1013 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LaulevTownHall_EventScript_PokeballOne_5
# 1039 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1040 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox StarterMon_NotChosen
	goto LaulevTownHall_EventScript_PokeballOne_1

LaulevTownHall_EventScript_PokeballOne_5:
# 1014 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_POLIWAG, 5, ITEM_ORAN_BERRY
# 1015 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq LaulevTownHall_EventScript_PokeballOne_8
# 1024 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq LaulevTownHall_EventScript_PokeballOne_9
# 1034 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1035 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_2
	goto LaulevTownHall_EventScript_PokeballOne_1

LaulevTownHall_EventScript_PokeballOne_8:
# 1016 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1017 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_1
# 1018 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 4
# 1019 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1020 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1021 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag POLIWAG_CHOSEN
# 1022 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto LaulevTownHall_EventScript_PokeballOne_1

LaulevTownHall_EventScript_PokeballOne_9:
# 1025 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1026 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_1
# 1027 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 4
# 1028 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1029 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1030 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag POLIWAG_CHOSEN
# 1031 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknameBoxMon
	goto LaulevTownHall_EventScript_PokeballOne_1


LaulevTownHall_EventScript_PokeballTwo::
# 1054 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_STARTER_CHOSEN, LaulevTownHall_EventScript_PokeballTwo_2
# 1088 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_3
LaulevTownHall_EventScript_PokeballTwo_1:
# 1090 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 1091 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LaulevTownHall_EventScript_PokeballTwo_2:
# 1055 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1056 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_MAGBY, 10, 3
# 1057 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballTwo_Text_0, MSGBOX_YESNO
# 1058 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LaulevTownHall_EventScript_PokeballTwo_5
# 1084 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1085 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox StarterMon_NotChosen
	goto LaulevTownHall_EventScript_PokeballTwo_1

LaulevTownHall_EventScript_PokeballTwo_5:
# 1059 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_MAGBY, 5, ITEM_ORAN_BERRY
# 1060 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq LaulevTownHall_EventScript_PokeballTwo_8
# 1069 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq LaulevTownHall_EventScript_PokeballTwo_9
# 1079 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1080 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_2
	goto LaulevTownHall_EventScript_PokeballTwo_1

LaulevTownHall_EventScript_PokeballTwo_8:
# 1061 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1062 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballTwo_Text_1
# 1063 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 3
# 1064 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1065 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1066 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag MAGBY_CHOSEN
# 1067 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto LaulevTownHall_EventScript_PokeballTwo_1

LaulevTownHall_EventScript_PokeballTwo_9:
# 1070 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1071 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballTwo_Text_1
# 1072 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 3
# 1073 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1074 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1075 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag MAGBY_CHOSEN
# 1076 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknameBoxMon
	goto LaulevTownHall_EventScript_PokeballTwo_1


LaulevTownHall_EventScript_PokeballThree::
# 1100 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_STARTER_CHOSEN, LaulevTownHall_EventScript_PokeballThree_2
# 1134 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_3
LaulevTownHall_EventScript_PokeballThree_1:
# 1136 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 1137 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LaulevTownHall_EventScript_PokeballThree_2:
# 1101 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1102 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_SMOLIV, 10, 3
# 1103 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballThree_Text_0, MSGBOX_YESNO
# 1104 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LaulevTownHall_EventScript_PokeballThree_5
# 1130 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1131 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox StarterMon_NotChosen
	goto LaulevTownHall_EventScript_PokeballThree_1

LaulevTownHall_EventScript_PokeballThree_5:
# 1105 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_SMOLIV, 5, ITEM_ORAN_BERRY
# 1106 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq LaulevTownHall_EventScript_PokeballThree_8
# 1115 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq LaulevTownHall_EventScript_PokeballThree_9
# 1125 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1126 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_2
	goto LaulevTownHall_EventScript_PokeballThree_1

LaulevTownHall_EventScript_PokeballThree_8:
# 1107 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1108 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballThree_Text_1
# 1109 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 2
# 1110 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1111 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1112 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag SMOLIV_CHOSEN
# 1113 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto LaulevTownHall_EventScript_PokeballThree_1

LaulevTownHall_EventScript_PokeballThree_9:
# 1116 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1117 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballThree_Text_1
# 1118 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 2
# 1119 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1120 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1121 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag SMOLIV_CHOSEN
# 1122 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknameBoxMon
	goto LaulevTownHall_EventScript_PokeballThree_1


LaulevTownHall_EventScript_PokeballFour::
# 1147 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_STARTER_CHOSEN, LaulevTownHall_EventScript_PokeballFour_2
# 1181 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_3
LaulevTownHall_EventScript_PokeballFour_1:
# 1183 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 1184 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LaulevTownHall_EventScript_PokeballFour_2:
# 1148 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1149 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_FARFETCHD_GALARIAN, 10, 3
# 1150 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballFour_Text_0, MSGBOX_YESNO
# 1151 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LaulevTownHall_EventScript_PokeballFour_5
# 1177 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1178 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox StarterMon_NotChosen
	goto LaulevTownHall_EventScript_PokeballFour_1

LaulevTownHall_EventScript_PokeballFour_5:
# 1152 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_FARFETCHD_GALARIAN, 5, ITEM_ORAN_BERRY
# 1153 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq LaulevTownHall_EventScript_PokeballFour_8
# 1162 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq LaulevTownHall_EventScript_PokeballFour_9
# 1172 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1173 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_2
	goto LaulevTownHall_EventScript_PokeballFour_1

LaulevTownHall_EventScript_PokeballFour_8:
# 1154 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1155 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballFour_Text_1
# 1156 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 5
# 1157 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1158 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1159 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FARFETCHD_CHOSEN
# 1160 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto LaulevTownHall_EventScript_PokeballFour_1

LaulevTownHall_EventScript_PokeballFour_9:
# 1163 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1164 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballFour_Text_1
# 1165 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 5
# 1166 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1167 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1168 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FARFETCHD_CHOSEN
# 1169 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknameBoxMon
	goto LaulevTownHall_EventScript_PokeballFour_1


LaulevTownHall_EventScript_PokeballFive::
# 1193 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	goto_if_unset FLAG_STARTER_CHOSEN, LaulevTownHall_EventScript_PokeballFive_2
# 1226 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_3
LaulevTownHall_EventScript_PokeballFive_1:
# 1228 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	waitmessage
# 1229 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	releaseall
	end

LaulevTownHall_EventScript_PokeballFive_2:
# 1194 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	lockall
# 1195 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	showmonpic SPECIES_LEDYBA, 10, 3
# 1196 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballFive_Text_0, MSGBOX_YESNO
# 1197 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LaulevTownHall_EventScript_PokeballFive_5
# 1222 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1223 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox StarterMon_NotChosen
	goto LaulevTownHall_EventScript_PokeballFive_1

LaulevTownHall_EventScript_PokeballFive_5:
# 1198 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	givemon SPECIES_LEDYBA, 5, ITEM_ORAN_BERRY
# 1199 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq LaulevTownHall_EventScript_PokeballFive_8
# 1208 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq LaulevTownHall_EventScript_PokeballFive_9
# 1217 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1218 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballOne_Text_2
	goto LaulevTownHall_EventScript_PokeballFive_1

LaulevTownHall_EventScript_PokeballFive_8:
# 1200 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1201 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballFive_Text_1
# 1202 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 6
# 1203 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1204 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1205 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag LEDYBA_CHOSEN
# 1206 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call NicknamePartyMon
	goto LaulevTownHall_EventScript_PokeballFive_1

LaulevTownHall_EventScript_PokeballFive_9:
# 1209 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1210 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox LaulevTownHall_EventScript_PokeballFive_Text_1
# 1211 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	removeobject 6
# 1212 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_STARTER_CHOSEN
# 1213 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1214 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	setflag LEDYBA_CHOSEN
	goto LaulevTownHall_EventScript_PokeballFive_1


NicknamePartyMon::
# 1235 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 1236 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1237 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
# 1238 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 1239 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
# 1247 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
# 1248 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	hidemonpic
# 1249 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
# 1252 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_TransferredToPC
	return

NicknameBoxMon_2:
# 1250 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


LaulevTownHall_EventScript_PokeballOne_Text_0:
# 1012 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Do you want to choose Poliwag?$"

LaulevTownHall_EventScript_PokeballOne_Text_1:
# 1017 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Recieved Poliwag.$"

LaulevTownHall_EventScript_PokeballOne_Text_2:
# 1035 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "No More Room.$"

LaulevTownHall_EventScript_PokeballOne_Text_3:
# 1043 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Don't get greedy.$"

LaulevTownHall_EventScript_PokeballTwo_Text_0:
# 1057 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Do you want to choose Magby?$"

LaulevTownHall_EventScript_PokeballTwo_Text_1:
# 1062 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Recieved Magby.$"

LaulevTownHall_EventScript_PokeballThree_Text_0:
# 1103 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Do you want to choose Smoliv?$"

LaulevTownHall_EventScript_PokeballThree_Text_1:
# 1108 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Recieved Smoliv.$"

LaulevTownHall_EventScript_PokeballFour_Text_0:
# 1150 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Do you want to choose Farfetchd?$"

LaulevTownHall_EventScript_PokeballFour_Text_1:
# 1155 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Recieved Farfetchd.$"

LaulevTownHall_EventScript_PokeballFive_Text_0:
# 1196 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Do you want to choose Ledyba?$"

LaulevTownHall_EventScript_PokeballFive_Text_1:
# 1201 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Recieved Ledyba.$"

NicknamePartyMon_Text_0:
# 1235 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "Give it a nickname?$"

StarterMon_NotChosen::
# 1256 "data/maps/LaulevTown_ProfessorBirchsLab/scripts.pory"
	.string "You did not choose the Pokemon.$"
