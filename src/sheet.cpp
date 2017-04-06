/*
 * sheet.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: asch
 */
#include "../include/sheet.h"
#include "../include/column.h"


Sheet::Sheet():
sheet(maxColumnNumber)
{}


Column& Sheet::getColumn(int column){
	return sheet[column];
}

Cell& Sheet::getCell(int row, int column){
	return getColumn(column).getCell(row);
}

/*
*
*/
SheetIterator Sheet::begin(void){
	return SheetIterator(*this,0);
}

/*
*
*/
SheetIterator Sheet::end(void){
	return SheetIterator(*this, sheet.size());
}

