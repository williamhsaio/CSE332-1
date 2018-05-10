// Lab2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "card1.h"
#include "deck.h"
#include "hand.h"


using namespace std;

int check_command(int argc, char *argv[],int &location, bool &shuffle1) {
	if (argc > 3) {
		// too many command inout 
		cout << "please input the command as following style: -> Lab2.exe <filename> -shuffle (optional)" << endl;
		
		throw card1::command_line::too_much;
	}
	if (argc <= 1) {
		// so few input command
		
		throw card1::command_line::too_few;
	}
	if (argc == 2) {
		string a = argv[1];
		if (a == "-shuffle") {
			// plase inut a file to load
			cout << "please input the command as following style: -> Lab2.exe <filename> -shuffle (optional)" << endl;
		
			throw card1::command_line::no_input_file;
		}
		location = 1;
	}
	if (argc == 3) {
		string b = argv[1];
		string c = argv[2];

		if (b == "-shuffle") {
			location = 2;
			shuffle1 = true;
			return card1::command_line::all_right;
		}
		if (c == "-shuffle") {
			location = 1;
			shuffle1 = true;
			return card1::command_line::all_right;
		}
		// either case no -shuffle, tell the user
		cout << "please input the command as following style: -> Lab2.exe <filename> -shuffle (optional)" << endl;
		
		throw card1::command_line::wrong_input_three;

	}
	// return 0
	return card1::command_line::all_right;
}

void usage1(int argc, char *argv[]) {
	
	cout << "Please do as fllowing to use Lab2.exe:  ";
	cout << "with 1-2 arguments as " << argv[0];
	cout << "  <card input file>  [-shuffle]" << endl;
	cout << "YOU wrong input was : ";
	for (int i = 0; i < argc; ++i) {
		cout << argv[i] << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[])
{	
	int location;
	bool shuffle1 = false;
	try {
		check_command(argc, argv, location, shuffle1);
		
	}
	catch (command_line &e) {
		usage1(argc, argv); // print out the usage function
		return e;
	}
	try {
		Deck k(argv[location]);
		cout <<"the deck's size is : "<< k.size() << endl;
		if (shuffle1 == true) {
			k.shuffle();
			cout << "deck do shuffle" << endl;
		}
		vector<hand> hands_vector;
		for (size_t i = 0; i < 9;i++) {
			hands_vector.push_back(hand());
		}
		if (k.size() < 45) {
			cout << "the deck doesn't have enough cards, so please check your input document" << endl;
			throw card1::success_fail::short_cards;
		}

		cout << k << endl;
		for (size_t i = 0; i < 5;++i) {
			for (size_t j = 0; j < 9; ++j) {
				hands_vector[j] << k;

			}
		}
		cout << "print out the dealt deck" << endl;
		cout << k << endl;

		// hand in vector hands_vector already sorted
		cout << "print out UNSORTED hand in the hands_vector " << endl;
		for (int i = 0; i < 9; i++) {
			cout << "Hand " << i << " : " << hands_vector[i] << endl;
		}
		//cout << hands_vector.size() << endl;

		cout << "print out SORTED by STL sort algorithm hand in the hands_vector " << endl;
		sort(hands_vector.begin(),hands_vector.end());
		for (int i = 0; i < 9; i++) {
			cout << "Hand " << i << " : " << hands_vector[i] << endl;
		}

		cout << "print out SORTED by algorithm poker_rank hand in the hands_vector " << endl;

		sort(hands_vector.begin(), hands_vector.end(), hand::poker_rank);
		
		for (int i = 0; i < 9; i++) {
			hand::check_rank_new_with_hand(hands_vector[i]);
			cout << "Hand " << i << " : " << hands_vector[i] << endl;
		}
		
	}
	catch (success_fail &e) {
		return e;
	}


    return 0;
}

