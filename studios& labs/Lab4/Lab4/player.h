#pragma once
#include "hand.h"
#include <iostream>
#include <string>
#include <string>
#include <vector>


struct player {

	player();
	player(string name);
	int get_lost() const;
	int get_won() const;
	int get_chips() const;
	string get_name() const;
	hand player_hand;


	string playerName;
	unsigned int lost_hand;
	unsigned int won_hand;
	// lab 4
	unsigned int chips;
	//unsigned int bet_this_turn;
	unsigned int bet_total;
	void reset_chips();
	bool is_fold = false;
	bool no_money;

};

ostream &operator <<(ostream &out, const player &p);