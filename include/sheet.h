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
#include <vector>
#include "sheetobserver.h"
#include "cellvaluebase.h"
#include <string>

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
	
	std::vector<SheetObserver*> observer;
	
	void addObserver(SheetObserver* sheetobs);

	public:

	Sheet();

	~Sheet() = default;

	Column& getColumn(int column);

	Cell& getCell(const int row, const int column);
	
	void setFloat(const float val, int row, int column);
	
	void setString(const std::string val, int row, int column);
	
	void setCellValue(CellValueBase* base, int row, int column);
	
	void notify();

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
