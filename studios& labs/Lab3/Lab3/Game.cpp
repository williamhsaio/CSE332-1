#include "stdafx.h"
#include "Game.h"
#include "player.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<exception>
#include "FiveCardDraw.h"
using namespace std;
shared_ptr<game> game::game_G(nullptr);

game::game() : deck_game(Deck()), players_game(vector<shared_ptr<player>>())
{
	cout << "created game" << endl;
}


game::~game()
{
	cout << "delete Game " << endl;
}

shared_ptr<game> game::instance() {
	if (game_G == nullptr) {
		throw(card1::success_fail::instance_not_available);
	}
	
	return shared_ptr<game>(game_G);
}
/*

allocate an instance of the FiveCardDraw class (to be described below) and store its address 
in the static pointer member variable: if you use a shared_ptr (which is preferred) instead of 
a native C++ pointer, then you would use make_shared instead of new.
*/
void game::start_game(const string & input) {
	if (game_G != nullptr) {
		throw(card1::success_fail::game_already_started);
	}
	if (input.find("FiveCardDraw") == std::string::npos) {
		throw(card1::success_fail::unknown_game);
	}
	game_G = make_shared<FiveCardDraw>();
	cout << "game started" << endl;
	return;
}
void game::stop_game() {
	if (game_G == nullptr) {
		throw(card1::success_fail::no_game_in_progress);
	}
	game_G = nullptr;
	cout << "stopped successfully" << endl;
	return;
}
//may be wrong 
void game::add_player(const string & p1) {
	int size = players_game.size();
	
	for (int i = 0; i < size;i++) {
		const string &name = (*players_game[i]).get_name();
		if (p1 ==name) {
			cout << "the guy you want to add is already playing" << endl;
			throw(card1::success_fail::already_playing);
		}
	}
	
	players_game.push_back(make_shared<player>(p1));
	player A(p1);
	cout << "added "<< A.get_name() <<" successfully" << endl;
}

void game::add_player(player a) {
	string & name = a.get_name();
	players_game.push_back(make_shared<player>(name));
}
shared_ptr<player> game::find_palyer(const string & player1) {
	shared_ptr<player> out_1(nullptr);
	int size = players_game.size();
	for (int i = 0; i < size;i++) {
		player & p1 = (*players_game[i]);
		const string &name = p1.get_name();
		if (name == player1) {
			out_1 = players_game[i];
			cout << "found" << endl;
			return out_1;
		}
	}
	cout << " not found" << endl;
	return out_1;
}

int game::player_size() const {
	return players_game.size();
}