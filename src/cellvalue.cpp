/*
 * cellvalue.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: asch
 */
#include "../include/cellvalue.h"

template <>
float CellValue<string>::returnFloatValue()
{
	return 1;
}
