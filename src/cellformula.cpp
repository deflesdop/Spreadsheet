/*
 * cellformula.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: asch
 */

#include "../include/cellformula.h"
#include "../include/range.h"
#include "../include/celladdress.h"
#include "../include/sheet.h"
#include "../include/sheetobserver.h" 

CellFormula::CellFormula(std::string formula, Sheet &sheetref):
	SheetObserver(sheetref),
	rawFormula(formula), sheetref(sheetref), sum(0), count(0), avg(0)
{}

std::string CellFormula::parseFormula(std::string formula, std::string &cell1, std::string &cell2){
	std::string delimiter = "=():";
	std::string s1, s2, s3;
	char* cstr = &formula[0u];
	char* ch = strtok(cstr, delimiter.c_str());
	s1 = ch[0];
	s2 = ch[1];
	s3 = ch[2];
	cell1 = s2;
	cell2 = s3;
	return s1;
}

	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	std::string CellFormula::getString(){
		try{
			return "";
		}
		catch(const char* msg){
			std::cerr << msg << std::endl;
			return "ERR";
		}
	}


	/*
	 * Returns the value of the cell as float.
	 */
	float CellFormula::getFloat(){
		return -9.f;
	}
	
	void CellFormula::calculateFormula(){
		std::string formula = parseFormula(rawFormula, cell1, cell2);
		CellAddress begin(cell1), end(cell2);
		Range range(sheetref, begin, end);
		for(Range::iterator rit = range.begin(); rit != range.end(); ++rit){
			count++;
			sum+= rit->getFloat();
		}
		avg = sum / count;
	}
	
	void CellFormula::cellChanged(){
			calculateFormula();
	}
	
	
	
	
	
	
	
	

