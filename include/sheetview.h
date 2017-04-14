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
		void drawSheet(Sheet &sheet);
		void undoCursor(Sheet &sheet);
		void drawCursor(Sheet &sheet);
		CellAddress getCursor();
		void setCursor(int row, int col); 

		char getChar();
		WINDOW* getWin();
		void exitSheet();

	private:
		const int MAXrow = 24;
		const int MAXcol = 80;
		const int CellSize = 8;
		CellAddress cursor;
		WINDOW *win;

		std::string headerLetter(int colNum);
		std::string formatCell(std::string, const size_t size);

};


#endif /* INCLUDE_SHEETVIEW_H_ */
