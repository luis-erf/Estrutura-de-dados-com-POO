#include <iostream>
#include <string>
#include "Linked_list_metodos.cpp"

using namespace std;

int main(){
    int casos;
    int qnt_com;
    cin >> casos
        >> qnt_com;
    string comando;
    int num;
    Linked_list<int> lista;
    for(int i = 0; i < qnt_com; i++){
        cin >> comando;
            cin >> num;
            lista.insert(num);
        }
        else if(comando == "remove"){
            lista.remove();
        }
        else if(comando == "count"){
            int count = 0;
            cin >> num;
            count = lista.count(num);
            cout << count << "\n";
        }
        else if(comando == "prev"){
            lista.prev();
        }
        else if(comando == "next"){
            lista.next();
        }
    }
}