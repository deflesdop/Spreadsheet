/*
 * cellformula.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: asch
 */

#include <curses.h>
#include "../include/cellformula.h"
#include "../include/range.h"
#include "../include/celladdress.h"
#include "../include/sheet.h"
#include "../include/column.h"
#include "../include/sheetobserver.h" 


CellFormula::CellFormula(std::string formula, Sheet &sheetref):
	SheetObserver(sheetref), mode(-1), iterMode(-1),
	rawFormula(formula), sheetref(sheetref), sum(0), count(0), avg(0)
{}

bool CellFormula::validateFormula(std::string formula){
	int check1(0), check2(0), check3(0), check4(0);
	for(char c : formula){
		switch(c){
		case	'=':
			check1++;
			break;
		case	'(':
			check2++;
			break;
		case	')':
			check3++;
			break;
		case	':':
			check4++;
			break;
		default:
			break;
		}
	}
	if(check1 == 1 && check2 ==1 && check3 == 1 && check4 ==1)
		return true;
	else
		return false;
}

std::string CellFormula::parseFormula(std::string formula, std::string &cell1, std::string &cell2){
	if(validateFormula(formula)){
	std::string delimiter = "=():";
	std::vector<std::string> v ; //Use vector to add the words

	std::size_t prev_pos = 0, pos;
	while ((pos = formula.find_first_of(delimiter, prev_pos)) != std::string::npos)
	{
		if (pos > prev_pos)
			v.push_back(formula.substr(prev_pos, pos-prev_pos));
		prev_pos= pos+1;
	}
	if (prev_pos< formula.length())
		v.push_back(formula.substr(prev_pos, std::string::npos));
	cell1 = v[1];
	cell2 = v[2];
	return v[0];
	}
	else{
		return "ERR";
	}

}

	/*
	 *Returns the string of the cell used for drawing
	 *the spreadsheet.
	 */
	std::string CellFormula::getString(){
		if(errmsg == "ERR")
			return errmsg;
		else{
			switch(mode){
			case	0:
				return std::to_string(sum);
				//return str1;
			case	1:
				return std::to_string(count);
				//return "COUNT";
			case	2:
				avg = sum / count;
				return std::to_string(avg);
			default:
				return "ERR";
			}
		}
	}


	/*
	 * Returns the value of the cell as float.
	 */
	float CellFormula::getFloat(){
		return -9.f;
	}

	void CellFormula::createCellAddress(std::string str1, std::string str2){
		try{
			begin.createFromReference(str1), end.createFromReference(str2);
		}
		catch(const char* msg){
			errmsg = "ERR";
		}
	}

	void CellFormula::setMode(std::string str){
		if(str == "SUM"){
			mode = 0;
		}
		else if(str == "COUNT"){
			mode = 1;
		}
		else if(str == "AVG"){
			mode = 2;
		}
	}

	void CellFormula::iterateHori(CellAddress c1, CellAddress c2){
		int beginX = c1.getColNum(), endX = c2.getColNum(), i(0);
		int axisY = c1.getRowNum();
		for(Sheet::iterator sit = sheetref.begin(); sit != sheetref.end(); ++sit){
			if(i >= beginX && i <= endX){
				if(!sit->getCell(axisY).isEmpty())
					sum += sit->getCell(axisY).getFloat();
				count++;
			}
			i++;
		}
	}

	void CellFormula::iterateVert(CellAddress c1, CellAddress c2){
		int beginY = c1.getRowNum(), endY = c2.getRowNum(), i(0);
		int axisX = c1.getColNum();
		for(Column::iterator cit = sheetref.getColumn(axisX).begin();
				cit != sheetref.getColumn(axisX).end(); ++cit){
			if(i >= beginY && i <= endY){
				if(!cit->isEmpty())
					sum += cit->getFloat();
				count++;
			}
			i++;
		}
	}

	void CellFormula::iterateBlock(CellAddress c1, CellAddress c2){
		int beginY = c1.getRowNum(), endY = c2.getRowNum(), i(0);
		int beginX = c1.getColNum(), endX = c2.getColNum(), j(0);

		for(Sheet::iterator sit = sheetref.begin(); sit != sheetref.end(); ++sit){
			for(Column::iterator cit = sit->begin(); cit != sit->end(); ++cit){
				if((i >= beginY && i <= endY)&&(j >= beginX && j <= endX)){
					if(!cit->isEmpty())
						sum += cit->getFloat();
					count++;
					j++;
				}

			}
			j = 0;
			i++;
		}

	}

	void CellFormula::setIterMode(CellAddress c1, CellAddress c2){
		if(c1.getRowNum() == c2.getRowNum())
			iterMode = 0;
		else if(c1.getColNum() == c2.getColNum())
			iterMode = 1;
		else
			iterMode = 2;

	}

	void CellFormula::iterate(CellAddress c1, CellAddress c2){
		switch(iterMode){
		case	0:
				iterateHori(c1,c2);
				break;
		case	1:
				iterateVert(c1,c2);
				break;
		case	2:
				iterateBlock(c1,c2);
				break;
		default:
				break;
		}
	}

	void CellFormula::calculateFormula(){
		errmsg.clear();
		std::string s1, s2;
		setMode(parseFormula(rawFormula, s1, s2));
		createCellAddress(s1,s2);
		setIterMode(begin, end);
		if(errmsg != "ERR"){
			iterate(begin, end);
		}
	}
	
	bool CellFormula::recalculateNeeded(const Cell &cell){
		int beginY = begin.getRowNum(), endY = end.getRowNum(), i(0);
		int beginX = begin.getColNum(), endX = end.getColNum(), j(0);

		for(Sheet::iterator sit = sheetref.begin(); sit != sheetref.end(); ++sit){
			for(Column::iterator cit = sit->begin(); cit != sit->end(); ++cit){
				if((i >= beginY && i <= endY)&&(j >= beginX && j <= endX)){
					if((i >= beginY && i < endY)&&(j >= beginX && j < endX)){
						if(*cit == cell)
							return true;
						}
					j++;
				}
			}
			j = 0;
			i++;
				}
		return false;
	}

	void CellFormula::cellChanged(const Cell &cell){
			if(recalculateNeeded(cell))
				iterate(begin, end);
	}
