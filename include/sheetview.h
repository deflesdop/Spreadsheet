#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_
#include <curses.h>
#include <string>
#include "sheet.h"
#include "celladdress.h"

class SheetView{
	public:
		SheetView();
		~SheetView();
		void initHeader();
		std::string formatCell(std::string);
		void drawSheet(Sheet &sheet);
		void drawCursor(Sheet &sheet, int row, int col);
		CellAddress getCursor();
		void setCursor(int row, int col); 
		char getChar();
		void drawPopup();
		void exitSheet();
		void suspend();
		std::string headerLetter(int colNum);
		
	private:
		const int MAXrow = 24;
		const int MAXcol = 80;
		const int CellSize = 8;
		CellAddress cursor;
		WINDOW *win;

};


#endif /* INCLUDE_SHEETVIEW_H_ */
