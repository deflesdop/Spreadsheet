#ifndef INCLUDE_SHEETCONTROLLER_H_
#define INCLUDE_SHEETCONTROLLER_H_

#include "sheetview.h"
#include "editwindow.h"
#include "editcontroller.h"
#include <curses.h>
#include <string>
#include "sheet.h"


class SheetController{

	public:

	SheetController();
	~SheetController() = default;

	void moveLeft(WINDOW* win);
	void moveRight(WINDOW* win);
	void moveUp(WINDOW* win);
	void moveDown(WINDOW* win);
	void openEditor(Sheet &sheet, CellAddress cursor);
	void pressEnter(Sheet &sheet, CellAddress cursor);
	void pressBackspace(Sheet &sheet, CellAddress cursor);

	void handleInput(WINDOW* win, CellAddress cursor, Sheet &sheet, int ch);
	bool validateFormula(std::string formula);
	void parseCell(WINDOW* win, CellAddress cursor, Sheet &sheet);

	void run(Sheet &sheet);

	private:
	int row, col;
	const int maxCol = 80;
	const int maxRow = 23;
	const int maxCellSize = 8;




};



#endif /* INCLUDE_SHEETCONTROLLER_H_ */
