#ifndef INCLUDE_SHEETOBSERVER_H_
#define INCLUDE_SHEETOBSERVER_H_

#include "sheet.h"
#include <curses.h>


class SheetObserver{

	friend class Sheet;
	
	public:

		SheetObserver(){}
		
		~SheetObserver(){}



		virtual void cellChanged(const Cell &cell) = 0;
	
	private:

};


#endif /* INCLUDE_SHEETOBSERVER_H_ */
