#ifndef CELLVALUE_H_
#define CELLVALUE_H_

#include <string>
#include <sstream>
using namespace std;

template<typename T>
class CellValue final : public CellValueBase
{
	private: 
		T value;
		
	public:
	CellValue(T initial_value)
		:CellValueBase(), value(initial_value)
	{}
	
	virtual ~CellValue(){

	}
	
	virtual string returnInfo(){
		stringstream os;
		os << value << endl;
		return os.str();
	}
	
	virtual string returnValueEdit(){
		return "";
	}
	
	virtual float returnFloatValue(){
		return value;
	}

	virtual void print() const
		    {
		      cout << "Cellvalue!" << endl;
		    }

};

#endif
