/*
 * range.h
 *
 *  Created on: Apr 11, 2017
 *      Author: asch
 */

#ifndef INCLUDE_RANGE_H_
#define INCLUDE_RANGE_H_

#include "celladdress.h"
#include "sheet.h"
class RangeIterator;
class Range{


	private:

		Sheet& sheetref;
		CellAddress beginAddress, endAddress;
		const char delim = ':';


	public:

		Range(Sheet &sheet);

		Range(Sheet &sheet, CellAddress begin, CellAddress end);

		RangeIterator begin();

		RangeIterator end();

		Range* makeRangeIt(Sheet sheet, RangeIterator begin, RangeIterator end);

		Range* makeRangeRef(Sheet sheet, std::string ref);

		CellAddress setCellAddress();




};

class RangeIterator : public std::iterator<std::input_iterator_tag, int>
{
	private:
	Sheet &sheet;
	int offsetX, offsetY;

	public:
		RangeIterator(Sheet &sheet, int offsetX, int offsetY)
			:sheet(sheet), offsetX(offsetX), offsetY(offsetY)
			{}

		bool operator==(const RangeIterator &iter) const
			{
			  return &iter.sheet == &sheet && iter.offsetX == offsetX && iter.offsetY == offsetY;
			}

		bool operator!=(const RangeIterator &iter) const
			{
			  return !operator==(iter);
			}

		Cell &operator*() const
			{
			 return sheet.getColumn(offsetX).getCell(offsetY);
			}

		Cell *operator->() const
			{
			 return &sheet.getColumn(offsetX).getCell(offsetY);
			}

		RangeIterator &operator++()
			{
			++offsetY;
			++offsetX;
			return *this;
			}
};

#endif /* INCLUDE_RANGE_H_ */
