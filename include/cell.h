#ifndef CELL_H_
#define CELL_H_

#include <memory>
#include "../include/cellvaluebase.h"

template <typename T>
class Cell {

	public:
		Cell();
		void setValue(const T value);
		T readValue();
		void emptyCell();
		
	private:
		std::unique_ptr<CellValueBase> value;
};

#endif
