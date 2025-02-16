#include "class_base_pilha.h"

template<typename T>
Array_stack<T> :: Array_stack(int size){
    max_size = size;
    top = 0;
    list_array = new T[size];
}

template<typename T>
Array_stack<T> :: ~Array_stack(){
    delete [] list_array;
}

template<typename T>
void Array_stack<T> :: clear(){
    top = 0;
}

template<typename T>
void Array_stack<T> :: push(const T& termo){
    if(top != max_size){
        list_array[top++] = termo;
    }
}

template<typename T>
T Array_stack<T> :: pop(){
    if(top != 0){
        return list_array[--top];
    }
}

template<typename T>
const T& Array_stack<T> :: top_value() const{
    if(top != 0){
        return list_array[top - 1];
    }
}

template<typename T>
int Array_stack<T> :: length() const{
    return top;
}