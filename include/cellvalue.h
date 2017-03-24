#ifndef CELLVALUE_H_
#define CELLVALUE_H_

#include <string>
#include <sstream>
using namespace std;

/*
 * Header file for CellValue class.
 * Class which stores virtual functions to store different
 * types of values using templates.
 */

template<typename T>
class CellValue final : public CellValueBase
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
		:CellValueBase(), value(initial_value)
	{}
	
	/*
	 * CellValue Destructor.
	 */
	virtual ~CellValue(){

	}
	
	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	virtual string returnInfo(){
		stringstream os;
		os << value << endl;
		return os.str();
	}

	/*
	 * Returns the string of the cell used for editing
	 * values.
	 */
	virtual string returnValueEdit(){
		return "";
	}
	
	/*
	 * Returns the value of the cell as float.
	 * *****************
	 * Gets called when Cell<string> is created
	 * causing an conversion error.
	 * TODO Fix conversion error.
	 */
	virtual float returnFloatValue(){
		return value;
	}

	/*
	 * Print function used for testing.
	 */
	virtual void print() const
		    {
		      cout << "Cellvalue!" << endl;
		    }

};

#endif
