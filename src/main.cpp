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


int main(void) {
	Sheet sheet;
	SheetView sheetview;
	sheetview.initHeader();
	sheetview.drawSheet(sheet);
	sheetview.suspend();
	sheetview.exitSheet();
	return 0;
}
