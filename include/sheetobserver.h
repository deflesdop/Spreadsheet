#ifndef INCLUDE_SHEETOBSERVER_H_
#define INCLUDE_SHEETOBSERVER_H_

#include "sheet.h"


class SheetObserver{
	public:
	
		SheetObserver(){
		//	sheet = sheetref;
		//	sheet.addObserver(this);
		}
		
		
		~SheetObserver() = default;
		virtual void cellChanged();
	
	private:
		//Sheet& sheet;
};


#endif /* INCLUDE_SHEETOBSERVER_H_ */
