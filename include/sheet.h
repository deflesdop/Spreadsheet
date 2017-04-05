/*
 * sheet.h
 *
 *  Created on: Mar 24, 2017
 *      Author: asch
 */

#ifndef INCLUDE_SHEET_H_
#define INCLUDE_SHEET_H_

#include "cell.h"
#include "column.h"

/*
 *Header file for Sheet class.
 *Class which holds a vector list of Column objects
 *to form a spreadsheet.
 */

class Sheet{

	private:

	/*
	 * Vector list to store columns.
	 */
	std::vector<Column> sheet;

	/*
	 * Number of columns in the spreadsheet.
	 */
	const int maxColumnNumber = 80;

	public:

	/*Constructor for the Sheet
	 *
	 ****************************
	 * Not working due to unique_ptr being copied somewhere
	 * TODO Fix call to copyconstructor
	 */
	Sheet();

	~Sheet() = default;


	/*
	 * Returns the Cell pointer at a certain row.
	 * PARAMS int row, row of the column.
	 * 		  int column, columns of the sheet.
	 * *********
	 * TODO Not yet implemented.
	 */
	Cell* getCell(const int row, const int column);


};



#endif /* INCLUDE_SHEET_H_ */
