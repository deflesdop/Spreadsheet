/*
 * cellformula.h
 *
 *  Created on: Apr 5, 2017
 *      Author: Andrew Huang, Micha de Jong
 */

#ifndef INCLUDE_CELLFORMULA_H_
#define INCLUDE_CELLFORMULA_H_

#include <string>
#include "cellvalue.h" 
#include "sheet.h"
#include "sheetobserver.h"
#include "cell.h"
#include <curses.h>

using namespace std;

class CellFormula : public CellValueBase, public SheetObserver{

public:

	CellFormula(std::string formula, Sheet &sheetref);
	~CellFormula();
	

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

	virtual void cellChanged(){
		iterate(begin, end);
	}

private:
	int mode, iterMode;
	std::string rawFormula;
	Sheet &sheetref;
	float sum, count, avg;
	std::string errmsg, str1, str2;
	CellAddress begin, end;

	void correctCell();

	bool validateFormula(std::string formula);

	std::string parseFormula(std::string formula, std::string &cell1, std::string &cell2);

	void setMode(std::string str);

	void createCellAddress(std::string str1, std::string str2);

	void iterateHori(CellAddress c1, CellAddress c2);

	void iterateVert(CellAddress c1, CellAddress c2);

	void iterateBlock(CellAddress c1, CellAddress c2);

	void reinitValues();

	void setIterMode(CellAddress c1, CellAddress c2);

	void iterate(CellAddress c1, CellAddress c2);

};


#endif /* INCLUDE_CELLFORMULA_H_ */
