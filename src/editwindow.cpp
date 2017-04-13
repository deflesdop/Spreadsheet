#include "../include/sheetview.h"
#include <curses.h>
#include <string>
#include "../include/celladdress.h"
#include "../include/editwindow.h"
#include "../include/editcontroller.h"

EditWindow::EditWindow(CellAddress location){
	noecho();
	curs_set(1);
	cursor = location;
	popup = newwin(height, width, cursor.getRowNum()+1, cursor.getColNum()*8 + 8);
	keypad(popup, TRUE);
}

void EditWindow::drawWindow(const char* str){
	//wborder(popup, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(popup, 0, 0, 0, 0, 0, 0, 0, 0);
	mvwaddstr(popup, 1, 1, str);
	wrefresh(popup);
}

void EditWindow::openEditor(Sheet &sheet){
	EditController econ;
	econ.editCell(popup, sheet, cursor);
	deleteWindow();
}

void EditWindow::deleteWindow(){
	wrefresh(popup);
	delwin(popup);

}
