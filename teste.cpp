#include <iostream>
#include <string>
#include "array_pilha_metodos.cpp"

using namespace std;

int main(){
    int casos;
    cin >> casos;
    string comando;
    int num;
    
    Array_stack<int> pilha(1000);
    for(int i = 0; i < casos; i++){
        cout << "Caso " << i + 1 << ":" << endl;
        while(comando != "end"){
            cin >> comando;
            if(comando == "end"){
                break;
            }
            cin >> num;
            if(comando == "push"){
                pilha.push(num);
            }
            else if(comando == "pop"){
                int soma = 0;
                for(int j = 0; j < num; j++){
                    soma += pilha.pop();
                }   
                cout << soma << endl;
            }
        }
    }   

    
    return 0;
}