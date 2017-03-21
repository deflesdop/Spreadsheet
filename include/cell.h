#ifndef CELL_H_
#define CELL_H_
template <typename T>
class Cell {
	public:
		Cell();
		void setValue(const T value);
		T readValue();
		void emptyCell();
		
	private:
		unique_ptr<CellValueBase> value;
}
#endif
