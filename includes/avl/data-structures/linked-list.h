/* *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= *
 |					               
 |        AUTHOR:     Aot Chanthorn		       
 |        CLASS :     CS_08		                
 | --------------------------------------------------------- +>
 |        File  :     linked-list.h 
 |        Desc  :     Header file for low level linked list
 |                    functions 
 |                                                                                                 	      	        
 * *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "LLnode.h"

#include <iostream>
#include <sstream>

//===========================================
// IO
//===========================================

template <class T>
void _print_list(node<T> *head);

template <class T>
void _print_listbackwards(node<T> *head);

//turns linked list into string
template <class T>
std::string LL_to_string(node<T> *head);

//===========================================
// SEARCH
//===========================================
template <class T>
node<T> *_search_list(node<T> *head, T key);

template <class T>
node<T> *_previous_node(node<T> *prev_to_this);

//return item at pos node
template <class T>
T& _at(node<T>* head, int pos);

//===========================================
// INSERTION
//===========================================

template <class T>
node<T> *_insert_head(node<T> *&head, T insert_this);

template <class T>
node<T> *_insert_after(node<T> *&head, node<T> *after_this, T insert_this);

template <class T>
node<T> *_insert_before(node<T> *&head, node<T> *before_this, T insert_this);

//===========================================
// COPY / DELETE
//===========================================

template <class T>
T _delete_node(node<T> *&head, node<T> *delete_this);

//copy list and return head
template <class T>
node<T> * _copy_list(node<T> *head);

//copy list and return rear
template <class T>
node<T> * _copy_list(node<T> *&dest, node<T> *src);

template <class T>
void _clear_list(node<T> *&head);


#include "linked-list.cpp"

#endif
