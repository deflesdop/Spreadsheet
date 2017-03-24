#ifndef CELLVALUEBASE_H_
#define CELLVALUEBASE_H_

#include <string>
using namespace std;

class CellValueBase {

	public:

		CellValueBase();

		virtual ~CellValueBase(void){
		}

		virtual string returnInfo(){
			return "WRONG";
		}

		virtual string returnValueEdit(){
			return "WRONG";
		}

		virtual float returnFValue(){
			return 9.6;
		}

		virtual void print() const
		    {
		      cout << "CellValueBase!" << endl;
		    }


	private:
	
};
#endif
