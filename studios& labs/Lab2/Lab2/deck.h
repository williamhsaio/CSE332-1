#pragma once
#include <deque>
#include <string>
#include <iostream>
#include "card1.h"
class Deck {
	friend ostream & operator<<(ostream & o, const Deck & d);
private:
	vector<card> deck;
public:
	void load(string file_name); //4.3
	Deck(string file_name); // 4.1
	~Deck(); //4.2
	
	void shuffle();//4.4
	int size() const;//4.5
	card popBack();
	
	

};

