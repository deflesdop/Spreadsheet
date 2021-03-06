#ifndef INCLUDE_EDITCONTROLLER_H_
#define INCLUDE_EDITCONTROLLER_H_

#include <curses.h>
#include <string>
#include "sheet.h"
#include "celladdress.h"

class EditController{
	public:
		EditController();
		~EditController() = default;
		void moveLeft(WINDOW* popup);
		void moveRight(WINDOW* popup);
		void backspace(WINDOW* popup);
		void handleInput(WINDOW* popup, int ch);
		bool validateFormula(std::string formula);
		void editCell(WINDOW* popup, Sheet &sheet, CellAddress cursor);


	private:
		int xIndex;
		const int yIndex = 1;
		const int maxEditSize = 14;

};

#endif /* INCLUDE_EDITCONTROLLER_H_ */
