// Lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lab0.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;




int usage() {
	cout << "Lab0 is a read card from a file and prient all the card in this file out" << endl;
	cout << "you need to set the input as this form : Lab0.exe card_file.txt" << endl;
	cout << "run the lab0.exe and set the care_file.txt as it input file" << endl;

	return fail;
}



card_rank change_to_rank(int value) {
	switch (value)
	{
	case 2: 
		return two;
		break;
	case 3: 
		return three;
		break;
	case 4: 
		return four;
		break;
	case 5: 
		return five;
		break;
	case 6: 
		return six;
		break;
	case 7: 
		return seven;
		break;
	case 8:
		return eight;
		break;
	case 9: 
		return nine;
		break;
	case 10: 
		return ten;
		break;
	case 11: 
		return jack;
		break;
	case 12: 
		return queen;
		break;
	case 13:
		return king;
		break;
	case 14:
		return ace;
		break;
	default:
		return nan1;
		break;
	}

}
suit change_to_suit(char suit) {
	switch (suit)
	{
	case 'c': 
		return c;
		break;
	case 'C':
		return c;
		break;
	case 'd':
		return d;
		break;
	case 'D':
		return d;
		break;
	case 'h':
		return h;
		break;
	case 'H':
		return h;
		break;
	case 's':
		return s;
		break;
	case 'S':
		return s;
		break;
	default:
		return nan2;
		break;
	}
}
/*
string string_of_card_suit(suit suit) {
	if (suit == 1) {
		return "Hearts";
	}
	else if (suit == 2) {
		return "Clubs";
	}
	else if (suit == 3) {
		return "Spades";
	}
	else if (suit == 4) {
		return "Diamonds";
	}
	else {
		return "invalid typle";
	}
}
*/
string string_of_card_suit(suit suit) {
	if (suit == 1) {
		return "Clubs";
	}
	else if (suit == 2) {
		return "Diamonds";
	}
	else if (suit == 3) {
		return "Hearts";
	}
	else if (suit == 4) {
		return "Spades";
	}
	else {
		return "invalid typle";
	}
}



string string_of_card_rank(card_rank rank) {
	if (rank == 2) {
		return "two";
	}
	else if (rank == 3) {
		return "three";
	}
	else if (rank == 4) {
		return "four";
	}
	else if (rank == 5) {
		return "five";
	}
	else if (rank == 6) {
		return "six";
	}
	else if (rank == 7) {
		return "seven";
	}
	else if (rank == 8) {
		return "eight";
	}
	else if (rank == 9) {
		return "nine";
	}
	else if (rank == 10) {
		return "ten";
	}
	else if (rank == 11) {
		return "jack";
	}
	else if (rank == 12) {
		return "queen";
	}
	else if (rank == 13) {
		return "king";
	}
	else if (rank == 14) {
		return "ace";
	}
	else {
		return "can't read this card";
	}
}

int print_all(const vector<card> & deck) {
	if (deck.size() == 0) {
		cout << "no card inside in the deck" << endl;
		return fail;
	}
	for (size_t i = 0; i < deck.size(); ++i) {
		card x = deck[i];
		string info1 = string_of_card_rank(x.rank);
		string info2 = string_of_card_suit(x.suits);
		cout << "the infomation of a new card is : " << info1 << " && " << info2 << endl;
	}
	return 0;
}




int parse_card(vector<card> &deck, char * filename) {
	ifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open())
	{
		cout << "the file: " << filename << " can't be opened or can't be found for reading" << endl;
		return wrong_name;
	}
	int i = 0;
	while (!ifs.eof())
	{
		i++;
		//printf("%d\n",i);
		string line;
		ifs >> line;
		if (line == "" || line == " ") {
			break;
		}

		int value;
		char suit;
		if (line.length() == 3) {
			int v1 = line[0] - '0';
			int v2 = line[1] - '0';
			value = v1 * 10 + v2;
			if (value == 10) {
				suit = line[2];
			}
			else {
				suit = 'i';
			}
		}
		else if (line.length() == 2) {
			if (line[0] == '2') {
				value = 2;
				suit = line[1];
			}
			else if (line[0] == '3') {
				value = 3;
				suit = line[1];
			}
			else if (line[0] == '4') {
				value = 4;
				suit = line[1];
			}
			else if (line[0] == '5') {
				value = 5;
				suit = line[1];
			}
			else if (line[0] == '6') {
				value = 6;
				suit = line[1];
			}
			else if (line[0] == '7') {
				value = 7;
				suit = line[1];
			}
			else if (line[0] == '8') {
				value = 8;
				suit = line[1];
			}
			else if (line[0] == '9') {
				value = 9;
				suit = line[1];
			}
			else if (line[0] == 'j' || line[0] == 'J') {
				value = 11;
				suit = line[1];
			}
			else if (line[0] == 'q' || line[0] == 'Q') {
				value = 12;
				suit = line[1];
			}
			else if (line[0] == 'k' || line[0] == 'K') {
				value = 13;
				suit = line[1];
			}
			else if (line[0] == 'a' || line[0] == 'A') {
				value = 14;
				suit = line[1];
			}
		}
		card c = { change_to_suit(suit), change_to_rank(value) };
		if (c.rank != -1 && c.suits != -1) {
			deck.push_back(c);
		}

	}
	if (deck.size() == 0) {
		cout << "There isn't any valid or useful cards in this file" << endl;
		return null_file;
	}
	return 0;

}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		usage();
		cout << "please enter two command line arguments for " << argv[0] << endl;
		return invalid_command_line;
	}
	else {
		vector <card> all;
		if (parse_card(all, argv[1]) == 0) {
			print_all(all);
		}
		else {
			usage();
			return fail;
		}
	}
	return 0;
}