#pragma once

#include "card1.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "deck.h"
#include "player.h"
#include <memory>

using namespace std;
class game {
protected:
	//lab4 
	int pot_amout;
	static shared_ptr<game> game_G;//7.1
	
	Deck deck_game; // 7.2
	vector<shared_ptr<player>> players_game;//7.3
	
	
private:

public:
	//Deck deck_game; // 7.2

	game();
	virtual ~game();
	static shared_ptr<game> instance();
	static void start_game(const string & input); // string const string input 
	static void stop_game();
	void add_player( const string & player);
	
	shared_ptr<player> find_palyer(const string & player);
	
	virtual int before_turn(player &p1) =0;
	virtual int turn(player &p1)=0;
	virtual int after_turn(player &p1) = 0;
	virtual int before_round() =0;
	virtual int round() = 0;
	
	virtual int after_round() = 0;
	int player_size() const;
	//lab 4
	virtual void add_pot(player& p1, unsigned int amount);
	virtual void ask_to_add_money_or_not(player& p1);
	virtual void delete_user(player & p1);
	
};