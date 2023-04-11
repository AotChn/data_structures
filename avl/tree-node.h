#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>

template <typename T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;

    friend int balance_factor(tree_node<T> * root){
        if(root == nullptr){
            return 0;
        }
        int left = get_height(root->_left);
        int right = get_height(root->_right);
        
        return right - left;
    }

    friend int get_height(tree_node<T>* root){
        if(root == nullptr){
            return -1;
        }

        return root->_height;
    }
    
    int height(){
        int left = get_height(_left);
        int right = get_height(_right);
        int height = 1 + std::max(left, right); 

        return height;
    }
    
    int update_height(){
        _height = height();

        return _height;
    }

    tree_node(T item=T(), tree_node* left=nullptr, 
                          tree_node* right=nullptr, int height=0):
                        _item(item), _left(left), _right(right), _height(height){}

    friend std::ostream& operator <<(std::ostream& outs, 
                                const tree_node<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
        
        return outs;
    }

    std::string get_str(tree_node<T>& node){
        std::stringstream ss;
        std::string s;
        ss << "[" << node._item << "]";
        ss >> s;
        
        return s;
    }

    void print(){
        std::cout<<get_str();
    }

};


#endif


