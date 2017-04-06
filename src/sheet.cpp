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
{
}


Cell& Sheet::getCell(int row, int column){
	return sheet[column].getCell(row);
}


