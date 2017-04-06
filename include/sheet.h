/*
 * sheet.h
 *
 *  Created on: Mar 24, 2017
 *      Author: asch
 */

#ifndef INCLUDE_SHEET_H_
#define INCLUDE_SHEET_H_

#include "cell.h"
#include "column.h"
#include <iterator>

/*
 *Header file for Sheet class.
 *Class which holds a vector list of Column objects
 *to form a spreadsheet.
 */
class SheetIterator;
class Sheet{

	private:

	/*
	 * Vector list to store columns.
	 */
	std::vector<Column> sheet;

	/*
	 * Number of columns in the spreadsheet.
	 */
	const static int maxColumnNumber = 80;

	public:

	/*Constructor for the Sheet
	 *
	 ****************************
	 * Not working due to unique_ptr being copied somewhere
	 * TODO Fix call to copyconstructor
	 */
	Sheet();

	~Sheet() = default;

	Column& getColumn(int column);


	/*
	 * Returns the Cell pointer at a certain row.
	 * PARAMS int row, row of the column.
	 * 		  int column, columns of the sheet.
	 * *********
	 * TODO Not yet implemented.
	 */
	Cell& getCell(const int row, const int column);

	typedef SheetIterator iterator;

	/*
	 *
	 */
	SheetIterator begin(void);

	/*
	 *
	 */
	SheetIterator end(void);


};

class SheetIterator : public std::iterator<std::input_iterator_tag, int>
{
	private:
		Sheet &sheet;
		size_t offset;

	public:
		SheetIterator(Sheet &sheet, size_t offset)
			:sheet(sheet), offset(offset)
		{}

		bool operator==(const SheetIterator &iter) const
			{
		      return &iter.sheet == &sheet && iter.offset == offset;
		    }

		bool operator!=(const SheetIterator &iter) const
		    {
		      return !operator==(iter);
		    }

		Column &operator*() const
		    {
		     return sheet.getColumn(offset);
		    }

		Column *operator->() const
		    {
		     return &sheet.getColumn(offset);
		    }

		SheetIterator &operator++()
		    {
		      ++offset;
		      return *this;
		    }
};



#endif /* INCLUDE_SHEET_H_ */
