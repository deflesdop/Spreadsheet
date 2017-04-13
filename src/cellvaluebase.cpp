#include <iostream>
#include "../include/cellvaluebase.h"
#include "../include/cellvalue.h"

#include <string>


CellValueBase* CellValueBase::cellValueFactory(std::string str){
	float f;
	CellValueBase* base;
	try{
		f = std::stof(str);
		base = new CellValue<float>(f);
		
	}
	catch(const std::invalid_argument& err){
		base = new CellValue<std::string>(str);
	}
	return base;
}

