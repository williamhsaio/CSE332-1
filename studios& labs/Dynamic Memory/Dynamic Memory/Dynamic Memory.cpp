// Dynamic Memory.cpp : Defines the entry point for the console application.
//


//global is b

#include "stdafx.h"
#include "detector.h"


#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <vector>


using namespace std;
void find(shared_ptr<detector> k){
	cout << "find" << endl;
	cout << k << endl;
}

int main(int argc, char * argv[])
{

	cout << "1"<<endl;

	
	shared_ptr<detector> k1 = make_shared<detector>();
	shared_ptr<detector> k2 = make_shared<detector>();
	shared_ptr<detector> k3 = make_shared<detector>();
	vector<shared_ptr<detector>> pt;
	pt.push_back(k1);
	pt.push_back(k2);
	pt.push_back(k3);
	cout << "3" << endl;
	std::cout << "Original memory addresses: " << &*k1 << ", " << &*k2;
	std::cout << ", " << &*k3 << std::endl;
	std::cout << "Vector memory addresses: " << &*pt[0] << ", " << &*pt[1];
	std::cout << ", " << &*pt[2] << std::endl;
    return 0;
	cout <<"3"<< endl;
}

