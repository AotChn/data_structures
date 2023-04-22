/* *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= *
 |					               
 |        AUTHOR:     Aot Chanthorn		       
 |        CLASS :     CS_08		                
 | --------------------------------------------------------- +>
 |        File  :     Queue.h 
 |        Desc  :     Header file for Queue class 			        
 |                    
 |                                                                                                 	      	        
 * *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= */

#ifndef QUEUE_H
#define QUEUE_H

#include "linked-list.h"



template <class T>
class Queue{
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
	return temp;
}

private:
node<T> *_ptr;
};

	Queue();

//===========================================
// BIG THREE
//===========================================
    ~Queue();
    Queue(const Queue<T>& copyMe);
    Queue& operator=(const Queue<T>& RHS);

//===========================================
// INFO
//===========================================
    T back();
    T front();
    bool empty();
    int size() const { return _size; }
    Queue<T>::Iterator begin() const{Queue<T>::Iterator it(_front); return it;}
    Queue<T>::Iterator end() const{Queue<T>::Iterator it(nullptr); return it;}

//===========================================
// PUSH/POP
//===========================================
    void push(T Item);
    T pop();
	
//===========================================
// IO
//===========================================
	std::string to_str();
    void print_pointers();
    
	template<typename TT>
    friend std:: ostream& operator << (std::ostream& outs, Queue<TT>& printMe){
		outs << printMe.to_str();
		return outs;
	}
    
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};


#include "Queue.cpp"

#endif



