#ifndef AVL_CPP
#define AVL_CPP

#include "avl.h"

template <class T>
AVL<T>::AVL(){
    _root = nullptr;
}

template <class T>
AVL<T>::AVL(const T *list, int size){
    _root = nullptr;
    avl_tree_from_sorted(list, size, _root);
}
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template <class T>
AVL<T>::AVL(const AVL<T> &copy_me){
    _root = tree_copy(copy_me._root);
}

template <class T>
AVL<T>& AVL<T>::operator=(const AVL<T> &rhs){
    tree_clear(_root);
    _root = tree_copy(rhs._root);
}

template <class T>
AVL<T>::~AVL(){
    clear_all();
}
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template <class T>
bool AVL<T>::insert(const T &insert_me){
    return avl_tree_insert(_root, insert_me, 1);
}

template <class T>
bool AVL<T>::erase(const T &target){
    return avl_tree_erase(_root, target);
}

template <class T>
bool AVL<T>::contains(const T &target) const{
    return tree_search(_root, target);
}

template <class T>
void AVL<T>::clear(){
    clear_all();
}

template <class T>
void AVL<T>::clear_all(){
    tree_clear(_root);
    _root = nullptr;
}

template <class T>
bool AVL<T>::empty()const{
    return _root == nullptr;
}

template <class T>
std::string AVL<T>::pre_order() const{
    return pre_order_string(_root);
}

template <class T>
std::string AVL<T>::in_order() const{
    return in_order_string(_root);
}

template <class T>
std::string AVL<T>::post_order() const{
    return post_order_string(_root);
}

template <class T>
bool AVL<T>::search(const T &target, tree_node<T> *&found_ptr) const{
    found_ptr = tree_search(_root, target);
    return found_ptr != nullptr;
}

template <class T>
void AVL<T>::output_inorder(std::ostream &outs){
    outs << in_order_string(_root);
}

template <class T>
AVL<T>& AVL<T>::operator+=(const AVL<T> &rhs){
    avl_add(rhs._root, _root);
    return *this;
}


#endif