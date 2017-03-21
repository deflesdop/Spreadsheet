#ifndef CELLVALUEBASE_H_
#define CELLVALUEBASE_H_
template <typename T>
class CellValueBase {
	public:
		CellValueBase();
		virtual ~CellValueBase();
		virtual string returnInfo();
		virtual string returnValueEdit();
		virtual float returnValue();
	private:
	
}
#endif
