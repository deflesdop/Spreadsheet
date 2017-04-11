//============================================================================
// Name        : Andrew Huang, Micha de Jong
// Description : Spreadsheet
//============================================================================
#include "../include/cell.h"
#include "../include/column.h"
#include "../include/sheet.h"
#include "../include/sheetview.h"
#include <iostream>
#include <string>
#include <curses.h>

using namespace std;

static const int lines(24);
static const int cols(80);

void cellTest(){
	cout << "test" << endl;

		Cell cell;
		cell.setFloat(91.399);
		cout << cell.getFloat() << endl;

		CellValue<string> test("test");
		cout << test.getString() << endl;
		cout << test.getFloat() << endl;

		Column col;
		col.getCell(2).setString("This is a cell from column");
		cout << col.getCell(2).getString() << endl;

		Sheet sheet;
		sheet.getCell(2,2).setString("This is 2,2 from the sheet");
		cout << sheet.getCell(2,2).getString() << endl;

		int n = 0;
		for (Column::iterator it = col.begin(); it != col.end(); ++it){
			it->setString("0");
			cout << it->getString() << endl;
			n++;
		}
		cout << n <<  endl;
		int c = 0;

		for(Sheet::iterator it = sheet.begin(); it != sheet.end(); ++it){
			it->getCell(2).setString("0");
			c++;
			cout << it->getCell(2).getString()<< " ";
		}

		cout << '\n' << c << endl;

}

void testAddress(){
	Sheet sheet;
	sheet.getCell(0,0).setFloat(0.5f);
	string ref = "A6";
	CellAddress celladdress;
	celladdress.createFromReference(ref);
	cout << celladdress.getColNum() << endl;
	cout << celladdress.getRowNum() << endl;
}


int main(void) {
	SheetView sheet;
	sheet.initHeader();

  sheet.exitSheet();
	return 0;
}
