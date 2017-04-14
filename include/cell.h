#ifndef CELL_H_
#define CELL_H_

#include <memory>
#include <iostream>
#include "cellvaluebase.h"
#include "cellvalue.h"
#include "celladdress.h"

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
		~Cell() = default;

		/*
		 *Stores a new value in a cell.
		 *PARAMS float type, value to store.
		 */
		void setFloat(const float val);

		/*
		 *Stores a new value in a cell.
		 *PARAMS string type, value to store.
		 */
		void setString(const std::string val);
		
		void setCellValue(CellValueBase* base);
		
		/*
		 *Returns the string of the cell used for drawing
		 *the spreadsheet.
		 */
		std::string getString();

		/*
		 * Returns the value of the cell as float.
		 */
		float getFloat();

		/*
		 * Clears the value of the cell.
		 */
		void empty();
		
		bool isEmpty();

		bool isEqual(Cell &cell);

		bool operator==(const Cell &x){
			if(value == x.value)
				return true;
			else
				return false;
		}
};

#endif
