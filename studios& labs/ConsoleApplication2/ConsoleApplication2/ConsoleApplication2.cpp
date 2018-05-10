// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>;
using namespace std;
#include <string>;
#include <sstream>;
#include <fstream>;


int main (int argc, char * argv[])
{	
	std::vector<string> v;
	/*
	if (argc != 3) 
	{	
		cout << "please enter two command line arguments for " << argv[0] << endl;
		return 1;

	}
	else 
	{	
		ifstream ifs;
		ifs.open(argv[1]);
		ofstream ofs(argv[2]);
		if (!ifs.is_open())
		{
			cout << "the file: " << argv[1] << " can't be opened for reading" << endl;
			return 2;
		}
		if (!ofs.is_open()) 
		{
			cout << "the file: " << argv[2] << " can't be opened for writing" << endl;
			return 3;
		}
		while (!ifs.eof()) 
		{
			string line;
			ifs >> line;
			line = line +"\n";
			ofs << line;


		}
		return 0;
	}
	*/
	printf("\ncmdline args count=%d", argc);

	printf("\nexe name=%s\n", argv[0]);
	string s1;
	for (int i = 1; i< argc; i++) {
		//printf("\nGroup student name is %s", argv[i]);
		//v.push_back(argv[i]);
		s1 += argv[i];
		s1 = s1 + " ";
	}
	istringstream iss(s1);
	for (int i = 0; i < argc; ++i) 
	{
		string s1;
		iss >> s1;
		cout << s1 << endl;
		//cout << "nice" << endl;
	}

	for (int t = 0; t < v.size(); ++t) 
	{
		//cout << "v[" << t << "] is " << v[t] << endl;
	}

	printf("\n");
	//cout << v[0] << endl;
	int a = 0;
	int array[2][3][5] = { 
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
		}, 
	};
	for (size_t i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
		for (size_t j = 0; j < sizeof(array[0]) / sizeof(array[0][0]);j++) {
			for (size_t k = 0; k < sizeof(array[0][0]) / sizeof(array[0][0][0]); k++) {
				array[i][j][k] = i*j*k;
				//cout << "array["<<i<<"]["<<j<<"]["<<k<<"] is"<<array[i][j][k] << endl;
			}
		}
	}
	return 0;
}

