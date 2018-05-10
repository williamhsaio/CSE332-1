#pragma once
#ifndef five_card
#define five_card
#include "card1.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "deck.h"
#include "player.h"
#include <memory>
#include "Game.h"
class FiveCardDraw : public game
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
	FiveCardDraw();
	virtual int before_turn(player &p);
	virtual int turn(player &p);
	virtual int after_turn(player &p);
	virtual int before_round() ;
	virtual int round();
	virtual int after_round();
	bool AllisNum(string str);
	
	//lab 4
	virtual int bet_phase(player& p1);
	//bool poker_rank(shared_ptr<player> &p1, shared_ptr<player> &p2);
	
};
bool poker_rank(shared_ptr<player> &p1, shared_ptr<player> &p2);

#endif