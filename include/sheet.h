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

template <typename T>
class Sheet{

	public:

	Sheet(){
		sheet.resize(80);
	}

	~Sheet();


	Cell<T>* getCell(){

	}

	private:
	std::vector<Cell<T>> sheet;
	const int columns = 80;
	const int rows = 24;

};



#endif /* INCLUDE_SHEET_H_ */
