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
	cout << "test" << endl;

	Cell cell;
	cell.setFloatValue(91.399);
	cout << cell.readFloatValue() << endl;

	CellValue<string> test("test");

	cout << test.returnFloatValue() << endl;
	return 0;
}
