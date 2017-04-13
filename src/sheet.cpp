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


Sheet::Sheet():
sheet(maxColumnNumber)
{}

void Sheet::addObserver(SheetObserver* sheetobs){
	observer.push_back(sheetobs);
}

Column& Sheet::getColumn(int column){
	return sheet[column];
}

Cell& Sheet::getCell(int row, int column){
	return getColumn(column).getCell(row);
}

void Sheet::setFloat(const float val, int row, int column){
	getCell(row, column).setFloat(val);
}
	
void Sheet::setString(const std::string val, int row, int column){
	getCell(row, column).setString(val);
}
	
void Sheet::setCellValue(CellValueBase* base, int row, int column){
	getCell(row, column).setCellValue(base);
}

void Sheet::notify(){
	for(int i = 0; i < observer.size(); i++){
		observer[i]->cellChanged();
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

