#include<iostream>
#include<vector>

using namespace std;

void show(vector<int> vetor, int escolhido){
    cout << "[";
    for(int i = 0; i < vetor.size(); i++){
        if(i == escolhido)
            cout << vetor[i] << "> ";
         else 
            cout <<  vetor[i] << ", ";
    }
    cout << "]\n";
}

int next(vector<int> vetor, int pos){
    return (pos + 1) % vetor.size();
}

int main(){
    int tamanho {};
    cin >> tamanho;

    vector<int> vet;
    for(int i = 0; i < tamanho; i++)
        vet.push_back(i+1);

    int espada {};
    cin >> espada;
    espada = espada - 1;

    show(vet, espada);

    int qtd = tamanho - 1;
    while(qtd--){
        int pos = next(vet, espada);
        vet.erase(vet.begin() + pos);
        espada = next(vet, pos - 1 );
        show(vet, espada);
    }
}