/*
 * column.h
 *
 *  Created on: Mar 23, 2017
 *      Author: asch
 */

#ifndef INCLUDE_COLUMN_H_
#define INCLUDE_COLUMN_H_

#include <vector>
#include "cell.h"
#include <iterator>
using namespace std;

/*
 * Header file for the Column class.
 * This class stores Cell objects in a vector
 * list to form a column.
 */
class ColIterator;

class Column {


	private:

	/*
	 * Number of rows in the spreadsheet.
	 */
	const int maxNumberCells = 24;

	/*
	 * Vector list of Cells.
	 */
	vector<Cell*> column;

	public:

	/*Constructor for the columns
	 *
	 ****************************
	 * Not working due to unique_ptr being copied somewhere
	 * TODO Fix call to copyconstructor
	 */
	Column(void);


	~Column(void) = default;

	/*
//	 * Returns the Cell pointer at a certain row.
	 * PARAMS int row, row of the column.
	 */
	Cell* getCell(const int row);

	typedef ColIterator iterator;

	/*
	 *
	 */
	ColIterator begin(void);

	/*
	 *
	 */
	ColIterator end(void);

};


class ColIterator : public std::iterator<std::input_iterator_tag, int>
{
	private:
		Column &col;
		size_t offset;

	public:
		ColIterator(Column &col, size_t offset)
			:col(col), offset(offset)
		{}

		bool operator==(const ColIterator &iter) const
			{
		      return &iter.col == &col && iter.offset == offset;
		    }

		bool operator!=(const ColIterator &iter) const
		    {
		      return !operator==(iter);
		    }

		Cell* &operator*() const
		    {
		     // return col.getCell(offset);
		    }

		Cell* *operator->() const
		    {
		     // return &col.getCell(offset);
		    }

		ColIterator &operator++()
		    {
		      ++offset;
		      return *this;
		    }
};

#endif /* INCLUDE_COLUMN_H_ */
