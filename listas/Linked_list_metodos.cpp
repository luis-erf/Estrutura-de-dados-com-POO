#include "listas/Classe_listas.h"

template<typename T>
void Linked_list<T> :: init(){
    curr = tail = head = new link<T>;
}

template<typename T>
void Linked_list<T> :: removeall(){
    while(head != NULL){
        curr = head;
        head = head -> next;
        delete curr;
    }
}

template<typename T>
Linked_list<T> :: Linked_list(){
    init();
}

template<typename T>
Linked_list<T> :: ~Linked_list(){
    removeall();
}

template<typename T>
void Linked_list<T> :: insert(const T& termo){
    curr -> next = new link<T>(termo, curr -> next);
    if(tail == curr){
        tail = curr -> next;
    }
    cnt++;
}

template<typename T>
void Linked_list<T> :: append(const T& termo){
    tail = tail->next = new link<T> (termo, NULL);
    cnt++;
}

template<typename T>
void Linked_list<T> :: remove(){
    if(curr->next != NULL){
        link<T>* ltemp = curr->next;
        if(tail == curr->next){
            tail = curr;
        }
        curr->next = curr->next->next;
        delete ltemp;
        cnt--;
    }
}

template<typename T>
void Linked_list<T> :: moveToStart(){
    curr = head;
}

template<typename T>
void Linked_list<T> :: moveToEnd(){
    curr = tail;
}

template<typename T>
void Linked_list<T> :: prev(){
    if(curr == head){
        return;
    }
    link<T>* temp = head;
    while(temp->next != curr){
        temp = temp->next;
    }
    curr = temp;
}

template<typename T>
void Linked_list<T> :: next(){
    if(curr != tail){
        curr = curr->next;
    }
}

template<typename T>
int Linked_list<T> :: length() const{
    return cnt;
}

template<typename T>
int Linked_list<T> :: currPos() const{
    link<T>* temp = head;
    int i;
    for(i = 0; curr != temp; i++){
        temp = temp->next;
    }
    return i;
}

template<typename T>
void Linked_list<T> :: moveToPos(int pos){
    if(pos >= 0 && pos <= cnt){
        curr = head;
        for(int i = 0; i < pos; i++){
            curr = curr->next;
        }
    }
}

template<typename T> 
const T& Linked_list<T> :: getValue() const{
    if(curr->next != NULL){
        return curr->next->elemento;
    }
}

template<typename T>
int Linked_list<T> :: count(const T& termo) const{
    int qnt = 0;
    link<T>* temp = head->next;
    while(temp != NULL){
        if(temp->elemento == termo){
            qnt++;
        }
        temp = temp->next;
    }
    return qnt;
}

template<typename T>
void Linked_list<T> :: clear(){
    removeall();
    init();
}

template<typename T>
link<T> :: link(const T& valor_elemento, link* nextval){
    elemento = valor_elemento;
    next = nextval;
}

template<typename T>
link<T> :: link(link* nextval){
    next = nextval;
}