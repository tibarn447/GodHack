# 1 "data/maps/ROUTE101/scripts.pory"
.set LOCALID_BIRCH, 2
# 2 "data/maps/ROUTE101/scripts.pory"
.set LOCALID_ZIGZAGOON, 4
# 3 "data/maps/ROUTE101/scripts.pory"

# 4 "data/maps/ROUTE101/scripts.pory"
Route101_MapScripts::
# 5 "data/maps/ROUTE101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 6 "data/maps/ROUTE101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
# 7 "data/maps/ROUTE101/scripts.pory"
	.byte 0
# 8 "data/maps/ROUTE101/scripts.pory"

# 9 "data/maps/ROUTE101/scripts.pory"
Route101_OnTransition:
# 10 "data/maps/ROUTE101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 11 "data/maps/ROUTE101/scripts.pory"
	end
# 12 "data/maps/ROUTE101/scripts.pory"

# 13 "data/maps/ROUTE101/scripts.pory"
Route101_OnFrame:
# 14 "data/maps/ROUTE101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
# 15 "data/maps/ROUTE101/scripts.pory"
	.2byte 0
# 16 "data/maps/ROUTE101/scripts.pory"

# 17 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_HideMapNamePopup::
# 18 "data/maps/ROUTE101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 19 "data/maps/ROUTE101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
# 20 "data/maps/ROUTE101/scripts.pory"
	end
# 21 "data/maps/ROUTE101/scripts.pory"

# 22 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_StartBirchRescue::
# 23 "data/maps/ROUTE101/scripts.pory"
	lockall
# 24 "data/maps/ROUTE101/scripts.pory"
	playbgm MUS_HELP, TRUE
# 25 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
# 26 "data/maps/ROUTE101/scripts.pory"
	closemessage
# 27 "data/maps/ROUTE101/scripts.pory"
	setobjectxy LOCALID_BIRCH, 0, 15
# 28 "data/maps/ROUTE101/scripts.pory"
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
# 29 "data/maps/ROUTE101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
# 30 "data/maps/ROUTE101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
# 31 "data/maps/ROUTE101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
# 32 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 33 "data/maps/ROUTE101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
# 34 "data/maps/ROUTE101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
# 35 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 36 "data/maps/ROUTE101/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 37 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 38 "data/maps/ROUTE101/scripts.pory"
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
# 39 "data/maps/ROUTE101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
# 40 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 41 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
# 42 "data/maps/ROUTE101/scripts.pory"
	closemessage
# 43 "data/maps/ROUTE101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 2
# 44 "data/maps/ROUTE101/scripts.pory"
	releaseall
# 45 "data/maps/ROUTE101/scripts.pory"
	end
# 46 "data/maps/ROUTE101/scripts.pory"

# 47 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_PreventExitSouth::
# 48 "data/maps/ROUTE101/scripts.pory"
	lockall
# 49 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 50 "data/maps/ROUTE101/scripts.pory"
	closemessage
# 51 "data/maps/ROUTE101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
# 52 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 53 "data/maps/ROUTE101/scripts.pory"
	releaseall
# 54 "data/maps/ROUTE101/scripts.pory"
	end
# 55 "data/maps/ROUTE101/scripts.pory"

# 56 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_PreventExitWest::
# 57 "data/maps/ROUTE101/scripts.pory"
	lockall
# 58 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 59 "data/maps/ROUTE101/scripts.pory"
	closemessage
# 60 "data/maps/ROUTE101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
# 61 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 62 "data/maps/ROUTE101/scripts.pory"
	releaseall
# 63 "data/maps/ROUTE101/scripts.pory"
	end
# 64 "data/maps/ROUTE101/scripts.pory"

# 65 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_PreventExitNorth::
# 66 "data/maps/ROUTE101/scripts.pory"
	lockall
# 67 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 68 "data/maps/ROUTE101/scripts.pory"
	closemessage
# 69 "data/maps/ROUTE101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
# 70 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 71 "data/maps/ROUTE101/scripts.pory"
	releaseall
# 72 "data/maps/ROUTE101/scripts.pory"
	end
# 73 "data/maps/ROUTE101/scripts.pory"

# 74 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 75 "data/maps/ROUTE101/scripts.pory"
	walk_up
# 76 "data/maps/ROUTE101/scripts.pory"
	step_end
# 77 "data/maps/ROUTE101/scripts.pory"

# 78 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_PreventExitWest:
# 79 "data/maps/ROUTE101/scripts.pory"
	walk_right
# 80 "data/maps/ROUTE101/scripts.pory"
	step_end
# 81 "data/maps/ROUTE101/scripts.pory"

# 82 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 83 "data/maps/ROUTE101/scripts.pory"
	walk_down
# 84 "data/maps/ROUTE101/scripts.pory"
	step_end
# 85 "data/maps/ROUTE101/scripts.pory"

# 86 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 87 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 88 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 89 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 90 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 91 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 92 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 93 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 94 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 95 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 96 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 97 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 98 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 99 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 100 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 101 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 102 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 103 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 104 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 105 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 106 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 107 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 108 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 109 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 110 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 111 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 112 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 113 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 114 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 115 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 116 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 117 "data/maps/ROUTE101/scripts.pory"
	step_end
# 118 "data/maps/ROUTE101/scripts.pory"

# 119 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 120 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 121 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 122 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 123 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 124 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 125 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 126 "data/maps/ROUTE101/scripts.pory"
	step_end
# 127 "data/maps/ROUTE101/scripts.pory"

# 128 "data/maps/ROUTE101/scripts.pory"
@ Leftover data? This command is unused.
# 129 "data/maps/ROUTE101/scripts.pory"
	step_end
# 130 "data/maps/ROUTE101/scripts.pory"

# 131 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 132 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_fast_left
# 133 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_fast_left
# 134 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_fast_left
# 135 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_fast_left
# 136 "data/maps/ROUTE101/scripts.pory"
	step_end
# 137 "data/maps/ROUTE101/scripts.pory"

# 138 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_EnterScene:
# 139 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 140 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 141 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 142 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 143 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_faster_left
# 144 "data/maps/ROUTE101/scripts.pory"
	step_end
# 145 "data/maps/ROUTE101/scripts.pory"

# 146 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 147 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 148 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 149 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 150 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 151 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 152 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 153 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 154 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 155 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 156 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 157 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 158 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 159 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 160 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 161 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 162 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 163 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 164 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 165 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 166 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 167 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 168 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 169 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 170 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 171 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 172 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 173 "data/maps/ROUTE101/scripts.pory"
	walk_fast_down
# 174 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 175 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 176 "data/maps/ROUTE101/scripts.pory"
	walk_fast_left
# 177 "data/maps/ROUTE101/scripts.pory"
	step_end
# 178 "data/maps/ROUTE101/scripts.pory"

# 179 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 180 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 181 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 182 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 183 "data/maps/ROUTE101/scripts.pory"
	walk_fast_right
# 184 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 185 "data/maps/ROUTE101/scripts.pory"
	walk_fast_up
# 186 "data/maps/ROUTE101/scripts.pory"
	step_end
# 187 "data/maps/ROUTE101/scripts.pory"

# 188 "data/maps/ROUTE101/scripts.pory"
@ Leftover data? This command is unused.
# 189 "data/maps/ROUTE101/scripts.pory"
	step_end
# 190 "data/maps/ROUTE101/scripts.pory"

# 191 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 192 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_fast_right
# 193 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_fast_right
# 194 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_fast_right
# 195 "data/maps/ROUTE101/scripts.pory"
	walk_in_place_fast_right
# 196 "data/maps/ROUTE101/scripts.pory"
	step_end
# 197 "data/maps/ROUTE101/scripts.pory"

# 198 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_Unused1:
# 199 "data/maps/ROUTE101/scripts.pory"
	walk_up
# 200 "data/maps/ROUTE101/scripts.pory"
	walk_up
# 201 "data/maps/ROUTE101/scripts.pory"
	step_end
# 202 "data/maps/ROUTE101/scripts.pory"

# 203 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_Unused2:
# 204 "data/maps/ROUTE101/scripts.pory"
	walk_up
# 205 "data/maps/ROUTE101/scripts.pory"
	walk_left
# 206 "data/maps/ROUTE101/scripts.pory"
	walk_up
# 207 "data/maps/ROUTE101/scripts.pory"
	step_end
# 208 "data/maps/ROUTE101/scripts.pory"

# 209 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_Youngster::
# 210 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
# 211 "data/maps/ROUTE101/scripts.pory"
	end
# 212 "data/maps/ROUTE101/scripts.pory"

# 213 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_Boy::
# 214 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
# 215 "data/maps/ROUTE101/scripts.pory"
	end
# 216 "data/maps/ROUTE101/scripts.pory"

# 217 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_RouteSign::
# 218 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
# 219 "data/maps/ROUTE101/scripts.pory"
	end
# 220 "data/maps/ROUTE101/scripts.pory"

# 221 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_BirchsBag::
# 222 "data/maps/ROUTE101/scripts.pory"
	lock
# 223 "data/maps/ROUTE101/scripts.pory"
	faceplayer
# 224 "data/maps/ROUTE101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 225 "data/maps/ROUTE101/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 226 "data/maps/ROUTE101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 227 "data/maps/ROUTE101/scripts.pory"
	removeobject LOCALID_ZIGZAGOON
# 228 "data/maps/ROUTE101/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
# 229 "data/maps/ROUTE101/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 230 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 231 "data/maps/ROUTE101/scripts.pory"
	special ChooseStarter
# 232 "data/maps/ROUTE101/scripts.pory"
	waitstate
# 233 "data/maps/ROUTE101/scripts.pory"
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
# 234 "data/maps/ROUTE101/scripts.pory"
	waitmovement 0
# 235 "data/maps/ROUTE101/scripts.pory"
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
# 236 "data/maps/ROUTE101/scripts.pory"
	special HealPlayerParty
# 237 "data/maps/ROUTE101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
# 238 "data/maps/ROUTE101/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 239 "data/maps/ROUTE101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 240 "data/maps/ROUTE101/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 2
# 241 "data/maps/ROUTE101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 242 "data/maps/ROUTE101/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 243 "data/maps/ROUTE101/scripts.pory"
	checkplayergender
# 244 "data/maps/ROUTE101/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
# 245 "data/maps/ROUTE101/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
# 246 "data/maps/ROUTE101/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 247 "data/maps/ROUTE101/scripts.pory"
	waitstate
# 248 "data/maps/ROUTE101/scripts.pory"
	release
# 249 "data/maps/ROUTE101/scripts.pory"
	end
# 250 "data/maps/ROUTE101/scripts.pory"

# 251 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_HideMayInBedroom::
# 252 "data/maps/ROUTE101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 253 "data/maps/ROUTE101/scripts.pory"
	return
# 254 "data/maps/ROUTE101/scripts.pory"

# 255 "data/maps/ROUTE101/scripts.pory"
Route101_EventScript_HideBrendanInBedroom::
# 256 "data/maps/ROUTE101/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 257 "data/maps/ROUTE101/scripts.pory"
	return
# 258 "data/maps/ROUTE101/scripts.pory"

# 259 "data/maps/ROUTE101/scripts.pory"
Route101_Movement_BirchApproachPlayer:
# 260 "data/maps/ROUTE101/scripts.pory"
	walk_right
# 261 "data/maps/ROUTE101/scripts.pory"
	step_end
# 262 "data/maps/ROUTE101/scripts.pory"

# 263 "data/maps/ROUTE101/scripts.pory"
Route101_Text_HelpMe:
# 264 "data/maps/ROUTE101/scripts.pory"
	.string "H-help me!$"
# 265 "data/maps/ROUTE101/scripts.pory"

# 266 "data/maps/ROUTE101/scripts.pory"
Route101_Text_PleaseHelp:
# 267 "data/maps/ROUTE101/scripts.pory"
	.string "Hello! You over there!\n"
# 268 "data/maps/ROUTE101/scripts.pory"
	.string "Please! Help!\p"
# 269 "data/maps/ROUTE101/scripts.pory"
	.string "In my BAG!\n"
# 270 "data/maps/ROUTE101/scripts.pory"
	.string "There's a POKé BALL!$"
# 271 "data/maps/ROUTE101/scripts.pory"

# 272 "data/maps/ROUTE101/scripts.pory"
Route101_Text_DontLeaveMe:
# 273 "data/maps/ROUTE101/scripts.pory"
	.string "Wh-Where are you going?!\n"
# 274 "data/maps/ROUTE101/scripts.pory"
	.string "Don't leave me like this!$"
# 275 "data/maps/ROUTE101/scripts.pory"

# 276 "data/maps/ROUTE101/scripts.pory"
Route101_Text_YouSavedMe:
# 277 "data/maps/ROUTE101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
# 278 "data/maps/ROUTE101/scripts.pory"
	.string "I was in the tall grass studying wild\n"
# 279 "data/maps/ROUTE101/scripts.pory"
	.string "POKéMON when I was jumped.\p"
# 280 "data/maps/ROUTE101/scripts.pory"
	.string "You saved me.\n"
# 281 "data/maps/ROUTE101/scripts.pory"
	.string "Thanks a lot!\p"
# 282 "data/maps/ROUTE101/scripts.pory"
	.string "Oh?\p"
# 283 "data/maps/ROUTE101/scripts.pory"
	.string "Hi, you're {PLAYER}{KUN}!\p"
# 284 "data/maps/ROUTE101/scripts.pory"
	.string "This is not the place to chat, so come\n"
# 285 "data/maps/ROUTE101/scripts.pory"
	.string "by my POKéMON LAB later, okay?$"
# 286 "data/maps/ROUTE101/scripts.pory"

# 287 "data/maps/ROUTE101/scripts.pory"
Route101_Text_TakeTiredPokemonToPokeCenter:
# 288 "data/maps/ROUTE101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
# 289 "data/maps/ROUTE101/scripts.pory"
	.string "a POKéMON CENTER.\p"
# 290 "data/maps/ROUTE101/scripts.pory"
	.string "There's a POKéMON CENTER in OLDALE\n"
# 291 "data/maps/ROUTE101/scripts.pory"
	.string "TOWN right close by.$"
# 292 "data/maps/ROUTE101/scripts.pory"

# 293 "data/maps/ROUTE101/scripts.pory"
Route101_Text_WildPokemonInTallGrass:
# 294 "data/maps/ROUTE101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
# 295 "data/maps/ROUTE101/scripts.pory"
	.string "tall grass.\p"
# 296 "data/maps/ROUTE101/scripts.pory"
	.string "If you want to catch POKéMON, you have\n"
# 297 "data/maps/ROUTE101/scripts.pory"
	.string "to go into the tall grass and search.$"
# 298 "data/maps/ROUTE101/scripts.pory"

# 299 "data/maps/ROUTE101/scripts.pory"
Route101_Text_RouteSign:
# 300 "data/maps/ROUTE101/scripts.pory"
	.string "ROUTE 101\n"
# 301 "data/maps/ROUTE101/scripts.pory"
	.string "{UP_ARROW} OLDALE TOWN$"
