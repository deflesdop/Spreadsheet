/*
 * cellformula.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: asch
 */

#include "../include/cellformula.h"
#include "../include/range.h"

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

