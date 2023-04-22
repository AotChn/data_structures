/* *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= *
 |					               
 |        AUTHOR:     Aot Chanthorn		       
 |        CLASS :     CS_08		                
 | --------------------------------------------------------- +>
 |        File  :     linked-list.cpp 
 |        Desc  :     Definition file for low level linked-list 
 |					  Functions                    

 * *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= */

#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "linked-list.h"
#include <sstream>
#include <string>
#include <iostream>

//===========================================
// IO
//===========================================

template <class T>
void _print_list(node<T> *head){
	std::cout<<LL_to_string(head);
}

template <class T>
void _print_listbackwards(node<T> *head){
	//not fun 
}

template <class T>
std::string LL_to_string(node<T> *head){
	std::stringstream ss;
	std::string list="";
	for(node<T> *curr=head; curr!=nullptr; curr=curr->_next){
		ss << *curr;
	}
	ss << "[NULL]";
	ss >> list;
	
	return list;
}

//===========================================
// SEARCH
//===========================================

template <class T>
node<T> *_search_list(node<T> *head, T key){
	for(node<T> *curr=head; curr!=nullptr; curr=curr->_next){
		if(curr->item == key){
			return curr;
		}
	}

	return nullptr;
}

template <class T>
T& _at(node<T> *head, int pos){
	node<T> *curr;
	for(int i=0; i<pos; i++){
		curr=curr->_next;
	}

	return *curr;
}

template <class T>
node<T> *_previous_node(node<T> *prev_to_this){
	return prev_to_this->_prev;
}

//===========================================
// INSERTION
//===========================================

template <class T>
node<T> *_insert_head(node<T> *&head, T insert_this){
	node<T> *n = new node<T>(insert_this);
	if(head == nullptr){
		head = n;
	}
	else{
		n->_next = head;
		head = n;
	}

	return head;

}

template <class T>
node<T> *_insert_after(node<T> *&head, node<T> *after_this, T insert_this){
	node<T> *n = new node<T>(insert_this);
	if(after_this == nullptr){
		n = _insert_head(head, insert_this);
	}
	n->_next = after_this->_next;
	after_this->_next = n;
	n->_prev = after_this;

	return n;
}

template <class T>
node<T> *_insert_before(node<T> *&head, node<T> *before_this, T insert_this){
	node<T> *n = new node<T>(insert_this);
	if(before_this->_prev == nullptr){
		n = _insert_head(head, insert_this);
	}
	else{
		n->_prev = before_this->_prev;
		n = _insert_head(before_this->_prev, insert_this);
	}

	return n;
}

//===========================================
// COPY / DELETE
//===========================================

template <class T>
T _delete_node(node<T> *&head, node<T> *delete_this){
	T popped;
	if(head == delete_this){
		head = delete_this->_next;
		popped = delete_this->item;
	delete delete_this;
	
	return popped;
	}
	node<T>* _prev = _previous_node(delete_this);
	_prev->_next = delete_this->_next;
	popped = delete_this->item;
	delete delete_this;

	return popped;
}

template <class T>
node<T> * _copy_list(node<T> *head){
	node<T> * wlk = head;
	node<T> * cpy = nullptr;
	node<T> * tail = nullptr;
	while(wlk != nullptr){
		if(cpy == nullptr){
			cpy = new node<T>;
			cpy->item = wlk->item;
			cpy->_next = nullptr; 
			tail = cpy;
		}
		else{
			tail->_next = new node<T>;
			tail = tail->_next;
			tail->item = wlk->item;
			tail->_next = nullptr;
		}
		wlk = wlk->_next;
	}
	return cpy;
}

template <class T>
node<T> * _copy_list(node<T> *&dest, node<T> *src){	
	node<T> * wlk = src;
	node<T> * cpy = nullptr;
	node<T> * tail = nullptr;
	while(wlk != nullptr){
		if(cpy == nullptr){
			cpy = new node<T>;
			cpy->item = wlk->item;
			cpy->_next = nullptr; 
			tail = cpy;
		}
		else{
			tail->_next = new node<T>;
			tail = tail->_next;
			tail->item = wlk->item;
			tail->_next = nullptr;
		}
		wlk = wlk->_next;
	}
	dest = cpy;
	return tail;
}

template <class T>
void _clear_list(node<T> *&head){
	while(head != nullptr){
		_delete_node(head, head);
	}
}


#endif

