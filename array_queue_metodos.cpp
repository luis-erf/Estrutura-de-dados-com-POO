#include "classe_base_fila.h"

template<typename T>
Array_queue<T> :: Array_queue(int size){
    max_size = size;
    front = rear = 0;
    list_array = new T[max_size];
}

template<typename T>
Array_queue<T> :: ~Array_queue(){
    delete[] list_array;
}

template<typename T>
void Array_queue<T> :: clear(){
    front = 0;
    rear = 0;
}

template<typename T>
void Array_queue<T> :: enqueue(const T& termo){
    if(rear + 2 % max_size != front){
        rear = rear + 1 % max_size;
        list_array[rear] = termo;
    }
}

template<typename T>
T Array_queue<T> :: dequeue(){
    if(length() != 0){
        T termo = list_array[front];
        front = front + 1 % max_size;
        return termo;
    }
}

template<typename T>
const T& Array_queue<T> :: front_value() const{
    if(length() == 0){
        throw "Fila vazia";
    }
    else{
        return list_array[front];
    }
}

template<typename T>
int Array_queue<T> :: length() const{
    return ((rear + max_size) - front + 1) % max_size;
}