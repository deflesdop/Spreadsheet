/*
 * range.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: asch
 */
#include "../include/range.h"

Range::Range(Sheet &sheet):
	sheetref(sheet)
{}

Range::Range(Sheet &sheet, CellAddress begin, CellAddress end):
	sheetref(sheet), beginAddress(begin), endAddress(end)
{}

RangeIterator Range::begin(){
	return RangeIterator(sheetref,beginAddress.getColNum(),beginAddress.getRowNum());
}

RangeIterator Range::end(){
	return RangeIterator(sheetref,endAddress.getColNum(),endAddress.getRowNum());
}

Range* Range::makeRangeIt(Sheet sheet, RangeIterator begin, RangeIterator end){
	CellAddress cellad;

	return new Range(sheet);
}

Range* Range::makeRangeRef(Sheet sheet, std::string ref){
	CellAddress begin, end;
	std::string add1, add2;

	add1 = ref.substr(0, ref.find(delim));
	add2 = ref.substr(1, ref.find(delim));

	try{
		begin.createFromReference(add1);
		end.createFromReference(add2);
	}
	catch(const char* msg){
		std::cerr << msg << std::endl;
	}

	return new Range(sheet,begin,end);

}
