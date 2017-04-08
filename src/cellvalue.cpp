/*
 * cellvalue.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: asch
 */
#include "../include/cellvalue.h"

template <>
float CellValue<string>::getFloat()
{
	return 1;
}
