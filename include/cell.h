#ifndef CELL_H_
#define CELL_H_

#include <memory>
#include <iostream>
#include "../include/cellvaluebase.h"
#include "../include/cellvalue.h"

template <typename T>
class Cell {

	public:

		Cell(Cell const &) = delete;
		Cell &operator=(Cell const &) = delete;

		Cell(){
		 value = nullptr;
		}
		
		~Cell(){

		}

		Cell &operator=(Cell const &&o){
			if (this != &o){
				value = std::move(o.value);
			}
			return *this;
		}

		void setValue(const T val){

			value.reset(new CellValue<T>(val));
		}

		T readStrValueDraw(){
			return value->returnInfo();
		}


		T readStrValueEdit(){
				return value->returnValueEdit();
			}


		T readFloatValue(){
				return value->returnFloatValue();
			}

		void emptyCell(){
			value.reset(nullptr);
		}

	private:
		std::unique_ptr<CellValueBase> value;
};

#endif
