#include "classe_base.h"
template<typename T>
Lista_array<T> :: Lista_array(int size){
    maxSize = size;
    current_size = curr = 0;
    listArray = new T[maxSize];
}

template<typename T>
Lista_array<T> :: ~Lista_array(){
    delete [] listArray;
}

template<typename T>
void Lista_array<T> :: clear(){
    delete [] listArray;
    current_size = curr = 0;
    listArray = new T[maxSize];
}

template<typename T>
void Lista_array<T> :: insert(const T& termo){
    if(current_size < maxSize){
        // As mudanças irão ocorrer sempre nos termos a direita do cursor de referência, ou seja, a leitura é de trás pra frente
        for(int i = current_size; i > curr; i--){
            listArray[i] = listArray[i - 1];
        }
        listArray[curr] = termo;
        current_size++;
    }
}

template<typename T>
void Lista_array<T> :: append(const T& termo){
    if(current_size < maxSize){
        listArray[current_size++] = termo;
    }
}

template<typename T>
int Lista_array<T> :: count(const T& termo) const{
    int qnt = 0;
    for(int i = 0; i < current_size; i++){
        if(listArray[i] == termo){
            qnt++;
        }
    }
    return qnt;
}

template<typename T>
void Lista_array<T> :: remove(){
    if(curr >= 0 && curr < current_size){
        for(int i = curr; i < current_size; i++){
            listArray[i] = listArray[i + 1];
        }
        current_size--;
    }
}

template<typename T>
void Lista_array<T> :: moveToStart(){
    curr = 0;
} 

template<typename T>
void Lista_array<T> :: moveToEnd(){
    curr = current_size;
} 

template<typename T>
void Lista_array<T> :: prev(){
    if(curr != 0){
        curr--;
    }
} 

template<typename T>
void Lista_array<T> :: next(){
    if(curr < current_size){
        curr++;
    }
}

template<typename T>
int Lista_array<T> :: length() const{
    return current_size;
}

template<typename T>
int Lista_array<T> :: currPos() const{
    return curr;
}

template<typename T>
void Lista_array<T> :: moveToPos(int pos){
    if(pos >= 0 && pos <= current_size){
        curr = pos;
    }
}

template<typename T>
const T& Lista_array<T> :: getValue() const{
    if(curr >= 0 && curr < current_size){
        return listArray[curr];
    }
}