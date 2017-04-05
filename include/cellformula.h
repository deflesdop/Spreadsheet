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



	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	string returnInfo();


	/*
	 * Returns the value of the cell as float.
	 */
	float returnFloatValue();



};


#endif /* INCLUDE_CELLFORMULA_H_ */
