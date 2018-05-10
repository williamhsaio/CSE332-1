// Sequence Containers studio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <deque>
#include<list>
#include<forward_list>
#include<iostream>
using namespace std;

void Qfour(const vector<int> &vi) {
	vector<int>::const_iterator vii;
	cout << "question-4 new vector int- push back" << endl;
	for (vii = vi.begin(); vii != vi.end(); vii++) {
		cout << *vii << endl;

	}
	cout << "\n" << endl;
}

int main(int argc, char* argv[])
{
	char cString[13] = "midterm exam";
	char & cP = cString[3];
	//cout << cP << endl; // 1
	cout << &cP << endl; // 2
	cout << cP + 5 << endl; // 3
	char s = 't';
	cout << s << endl;
	vector<int> vi;
	deque<int> qi;
	list<int> li;
	forward_list<int> fi;
	
	vector<int>::iterator vii;
	deque<int>::iterator qii;
	list<int>::iterator lii;
	forward_list<int>::iterator fii;
	//question four
	

	int i = 0;
	for (i = 0; i < 3; i++) {
		vi.push_back(i);
		qi.push_back(i);
		li.push_back(i);
		fi.push_front(2 - i);
	}

	cout << "vector int- push back" << endl;
	for (vii = vi.begin(); vii < vi.end(); vii++) {
		cout << *vii << endl;

	}
	cout << "\n" << endl;
	unsigned int t=0;
	cout << "vector int- push back-question 5" << endl;
	for (t = 0; t < vi.size(); t++) {
		cout << vi[t] << endl;

	}
	cout << "\n" << endl;

	cout << "deque int- push back" << endl;
	for (qii = qi.begin(); qii < qi.end(); qii++) {
		cout << *qii << endl;
		


	}
	cout << "\n" << endl;

	cout << "forward-list int- push back" << endl;
	for (fii = fi.begin(); fii != fi.end(); fii++) {
		cout << *fii << endl;

	}
	cout << "\n" << endl;

	cout << "list int- push back" << endl;
	for (lii = li.begin(); lii != li.end(); lii++) {
		cout << *lii << endl;
		
		


	}
	cout << "\n" << endl;
	cout << "new" << endl;
	//Qfour(vi);
	//return 0;

	vector<int> vi6(vi);
	

	deque<int> qi6(qi);
	

	list<int> li6(li);
	forward_list<int> fi6(fi);
	

	cout << "\n question SIX" << endl;
	cout << "vector int- push back" << endl;
	for (vii = vi6.begin(); vii < vi6.end(); vii++) {
		cout << *vii << endl;

	}
	cout << "\n" << endl;


	cout << "deque int- push back" << endl;
	for (qii = qi6.begin(); qii < qi6.end(); qii++) {
		cout << *qii << endl;



	}
	cout << "\n" << endl;

	cout << "forward-list int- push back" << endl;
	for (fii = fi6.begin(); fii != fi6.end(); fii++) {
		cout << *fii << endl;

	}
	cout << "\n" << endl;

	cout << "list int- push back" << endl;
	for (lii = li6.begin(); lii != li6.end(); lii++) {
		cout << *lii << endl;




	}
	cout << "\n" << endl;

	/*
	vi.push_back(6);
	qi.push_back(6);
	li.push_back(6);
	vi.push_back(5);
	qi.push_back(5);
	li.push_back(5);
	//fi.push_back(6); Can only grow at front of forward_list
	//vi.push_front(1); Can only grow at back of vector(reallocates as needed)
	qi.push_front(1);
	li.push_front(1);
	fi.push_front(1);
	qi.push_front(2);
	li.push_front(2);
	fi.push_front(2);
	vi.pop_back();
	qi.pop_back();
	li.pop_back();
	//fi.pop_back;

	//vi.pop_front();
	qi.pop_front();
	li.pop_front();
	fi.pop_front();
	*/
}

