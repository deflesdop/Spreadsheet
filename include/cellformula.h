/*
 * cellformula.h
 *
 *  Created on: Apr 5, 2017
 *      Author: asch
 */

#ifndef INCLUDE_CELLFORMULA_H_
#define INCLUDE_CELLFORMULA_H_

#include <string>

using namespace std;

class CellFormula : public CellValueBase{

public:

	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	string getString();


	/*
	 * Returns the value of the cell as float.
	 */
	float getFloat();

	std::string parseFormula(std::string formula, std::string cell1, std::string cell2);

	int calculateFormula();

private:

};


#endif /* INCLUDE_CELLFORMULA_H_ */
