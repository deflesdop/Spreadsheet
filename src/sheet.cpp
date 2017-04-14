/*
 * sheet.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: asch
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

Sheet::~Sheet(){
//	std::vector<SheetObserver*>::iterator it = observer.begin();
//	while (it != observer.end() && *it != nullptr){
//		delete *it;
//		it = observer.erase(it);
//	}
}

void Sheet::addObserver(SheetObserver* sheetobs){
	observer.push_back(sheetobs);
}

Column& Sheet::getColumn(int column){
	return sheet[column];
}

Cell& Sheet::getCell(int row, int column){
	return getColumn(column).getCell(row);
}

void Sheet::setCellValue(CellValueBase* base, int row, int column){
	getCell(row, column).setCellValue(base);
	//notify(getCell(row,column));
}

void Sheet::notify(const Cell &cell){
	size_t size = observer.size();
	for(int i = 0; i < size; i++){
		observer[i]->cellChanged(cell);
	}
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

