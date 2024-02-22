LAULEVCANYON_MapScripts::
	.byte 0

LAULEVCANYON_EventScript_LittleBoy::
	msgbox LAULEVCANYON_Text_ImNotVeryTall, MSGBOX_NPC
	end

LAULEVCANYON_EventScript_RouteSignOldale::
	msgbox LAULEVCANYON_Text_RouteSignOldale, MSGBOX_SIGN
	end

LAULEVCANYON_EventScript_RouteSignPetalburg::
	msgbox LAULEVCANYON_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

LAULEVCANYON_EventScript_Boy::
	msgbox LAULEVCANYON_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

LAULEVCANYON_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, LAULEVCANYON_Text_CalvinIntro, LAULEVCANYON_Text_CalvinDefeated, LAULEVCANYON_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LAULEVCANYON_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, LAULEVCANYON_EventScript_CalvinTryRegister
	msgbox LAULEVCANYON_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

LAULEVCANYON_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, LAULEVCANYON_EventScript_CalvinRegisterMatchCall
	release
	end

LAULEVCANYON_EventScript_CalvinRegisterMatchCall::
	msgbox LAULEVCANYON_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

LAULEVCANYON_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, LAULEVCANYON_EventScript_CalvinRegister
	msgbox LAULEVCANYON_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

LAULEVCANYON_EventScript_CalvinRegister::
	msgbox LAULEVCANYON_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

LAULEVCANYON_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, LAULEVCANYON_Text_CalvinRematchIntro, LAULEVCANYON_Text_CalvinRematchDefeated
	msgbox LAULEVCANYON_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

LAULEVCANYON_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, LAULEVCANYON_Text_RickIntro, LAULEVCANYON_Text_RickDefeated
	msgbox LAULEVCANYON_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

LAULEVCANYON_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, LAULEVCANYON_Text_TianaIntro, LAULEVCANYON_Text_TianaDefeated
	msgbox LAULEVCANYON_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

LAULEVCANYON_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, LAULEVCANYON_Text_AllenIntro, LAULEVCANYON_Text_AllenDefeated
	msgbox LAULEVCANYON_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

LAULEVCANYON_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

LAULEVCANYON_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

LAULEVCANYON_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

LAULEVCANYON_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

LAULEVCANYON_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

LAULEVCANYON_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

LAULEVCANYON_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
