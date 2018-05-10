// DataStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	int arr[5] = { 2, 4, 3, 1, 5 };
	int *p1 = arr + 2;
	cout << p1;

	string t = "wushuo";
	int a = 5;
	printf("%s\n", argv[0]);
	printf("%s\n", t.c_str());
	printf("%d\n", a);
	printf("%s\n", argv[1]);
	//printf("%s\n", t.c_str());
	//int pause;
	//pause = 0;
	//cin >> pause;
	//cout << pause;
	//cin >> pause;
	decltype (&argv[0][0]) point = &argv[0][0];
	
	for (*point; *point != '\0'; *point++) 
	{
		cout << *point << endl;
	}
	//char j = '1';
	//char * pt = &j;
	//const char *p = &argv[0][0];
	
	//char & point1 = argv[0][0];
	//for (&point; &point1!='\0'; point1++)
	//{
	//	cout << &point1 << endl;
	//}
	return 0;


}

