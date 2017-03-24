#ifndef CELLVALUEBASE_H_
#define CELLVALUEBASE_H_

#include <string>
using namespace std;

/*
 * Header file for CellValueBase class.
 * Class for storing values of cells.
 */
class CellValueBase {

	private:

	public:

		CellValueBase();

		virtual ~CellValueBase(void){
		}

		/*
		 *Returns the string of the cell used for drawing
		 *the spreadsheet.
		 */
		virtual string returnInfo(){
			return "WRONG";
		}

		/*
		 * Returns the string of the cell used for editing
		 * values.
		 */
		virtual string returnValueEdit(){
			return "WRONG";
		}

		/*
		 * Returns the value of the cell as float.
		 */
		virtual float returnFloatValue(){
			return 9.6;
		}

		/*
		 * Print function used for testing.
		 */
		virtual void print() const
		    {
		      cout << "CellValueBase!" << endl;
		    }

};
#endif
