#pragma once
#ifndef card1
#define card1
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


enum success_fail { success = 0, fail = -1, wrong_name = -2, null_file = 2, invalid_command_line = 1, big_problem = -5, invalid_vector = -2};
enum suit { c=1,d =2, h =3, s =4,  nan2 =-1 };
enum card_rank { nan1 = -1,two =2, three =3, four =4, five =5, six =6, seven =7, eight=8, nine=9, ten = 10, jack = 11, queen =12, king = 13, ace =14 };
enum hand_rank { No_Rank = 0, OnePair = 1, TwoPairs = 2, ThreeOfAKind = 3, Straight = 4, Flush = 5, FullHouse = 6, FourOfAKind = 7, StraightFlush = 8 };

struct card
{
	card();
	card::card(suit suit_name, card_rank rank_name);
	suit suits;
	card_rank rank;
	bool card::operator<(const card &another_card);//compare this with another
	
};
struct hand 
{
	card a_;
	card b_;
	card c_;
	card d_;
	card e_;
	hand::hand();
	hand::hand(card a, card b, card c, card d, card e);
	bool hand::operator<(const hand &another_hand);
};




int parse_card(vector<card> & deck , char *filename);
suit change_to_suit(char suit);
card_rank change_to_rank(int value);
int usage(); 
int check_rank(const vector<card> & deck);
int check_rank_new(const vector<card> & deck);
int print_all_cards(const vector<card> & deck);
int sorted_all_divide_5(const vector<card> & deck);
int print_all_sorted_cards(const vector<card> & deck);
int sorted_hand_and_print_it(const vector<hand> & test);

int sorted_all_divide_5_extension(const vector<card> & deck, vector<hand> test);

//lab1 condition test
bool IsStraightFlush(const vector<card> & case1);
bool  IsFourOfAKind(const vector<card> & case1);
bool  IsFullHouse(const vector<card> & case1);
bool  IsFlush(const vector<card> & case1);
bool  IsStraight(const vector<card> & case1);
bool  IsThreeOfAKind(const vector<card> & case1);
bool  IsTwoPairs(const vector<card> & case1);
bool  IsOnePair(const vector<card> & case1);
#endif