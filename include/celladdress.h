/*
 * celladdress.h
 *
 *  Created on: Apr 6, 2017
 *      Author: asch
 */

#ifndef INCLUDE_CELLADDRESS_H_
#define INCLUDE_CELLADDRESS_H_

#include <string>

class CellAddress{


	private:
	const int MaxCol = 80;
	const int MaxRol = 24;
	int rowNum, colNum;

	/*
	 * Converts a column reference to a column number.
	 */
	int convertColNameToColNum(std::string &cellref);

	/*
	 * Converts a column number to a column reference.
	 */
	std::string convertColNumToColName(int colNum);

	/*
	 * Converts a row number to a row sheet number.
	 */
	int convertRowNumToRowSheet(int rowNum);

	/*
	 * Converts a row sheet number to a row number.
	 */
	int convertRowSheetToRowNum(int rowSheet);


	public:

	/*
	 * Constructor for the CellAddress class.
	 */
	CellAddress();

	/*
	 * Constructor for the cellAddress class which instantiates
	 * a CellAddress with a celreference
	 */
	CellAddress(std::string &ref);

	/*
	 * Instantiates a CellAddress from a cellreference.
	 */
	void createFromReference(std::string &cellref);

	/*
	 * Returns the row number of the cell.
	 */
	int getRowNum();

	/*
	 * Sets the row number of the cell.
	 */
	void setRowNum(int row);

	/*
	 * Sets the column number of the cell.
	 */
	void setColNum(int col);

	/*
	 * Returns the column number of the cell.
	 */
	int getColNum();



};



#endif /* INCLUDE_CELLADDRESS_H_ */
