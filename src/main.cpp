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
	sheet.getCell(1,1).setString("TEST");
	SheetView sheetview;
	sheetview.initHeader();
	sheetview.drawSheet(sheet);
	sheetview.drawCursor(sheet, 1,1);
	sheetview.setCursor(1,1);
	sheetview.drawPopup(sheet);
	sheetview.suspend();
	sheetview.exitSheet();
	return 0;
}
