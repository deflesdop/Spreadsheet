/*
 * celladdress.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: asch
 */
#include "../include/celladdress.h"
#include <string>
#include <iostream>


CellAddress::CellAddress():
rowNum(-99), colNum(-99)
{}


CellAddress::CellAddress(std::string &ref){
	createFromReference(ref);
}

void CellAddress::createFromReference(std::string &ref){
	std::string s1,s2;
	if(ref.size() <= 0 || ref.size() > 4){
		throw "Illegal_Format_Exception";
	}
	for(char c : ref){
		if(isdigit(c)){
			s2 += c;
		}
		else if(isalpha(c)){
			s1 += c;
		}
	}
	if(s2.empty() || s1.empty()){
		throw "Illegal_Format_Exception";
	}
	setRowNum(convertRowNumToRowSheet(stoi(s2)));
	setColNum(convertColNameToColNum(s1));
}

/*
 * Returns the row number of the cell.
 */
int CellAddress::getRowNum(){
	return rowNum;
}

/*
 * Sets the row number of the cell.
 */
void CellAddress::setRowNum(int row){
	rowNum = row;
}

/*
 * Returns the column number of the cell.
 */
int CellAddress::getColNum(){
	return colNum;
}

/*
 * Sets the column number of the cell.
 */
void CellAddress::setColNum(int col){
	colNum = col;
}

void CellAddress::incDecRowCursor(bool inc)
	(inc ? rowNum++ : rowNum--);
	std::cout << rowNum << "," << colNum<<std::endl;
}

void CellAddress::incDecColCursor(bool inc){
	(inc ? colNum++ : colNum--);
	std::cout << rowNum << "," << colNum<<std::endl;
}



/*
 * Converts a column reference to a column number.
 */
int CellAddress::convertColNameToColNum(std::string &cellref){
	int temp, first;
	first = (int)(cellref.front() - 64);
	if (cellref.size() == 1){
		temp = first;
	}
	else{
		temp = (first*26)+(cellref.back() - 64);
	}
	return temp - 1;
}

/*
 * Converts a column number to a column reference.
 */
std::string CellAddress::convertColNumToColName(int colNum){
	if(colNum < 0 || colNum > MaxCol){
		throw "Out_of_Bounds_Exception";
	}
	char a[2] = {'@','@'};
	std::string str;

	if (colNum <= 26){
		str += static_cast<char>(a[0]+(colNum+1));
	}
	else if (colNum > 26 && colNum <= 52){
		str += static_cast<char>(a[0]+1);
		str += static_cast<char>(a[1]+((colNum+1)-26));
	}
	else if (colNum > 52 && colNum <= 78){
		str += static_cast<char>(a[0]+2);
		str += static_cast<char>(a[1]+((colNum+1)-52));
	}
	else if (colNum > 78 && colNum <= 104){
		str += static_cast<char>(a[0]+3);
		str += static_cast<char>(a[1]+((colNum+1)-78));
	}
	return str;
}

/*
 * Converts a row number to a row sheet number.
 */
int CellAddress::convertRowNumToRowSheet(int rowNum){
	return rowNum - 1;
}

/*
 * Converts a row sheet number to a row number.
 */
int CellAddress::convertRowSheetToRowNum(int rowSheet){
	return rowSheet + 1;
}

