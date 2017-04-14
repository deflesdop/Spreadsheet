#include "../include/sheetview.h"
#include <curses.h>
#include <string>
#include "../include/celladdress.h"
#include "../include/editwindow.h"
#include "../include/editcontroller.h"

EditWindow::EditWindow(CellAddress loc){
	noecho();
	curs_set(1);
	cursor = loc;
	popup = newwin(height, width, 27, 9);
	keypad(popup, TRUE);
}

void EditWindow::drawWindow(const char* str){
	//wborder(popup, 0, 0, 0, 0, 0, 0, 0, 0);
	mvwaddstr(popup, 1, 1, str);
	wrefresh(popup);
	
}

void EditWindow::openEditor(Sheet &sheet){
	EditController econ;
	econ.editCell(popup, sheet, cursor);
	wclear(popup);
	wrefresh(popup);
	deleteWindow();
}

void EditWindow::deleteWindow(){
	delwin(popup);

}
