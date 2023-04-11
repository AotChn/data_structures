#ifndef AVL_H
#define AVL_H

#include "binary-search-tree.h"
#include "tree-node.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

// #define tree_print tree_print_debug
template <typename T>
class AVL{
public:
    AVL();
    AVL(const T *list, int size = -1);
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    AVL(const AVL<T> &copy_me);
    AVL<T> &operator=(const AVL<T> &rhs);
    ~AVL();
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    bool insert(const T &insert_me);
    bool erase(const T &target);

    bool contains(const T &target) const;

    void clear();
    void clear_all();
    bool empty()const
    ;
    std::string pre_order() const;
    std::string in_order() const;
    std::string post_order() const;

    bool search(const T &target, tree_node<T> *&found_ptr) const;

    void output_inorder(std::ostream &outs);

    friend std::ostream& operator <<(std::ostream& outs, const AVL<T>& tree){
        tree_print(tree._root, 0, outs);
        return outs;
    }
    AVL<T> &operator+=(const AVL<T> &rhs);

private:

    tree_node<T>* _root;
};

#include "avl.cpp"

#endif