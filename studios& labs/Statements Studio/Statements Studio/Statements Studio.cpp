// Statements Studio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>;
#include <string>;
#include <set>;
using namespace std;
#include <iostream>;
#include <algorithm>;
#include <iterator>;

void function() {
	int i = 16;
	
	throw i;
}
void swap_integers(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}
int main(int argc, char * argv[])
{	
	set<string> s;
	s.insert(string("sample"));
	s.insert(string("midterm"));
	s.insert(string("question"));
	copy(s.begin(), s.end(), ostream_iterator<string>(cout," "));
	cout << endl;
	int i = 0;
	int k = 10;
	swap_integers(i, k);
	cout << i << endl;
	cout << k << endl;
	
	try {
		while (i < 5) {
				function();
				i++;

				cout << "test" << endl;
			}
	}
		catch (int t) {
			cout << "caught : " << t << endl;
			


		}
	
    return 1;
}

