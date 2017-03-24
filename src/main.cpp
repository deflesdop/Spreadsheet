//============================================================================
// Name        : Andrew Huang, Micha de Jong
// Description : Spreadsheet
//============================================================================
#include "../include/cell.h"
#include "../include/column.h"
#include <iostream>
#include <string>
using namespace std;


int main(void) {

	Cell<float> cell;
	cell.setValue(91.399);
	cout << cell.readFloatValue() << endl;
	return 0;
}
