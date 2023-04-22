#ifndef TWO_D_ARRAY_FUNCTIONS_H
#define TWO_D_ARRAY_FUNCTIONS_H

template <class T>
T read_twod(T** twod, int row, int col);

template <class T>
void write_twod(T** twod, int row, int col, const T& item);

template <class T>
T& get_twod(T** twod, int row, int col);

template <class T>
T** deallocate_twod(T** twod, int size);

//read [row][col]
template <class T>
T read_twod(T** twod, int row, int col){
    T item = get_twod(twod, row, col);
    return item;
}

//write to [row][col]
template <class T>
void write_twod(T** twod, int row, int col, const T& item){
    get_twod(twod, row, col) = item;
}

//ptr to [row][col]
template <class T>
T& get_twod(T** twod, int row, int col){
        T** row_ptr = twod + row;
        T* col_ptr = *row_ptr+col;
        return *col_ptr;
}

//deallocate a 2d array
template <class T>
T** deallocate_twod(T** twod, int size){
    for(int i = 0;i<size;i++){
        delete [] *twod;
        twod++; 
    }
    return twod;
}

#endif