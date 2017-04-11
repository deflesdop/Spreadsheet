#include "../include/sheetview.h"
#include <curses.h>
#include <string>

SheetView::SheetView(){
	initscr();
  	noecho();
  	win = newwin(MAXrow, MAXcol*CellSize, 0, 0);
  	keypad(win, TRUE);
  	wmove(win, 0, 0);
}

SheetView::~SheetView(){
	delwin(win);  /* Dealloceer venster */
	endwin();  /* Curses stoppen */
}

std::string SheetView::headerLetter(int colNum){
	char a[2] = {'@','@'};
	std::string str;

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
	attr_t old_attr; /* Huidige settings onthouden */
	short old_pair;
	wattr_get(win, &old_attr, &old_pair, NULL);
	wattron(win, A_STANDOUT);
	
	for(int i = 0; i <= MAXcol*CellSize; i++){
	wmove(win, 0, CellSize+i);	
		if(i != 0 && i%CellSize == 0){
			str = headerLetter(i/CellSize);
			waddstr(win, str.c_str());
		}
		else{
			waddstr(win, " ");
		}
	}
	
	wattr_set(win, old_attr, old_pair, NULL); /* Oude settings terugzetten */
		
int ch;
  while ((ch = wgetch(win)) != '\n');
}

void SheetView::drawSheet(){

}

void SheetView::exitSheet(){
	delwin(win);  /* Dealloceer venster */
	endwin();  /* Curses stoppen */
}

