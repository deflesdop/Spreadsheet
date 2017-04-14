
#include <curses.h>
#include <string>
#include "../include/sheet.h"
#include "../include/sheetview.h"
#include "../include/editcontroller.h"
#include "../include/cellvaluebase.h"
#include "../include/cellformula.h"

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

bool EditController::validateFormula(std::string formula){
	int check1(0), check2(0), check3(0), check4(0);
	for(char c : formula){
		switch(c){
		case	'=':
			check1++;
			break;
		case	'(':
			check2++;
			break;
		case	')':
			check3++;
			break;
		case	':':
			check4++;
			break;
		default:
			break;
		}
	}
	if(check1 == 1 && check2 ==1 && check3 == 1 && check4 ==1)
		return true;
	else
		return false;
}

void EditController::editCell(WINDOW* popup, Sheet &sheet, CellAddress cursor){
	int command;
	CellValueBase* base;
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
	if(validateFormula(str)){
		base = new CellFormula(str,sheet);
	}
	else{
		base = CellValueBase::cellValueFactory(str);
	}
	sheet.setCellValue(base, cursor.getRowNum(), cursor.getColNum());
}
