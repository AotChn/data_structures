/* *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= *
 |					               
 |        AUTHOR:     Aot Chanthorn		       
 |        CLASS :     CS_08		                
 | --------------------------------------------------------- +>
 |        File  :     Queue.cpp 
 |        Desc  :     Header file for queue class 			        
 |                                                                                                 	      	        
 * *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= */

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

template<class T>
Queue<T>::Queue(){
	_front = nullptr;
	_rear = nullptr;
	_size = 0;
}

template <class T>
Queue<T>::Queue(const Queue<T>& copyMe){
	_rear = _copy_list(_front, copyMe._front);
	_size = copyMe._size;
}

template <class T>
Queue<T>::~Queue(){
	_clear_list(_front);
}

template <class T>
Queue<T>&  Queue<T>::operator=(const Queue<T>& RHS){
	_clear_list(_front);
	_rear = _copy_list(_front, RHS._front);
	_size = RHS._size;
	return *this;
}

template <class T>
bool Queue<T>::empty(){
	return _size == 0;
}

template <class T>
T Queue<T>::front(){
	return _front->item;
}

template <class T>
T Queue<T>::back(){
	return _rear->item;
}

template <class T>
void Queue<T>::push(T Item){
	if(_size == 0){
		_front = _insert_head(_front, Item);
		_rear = _front;
	}
	else{
		_rear = _insert_after(_front, _rear, Item);
	}
	_size++;
}

template <class T>
T Queue<T>::pop(){
	if(_size == 0){
		std::cout<<"warning: popping an empty queue";
		return T();
	}
	_size--;
	return _delete_node(_front, _front);	
}

template <class T>
std::string Queue<T>::to_str(){
	std::stringstream ss;
	std::string q_str;
	node<T> *curr;
	for(curr=_front; curr!=nullptr; curr=curr->_next){
		ss << *curr;
	}
	ss <<"[NULL]";
	ss >> q_str;
	return q_str;

}

template <class T>
void Queue<T>::print_pointers(){
	std::cout<<this->to_str();
}





 #endif
