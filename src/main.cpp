//============================================================================
// Name        : Andrew Huang, Micha de Jong
// Description : Spreadsheet
//============================================================================
#include "../include/cell.h"
//#include "../include/column.h"
#include <iostream>
#include <string>
using namespace std;


int main(void) {

	Cell cell;
	cell.setFloatValue(91.399);
	cout << cell.readFloatValue() << endl;
	
	Cell cell2;
	cell2.setStringValue("Hello");
	cout << cell2.readStrValueDraw() << endl;
	
	return 0;
}
