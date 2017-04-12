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
	SheetView sheet;
	sheet.initHeader();
	sheet.suspend();
	sheet.exitSheet();
	return 0;
}
