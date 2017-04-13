#include <curses.h>
#include <string>
#include "../include/sheet.h"
#include "../include/sheetview.h"
#include "../include/sheetcontroller.h"
#include "../include/editwindow.h"
#include "../include/editcontroller.h"

SheetController::SheetController(){
	row = 0, col = 0;
}

void SheetController::moveLeft(WINDOW* win){
	if(col > 0)
		--col;
	wmove(win, row+1, col*maxCellSize+8);
}

void SheetController::moveRight(WINDOW* win){
	if(col < maxCol)
		++col;
	wmove(win, row+1, col*maxCellSize+8);
}

void SheetController::moveUp(WINDOW* win){
	if(row > 0)
		--row;
	wmove(win, row+1, col*maxCellSize+8);
}

void SheetController::moveDown(WINDOW* win){
	if(row < maxRow)
		++row;
	wmove(win, row+1, col*maxCellSize+8);
}

void SheetController::openEditor(Sheet &sheet, CellAddress cursor){
	EditWindow edit(cursor);
	std::string s1;

	if(!sheet.getCell(cursor.getRowNum(),cursor.getColNum()).isEmpty())
		s1 = sheet.getCell(cursor.getRowNum(), cursor.getColNum()).getString();

	edit.drawWindow(s1.c_str());
	edit.openEditor(sheet);
	edit.deleteWindow();
	curs_set(0);
}

void SheetController::pressEnter(Sheet &sheet, CellAddress cursor){
	openEditor(sheet,cursor);
}

void SheetController::pressBackspace(Sheet &sheet, CellAddress cursor){
	if(!sheet.getCell(cursor.getRowNum(),cursor.getColNum()).isEmpty())
		sheet.getCell(cursor.getRowNum(), cursor.getColNum()).empty();
}

void SheetController::handleInput(WINDOW* win, CellAddress cursor, Sheet &sheet, int ch){
	switch(ch){

	case	KEY_LEFT:
			moveLeft(win);
			break;

	case	KEY_RIGHT:
			moveRight(win);
			break;

	case	KEY_UP:
			moveUp(win);
			break;

	case	KEY_DOWN:
			moveDown(win);
			break;

	case	KEY_BACKSPACE:
			pressBackspace(sheet,cursor);
			break;

	case	'\n':
	case	KEY_ENTER:
			pressEnter(sheet,cursor);
			break;

	case	'q':
			break;

	default:
			break;
	}
}

//TODO Implement need CellFormula class
void SheetController::parseCell(CellAddress cursor, Sheet &sheet){

}

void SheetController::run(Sheet &sheet){
	SheetView view;
	wmove(view.getWin(), 1,8);

	int command;
	do{
		wclear(view.getWin());
		view.initHeader();
		view.drawSheet(sheet);
		wrefresh(view.getWin());
		handleInput(view.getWin(), view.getCursor(), sheet, command);
		view.setCursor(row,col);
		view.drawCursor(sheet);
		

		wrefresh(view.getWin());

	}while((command = wgetch(view.getWin())) != 'q');

	view.exitSheet();
}



