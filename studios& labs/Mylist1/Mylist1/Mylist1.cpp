// Mylist1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyList.h"
#include "MySortList.h"
#include<memory>
#include <array>
#include<numeric>
#include<vector>
using namespace std;

int main()
{
	/*
	shared_ptr<MyList<int>> sp= make_shared<MySortList<int>>();
	array <int,5 > aisa = {0,1,2,3,4};
	cout << "1" << endl;
	*/
	MyList<int> l;
	MySortList<int> sl;
	l.insert(5).insert(10).insert(1);
	l.print(cout);
	sl.insert(5).insert(10).insert(1);
	sl.print(cout);
	//MySortList<int> ssl(l);
	MyList<int> copyl(sl);
	
	copyl.insert(7);
	copyl.print(cout);
	
	

	
	//sp->insert(10);
	//sp->insert(5);
	//sp->insert(7);
	//sl.print(cout);
	//sl.print(cout);
	
	//sp->print(cout);
	//sl.print(cout);
	

    return 0;
}

