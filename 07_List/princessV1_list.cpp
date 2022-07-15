#include <iostream>
#include <list>
#include <numeric>

using namespace std;

void show(list<int>& lista, list<int>::iterator& sword){
    cout << "[";
    for(auto i = lista.begin(); i != lista.end(); i++){
        cout << *i;
        if(i == sword)
            cout << ">, ";
        else 
            cout << ", ";
    }
    cout << "]\n";
}

int main()
{
    
    int tamanho {}, espada {};
    cin >> tamanho >> espada;
    list<int> lista(tamanho);
    iota(begin(lista), end(lista), 1);

    auto sword = next(lista.begin(), espada - 1);
    while(lista.size() > 1){
        show(lista, sword);
        sword++;
        if(sword == lista.end()) 
            sword = lista.begin();
            
        sword = lista.erase(sword);
        
        if(sword == lista.end()) 
            sword = lista.begin();
    }
    show(lista, sword);
}