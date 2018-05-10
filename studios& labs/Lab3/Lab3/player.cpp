#include "stdafx.h"
#include "player.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<exception>
using namespace std;

player::player() {
	cout << "please give the player a name" << endl;
	throw(card1::success_fail::none_name);
}

int player::get_lost() const
{
	return this->lost_hand;
}

int player::get_won() const
{
	return won_hand;
}

string player::get_name() const
{
	return playerName;
}
player::player(string name) {
	lost_hand = 0;
	won_hand = 0;
	//player_hand = hand();
	playerName = name;

	ifstream ifs;
	ifs.open(playerName);
	// how to directly read a file without txt 
	if (!ifs.is_open()) {
		cout << "the file: " << playerName << " can't be opened or can't be found for reading" << endl;
		return;
	}
	
	try {
			string this_line;
			string this_word;
			
			stringstream middle;
			getline(ifs, this_line);
			if (this_line.empty()) {
				throw;
			}
			middle << this_line;

			
			if (middle >> this_word) {
					playerName = this_word;
			}
			else {
				cout << "please check the file name of "<<name <<" has enough information" << endl;
				throw(card1::success_fail::not_enough_info);
			}
			if (middle >> this_word) {
					won_hand = stoi(this_word);
			}
			else {
				cout << "please check the file name of " << name << " has enough information" << endl;
				throw(card1::success_fail::not_enough_info);
			}
			if (middle >> this_word) {
					lost_hand = stoi(this_word);
			}
			else {
				cout << "please check the file name of " << name << " has enough information" << endl;
				throw(card1::success_fail::not_enough_info);
			}
			
	}
	catch (...) {
			lost_hand = 0;
			won_hand = 0;
			//player_hand = hand();
			playerName = name;
	}
	ifs.close();
	return;

	


}

ostream &operator <<(ostream &return1, const player &p) {
	return1 << "Name: " << p.get_name()<< "| Lost: "<<p.get_lost() << " | Won :" << p.get_won() << " | lost" ;
	return return1;
}