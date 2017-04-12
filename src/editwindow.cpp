#include "../include/sheetview.h"
#include <curses.h>
#include <string>
#include "../include/celladdress.h"
#include "../include/editwindow.h"

EditWindow::EditWindow(WINDOW* win, CellAddress location){
	noecho();
	cursor = location;
	popup = subwin(win, height, width, 2, 16);
	wrefresh(popup);
}

void EditWindow::drawWindow(){
	wborder(popup, '|', '|', '-', '-', '+', '+', '+', '+');
	mvwaddstr(popup, 1,1,"Sub");
	
	
}
void EditWindow::deleteWindow(){
	delwin(popup);
}
void EditWindow::readWindow(Sheet &sheet){

}
