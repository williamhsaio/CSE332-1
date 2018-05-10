#pragma once 
#include "stdafx.h"
#include "card1.h"

#include "Deck.h"
#include "hand.h"
#include "player.h"
#include "Game.h"
#include "FiveCardDraw.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
// insert 52 cards into deck_game
FiveCardDraw::FiveCardDraw() {
	position_dealer = 0;
	discard_deck = Deck();
	deck_game = Deck();
	for (int i = 2; i < 15; i++) {
		for (int j = 1; j < 5;j++) {
			card to_insert = card(suit(j),card_rank(i));
			deck_game.add_card(to_insert);
		}
	}

}
// help function to check the cin is all number variable
bool AllisNum(string str)
	{
		for (size_t i = 0; i < str.size(); i++){
			int tmp = (int)str[i];
			if (tmp >= 48 && tmp <= 57 || tmp ==32|| tmp ==45){
				continue;
			}
			else{
				return false;
			}
		}
		return true;	
}

int FiveCardDraw::before_turn(player &p) {
	cout << "| " << p.get_name() << " | " << p.player_hand << endl;
	cout << "enter the index of the card you want to discard" << endl;
	cout << "enter multuply number if you want to discard several cards and set a space between each index" << endl;
	cout << "the numbe of card in this hand is : " <<p.player_hand.size() << endl;
	cout << "enter -1 to don't discard any card" << endl;
	string input1;
	getline(cin, input1);
	cout << "your input string is : " << input1 << endl;
	// need to check string input
	if (AllisNum(input1)==false) {
		cout << "plz enter number only " << endl;
		return before_turn(p);
	}


	cout << endl;
	std::istringstream iss(input1);
	
	int index;
	vector <int> discard_index;
	while (iss >> index) {
		
		if (index == -1) {
			cout << "do nothing" << endl;			
			return card1::success_fail::success;
		}
		if (find(discard_index.begin(), discard_index.end(),index) != discard_index.end()) {
			cout << "plz enter different index "<< endl;
			return before_turn(p);
		}
		if (index >=0 && index <p.player_hand.size()) {
			discard_index.push_back(index);
		}
		// if any invalid index
		else {
			cout << "plz enter valid index which from 0 to " << p.player_hand.size() - 1 << endl;
			return before_turn(p);
		}
	}
	
	//sort the index
	sort(discard_index.begin(), discard_index.end());

	// if too many
	int a = discard_index.size();
	int b = p.player_hand.size();
	
	if (a >b) {
		cout << "you enter too many index, more the number of cards in this player's hand" << endl;
		return before_turn(p);
	}
	// need to change, since the index is change!
	for (size_t i = 0; i < discard_index.size();i++) {
		//cout << "doing add card first " << endl;
		discard_deck.add_card(p.player_hand[discard_index[i]]);// use hand operator [] 
		//p.player_hand.remove_card(discard_index[i]);
	}
	// remove card and show the card be removed
	cout << "doing delete card second and the card is : " << endl;
	for (size_t i = 0; i < discard_index.size(); i++) {
		cout << card::string_of_card_rank(p.player_hand[discard_index[i] - i].rank) << card::string_of_card_suit(p.player_hand[discard_index[i] - i].suits) << " | ";
		p.player_hand.remove_card(discard_index[i]-i);
		
	}
	cout << endl;
	cout << "the cards in hand right now : " << p.player_hand << endl;
	cout << endl;

	cout << "did successfully" << endl;
	return card1::success_fail::success;

}

int FiveCardDraw::turn(player &p) {
	if (p.player_hand.size() == 5) {
		//cout << "| " << p.get_name() << " | " << p.player_hand << endl;
		return card1::success_fail::success;
	}
	int card_number_need = 5-p.player_hand.size();
	if (discard_deck.size()+ deck_game.size() < card_number_need) {
		cout << "doesn't have enough card in the main_deck and discard_deck" << endl;
		return card1::success_fail::no_enough_card_in_both_deck;
	}
	while (p.player_hand.size() != 5) {
		if (deck_game.size() != 0) {
			cout << p.get_name() << " got the new card : ";
			Deck::print_last(deck_game);
			p.player_hand << deck_game;
		}
		else {
			// get card from discard deck
			discard_deck.shuffle();
			p.player_hand << discard_deck;
		}
	}
	cout << "turn method successed" << endl;
	return card1::success_fail::success;
}

int FiveCardDraw::after_turn(player &p) {
	cout << "name : "<<p.get_name() << endl;
	cout << "hand : " << p.player_hand << endl;
	return card1::success_fail::success;
}

int FiveCardDraw::before_round() {
	deck_game.shuffle();
	size_t start_index = position_dealer + 1;
	//or, if the player in the last position is the dealer, starting at position 0),
	start_index = start_index % players_game.size();
	
	size_t player_right_now = start_index;
	for (size_t i = 0; i < players_game.size()*5;i++) { // 5* players number
		
		player &p1 = *players_game[player_right_now];
		if (p1.player_hand.size() ==5) {
			player_right_now++;
			player_right_now = player_right_now % players_game.size();
			continue;
		}
		p1.player_hand << deck_game;
		player_right_now++;
		player_right_now = player_right_now % players_game.size();
		
	}

	player_right_now = start_index;
	for (size_t i = 0; i < players_game.size();i++) {
		player_right_now = player_right_now % players_game.size();

		player &p1 = *players_game[player_right_now];
		before_turn(p1);
		player_right_now++;

	}

	return card1::success_fail::success;
}
int FiveCardDraw::round() {
	/*
	 
	The method should iterate once more through the players (again starting with the
	one just past the dealer), and at each player calling their turn method and then
	their after_turn method. If any player's turn method returns a non-zero value, 
	the method should immediately return that non-zero value; otherwise if it completes
	with no problems the method should return 0 to indicate success.
	*/
	size_t player_right_now = position_dealer+1;
	for (size_t i = 0; i < players_game.size(); i++) {
		player_right_now = player_right_now % players_game.size();
		player &p1 = *players_game[player_right_now];
		int outp = turn(p1);
		if (outp!=0) {
			cout <<" round - turn -error" << endl;
			return outp;
		}
		after_turn(p1);
		player_right_now++;
	}

	return card1::success_fail::success;
}
//helper function to sort the player
bool poker_rank(shared_ptr<player> &p1, shared_ptr<player> &p2) {
	if (p1 == nullptr) {
		return false;
	}
	if ( p1 != nullptr && p2 == nullptr) {
		return true;
	}
	else {
		hand hand1 = p1->player_hand;
		hand hand2 = p2->player_hand;
		return hand::poker_rank(hand1, hand2);
	}
}

int FiveCardDraw::after_round() {
	// copy all the players in the game into temp_players
	vector <shared_ptr<player>> players_temp(players_game);
	sort(players_temp.begin(), players_temp.end(), poker_rank);

	for (size_t i = 0; i < players_temp.size();i++) {
		if (i == 0) {
			cout << " the winner is " << players_temp[i]->get_name() << endl;
			players_temp[i]->won_hand++;
		}
		else {
			players_temp[i]->lost_hand++;
		}
	}
	for (size_t i = 0; i < players_temp.size(); i++) {
		player &p1 = *players_game[i];
		cout << "name : " << p1.get_name() << " | won : " << p1.get_won() << " | lost : " << p1.get_lost() << endl;
	}
	cout << "befor get back the totally size is : " << deck_game.size() << endl;
	// put the card in discard into main deck
	while (discard_deck.size()!=0) {
		deck_game << discard_deck;
	}
	// put the cards in players hand into main deck
	for (size_t t = 0; t < players_game.size();t++ ) {
		while (players_game[t]->player_hand.size() !=0) {
			deck_game << players_game[t]->player_hand;
		}
	}
	cout <<"the totally size is : "<<deck_game.size() << endl;
	//todo leave and join function
	// leave
	string answer;
	while (answer != "no") {
		cout << "currenrt players in the game are : " << " number is "<< players_game.size() << endl;
		for (size_t i = 0; i < players_game.size(); i++) {
			cout << players_game[i]->get_name() <<" | " ;
		}
		cout << endl;
		cout << "is there any one want to leave the game, if any, please enter their name to kick them out" << endl;
		cout << "if no, just enter no to keep running the game" << endl;
		getline(cin, answer);
		if (answer == "no") {
			cout << "you said no one want to leave, ok, let's fins any one want to join the game" << endl;
			break;
		}
		shared_ptr<player> p = game::find_palyer(answer);
		if ( p == nullptr) {
			cout << "the guy : " << answer << " is not in the game right now " << endl;
			continue;
		}
		
		
		// only update the player information when they want to leave,
		for (size_t i = 0; i < players_game.size();i++) {
			if (players_game[i]->get_name() == answer) {
				ofstream ofs;
				ofs.open(answer);
				string to_write = players_game[i]->get_name() + " " + to_string(players_game[i]->get_won()) +" " + to_string(players_game[i]->get_lost());
				ofs << to_write;
				ofs.close();
				players_game.erase(players_game.begin() + i);
				break;
			}
		}
	}
	//save all player right now 
	for (size_t i = 0; i < players_game.size(); i++) {
		string name = players_game[i]->get_name();
		ofstream ofs;
		ofs.open(name);
		string to_write = players_game[i]->get_name() + " " + to_string(players_game[i]->get_won()) + " " + to_string(players_game[i]->get_lost());
		ofs << to_write;
		ofs.close();
		//players_game.erase(players_game.begin() + i);
	}
	// find if any one want to join the game::
	cout << endl << "------------------------" << endl;
	cout << endl << "------------------------" << endl;
	string join_player;
	//int &e;
	while (join_player != "no") {
		cout << "currenrt players in the game are : " << " number is " << players_game.size() << endl;
		for (size_t i = 0; i < players_game.size(); i++) {
			cout << players_game[i]->get_name() << " | ";
		}
		cout << endl;
		cout << "is there any one wnat to join the game, if any, please enter their name to get them join" << endl;
		cout << "if no, just enter no to continue the game" << endl;
		getline(cin, join_player);
		if (join_player == "no") {
			cout << "you said no one want to join, ok, let start a new round " << endl;
			break;
		}
		if (join_player != "no") {
			try {
				game::add_player(join_player);
			}
			catch (card1::success_fail &e) {
				(void)e;
				cout << endl << "------------------------" << endl;
				cout << "please add a different player" << endl;
				continue;
			}
		}
		// only update the player information when they want to leave,
		
	}
	//save all player right now 
	for (size_t i = 0; i < players_game.size(); i++) {
		string name = players_game[i]->get_name();
		ofstream ofs;
		ofs.open(name);
		string to_write = players_game[i]->get_name() + " " + to_string(players_game[i]->get_won()) + " " + to_string(players_game[i]->get_lost());
		ofs << to_write;
		ofs.close();
		//players_game.erase(players_game.begin() + i);
	}
	position_dealer++;
	position_dealer = position_dealer % players_game.size();
	cout << "position_dealer : " << position_dealer << endl;
	return card1::success_fail::success;
}



