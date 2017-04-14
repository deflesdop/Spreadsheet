#ifndef INCLUDE_SHEETOBSERVER_H_
#define INCLUDE_SHEETOBSERVER_H_

#include "sheet.h"


class SheetObserver{
	public:
	
		SheetObserver(Sheet &sheet){
			sheet.addObserver(this);
		}
		
		
		virtual ~SheetObserver() = default;
		virtual void cellChanged(const Cell &cell) = 0;
	
	private:

};


#endif /* INCLUDE_SHEETOBSERVER_H_ */
