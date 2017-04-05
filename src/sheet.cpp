/*
 * sheet.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: asch
 */
#include "../include/sheet.h"
#include "../include/column.h"


Sheet::Sheet(){
	for(int i = 0; i < maxColumnNumber; i++){
		Column col;
		sheet.push_back(col);
	}
}


Cell* Sheet::getCell(int row, int column){
	return sheet[column].getCell(row);
}


