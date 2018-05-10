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
#include "SevenCardStud.h"
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
	if (input.find("FiveCardDraw") == std::string::npos&& input.find("SevenCardStud") == std::string::npos) {
		throw(card1::success_fail::unknown_game);
	}
	if (input == "FiveCardDraw") {
		game_G = make_shared<FiveCardDraw>();
	}
	else if (input == "SevenCardStud") {
		game_G = make_shared<SevenCardStud>();
	}
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
	//player A(p1);
	cout << "added "<< players_game[size]->get_name() <<" successfully" << endl;
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
void game::add_pot(player& p1, unsigned int amount) {
	if (p1.chips > amount) {
		p1.chips = p1.chips - amount;
		p1.bet_total = p1.bet_total + amount;
		pot_amout = pot_amout + amount;
	}
	else {
		p1.no_money = true;
		
		p1.bet_total = p1.bet_total + p1.chips;
		pot_amout = pot_amout + p1.chips;
		p1.chips = 0;
	}
}

void game::ask_to_add_money_or_not(player& p1) {
	cout << "sorry "<< p1.get_name()<< " don't have money to play the game" << endl;
	cout << " if you need to add money to "<< p1.get_name() <<" account, type in yes to reset your chips =20, or anything else will kick you out of the game" << endl;
	string answer;
	int tl = 1;
	getline(cin, answer); 
	if (answer == "yes") {
		p1.chips = 20;
		add_pot(p1, tl);
		p1.no_money = false;// very important
	}
	else {
		for (size_t i = 0; i < players_game.size(); i++) {
			if (players_game[i]->get_name() == p1.get_name()) {
				ofstream ofs;
				ofs.open(p1.get_name());
				string to_write = players_game[i]->get_name() + " " + to_string(players_game[i]->get_won()) + " " + to_string(players_game[i]->get_lost()) + " " + to_string(players_game[i]->get_chips());
				ofs << to_write;
				ofs.close();
				players_game.erase(players_game.begin() + i);
				break;
			}
		}
		
	}
	return;
}
void game::delete_user(player& p1) {
	ofstream ofs;
	ofs.open(p1.get_name());
	string to_write = p1.get_name() + " " + to_string(p1.get_won()) + " " + to_string(p1.get_lost() + 1) + " " + to_string(p1.get_chips());
	ofs << to_write;
	ofs.close();
	for (std::vector<std::shared_ptr<player>>::iterator p = players_game.begin(); p != players_game.end(); ++p) {
		if ((*p)->get_name() == p1.get_name()) {
			players_game.erase(p);
			cout << "dropping this player from the game" << endl;
			break;
		}
	}
	return;
}