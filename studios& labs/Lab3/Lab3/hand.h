
#pragma once
#ifndef hand10
#define hand10
#include "card1.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "deck.h"
class hand
{
	friend ostream & operator<< (ostream &o, const hand &h);
	friend void operator<<(hand &h, Deck &d);
public:
	vector<card> hand_;

public:
	hand();// default constructor 
	~hand();
	hand(const hand &another); // copy constructor
	hand operator= (const hand &another);
	const bool operator== (const hand &another);
	const int size() const;
	const bool operator< (const hand &another);
	const string asString();
	//const bool operator<(const hand &another_hand); // this is for lab 1 extra credit 
	static bool poker_rank(const hand & hand1, const hand & hand2);
	static void check_rank_new_with_hand(hand & hand1);
	//bool hand::operator<(const hand &another_hand);
	//int hand::sorted_hand_and_print_it(const vector<hand> & test);
	//int hand::sorted_all_divide_5_extension(const vector<card> & deck, vector<hand> test);
	static card_rank GetThePair(const hand &h);
	static vector<int> GetTwoPair(const hand &h);
	// lab3
	card operator[](size_t index);
	void remove_card(size_t index);

};
#endif
