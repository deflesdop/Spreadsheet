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

template <typename T>
class Column {


	private:

	const int maxNumberCells = 24;
	vector<Cell<T>> column;

	public:

	/*Constructor for the columns
	 *
	 ****************************
	 * Not working due to unique_ptr being copied somewhere
	 */
	Column(void){
		column.resize(maxNumberCells);

		for(int i = 0; i < maxNumberCells; i++){
			Cell<T> cell;
			column.push_back(cell);
		}
	}

	~Column(void) = default;

	Cell<T>* getCell(const int row){
		Cell<T>* temp;
		temp = column[row];
		return temp;
	}




};




#endif /* INCLUDE_COLUMN_H_ */
