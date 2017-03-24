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

	vector<Cell<T>>::iterator begin(){
		return column.begin();
	}

	vector<Cell<T>>::iterator end(){
			return column.end();
		}

	public:

	Column(void){
		column.resize(maxNumberCells);

		for(int i = 0; i < maxNumberCells; i++){
			Cell<T> cell;
			column.push_back(cell);
		}
	}

	Cell<T>* getCell(const int row){
		for(vector<Cell<T>>::iterator it = begin(); it != end(); ++it){

		}

	}





};




#endif /* INCLUDE_COLUMN_H_ */
