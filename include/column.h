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

template <typename T>
class Column {


	private:

	/*
	 * Number of rows in the spreadsheet.
	 */
	const int maxNumberCells = 24;

	/*
	 * Vector list of Cells.
	 */
	vector<Cell<T>> column;

	public:

	/*Constructor for the columns
	 *
	 ****************************
	 * Not working due to unique_ptr being copied somewhere
	 * TODO Fix call to copyconstructor
	 */
	Column(void){
		column.resize(maxNumberCells);

		for(int i = 0; i < maxNumberCells; i++){
			Cell<T> cell;
			column.push_back(cell);
		}
	}

	~Column(void) = default;

	/*
	 * Returns the Cell pointer at a certain row.
	 * PARAMS int row, row of the column.
	 */
	Cell<T>* getCell(const int row){
		Cell<T>* temp;
		temp = column[row];
		return temp;
	}

};

#endif /* INCLUDE_COLUMN_H_ */
