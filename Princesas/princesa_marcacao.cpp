#include <iostream>
#include <vector>

using namespace std;

int find_alive(vector<bool> vet, int pos) {
    int prox = (pos + 1 ) % vet.size();
    while (vet[prox] == false ) {
        prox = (prox + 1) % vet.size();
    }
    return prox;
}

void show_vector(vector<bool> vet, int espada) {
    cout << '[';
    for (int i = 0; i < vet.size(); i++){
        if ( vet[i] == true){
            if(i == espada) {
            cout << vet[i] << "> ";
            } else {
            cout << vet[i] << " ";
            }
        } else {
         vet[i] = 0;
        }
    } 
    cout << "]\n";
}

int main()
{
    int tamanho {};
    cin >> tamanho;
    std::vector<bool> vet(tamanho, true);
    int espada {};
    cin >> espada;
    espada = espada - 1;
    show_vector(vet, espada);
    int qtd = tamanho - 1;
    while (qtd--){
        int to_die = {find_alive(vet, espada)};
        vet[to_die] = false;
        espada = find_alive(vet, to_die);
        show_vector(vet, espada);
    }
    
    return 0;
}
