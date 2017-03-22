#include <iostream>
#include "../include/cell.h" 
#include <memory>

using namespace std;

template<typename T>
Cell<T>::Cell(){
 value = nullptr;
}

template<typename T>
unique_ptr<CellValueBase> Cell<T>::getValue(){
	return value;
}


template <typename T>
void Cell<T>::setValue(const T val){

}


template <typename T>
T Cell<T>::readValue(){

}


template <typename T>
void Cell<T>::emptyCell(){

}
