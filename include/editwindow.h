#ifndef INCLUDE_EDITWINDOW_H_
#define INCLUDE_EDITWINDOW_H_

#include "celladdress.h"

class EditWindow{
	public:
		EditWindow(WINDOW* win, CellAddress location);
		~EditWindow() = default;
		void drawWindow();
		void deleteWindow();
		void readWindow(Sheet &sheet);
	private:
		const int height = 3;
		const int width = 16;
		WINDOW* popup;
		CellAddress cursor;
};

#endif /* INCLUDE_EDITWINDOW_H_ */
