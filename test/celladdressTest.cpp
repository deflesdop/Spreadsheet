/*
 * celladdressTest.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: asch
 */

#include "../include/celladdress.h"
#define BOOST_TEST_MODULE CellAddressTest
#include <boost/test/unit_test.hpp>
#include <string>
//TODO FIX THIS THING!!!
BOOST_AUTO_TEST_SUITE(celladdressTest)

BOOST_AUTO_TEST_CASE(celladdress_createFromReference){
	CellAddress celladdress;
	std::string str = "A1";
	celladdress.createFromReference(str);
	BOOST_CHECK_EQUAL(celladdress.getColNum(),0);
	BOOST_CHECK_EQUAL(celladdress.getRowNum(),0);
}












BOOST_AUTO_TEST_SUITE_END()
