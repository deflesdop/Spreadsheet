/*
 * sheet.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: Andrew Huang, Micha de Jong
 */
#include "../include/sheet.h"
#include "../include/column.h"
#include "../include/cellvaluebase.h"
#include "../include/sheetobserver.h"
#include <string>
#include <curses.h>


Sheet::Sheet():
sheet(maxColumnNumber)
{}

void Sheet::addObserver(SheetObserver* sheetobs){
	observer.push_back(sheetobs);
}

void Sheet::removeObserver(SheetObserver* sheetobs){
	observer.erase(std::remove(observer.begin(), observer.end(), sheetobs), observer.end());
}

void Sheet::notify(){
	for(SheetObserver* ob : observer){
		if(ob)
			ob->cellChanged();
	}
}

Column& Sheet::getColumn(int column){
	return sheet[column];
}

Cell& Sheet::getCell(int row, int column){
	return getColumn(column).getCell(row);
}

void Sheet::setCellValue(CellValueBase* base, int row, int column){
	getCell(row, column).setCellValue(base);
	notify();
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

