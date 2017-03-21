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
	{
	
	
	}
	
	~CellValueBase(){
	
	}
	void setValue(T value){
		this.value = value; 
	}
	T getValue(){
		return value;
	}
	
	string returnInfo(){
		ostringstream os;
		os << value << endl;
		return os.str();
	}
	
	string returnValueEdit(){
		return typeid(T).name();
	}
	
	float returnValue(){
		return (float)value;
	}
	
}	
