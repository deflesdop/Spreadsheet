#ifndef INCLUDE_SHEETOBSERVER_H_
#define INCLUDE_SHEETOBSERVER_H_

#include "sheet.h"


class SheetObserver{
	public:
	
		SheetObserver(Sheet &sheet){
			sheet.addObserver(this);

		}
		
		
		virtual ~SheetObserver() = default;
		virtual void cellChanged() = 0;
	
	private:

};


#endif /* INCLUDE_SHEETOBSERVER_H_ */
