/* *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= *
 |					               
 |        AUTHOR:     Aot Chanthorn		       
 |        CLASS :     CS_08		                
 | --------------------------------------------------------- +>
 |        File  :     stack.cpp 
 |        Desc  :     Definition file for linked list node 			        
 |                                                                                                 	      	        
 * *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= */

#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"

template <class T>
Stack<T>::Stack(){
	_top = nullptr;
	_size = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& copyMe){
	_top = _copy_list(copyMe._top);
	_size = copyMe._size;
}

template <class T>
Stack<T>::~Stack(){
	_clear_list(_top);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& RHS){
	_clear_list(_top);
	_top = _copy_list(RHS._top);
	_size = RHS._size;
	return *this;
}

template <class T>
T Stack<T>::top(){
	return _top->item;
}

template <class T>
bool Stack<T>::empty(){
	return _size == 0;
}

template <class T>
void Stack<T>::push(T item){
	_top = _insert_head(_top, item);
	_size++;
}

template <class T>
T Stack<T>::pop(){
	if(_size == 0){
		std::cout<< "warning: popping an empty stack";
		return T();
	}
	_size--;
	return _delete_node(_top, _top);
}

template <class T>
std::string Stack<T>::to_str(){
	std::stringstream ss;
	std::string stack;
	for(node<T> *curr=_top; curr!=nullptr; curr=curr->_next){
		ss << *curr;
	}
	ss << "[NULL]";
	ss >> stack;
	return stack;
}

template <class T>
void Stack<T>::print(){
	std::cout<< this->to_str();
}

#endif

