#ifndef CELLVALUEBASE_H_
#define CELLVALUEBASE_H_

#include <string>

   
using namespace std;

/*
 * Header file for CellValueBase class.
 * Class for storing values of cells.
 */
class CellValueBase {
	
	public:

		CellValueBase() = default;

		virtual ~CellValueBase(void) = default;

		/*
		 *Returns the string of the cell used for drawing
		 *the spreadsheet.
		 */
		virtual string getString() = 0;


		/*
		 * Returns the value of the cell as float.
		 */
		virtual float getFloat() = 0;
		
		static CellValueBase* cellValueFactory(std::string str);

	
	private:

};
#endif
