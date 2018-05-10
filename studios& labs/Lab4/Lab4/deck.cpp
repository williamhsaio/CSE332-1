#include "stdafx.h"
#include "deck.h"
#include "hand.h"
#include <random>
#include <ctime>
using namespace std;

Deck::Deck(string file_name)
{
	deck = vector<card>();
	load(file_name);
}
Deck::Deck() {

}// lab3 4.1
void Deck::add_card(card & card2) {
	deck.push_back(card2);
	
}
Deck::~Deck()
{
	this->deck.~vector();
}

// load function
void Deck::load(string  fileName)
{
	vector<card> to_use;
	//char * path = const_cast<char*>(fileName.c_str());
	//change the parse_card second variable into const
	const char* path = fileName.c_str();

	card::parse_card(to_use, path);// call the lab1 function to build a to_use vector 

	int number = to_use.size();
	for (int i = 0; i < number; ++i) {
		deck.push_back(to_use[i]);
	}
}

void Deck::shuffle() {
	// shuffle the deck
	//default_random_engine e;
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(), g);
}
//A const "size" method that returns the number of elements in the container member variable.
int Deck::size() const
{
	return deck.size();
}
//A non-member insertion operator (operator<<) that takes a reference to an ostream 
//and a reference to a const deck object, and uses the passed ostream to print out valid card definition strings on 
//separate lines, for each card in the deck object's container member variable. Note that your implementation may use a friend
// declaration to grant this operator access to the deck object's private container member variable.
ostream & operator <<(ostream & o, const Deck & d) {

	int cardCount = d.deck.size();
	vector<card> temp = d.deck;
	card temp1;
	for (int i = 0; i < cardCount; ++i) {
		temp1 = temp[i];
		o << card::string_of_card_rank(temp1.rank) << card::string_of_card_suit(temp1.suits) << " | ";
		if (i % 5 == 4) {
			o << "\n";
		}
	}
	return o;
}

void Deck::print_last(Deck & d) {
	int cardCount = d.deck.size();
	vector<card> temp = d.deck;
	card temp1 = temp[cardCount-1];
	cout << card::string_of_card_rank(temp1.rank) << card::string_of_card_suit(temp1.suits) << endl;
}
card Deck::popBack() {
	if (this->size() <1) {
		throw(card1::success_fail::empty_deck);
	}

	vector <card> a = deck;
	card out = a.back();
	deck.pop_back();
	return out;
}

void operator<< (Deck &d1, Deck &d2) {
	d1.deck.push_back(d2.deck.back());
	d2.deck.pop_back();
}
void operator<< (Deck &d1, hand &h1) {
	d1.deck.push_back(h1.hand_.back());
	h1.hand_.pop_back();
}

void operator<< (card &c1,Deck &d1) {
	c1 = d1.deck.back();
	d1.deck.pop_back();

}

