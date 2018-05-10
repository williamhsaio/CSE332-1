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
	pot_amout = 0;
	position_dealer = 0;
	discard_deck = Deck();
	deck_game = Deck();
	//lab 4
	ante = 1;
	highest_bet_amount = 0;
	for (int i = 2; i < 15; i++) {
		for (int j = 1; j < 5;j++) {
			card to_insert = card(suit(j),card_rank(i));
			deck_game.add_card(to_insert);
		}
	}

}
// help function to check the cin is all number variable
bool FiveCardDraw::AllisNum(string str)
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
	//lab4 
	if (p.is_fold == true) {
		cout << "| " << p.get_name() << " | " << p.player_hand.asString() << endl;
		cout << "chose to fold, let's drop him and goto next player" << endl;
		//delete_user(p);
		return card1::success_fail::success;
	
	}

	cout << "| " << p.get_name() << " | " << p.player_hand.asString() << endl;
	cout << "enter the index of the card(s) you want to discard" << endl;
	cout << "enter multiple numbers seperated by spaces if you want to discard several cards" << endl;
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
		cout << "you entered too many indices, not enough cards in the hand" << endl;
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
	cout << "the cards in hand right now : " << p.player_hand.asString() << endl;
	cout << endl;

	cout << "did successfully" << endl;
	return card1::success_fail::success;

}

// give a player 5 cards
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

// show cards in hand
int FiveCardDraw::after_turn(player &p) {
	if (p.is_fold == true) {
		cout << "name : " << p.get_name() << endl;
		cout << "this player chose to fold, don't show him hands" << endl;
		
		return card1::success_fail::success;
	}
	cout << "name : "<<p.get_name() << endl;
	cout << "hand : " << p.player_hand.asString() << endl;
	return card1::success_fail::success;
}

//
int FiveCardDraw::before_round() {
	
	deck_game.shuffle();
	size_t start_index = position_dealer + 1;
	//or, if the player in the last position is the dealer, starting at position 0),
	start_index = start_index % players_game.size();
	
	size_t player_right_now = start_index;

	//lab4 
	pot_amout = 0;
	
	highest_bet_amount = 0;
	int tl = 1;
	// initialization
	for (size_t i = 0; i < players_game.size();i++) {
		
		
		players_game[i]->is_fold = false;
		players_game[i]->bet_total = 0;
		if (players_game[i]->chips <= 0 ) {
			ask_to_add_money_or_not(*players_game[i]);
			if (players_game.size() <= 1) {
				cout << "sorry, only | " << players_game.size() << " | player, we have to cancel the game" << endl;
				throw(card1::success_fail::no_enough_player_in_game);
			}
		}
		else {
			//add_pot(*players_game[i],tl);
			players_game[i]->chips = players_game[i]->chips - 1;
			pot_amout = pot_amout + 1;
		}
	}
	
	//

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
	cout << "their initial 5 cards" << endl;
	for (size_t i = 0; i < players_game.size(); i++) {
		cout << "Name : " << (*players_game[i]).get_name() << "| hand : " << (*players_game[i]).player_hand.asString() << endl;
	}

	//betting phase 1
	cout << "after the initialization process, the total amount in game pot is : " << pot_amout << endl;
	int check_round = 0;
	bool already_one_round = false;
	highest_bet_amount = 0;// every one need to bet
	bet_player_number = 0;
	fold_player_number = 0;
	phase_done = false;// all but one choose to fold
	phase_done_one_round = false;
	while (!((already_one_round == true && bet_player_number == 0) || (bet_player_number != 0 && highest_bit_amount_player == nullptr) || (fold_player_number == (players_game.size() - 1)))) {


		player_right_now = player_right_now % players_game.size();
		//check money

		bet_phase(*players_game[player_right_now]);
		if (phase_done == true) {
			cout << "finished pahse beacuse so many players fold" << endl;
			throw(card1::success_fail::all_but_one_fold);

		}
		if (phase_done_one_round == true) {
			cout << "finished pahse because already one round" << endl;
			break;
		}
		if (check_round + 1 == players_game.size()) {
			already_one_round = true;
		}
		player_right_now = player_right_now + 1;
		check_round++;
		cout << "after this phase, the total amount in game pot is : " << pot_amout << endl;

	}
	phase_done_one_round = false;
	// finished pahse 1
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
	//betting phase 2

	size_t start_index = position_dealer + 1;
	//or, if the player in the last position is the dealer, starting at position 0),
	start_index = start_index % players_game.size();

	size_t player_right_now = start_index;

	cout << "after the first phase, the total amount in game pot is : " << pot_amout << endl;
	int check_round = 0;
	bool already_one_round = false;
	highest_bet_amount = 0;// every one need to bet
	bet_player_number = 0;
	//fold_player_number = 0;
	//phase_done = false;// all but one choose to fold
	phase_done_one_round = false;
	for (size_t i = 0; i < players_game.size(); i++) {
		(*players_game[i]).bet_total = 0;
	}

	while (!((already_one_round == true && bet_player_number == 0) || (bet_player_number != 0 && highest_bit_amount_player == nullptr) || (fold_player_number == (players_game.size() - 1)))) {


		player_right_now = player_right_now % players_game.size();
		//check money

		bet_phase(*players_game[player_right_now]);
		if (phase_done == true) {
			cout << "finished pahse beacuse so many players fold" << endl;
			throw(card1::success_fail::all_but_one_fold);

		}
		if (phase_done_one_round == true) {
			cout << "finished pahse because already one round" << endl;
			break;
		}
		if (check_round + 1 == players_game.size()) {
			already_one_round = true;
		}
		player_right_now = player_right_now + 1;
		check_round++;
		cout << "after this phase, the total amount in game pot is : " << pot_amout << endl;

	}
	phase_done_one_round = false;





	vector <shared_ptr<player>> players_temp(players_game);
	sort(players_temp.begin(), players_temp.end(), poker_rank);
	// do something to kick out the fold player!!!!
	int check_number = 0;
	for (size_t i = 0; i < players_temp.size();i++) {
		
		if (check_number == 0 && players_temp[i]->is_fold == false) {
			cout << endl << "---------------------------" << endl;
			cout << " the winner is " << players_temp[i]->get_name() << endl;

			players_temp[i]->won_hand++;
			players_temp[i]->chips = players_temp[i]->chips + pot_amout;
			players_temp[i]->no_money = false;// set the winner always have money
			pot_amout = 0;
			check_number = 1;
		}
		else if (players_temp[i]->is_fold == false) {
			players_temp[i]->lost_hand++;
		}
		else {
			continue;
		}
	}
	for (size_t i = 0; i < players_temp.size(); i++) {
		cout << endl << "---------------------------" << endl;
		player &p1 = *players_game[i];
		if (p1.is_fold != true) {
			cout << "name : " << p1.get_name() << " | won : " << p1.get_won() << " | lost : " << p1.get_lost() << " | chips : " << p1.get_chips() << " | hand : " << p1.player_hand.asString() << endl;
		}
		if (p1.is_fold == true) {
			cout<< "name : " << p1.get_name() << " | won : " << p1.get_won() << " | lost : " << p1.get_lost() << " | chips : " << p1.get_chips() << " | this guy chose fold "<<endl;
		}
	}
	cout << endl << "---------------------------" << endl;
	//cout << "befor get back the totally size is : " << deck_game.size() << endl;
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
	//cout <<"the totally size is : "<<deck_game.size() << endl;
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
				string to_write = players_game[i]->get_name() + " " + to_string(players_game[i]->get_won()) + " " + to_string(players_game[i]->get_lost()) + " " + to_string(players_game[i]->get_chips());
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
		string to_write = players_game[i]->get_name() + " " + to_string(players_game[i]->get_won()) + " " + to_string(players_game[i]->get_lost())+" "+ to_string(players_game[i]->get_chips());
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
		string to_write = players_game[i]->get_name() + " " + to_string(players_game[i]->get_won()) + " " + to_string(players_game[i]->get_lost()) + " " + to_string(players_game[i]->get_chips());
		ofs << to_write;
		ofs.close();
		//players_game.erase(players_game.begin() + i);
	}
	
	string finish_;
	cout << endl << "------------------------" << endl;
	cout << endl << "------------------------" << endl;
	cout << "would you like to finish that game?" << endl;
	cout << "enter : <finish> to finish or any other input wil make you keep playing the game" << endl;

	getline(cin, finish_);
	cout << "your inpur string is : " << finish_ << endl;
	if (finish_.find("finish") != std::string::npos) {

		throw(card1::success_fail::success);
	}
	else {
		cout << "you choose to keep playing " << endl;
	}
	

	position_dealer++;
	position_dealer = position_dealer % players_game.size();
	cout << "position_dealer : " << position_dealer << endl;
	return card1::success_fail::success;
}
//lab 4
int FiveCardDraw::bet_phase(player & p1) {
	cout << "| " << p1.get_name() << " | " << p1.player_hand.asString() << endl;
	cout << "this player has : " << p1.chips << " chips right now" << endl;
	if (p1.no_money == true&& bet_player_number != 0&& p1.get_name() != (*highest_bit_amount_player).get_name()) {
		
		cout << "doesn't have money, let's skip him and goto next player" << endl;
		return card1::success_fail::success;
	}
	if (p1.is_fold == true) {
		
		cout << "chose to fold, let's skip him and goto next player" << endl;
		//delete_user(p1);
		
		return card1::success_fail::success;
	}
	
	if (fold_player_number == players_game.size()-1) {
		
		cout << "only you not fold right now, you are the warrior,so you win the game " << endl;
		return card1::success_fail::success;
	}
	// not one in the table bet yet_____condition 1
	// player can check or bet
	if (bet_player_number == 0) {
		
		// player has no money
		if (p1.chips <=0) {
			cout << "sorry, you don't have enough money, so you have to check" << endl;
			p1.no_money = true;
			return card1::success_fail::success;
		}

		int ai = 0;
		string input12;
		while (ai == 0) {
			cout << "the number of bet_er is 0, so you can check or bet, if you want to check, type in check, or type in bet" << endl;
			getline(cin, input12);
			
			if (input12 =="check") {
				// nothing happended
				if (p1.chips <= 0) {
					p1.no_money = true;
				}
				cout << "you made a wise choice ----- check" << endl;
				ai = 1;
				cout << p1.get_name() << " has totally : " << p1.get_chips() << " and bet " << p1.bet_total << endl;
				return card1::success_fail::success;
				//break;
			}

			else if (input12 == "bet") {
				if (p1.no_money == true) {
					cout << "this player doesn't have enough money, so he has to check at this round" << endl;
					cout << p1.get_name() << " has totally : " << p1.get_chips() << " and bet " << p1.bet_total << endl;
					return card1::success_fail::success;
				}
				bet_player_number++;
				ai = 1;
				int aii = 0;
				while(aii ==0){
					cout << "type 1 or 2 chips you want to bet" << endl;
					string first_bet_amout;
					getline(cin, first_bet_amout);
					if (first_bet_amout =="1") {
						cout << "you bet 1 chip" << endl;
						highest_bet_amount = highest_bet_amount + 1;
						add_pot(p1, 1);// to be check
						if (p1.chips <= 0) {
							p1.no_money = true;
						}
						highest_bit_amount_player = &p1;
						aii = 1;
						break;
					}
					else if (first_bet_amout == "2") {
						//check player have 2 chips
						if (p1.chips < 2) {
							cout << "you don't have enough money to bet, so We auto set your bet amout is 1 " << endl;
							highest_bet_amount = highest_bet_amount + 1;
							add_pot(p1, 1);
							if (p1.chips <= 0) {
								p1.no_money = true;
							}
							highest_bit_amount_player = &p1;
							aii = 1;
							break;
						}
						cout << "you bet 2 chip" << endl;
						highest_bet_amount = highest_bet_amount + 2;
						add_pot(p1, 2);
						if (p1.chips <= 0) {
							p1.no_money = true;
						}
						highest_bit_amount_player = &p1;
						aii = 1;
						break;

					}
					else {
						cout << "please enter valid number" << endl;
						continue;
					}
					
				}
				if (p1.chips <= 0) {
					p1.no_money = true;
				}
				highest_bit_amount_player = &p1;// set the highest player
				break;
				
			}

			else {
				continue;
			}
		}

		
	}
	// some players already bet 
	else {
		// any players go in here should have money, but might be not enough money
		if (p1.get_name() == (*highest_bit_amount_player).get_name()) {
			// one round, phase finished
			// reset all parameters
			highest_bit_amount_player = nullptr;
			//bet_player_number = 0;
			fold_player_number = 0;
			//highest_bet_amout = 0;
			cout << "back to the most recent bet, " << endl;
			cout << p1.get_name() << " has totally : " << p1.get_chips() << " and bet " << p1.bet_total << endl;
			cout << "phase over" << endl;
			phase_done_one_round = true;
			return card1::success_fail::success;// need to check outside the phase function
		}

		cout << "some one already bet, so you have to call or fold or raise" << endl;
		cout << "you have to bet at least : " << highest_bet_amount - p1.bet_total << endl;//
		cout << "you at most can bet : " << highest_bet_amount - p1.bet_total + 2 << endl;
		cout << "let's first check if you have enough money" << endl;
		//check if  this player has money
		if (p1.chips + p1.bet_total < (highest_bet_amount )) {
			cout << "not enough money to call, so you have to put all chips you have to the pot" << std::endl;
			cout << "which is : " << p1.chips << endl;
			add_pot(p1, p1.chips);
			p1.no_money = true;
			return card1::success_fail::success;
		}

		else if (p1.chips + p1.bet_total  == highest_bet_amount ) {//only have enough money to call
			add_pot(p1, highest_bet_amount - p1.bet_total);
			std::cout << "not enough money to raise, so you have to put all chips you have to call" << std::endl;
			p1.no_money = true;
			return card1::success_fail::success;
		}

		else {//p1.chips >highest_bet_amout - p1.bet_total
			// ask them to fold at first
			string input111;

			
			int i1111 = 0;
			while (i1111 == 0) {
				
				cout << "would you like to fold or call or raise? enter fold or call or raise" << endl;
				getline(cin, input111);
				cout << " in phase your input string is : " << input111 << endl;
				if (input111 == "fold") {
					cout << " you choose to fold." << endl;
					fold_player_number++;
					p1.is_fold = true;
					cout << "totally fold players number is : " << fold_player_number << endl;
					if (fold_player_number == players_game.size()-1) {
						phase_done = true;
						throw(card1::success_fail::all_but_one_fold);

					}
					//delete_user(p1);
					return card1::success_fail::success;
				}
				else if (input111 == "call") {
					cout << " you want to call, ok, let go get it" << endl;
					add_pot(p1, highest_bet_amount - p1.bet_total);
					return card1::success_fail::success;
				}
				else if (input111 == "raise") {
					if (p1.bet_total+p1.chips == highest_bet_amount +1) {
						cout << "you only can raise for one chip based on the money you have" << endl;
						cout << "and let me auto set your raise amount to 1" << endl;
						highest_bet_amount = highest_bet_amount + 1;
						add_pot(p1, highest_bet_amount - p1.bet_total);
						highest_bit_amount_player = &p1;

						if (p1.chips <= 0) {
							p1.no_money = true;
						}
						return card1::success_fail::success;
					}
					else {
						int check_raise = 0;
						while (check_raise == 0) {
							cout << " you want to raise, ok, let start raise, please type in 1 or 2 to raise" << endl;
							string raise;
							getline(cin, raise);
							if (raise == "1") {
								cout << " you raise 1 chip" << endl;
								highest_bet_amount = highest_bet_amount + 1;
								add_pot(p1, highest_bet_amount - p1.bet_total);
								highest_bit_amount_player = &p1;
								if (p1.chips <= 0) {
									p1.no_money = true;
								}
								return card1::success_fail::success;
							}
							else if (raise == "2") {
								if (p1.chips < 2) {
									cout << "you don't have enough money to raise, so We auto set your raise amount is 1 " << endl;
									cout << " you raise 1 chip" << endl;
									highest_bet_amount = highest_bet_amount + 1;
									add_pot(p1, highest_bet_amount - p1.bet_total);
									highest_bit_amount_player = &p1;

									if (p1.chips <= 0) {
										p1.no_money = true;
									}
									check_raise = 1;
									return card1::success_fail::success;
								}
								cout << "you bet 2 chip" << endl;
								highest_bet_amount = highest_bet_amount + 2;
								add_pot(p1, highest_bet_amount - p1.bet_total);
								if (p1.chips <= 0) {
									p1.no_money = true;
								}
								check_raise = 1;
								highest_bit_amount_player = &p1;
								return card1::success_fail::success;

							}
							else {
								cout << "please enter valid number " << endl;
								continue;
							}

						}
					}

				}
				else {
					cout << "please type in valid string" << endl;
					continue;

				}
			}
		}
	}
	cout << p1.get_name() << " has totally : " << p1.get_chips() << " and bet " << p1.bet_total << endl;
	return card1::success_fail::success;
}




