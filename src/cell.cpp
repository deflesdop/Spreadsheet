#include <iostream>
#include "../include/cell.h"
#include "../include/cellvalue.h"
#include <memory>

using namespace std;

	/*
	 * Cell constructor.
	 */
	Cell::Cell():
	 value(nullptr)
	{}
		
//	/*
//	 * Cell destructor.
//	 */
//	Cell::~Cell(){
//
//	}

	/*
	 *Stores a new value in a cell.
	 *PARAMS float type, value to store.
	 */
	void Cell::setFloat(const float val){
		value.reset(new CellValue<float>(val));
	}

	/*
	 *Stores a new value in a cell.
	 *PARAMS string type, value to store.
	 */
	void Cell::setString(const string val){
		value.reset(new CellValue<string>(val));
	}		
		
	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	string Cell::getString(){
		return value->getString();
	}

	/*
	 * Returns the value of the cell as float.
	 */
	float Cell::getFloat(){
		return value->getFloat();
	}

	/*
	 *Returns the CellAddress of the cell.
	 */
	CellAddress Cell::getCellAddress(){
		return address;
	}

	/*
	 * Clears the value of the cell.
	 */
	void Cell::empty(){
		value.reset(nullptr);
	}
