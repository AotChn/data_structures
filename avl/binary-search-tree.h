#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/* *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= *
 |					               
 |        AUTHOR:     Aot Chanthorn		       
 |        CLASS :     CS_08		                
 | --------------------------------------------------------- +>
 |        File  :     LLnode.h 
 |        Desc  :     Header file for linked list node 			        
 |                    Contains next and prev ptr 
 |                                                                                                 	      	        
 * *=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+=*=+= */

#include "tree-node.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

//===========================================
// INSERTION
//===========================================
template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me);

template <typename T>
void avl_tree_insert(tree_node<T>* &root, const T& insert_me);

template <typename T> //tells us if we added something new (true)
bool avl_tree_insert(tree_node<T>* &root, const T& insert_me, int n);

//===========================================
// SEARCH
//===========================================

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target);

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr);

//===========================================
// IO
//===========================================

template<typename T> //reverse in_order
void tree_print(tree_node<T>* root, int depth=0,
                                    std::ostream& outs=std::cout, int order = 1);

template<typename T> //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int depth=0,
                                          std::ostream& outs=std::cout);

template <typename T> //print in_order
void in_order(tree_node<T>* root,std::ostream& outs=std::cout);

template <typename T> //print pre_order
void  pre_order(tree_node<T>* root, std::ostream& outs=std::cout);

template <typename T> //print post_order
void  post_order(tree_node<T>* root, std::ostream& outs=std::cout);

template <typename T> //string in_order
std::string in_order_string(tree_node<T>* root);

template <typename T> //string pre_order
std::string pre_order_string(tree_node<T>* root);

template <typename T> //string post_order
std::string post_order_string(tree_node<T>* root);

//===========================================
// DELETION
//===========================================

template <typename T> //clear the tree
void tree_clear(tree_node<T>* &root);

template <typename T> //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target);

template <typename T> //erase target from the tree
bool avl_tree_erase(tree_node<T>*& root, const T& target);

template <typename T> //erase rightmost node from the tree -> max_value
void tree_remove_max(tree_node<T>* &root, T& max_value);

//===========================================
// COPY
//===========================================

template <typename T> //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root);

template <typename T> //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src);

//===========================================
// SORTED ARRAY -> TREE
//===========================================

template <typename T> //sorted array of ints -> tree
tree_node<T>* tree_from_sorted_list(const T* a);

template <typename T> // uses left and right (BST)
tree_node<T>* tree_from_sorted(int left, int right, const T* a);

template <typename T> // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size);

template <typename T> 
void avl_tree_from_sorted(const T* a, int size, tree_node<T>* &root);

//===========================================
// ROTATIONS
//===========================================

template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root);
template <typename T> 
tree_node<T>* rotate_left(tree_node<T>* &root);
template <typename T>
tree_node<T>* rotate(tree_node<T>* & root); //decide which rotate is needed based on balance factor
//4 cases

template <typename T>
void avl_tree_insert(tree_node<T>* &root, const T& insert_me);

#include "binary-search-tree.cpp"
#endif