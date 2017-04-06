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
	void Cell::setFloatValue(const float val){
		value.reset(new CellValue<float>(val));
	}

	/*
	 *Stores a new value in a cell.
	 *PARAMS string type, value to store.
	 */
	void Cell::setStringValue(const string val){
		value.reset(new CellValue<string>(val));
	}		
		
	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	string Cell::readStrValueDraw(){
		return value->returnInfo();
	}

	/*
	 * Returns the value of the cell as float.
	 */
	float Cell::readFloatValue(){
		return value->returnFloatValue();
	}

	/*
	 * Clears the value of the cell.
	 */
	void Cell::emptyCell(){
		value.reset(nullptr);
	}
