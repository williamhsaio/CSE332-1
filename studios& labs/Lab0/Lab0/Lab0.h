#pragma once
#ifndef lab0
#define lab0
#include <vector>
#include <iostream>
using namespace std;

void usage(char * Lab0) 
{
	std::cout << "Lab0 head file" << std::endl;
}
enum success_fail { success = 0, fail = -1, wrong_name = -2, null_file = 2, invalid_command_line = 1 };
//enum suit { h=1,c =2, d =4, s =3,  nan2 =-1 };
enum suit { c = 1, d = 2, h = 3, s = 4, nan2 = -1 };
enum card_rank { nan1 = -1,two =2, three =3, four =4, five =5, six =6, seven =7, eight=8, nine=9, ten = 10, jack = 11, queen =12, king = 13, ace =14 };
struct card
{
	suit suits;
	card_rank rank;
};
int parse_card(vector<card> & deck , char *filename);
suit change_to_suit(char suit);
card_rank change_to_rank(int value);
int usage(); 

#endif