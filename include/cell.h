#ifndef CELL_H_
#define CELL_H_

#include <memory>
#include <iostream>
#include "../include/cellvaluebase.h"
#include "../include/cellvalue.h"

template <typename T>
class Cell {

	public:
		Cell(){
		 value = nullptr;
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

		T readFValue(){
				return value->returnFValue();
			}

		void emptyCell(){
			value.reset(nullptr);
		}

	private:
		std::unique_ptr<CellValueBase> value;
};

#endif
