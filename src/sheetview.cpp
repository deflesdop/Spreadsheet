#include <curses.h>
#include <string>
#include "../include/sheet.h"
#include "../include/column.h"
#include "../include/sheetview.h"

SheetView::SheetView(){
	initscr();
  	noecho();

  	win = newwin(MAXrow+3, MAXcol*CellSize+CellSize, 0, 0);
  	scrollok(win, TRUE);
  	keypad(win, TRUE);
  	wmove(win, 0, 0);
  	curs_set(0);

  	cursor.setRowNum(0);
	cursor.setColNum(0);	
}

SheetView::~SheetView(){
	exitSheet();
}

std::string SheetView::headerLetter(int colNum){
	char a[2] = {'@','@'};
	std::string str;
	colNum++;
	if (colNum <= 26){
		str += static_cast<char>(a[0]+colNum);
	}
	else if (colNum > 26 && colNum <= 52){
		str += static_cast<char>(a[0]+1);
		str += static_cast<char>(a[1]+(colNum-26));
	}
	else if (colNum > 52 && colNum <= 78){
		str += static_cast<char>(a[0]+2);
		str += static_cast<char>(a[1]+(colNum-52));
	}
	else if (colNum > 78 && colNum <= 104){
		str += static_cast<char>(a[0]+3);
		str += static_cast<char>(a[1]+(colNum-78));
	}
	
	return str;
}

void SheetView::initHeader(){
	std::string str;
	attr_t old_attr;
	short old_pair;
	int size = CellSize;

	wattr_get(win, &old_attr, &old_pair, NULL);
	wattron(win, A_STANDOUT);

	for(int i = 0; i < MAXcol*CellSize; i++){
		wmove(win, 0, CellSize+i);
		if(i != 0 && i%CellSize == CellSize/2){
			str = headerLetter(i/CellSize);
			waddstr(win, str.c_str());
		}
		else{
			waddstr(win, " ");
		}
	}
	
	for(int i = 0; i < MAXrow; i++){
		wmove(win, i+1, 0);
		if(i == 9)size--;
		for(int j = 0; j < size; j++){
			if(j == CellSize/2){
				wprintw(win,"%d", i+1);
			}
			else{
				waddch(win, ' ');
			}
		}
	}
	wattr_set(win, old_attr, old_pair, NULL); /* Oude settings terugzetten */
}

std::string SheetView::formatCell(std::string value, const size_t size){
	if(value.size() > size){
		value.resize(size);
		return value;
	}
	return value;
}

void SheetView::drawSheet(Sheet &sheet){
	int row = 1,col = 8;
	wmove(win,row,col);
	for (Sheet::iterator sit = sheet.begin(); sit != sheet.end(); ++sit){
		for(Column::iterator cit = sit->begin() ; cit != sit->end(); ++cit){
			if(!cit->isEmpty()){
				waddstr(win, formatCell(cit->getString(), 8).c_str());
				}
			wmove(win, ++row, col);
		}
		row = 1;
		col += 8;
		wmove(win, row, col);
	}
	wmove(win, cursor.getRowNum()+1, (cursor.getColNum()*CellSize)+8);
}

void SheetView::undoCursor(Sheet &sheet){
	int row = cursor.getRowNum()+1;
	int col = cursor.getColNum()+1;
	int size = 8;

	wmove(win,row,CellSize*col);
	if(!sheet.getCell(row-1,col-1).isEmpty()){
		if(sheet.getCell(row-1, col-1).getString().size() > 8){
			waddstr(win, formatCell(sheet.getCell(row-1, col-1).getString(), 8).c_str());
		}
		else{
			size -= sheet.getCell(row-1, col-1).getString().size();
			waddstr(win, sheet.getCell(row-1, col-1).getString().c_str());
			for(int i = 0; i < size; i++)
				waddch(win, ' ');
		}
	}
	else{
		for(int i = 1; i <= CellSize; i++){
			waddch(win, ' ');
			wmove(win,row,CellSize*col+i);
		}
	}
}

void SheetView::drawCursor(Sheet &sheet){

	int row = cursor.getRowNum()+1;
	int col = cursor.getColNum()+1;
	int size = 8;
	attr_t old_attr;
	short old_pair;
	wattr_get(win, &old_attr, &old_pair, NULL);
	wattron(win, A_STANDOUT);

	wmove(win,row,CellSize*col);
	if(!sheet.getCell(row-1,col-1).isEmpty()){
		if(sheet.getCell(row-1, col-1).getString().size() > 8){
			waddstr(win, formatCell(sheet.getCell(row-1, col-1).getString(), 8).c_str());
		}
		else{
			size -= sheet.getCell(row-1, col-1).getString().size();
			waddstr(win, sheet.getCell(row-1, col-1).getString().c_str());
			for(int i = 0; i < size; i++)
				waddch(win, ' ');
		}
	}
	else{
		for(int i = 1; i <= CellSize; i++){
			waddch(win, ' ');
			wmove(win,row,CellSize*col+i);
		}
	}
	wattr_set(win, old_attr, old_pair, NULL); /* Oude settings terugzetten */
	wmove(win, cursor.getRowNum()+1, (cursor.getColNum()*CellSize)+8);
}

CellAddress SheetView::getCursor(){
	return cursor;
}

void SheetView::setCursor(int row, int col){
	cursor.setRowNum(row);
	cursor.setColNum(col);
}

char SheetView::getChar(){
	int command;
	while((command = getch()) != 'q'){
	}
	return mvwinch(win,cursor.getRowNum()+1,(cursor.getColNum()*CellSize)+8);
}

WINDOW* SheetView::getWin(){
	return win;
}

void SheetView::exitSheet(){
	delwin(win);  /* Dealloceer venster */
	endwin();  /* Curses stoppen */
}

