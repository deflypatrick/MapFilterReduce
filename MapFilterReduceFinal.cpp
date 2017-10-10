// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> * map(int(*fxn) (int), vector<int>  * vec);
vector<int> * filter(bool(*fxn) (int), vector<int> * vec);
int reduce(int(*fxn) (int, int), vector<int> * vec);
int Printer(vector <int> *vec);

int square(int);        //For use with map
bool isEven(int);      // For use with filter
int product(int, int);  // For use with reduce


int main()
{
	vector <int> *point;
	//	int x[5];
	//	int num = sizeof(x) / sizeof(x[0]);
	//	for (int i = 0; i < num; i++) // input numbers into array
	//	{
	//		cin >> x[i];

	//	}

	//	vector <int> myVec(x, x + sizeof(x) / sizeof(x[0]));
	vector <int>  myVec;
	int dataIP;
	for (int i = 0; i < 5; i++) {
		cin >> dataIP;
		myVec.push_back(dataIP);
	}



	point = map(square, &myVec);
	Printer(point);

	//	vector <int> myVec2(x, x + sizeof(x) / sizeof(x[0]));
	point = filter(isEven, &myVec);
	Printer(point);

	//	vector <int> myVec3(x, x + sizeof(x) / sizeof(x[0]));
	int num4;
	num4 = reduce(product, &myVec);
	cout << "[ " << num4 << " ]" << endl;

}

int square(int x) {
	// For use with map
	return x * x;

}

bool isEven(int x) {
	// For use with filter

	if (x % 2 == 0) {
		return true;
	}
	else {
		return false;
	}

}

int product(int x, int y)
{
	// For use with reduce
	return x * y;
}


vector<int> * map(int(*fxn) (int), vector<int>  * vec)
{
	vector <int> * data = new vector <int>(0);
	int numVec = vec->size();
	for (int a = 0; a < numVec; a++)
	{
		int XY = fxn(vec->at(a));
		data->push_back(XY);

	}
	return data;
}

vector<int> * filter(bool(*fxn) (int), vector<int> * vec) {

	vector <int> * data = new vector <int>(0);
	int numVec = vec->size();
	for (int i = 0; i < numVec; i++)
	{
		int ret = fxn(vec->at(i));
		if (ret == true) {
			data->push_back(vec->at(i));
		}

	}
	return data;
	/*	if (XY == true) {
	XY = (XY*(vec->at(a)));
	}
	else {
	data->push_back(XY);
	return data;
	}
	data->push_back(XY);
	*/
}

int reduce(int(*fxn) (int, int), vector<int> * vec)
{
	int x;
	x = vec->at(0);
	int num = vec->size();
	for (int i = 1; i < num; i++) {
		x = fxn(x, vec->at(i));
	}

	return x;


	/*	if (vec->size() == 0)
	{
	return 0;
	}

	int x = vec->at(0);

	for (int i = 0; i < x; i++)
	{
	if (i != (vec->size()-1)) {
	x += fxn(x, (vec->at(i)));
	}
	else if (i == vec->size()) {
	return x;
	}
	else {
	cout << "";
	}



	}
	*/
}

int Printer(vector <int> * vec)
{
	int lastInd = vec->size() - 1;
	cout << "{ ";
	for (int i = 0; i < vec->size(); i++) {
		if (i == lastInd) {
			cout << vec->at(i);
		}
		else {
			cout << vec->at(i) << " , ";
		}

	}
	cout << " }" << endl;
	return 0;
}










