#ifndef CELLVALUEBASE_H_
#define CELLVALUEBASE_H_

#include <string>
using namespace std;

class CellValueBase {

	public:

		CellValueBase();

		virtual ~CellValueBase(){

		}

		virtual string returnInfo(){
			return "WRONG";
		}

		virtual string returnValueEdit(){
			return "WRONG";
		}

		virtual float returnValue(){
			return -9.6;
		}


	private:
	
};
#endif
