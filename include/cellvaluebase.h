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

};
#endif
