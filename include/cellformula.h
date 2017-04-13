/*
 * cellformula.h
 *
 *  Created on: Apr 5, 2017
 *      Author: asch
 */

#ifndef INCLUDE_CELLFORMULA_H_
#define INCLUDE_CELLFORMULA_H_

#include <string>
#include "cellvalue.h" 
#include "sheet.h"
#include "sheetobserver.h"
#include "cell.h"

using namespace std;

class CellFormula : public CellValueBase, public SheetObserver{

public:

	CellFormula(std::string formula, Sheet &sheetref);
	~CellFormula() = default;
	
	std::string parseFormula(std::string formula, std::string &cell1, std::string &cell2);
	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	string getString();


	/*
	 * Returns the value of the cell as float.
	 */
	float getFloat();
	
	void calculateFormula();
	
	void cellChanged();
	

private:
	std::string rawFormula;
	Sheet &sheetref;
	float sum, count, avg;
	std::string cell1, cell2;
	

};


#endif /* INCLUDE_CELLFORMULA_H_ */
