#ifndef CELL_H_
#define CELL_H_

#include <memory>
#include <iostream>
#include "../include/cellvaluebase.h"
#include "../include/cellvalue.h"

/*
 * Header file for the Cell class.
 * This object stores a template object.
 * The value is stored in CellValue and is accessible through a unique pointer.
 */

template <typename T>
class Cell {

	private:

	/*
	 * Unique pointer to a CellValueBase.
	 */
	std::unique_ptr<CellValueBase> value;

	public:


		Cell(Cell const &) = delete;
		Cell &operator=(Cell const &) = delete;

		/*
		 * Cell constructor.
		 */
		Cell(){
		 value = nullptr;
		}
		
		/*
		 * Cell destructor.
		 */
		~Cell(){

		}

		/*
		 * = overload for assigning pointers.
		 */
		Cell &operator=(Cell const &&o){
			if (this != &o){
				value = std::move(o.value);
			}
			return *this;
		}

		/*
		 *Stores a new value in a cell.
		 *PARAMS T type, value to store.
		 */
		void setValue(const T val){
			value.reset(new CellValue<T>(val));
		}

		/*
		 *Returns the string of the cell used for drawing
		 *the spreadsheet.
		 */
		T readStrValueDraw(){
			return value->returnInfo();
		}

		/*
		 * Returns the string of the cell used for editing
		 * values.
		 */
		T readStrValueEdit(){
				return value->returnValueEdit();
		}

		/*
		 * Returns the value of the cell as float.
		 */
		T readFloatValue(){
				return value->returnFloatValue();
		}

		/*
		 * Clears the value of the cell.
		 */
		void emptyCell(){
			value.reset(nullptr);
		}


};

#endif
