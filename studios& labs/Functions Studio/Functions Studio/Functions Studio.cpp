// Functions Studio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Functions Studio.h"
using namespace std;
#include <iostream>
void question6(unsigned int a = 3, unsigned int b = 4);
//void question6(unsigned int a , unsigned int b =2);

void question6(unsigned int a, unsigned int b) {
	if (a == 0) {
		cout << "answer is : " << a << " \n" << endl;
		return;
	}
	if (b == 0) {
		cout << "answer is : " << b << " \n" << endl;
	}
	unsigned int answer = 1;
	for (size_t i = 1; i <= a; i++) {
		answer = answer *b;
	}
	cout << "answer is : " << answer << " \n" << endl;
	return;
}
int main()
{
	const int i = 10;
	int & j = i;
	j = 100;
	cout << j << endl;
	cout << i << endl;

	unsigned int x = 4;
	//foo(x);
	// foo(5);
	//foo(0);
	//foo(-1);
	foo(2);
	unsigned int k = 1;
	foo_rerecursive_pointer(x, &k);
	question6(2, 3);
	//unsigned int t;
	unsigned int b = 5;
	question6( b );
	question6();
    return 0;
}

unsigned int foo(unsigned int a) {
	if (a == 0 || a < 0) {
		cout << "answer is : "<<1 << " \n" << endl;
		return 0;
	}
	unsigned int answer = 1;
	for (size_t i = 1; i <= a; i++) {
		answer = answer *i;
	}
	cout << "answer is :" << answer << "\n" << endl;

	return answer;

}

void foo_rerecursive(unsigned int a, unsigned int & answer) {
	
	if (a == 0) {
		cout << "answer is : " << answer << " \n" << endl;
		return;
	}
	
	cout << "inter answer is : " << answer << endl;

	answer = answer *a;
	return foo_rerecursive(a-1, answer);

}
void foo_rerecursive_pointer(unsigned int a, unsigned int * answer) {

	if (a == 0) {
		cout << "answer is : " << *answer << " \n" << endl;
		return;
	}

	cout << "inter answer is : " << *answer << endl;
	*answer = (*answer) *a;
	return foo_rerecursive_pointer(a - 1, answer);
}


