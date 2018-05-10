// Algorithms Studio I.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char * argv[]) {
	//if (argc != 1) { return 1; }

	//question 2
	int arr[] = { -2, 19, 80, -47, 80, 80, -2 };
	int *pointer_end = arr+size(arr);
	int *pointer_start = arr;
	ostream_iterator<int> ob(cout,"\t");
	copy(pointer_start, pointer_end, ob);
	cout << endl;
	//question 3
	vector<int> v;
	back_insert_iterator< vector<int> > v_iy(v);
	copy(pointer_start, pointer_end, v_iy);
	copy(v.begin(),v.end(),ob);
	//question 4
	cout << endl;
	sort(pointer_start,pointer_end);
	sort(v.begin(),v.end());
	copy(pointer_start, pointer_end, ob);
	cout << endl;	
	copy(v.begin(), v.end(), ob);
	// question 5
	auto t1 = adjacent_find(pointer_start, pointer_end);
	auto t2 = adjacent_find(v.begin(), v.end());
	cout  << endl;
	int temp=0;
	int temp2 = 0;
	int * test = t1;
	

	while ( test != pointer_end)
	{

		if (temp != *test) {
			cout << endl;

		}
		temp = *test;
		
		while (*test == temp) {
			cout << temp<<" ";
			++test;
		}
		
		test = adjacent_find(test, pointer_end);
		
		
	}



	while (t2 != v.end())
	{
		if (temp2 != *t2) {
			cout << endl;
		}
		temp2 = *t2;
		
		
		while (t2 != v.end()) {
			if (*t2 == temp2) {
				cout << temp2;
				++t2;
				
			}
			else {
				break;
			}

		}
		t2 = adjacent_find(t2, v.end());
	}
	float mean; 
	float sum;
	cout << endl;
	sum = accumulate(pointer_start,pointer_end,0);
	mean = sum / size(arr);
	int * med;
	med = pointer_start + (pointer_end - pointer_start) / 2;
	cout << "Mean is " << mean << endl;
	cout << "med is " << *med << endl;
	int * mode(pointer_start);
	int number;
	int total;
	int start = 0;
	int answer;
	while (mode != pointer_end) {
		number = *mode;
		total = count(pointer_start,pointer_end,number);
		if (total > start) {
			start = total;
			answer = number;
		}
		++mode;
	}


	cout << "mode number is : " << number << endl;
	return 0;
	



	





}

