#ifndef CELL_H_
#define CELL_H_

#include <memory>
#include <iostream>
#include "../include/cellvaluebase.h"
#include "../include/cellvalue.h"

/*
 * Header file for the Cell class.
 * This object stores a template object.
 * The value is stored in CellValue and is accessible through a unique pointer.
 */

class Cell {

	private:

	/*
	 * Unique pointer to a CellValueBase.
	 */
	std::unique_ptr<CellValueBase> value;

	public:

		/*
		 * Cell constructor.
		 */
		Cell();
		
		/*
		 * Cell destructor.
		 */
		~Cell();

		/*
		 *Stores a new value in a cell.
		 *PARAMS float type, value to store.
		 */
		void setFloatValue(const float val);

		/*
		 *Stores a new value in a cell.
		 *PARAMS string type, value to store.
		 */
		void setStringValue(const string val);
		
		/*
		 *Returns the string of the cell used for drawing
		 *the spreadsheet.
		 */
		string readStrValueDraw();

		/*
		 * Returns the string of the cell used for editing
		 * values.
		 */
		string readStrValueEdit();

		/*
		 * Returns the value of the cell as float.
		 */
		float readFloatValue();

		/*
		 * Clears the value of the cell.
		 */
		void emptyCell();


};

#endif
