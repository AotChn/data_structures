#ifndef BINARY_SEARCH_TREE_CPP
#define BINARY_SEARCH_TREE_CPP

#include "binary-search-tree.h"

//===========================================
// INSERTION
//===========================================
template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me){
    if(root == nullptr){
        root = new tree_node<T>(insert_me);
    }
    if(root->_item == insert_me){
        return;
    }
    else if(root->_item > insert_me){
        tree_insert(root->_left, insert_me);
    }
    else{
        tree_insert(root->_right, insert_me);
    }
    root->update_height();
}

template <typename T>
void avl_tree_insert(tree_node<T>* &root, const T& insert_me){
    if(root == nullptr){
        root = new tree_node<T>(insert_me);
    }
    else if(root->_item == insert_me){
        return;
    }
    else if(root->_item > insert_me){
        avl_tree_insert(root->_left, insert_me);
        root->update_height();
        root = rotate(root);
    }
    else{
        avl_tree_insert(root->_right, insert_me);
        root->update_height();
        root = rotate(root);
    }
    root->update_height();
    root = rotate(root);

}

template <typename T>
bool avl_tree_insert(tree_node<T>* &root, const T& insert_me, int n){
    if(root == nullptr){
        root = new tree_node<T>(insert_me);
    }
    else if(root->_item == insert_me){
        return false;
    }
    else if(root->_item > insert_me){
        return avl_tree_insert(root->_left, insert_me, 1);
        root->update_height();
        root = rotate(root);
    }
    else{
        return avl_tree_insert(root->_right, insert_me, 1);
        root->update_height();
        root = rotate(root);
    }
    root->update_height();
    root = rotate(root);

    return true;

}

//===========================================
// SEARCH
//===========================================

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target){
    if(root == nullptr)
        return nullptr;
    if(root->_item == target)
        return root;
    if(root->_item > target)
        return tree_search(root->_left, target);
    else
        return tree_search(root->_right, target);
}

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr){
    found_ptr = tree_search(root, target);
    return found_ptr != nullptr;
}

//===========================================
// IO
//===========================================

template<typename T>
void tree_print(tree_node<T>* root, int depth,
                                    std::ostream& outs, int order){
    if(root != nullptr){
        tree_print(root->_right, depth+1);
        std::cout<< std::setw(9*depth)<< "[" << root->_item <<"]";
        std::cout<<std::endl;
        tree_print(root->_left, depth+1);
    }

}

template<typename T> //prints details info about each node
void tree_print_debug(tree_node<T>* root, int depth,
                                          std::ostream&){
    if(root != nullptr){
        tree_print_debug(root->_right, depth+1);
        std::cout<< std::setw(10*depth)<< "[" << root->_item <<"]"<< "|H: "<<root->_height <<
        " BF: "<<balance_factor(root);
        std::cout<<std::endl;
        tree_print_debug(root->_left, depth+1);
    }

}

template <typename T> //print in_order
void in_order(tree_node<T>* root,std::ostream& outs){
    if(root == nullptr){}
    else{
        in_order(root->_left);
        std::cout<< "[" << to_string(root->_item) <<"   -]";
        in_order(root->_right);
        std::cout<<"ss";
    }
}

template <typename T> //print pre_order
void  pre_order(tree_node<T>* root, std::ostream& outs){
    if(root == nullptr){}
    else{
        std::cout<<"[" << root->_item <<"]";
        pre_order(root->_left);
        pre_order(root->_right);
        std::cout<<"ss";
    }
}

template <typename T> //print post_order
void  post_order(tree_node<T>* root, std::ostream& outs){
    if(root == nullptr){}
    else{
        post_order(root->_left);
        post_order(root->_right);
        std::cout<<"["<< root->_item <<"]";
        std::cout<<"s";
    }
}

template <typename T> //string in_order
std::string in_order_string(tree_node<T>* root){
    std::stringstream ss;
    std::string s;
    if(root == nullptr){}
    else{
        s += in_order_string(root->_left);
        s += "[";
        s += to_string(root->_item);
        s += "]";
        s += in_order_string(root->_right);
    }
    // ss >> s;
    return s;
}

template <typename T> //string pre_order
std::string pre_order_string(tree_node<T>* root){
    std::stringstream ss;
    std::string s;
    if(root == nullptr){}
    else{
        ss<<"["<< root->_item <<"]";
        ss<<pre_order_string(root->_left);
        ss<<pre_order_string(root->_right);
    }
    ss >> s;
    return s;
}

template <typename T> //string post_order
std::string post_order_string(tree_node<T>* root){
    std::stringstream ss;
    std::string s;
    if(root == nullptr){}
    else{
        ss<<post_order_string(root->_left);
        ss<<post_order_string(root->_right);
        ss<<"["<< root->_item <<"]";
    }
    ss >> s;
    return s;
}

//===========================================
// DELETION
//===========================================

template <typename T> //clear the tree
void tree_clear(tree_node<T>* &root){
    tree_node<T> * hold;
    if(root != nullptr){
        hold = root->_left;
        tree_clear(hold);
        hold = root->_right;
        tree_clear(hold);
        delete root;
        root = nullptr;
    }
}

template <typename T> //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target){
    if(root == nullptr){
        return false;
    }
    //search for node 
    if(root->_item > target){
        bool l = tree_erase(root->_left, target);
        //root->update_height();
    }
    else if(root->_item < target){
        bool r = tree_erase(root->_right, target);
      //  root->update_height();
    }
    else{
        if(root->_left == nullptr){
            tree_node<T> * hold = root;
            root = root->_right;
            delete hold;
            return true;
        }
        else if(root->_left != nullptr){
            tree_remove_max(root->_right, root->_item);
            // root->update_height();
            return true;
        }
        else{
            tree_node<T> * hold = root;
            root = nullptr;
            delete hold;
            return true;
        }
    }
    //root->update_height();
    return true;
}

template <typename T> //erase rightmost node from the tree -> max_value
void tree_remove_max(tree_node<T>* &root, T& max_value){
        tree_node<T> *cur = root;
    tree_node<T> *prev = nullptr;
    while(cur->_right != nullptr){
        prev = cur;
        cur = cur->_right;
    }
    if(prev == nullptr){
        max_value = cur->_item;
        root = root->_left;
        //root->update_height();
        delete cur;
    }
    else{
        max_value = cur->_item;
        prev->_right = nullptr;
        //root->update_height();
        delete cur; 
    }
}

template <typename T>
void remove_max_node(tree_node<T>* &root, T& max_value){
    if(root == nullptr){}
    if(root->_right != nullptr){
        remove_max_node(root->_right, max_value);
    }
    else{
        max_value = root->_item;
        if(root->_left != nullptr){
            tree_node<T> * hold = root;
            root = root->_left;
            delete hold;
        }
        else{
            tree_node<T> * hold = root;
            root = nullptr;
            delete hold;
        }
    }
}

template <typename T> //erase target from the tree
bool avl_tree_erase(tree_node<T>*& root, const T& target){
    if(root == nullptr){
        return false;
    }
    //search for node 
    if(root->_item > target){
        return avl_tree_erase(root->_left, target);
        root->update_height();
        root = rotate(root);
    }
    else if(root->_item < target){
        return avl_tree_erase(root->_right, target);
        root->update_height();
        root = rotate(root);
    }
    else{
        if(root->_left == nullptr){
            tree_node<T> * hold = root;
            root = root->_right;
            delete hold;
            root = rotate(root);

            return true;
        }
        if(root->_left != nullptr){
            remove_max_node(root->_left, root->_item);
            root->update_height();
            root = rotate(root);

            return true;
        }
    }

    root->update_height();
    root = rotate(root);

    return true;
}
//===========================================
// COPY
//===========================================

template <typename T> //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root){
    tree_node<T> *left;
    tree_node<T> *right;
    if(root == nullptr){
        return nullptr;
    }
    else{
        left = tree_copy(root->_left);
        right = tree_copy(root->_right);
        return new tree_node<T>(root->_item, left, right, root->_height);
    }
}

template <typename T> //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src){
    std::vector<T> a;
    tree_to_arr(src, a);
    for(int i=0; i<a.size(); i++){
        tree_insert(dest, a[i]);
        // std::cout<<"["<<a[i]<<"]";
    }

}

template <typename T> 
T tree_to_arr(const tree_node<T>* root, std::vector<T>& a){
    T n;
    if(root == nullptr){}
    else{
        n = tree_to_arr(root->_left, a);
        n = tree_to_arr(root->_right, a);
        n = root->_item;
        a.push_back(n);
    }
    return n;
} 


//===========================================
// SORTED ARRAY -> TREE
//===========================================

template <typename T> //sorted array of ints -> tree
tree_node<T>* tree_from_sorted_list(const T* a){
    int size=0;
    for(const T *cur = a; *cur != -1; cur++){
        size++;
    }
    return tree_from_sorted_list(a, size);
}

template <typename T> // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size){
    return tree_from_sorted(0, size-1, a);
}

template <typename T>
tree_node<T>* tree_from_sorted(int left, int right, const T* a){
    tree_node<T> * Tr = nullptr;
    if(left > right){
        return nullptr;
    }
    int mid = (left + (right - left+1)/2);
    tree_insert(Tr, a[mid]);
    Tr->_right = tree_from_sorted(mid+1, right, a);
    Tr->_left = tree_from_sorted(left, mid-1, a);
        
    return Tr;
}

template <typename T>
void avl_tree_from_sorted(const T* a, int size, tree_node<T>* &root){
    for(int i=0; i<size; i++){
        avl_tree_insert(root, a[i]);
    }
}

template <typename T>
bool is_leaf(tree_node<T>*& root){
    return (root->_right == nullptr && root->_left == nullptr);
}

//===========================================
// ROTATIONS
//===========================================

template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root){
    tree_node<T>* y = root->_left;
    tree_node<T>* a = y->_right;
    y->_right = root;
    root->_left = a;
    y->update_height();
    root->update_height();

    return y;
}

template <typename T>
tree_node<T>* rotate_left(tree_node<T>* &root){
    tree_node<T>* y = root->_right;
     tree_node<T>* a = y->_left;
    y->_left = root;
    root->_right = a;
    y->update_height();
    root->update_height();
    return y;
}

template <typename T>
tree_node<T>* rotate(tree_node<T>* & root){
    int bF = balance_factor(root);
    if(bF > 1){ //right heavy 
        int RbF = balance_factor(root->_right);
        if(RbF <= -1){ //RL case (sub is left heavy) (zig-zag)*
            root->_right = rotate_right(root->_right);
            return rotate_left(root);
        }
        else{ //L case (straight line)*
            return rotate_left(root);
        }
    }
    else if(bF < -1){ //left heavy 
        int LbF = balance_factor(root->_left);
        if(LbF >= 1){ //LR case (sub is right heavy) (zig-zag)*
            root->_left = rotate_left(root->_left);
            return rotate_right(root);
        }
        else{ //R case (straight line)*
            return rotate_right(root);
        }
    }
    else
        return root;
}

template <typename T>
T avl_add(tree_node<T>* src, tree_node<T>* dest){
    T n;
    if(src == nullptr){}
    else{
        n = avl_add(src->_left, dest);
        n = avl_add(src->_right, dest);
        n = src->_item;
        avl_tree_insert(dest, n);
    }
    return n;
}


#endif