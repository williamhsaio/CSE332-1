// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "card1.h"

using namespace std;



int main(int argc, char *argv[])
{
	
	int a = 5;
	int b = 10;
	char c = 'c';
	char d = 'd';

	card a1 = { change_to_suit('s') ,change_to_rank(a) };
	card b1 = { change_to_suit('h') ,change_to_rank(5) };
	bool answer =  (a1 < b1);
	//cout << answer << endl;

	if (argc != 2)
	{
		usage();
		cout << "please enter two command line arguments for " << argv[0] << endl;
		return invalid_command_line;
	}
	vector<card> all;
	if (parse_card(all, argv[1]) == 0) {
		//print all valid cards
		print_all_cards(all);
		int a;
		a = a + 1;
		a;
		cout
		cout << "" << endl;
		cout << "The following are sorted poker hand" << endl;
		cout << "" << endl;
		
		cout << "" << endl;
		//I call the STL sort algorithm in the floowing function, print all sorted hands 
		sorted_all_divide_5(all);
		
		cout << "The following are all hands in sorted order : from worst to best" << endl;
		

		
		

		vector<hand> test;
		cout << "" << endl;
		
		sorted_all_divide_5_extension(all, test);
		
		cout << "" << endl;
		cout << "The following are all cards in sorted order" << endl;
		cout << "" << endl;
		
		// finally. print all cards by order
		print_all_sorted_cards(all);

	}
	else {
		return fail;
	}
		
	return 0;
}
