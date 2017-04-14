#ifndef CELLVALUE_H_
#define CELLVALUE_H_

#include <boost/lexical_cast.hpp>
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
	
	~CellValue() = default;

	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	string getString(){
		stringstream os;
		os << value;
		return os.str();
	}

	
	/*
	 * Returns the value of the cell as float.
	 */
	float getFloat(){
		float temp;
		try{
			temp = boost::lexical_cast<float>(value);
			return temp;
		}
		catch(boost::bad_lexical_cast &error){
			temp = -99.f;
			return temp;
		}
	}

};




#endif
