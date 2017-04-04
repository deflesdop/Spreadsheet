/*
 * column.h
 *
 *  Created on: Mar 23, 2017
 *      Author: asch
 */

#ifndef INCLUDE_COLUMN_H_
#define INCLUDE_COLUMN_H_

#include <vector>
#include "cell.h"
#include <iterator>
using namespace std;

/*
 * Header file for the Column class.
 * This class stores Cell objects in a vector
 * list to form a column.
 */

class Column {


	private:

	/*
	 * Number of rows in the spreadsheet.
	 */
	const int maxNumberCells = 24;

	/*
	 * Vector list of Cells.
	 */
	vector<Cell> column;

	public:

	/*Constructor for the columns
	 *
	 ****************************
	 * Not working due to unique_ptr being copied somewhere
	 * TODO Fix call to copyconstructor
	 */
//	Column(void){
//		column.resize(maxNumberCells);

//		for(int i = 0; i < maxNumberCells; i++){
//			Cell cell;
//			column.push_back(cell);
//		}
//	}

//	~Column(void) = default;

	/*
	 * Returns the Cell pointer at a certain row.
	 * PARAMS int row, row of the column.
	 */
//	Cell* getCell(const int row){
//		return column[row];
//	}

};

#endif /* INCLUDE_COLUMN_H_ */
