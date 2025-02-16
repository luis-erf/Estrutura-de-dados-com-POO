#include "class_base_pilha.h"

template<typename T>
Linked_stack<T> :: Linked_stack(){
    top = NULL;
    size = 0;
};

template<typename T>
Linked_stack<T> :: ~Linked_stack(){
    clear();
};

template<typename T>
void Linked_stack<T> :: clear(){
    while(top != NULL){
        link<T>* temp = top;
        top = top->next;
        delete temp;
    }
    size = 0;
};

template<typename T>
void Linked_stack<T> :: push(const T& termo){
    top = new link<T>(termo, top);
    size++;
};

template<typename T>
T Linked_stack<T> :: pop(){
    if(top != NULL){
        T termo = top->elemento;
        link<T>* temp = top-> next;
        delete top;
        top = temp;
        size--;
        return termo;
    }
    else{
        return 0;
    }
}

template<typename T>
const T& Linked_stack<T> :: top_value() const{
    if(top != NULL){
        return top->elemento;
    }
    else{
        throw "Pilha vazia";
    }
}

template<typename T>
int Linked_stack<T> :: length() const{
    return size;
};

template<typename T>
link<T> :: link(const T& valor_elemento, link* nextval){
    elemento = valor_elemento;
    next = nextval;
}

template<typename T>
link<T> :: link(link* nextval){
    next = nextval;
}