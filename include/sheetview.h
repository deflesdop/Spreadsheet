#ifndef INCLUDE_SHEETVIEW_H_
#define INCLUDE_SHEETVIEW_H_
#include <curses.h>
#include <string>

class SheetView{
	public:
		SheetView();
		~SheetView();
		void initHeader();
		void drawSheet();
		void exitSheet();
		std::string headerLetter(int colNum);
		
	private:
		const int MAXrow = 24;
		const int MAXcol = 78;
		const int CellSize = 8;
		WINDOW *win;

};


#endif /* INCLUDE_SHEETVIEW_H_ */
