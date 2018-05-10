#include "stdafx.h"
#include <iostream>
#include "Wrapper.h"
#include <vector>

int main(int argc, char * argv[])
{
	using namespace std;
	cout << "Problems 1-4" << endl;
	int i;
	int j;
	i = 2;
	j = 3;
	int && rvrk = i + j;
	int && rvrl = i * j;

	cout << "i: " << i << endl;
	cout << "j: " << j << endl;
	cout << "rvrk: " << rvrk << endl;
	cout << "rvrl: " << rvrl << endl;

	i = i;
	cout << "i = i --> " << i << endl;
	i = j;
	cout << "i = j --> " << i << endl;
	i = rvrk;
	cout << "i = rvrk --> " << i << endl;
	i = rvrl;
	cout << "i = rvrl --> " << i << endl;

	i = 2;
	j = 3;
	rvrk = i + j;
	rvrl = i * j;

	j = i;
	cout << "j = i --> " << j << endl;
	j = j;
	cout << "j = j --> " << j << endl;
	j = rvrk;
	cout << "j = rvrk --> " << j << endl;
	j = rvrl;
	cout << "j = rvrl --> " << j << endl;

	i = 2;
	j = 3;
	rvrk = i + j;
	rvrl = i * j;

	rvrk = i;
	cout << "rvrk = i --> " << rvrk << endl;
	rvrk = j;
	cout << "rvrk = j --> " << rvrk << endl;
	rvrk = rvrk;
	cout << "rvrk = rvrk --> " << rvrk << endl;
	rvrk = rvrl;
	cout << "rvrk = rvrl --> " << rvrk << endl;

	i = 2;
	j = 3;
	rvrk = i + j;
	rvrl = i * j;

	rvrl = i;
	cout << "rvrl = i --> " << rvrl << endl;
	rvrl = j;
	cout << "rvrl = j --> " << rvrl << endl;
	rvrl = rvrk;
	cout << "rvrl = rvrk --> " << rvrl << endl;
	rvrl = rvrl;
	cout << "rvrl = rvrl --> " << rvrl << endl;

	int && m = move(i);
	cout << "int && m = move(i) --> " << m << endl;
	int n = m;
	i = m;

	cout << endl << endl << endl;

	cout << "Problem 4" << endl;
	cout << "Default Construction" << endl;
	Wrapper defaultW;
	cout << "Copy Construction" << endl;
	Wrapper copiedW(defaultW);
	cout << "Assignment Construction" << endl;
	Wrapper assignedW = defaultW;

	cout << endl << endl << endl;

	cout << "Problem 5" << endl;
	Wrapper x;
	Wrapper y;
	Wrapper z = move(x);

	cout << endl << endl << endl;

	cout << "Problem 6" << endl;
	vector<Wrapper> k;
	Wrapper q;
	k.push_back(move(q));
	Wrapper &&r = move(q);
	cout << "shows" << endl;
	Wrapper s (move(r));

	return 0;
}
