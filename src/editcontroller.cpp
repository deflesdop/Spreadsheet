#include "../include/sheetview.h"
#include <curses.h>
#include <string>
#include "../include/sheet.h"
#include "../include/editcontroller.h"

EditController::EditController(){
	xIndex = 1;
}

void EditController::moveLeft(WINDOW* popup){
	if(xIndex > 1 )
	wmove(popup, yIndex, --xIndex);
}

void EditController::moveRight(WINDOW* popup){
	if(xIndex <= maxEditSize-1)
	wmove(popup, yIndex, ++xIndex);
}

void EditController::backspace(WINDOW* popup){
	if(xIndex > 1){
		mvwdelch(popup, yIndex, --xIndex);
	}
}

void EditController::handleInput(WINDOW* popup, int ch){
	switch(ch){

	case	KEY_LEFT:
			moveLeft(popup);
			break;

	case	KEY_RIGHT:
			moveRight(popup);
			break;

	case	KEY_BACKSPACE:
			backspace(popup);
			break;

	case	KEY_UP:
			break;

	case	KEY_DOWN:
			break;

	case	KEY_DC:
			wdelch(popup);
			break;

	case	'\n':
	case	KEY_ENTER:
			break;

	default:
			xIndex++;
			waddch(popup, ch);
			break;
	}
}

void EditController::editCell(WINDOW* popup, Sheet &sheet, CellAddress cursor){
	int command;
	std::string str;
	chtype t;

	wmove(popup,yIndex,xIndex);

	while((command = wgetch(popup)) != '\n'){
		handleInput(popup, command);
		wrefresh(popup);

	}

	for(int i = 0; i < maxEditSize-1; i++){
		t = mvwinch(popup,1,1+i);
		str+=t;
	}

	sheet.getCell(cursor.getColNum(), cursor.getRowNum()).setString(str);
}
