#include "pilhas/class_base_pilha.h"

template<typename T>
array_stack<T> :: array_stack(int size){
    max_size = size;
    top = 0;
    list_array = new T[size];
}

template<typename T>
array_stack<T> :: ~array_stack(){
    delete [] list_array;
}

template<typename T>
void array_stack<T> :: clear(){
    top = 0;
}

template<typename T>
void array_stack<T> :: push(const T& termo){
    if(top != max_size){
        list_array[top++] = termo;
    }
}

template<typename T>
void array_stack<T> :: pop(){
    if(top != 0){
        list_array[--top];
    }
}

template<typename T>
const T& array_stack<T> :: top_value() const{
    if(top != 0){
        return list_array[top - 1];
    }
}

template<typename T>
int array_stack<T> :: length() const{
    return top;
}