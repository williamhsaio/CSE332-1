#pragma once

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
	
public:
	FiveCardDraw();
	virtual int before_turn(player &p);
	virtual int turn(player &p);
	virtual int after_turn(player &p);
	virtual int before_round() ;
	virtual int round();
	virtual int after_round();
	
};
bool poker_rank(shared_ptr<player> &p1, shared_ptr<player> &p2);