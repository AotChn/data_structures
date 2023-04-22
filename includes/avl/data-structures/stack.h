/* *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= *
 |					               
 |        AUTHOR:     Aot Chanthorn		       
 |        CLASS :     CS_08		                
 | --------------------------------------------------------- +>
 |        File  :     stack.h 
 |        Desc  :     Header file for Stack class 			        
 |                    
 |                                                                                                 	      	        
 * *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= */

#ifndef STACK_H
#define STACK_H

#include <sstream>
#include <string>

#include "linked-list.h"


template <class T>
class Stack{
public:
	class Iterator{

public:
Iterator(){_ptr = nullptr;}                  

Iterator(node<T> *p) {_ptr = p;}

T& operator*(){
	return _ptr->item;
}                             

T* operator->(){
	return &_ptr->item;
}                           

operator bool(){
	if(_ptr != nullptr){
		return true;
	}
	return false;
}

bool is_null(){
	if(_ptr == nullptr){
		return true;
	}

	return false;
}                           

friend bool operator!=(const Iterator &left, const Iterator &right){
	if(left._ptr != right._ptr){
		return true;
	}
	
	return false;
} 

friend bool operator==(const Iterator &left, const Iterator &right){
	if(left._ptr == right._ptr){
		return true;
	}
	
	return false;
} 

Iterator &operator++(){
	this->_ptr = this->_ptr->_next;
	return *this;
}                        

friend Iterator &operator++(Iterator &it,int unused){
	Iterator temp = it;
	++(it);
	return it;
}

Iterator &operator--(){
	this->_ptr = this->_ptr->_prev;
}

friend Iterator &operator--(Iterator &it, int unused){
	Iterator temp = it;
	--(it);
	return it;
}

private:
node<T> *_ptr;
};
	Stack();
    Stack(const Stack<T>& copyMe);
    
	~Stack();
    Stack<T>& operator=(const Stack<T>& RHS);
    
	T top();
    bool empty();
    
	void push(T item);
    T pop();
    
    
	Stack<T>::Iterator begin() const{ Stack<T>::Iterator it(_top); return it;}           
    Stack<T>::Iterator end() const{ Stack<T>::Iterator it(nullptr); return it;}           
    int size() const { return _size; }

	std::string to_str();
	void print();
	
	template <class TT>
    friend std::ostream& operator<<(std::ostream& outs, Stack<TT>& printMe){
		outs << printMe.to_str();
		return outs;
	}

private:
    node<T>* _top;
    int _size;

};

#include "iterator.h"
#include "stack.cpp"

#endif

