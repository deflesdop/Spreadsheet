/*
 * celladdress.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: asch
 */
#include "../include/celladdress.h"
#include <string>


CellAddress::CellAddress():
	rowNum(0), colNum(0)
{}


CellAddress::CellAddress(std::string &ref){
	createFromReference(ref);
}

void CellAddress::createFromReference(std::string &ref){
	std::string s1,s2;
	for(char c : ref){
		if(isdigit(c)){
			s2 += c;
		}
		else{
			s1 += c;
		}
	}
	rowNum = stoi(s2);
	colNum = convertColNameToColNum(s1);
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
	return temp;
}

/*
 * Converts a column number to a column reference.
 */
std::string CellAddress::convertColNumToColName(int colNum){
	char a[2] = {'@','@'};
	std::string str;
	if (colNum <= 26){
		str += static_cast<char>(a[0]+colNum);
	}
	else if (colNum > 26 && colNum <= 52){
		str += static_cast<char>(a[0]+1);
		str += static_cast<char>(a[1]+(colNum-26));
	}
	else if (colNum > 52 && colNum <= 78){
		str += static_cast<char>(a[0]+2);
		str += static_cast<char>(a[1]+(colNum-52));
	}
	else if (colNum > 78 && colNum <= 104){
		str += static_cast<char>(a[0]+3);
		str += static_cast<char>(a[1]+(colNum-78));
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

