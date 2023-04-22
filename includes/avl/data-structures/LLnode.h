/* *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= *
 |					               
 |        AUTHOR:     Aot Chanthorn		       
 |        CLASS :     CS_08		                
 | --------------------------------------------------------- +>
 |        File  :     LLnode.h 
 |        Desc  :     Header file for linked list node 			        
 |                    Contains _next and _prev ptr 
 |                                                                                                 	      	        
 * *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= */

#ifndef LLnode_H
#define LLnode_H

#include <iostream>
#include <sstream>

template <class T>
struct node{
	T item;
	node<T> * _prev;
	node<T> * _next;
	
	node() : item(T()), _prev(nullptr), _next(nullptr) {}
	node(T _item) : item(_item), _prev(nullptr), _next(nullptr) {}

	//turns node into string obj ed.
	std::string To_string(){
		std::string node_str;
		std::stringstream ss;
		ss<<"["<<item<<"]";
		ss>>node_str;
		
		return node_str;
	}

	//turns node into string *ptr ed.
	std::string To_ptr_string(){
		std::string node_str;
		std::stringstream ss;
		node<T> *curr = this;
		ss<<"["<<*(curr->item)<<"]";
		ss>>node_str;
		
		return node_str;
	}

	friend std::ostream& operator <<(std::ostream& outs, node<T> *&node ){
		outs << node->item ; 		
		return outs;		
	}

	friend std::ostream& operator <<(std::ostream& outs, node<T> &node ){
		outs << node.To_string();		
		return outs;		
	}
};

#endif


