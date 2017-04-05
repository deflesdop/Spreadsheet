#ifndef CELLVALUE_H_
#define CELLVALUE_H_

#include <string>
#include <sstream>
#include "cellvaluebase.h"
using namespace std;

/*
 * Header file for CellValue class.
 * Class which stores virtual functions to store different
 * types of values using templates.
 */

template<typename T>
class CellValue : public CellValueBase
{
	private: 
		/*
		 * Value of the cell.
		 */
		T value;

		
	public:

	/*
	 * CellValue constructor.
	 * PARAMS T type, value in the cell.
	 */
	CellValue(T initial_value)
		:value(initial_value)
	{}
	
	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	string returnInfo(){
		stringstream os;
		os << value << endl;
		return os.str();
	}

	
	/*
	 * Returns the value of the cell as float.
	 * *****************
	 * Gets called when Cell<string> is created
	 * causing an conversion error.
	 * TODO Fix conversion error.
	 */
	float returnFloatValue(){
		return 0.f;
	}

};




#endif
