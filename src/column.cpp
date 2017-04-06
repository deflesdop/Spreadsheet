/*
 * column.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: asch
 */
#include "../include/column.h"
#include "../include/cell.h"


Column::Column():
column(maxNumberCells)
{}



Cell& Column::getCell(const int row){
	return column[row];
}

ColIterator Column::begin(){
	return ColIterator(*this,0);
}

ColIterator Column::end(){
	return ColIterator(*this,column.size());
}
