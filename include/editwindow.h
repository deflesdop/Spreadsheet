#ifndef INCLUDE_EDITWINDOW_H_
#define INCLUDE_EDITWINDOW_H_

#include "celladdress.h"

class EditWindow{
	public:
		EditWindow(CellAddress loc);
		~EditWindow() = default;
		void drawWindow(const char* str);
		void openEditor(Sheet &sheet);
		void deleteWindow();

	private:
		const int height = 3;
		const int width = 16;
		WINDOW* popup;
		CellAddress cursor;
};

#endif /* INCLUDE_EDITWINDOW_H_ */
