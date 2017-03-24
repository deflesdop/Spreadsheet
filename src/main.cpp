//============================================================================
// Name        : SpreadSheet.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================
#include "../include/cell.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {

	Cell<float> test;

	test.setValue(9.2);
	cout << test.readFValue() << endl;
	test.emptyCell();

	test.setValue(2.5);
	cout << test.readFValue() << endl;

	return 0;
}
