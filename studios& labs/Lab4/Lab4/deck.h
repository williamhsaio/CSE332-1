#pragma once
#ifndef deck1
#define deck1
#include <deque>

#include <string>
#include <iostream>
#include "card1.h"
//#include "hand.h"
class hand;
class Deck {
	friend ostream & operator<<(ostream & o, const Deck & d);
	friend void operator<< (Deck &d1, Deck &d2);
	friend void operator<< (Deck &d1, hand &h2);
	friend void operator<< (card &c1,Deck &d1);
private:
	vector<card> deck;
public:
	Deck();//4.1
	void add_card(card & card);// lab 3 
	void load(string file_name); //4.3
	Deck(string file_name); // 4.1
	~Deck(); //4.2
	static void print_last(Deck & d);
	void shuffle();//4.4
	int size() const;//4.5
	card popBack();
	



};
#endif /* DECK_H */