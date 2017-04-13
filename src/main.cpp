//============================================================================
// Name        : Andrew Huang, Micha de Jong
// Description : Spreadsheet
//============================================================================

#include "../include/sheet.h"
#include "../include/sheetcontroller.h"
#include "../include/sheetview.h"
#include <iostream>
#include <string>
#include <curses.h>


int main(void) {
	Sheet sheet;
	sheet.getCell(4,4).setString("TEST");
	SheetController control;
	control.run(sheet);


	return 0;
}
