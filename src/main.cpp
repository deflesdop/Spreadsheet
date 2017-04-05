//============================================================================
// Name        : Andrew Huang, Micha de Jong
// Description : Spreadsheet
//============================================================================
#include "../include/cell.h"
#include "../include/column.h"
#include "../include/sheet.h"
#include <iostream>
#include <string>
using namespace std;


int main(void) {
	cout << "test" << endl;

	Cell cell;
	cell.setFloatValue(91.399);
	cout << cell.readFloatValue() << endl;

	CellValue<string> test("test");
	cout << test.returnInfo() << endl;
	cout << test.returnFloatValue() << endl;

	Column col;
	col.getCell(2)->setStringValue("This is a cell from column");
	cout << col.getCell(2)->readStrValueDraw() << endl;

	Sheet sheet;
	sheet.getCell(2,2)->setStringValue("This is 2,2 from the sheet");
	cout << sheet.getCell(2,2)->readStrValueDraw() << endl;
	return 0;
}
