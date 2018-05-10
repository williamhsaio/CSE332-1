#pragma once
#ifndef seven_card
#define seven_card
#include "card1.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "deck.h"
#include "player.h"
#include <memory>
#include "Game.h"
class SevenCardStud : public game
{
protected:
	size_t position_dealer;
	Deck discard_deck;
	//lab 4
	int bet_player_number = 0;
	int fold_player_number = 0;
	int ante;// 1 or 2
			 //unsigned int bet_amout_current;
	bool phase_done = false;
	bool phase_done_one_round = false;
	player* highest_bit_amount_player = nullptr;// check a round occurs
	unsigned int highest_bet_amount;

public:
	SevenCardStud();
	//might not use before_turn this time

	virtual int before_turn_1(player &p);// give the player one face down & two face up cards

	virtual int middle_round1();
	virtual int middle_round2();
	virtual int middle_round3();
	virtual int last_round();

	virtual int before_turn(player &p);
	virtual int turn(player &p);
	virtual int after_turn(player &p);
	virtual int before_round();
	virtual int round();
	virtual int after_round();
	bool AllisNum(string str);
	//lab 4
	virtual int bet_phase(player& p1);
	//bool poker_rank(shared_ptr<player> &p1, shared_ptr<player> &p2);

};
bool poker_rank1(shared_ptr<player> &p1, shared_ptr<player> &p2);

#endif
