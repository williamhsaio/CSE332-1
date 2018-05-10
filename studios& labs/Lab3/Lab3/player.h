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
	string get_name() const;
	hand player_hand;

	string playerName;
	unsigned int lost_hand;
	unsigned int won_hand;
	

};

ostream &operator <<(ostream &out, const player &p);