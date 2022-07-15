#include <iostream>
#include <vector>

using namespace std;

int prox_vivo(vector<int> vet, int pos)
{
    return (pos + 1) % vet.size();
}

void show(vector<int> vet, int espada) {
    cout << "[";
    for (int i = 0; i < vet.size(); i++) {
        if (i == espada)
            cout << vet[i] << "> ";
        else
            cout << vet[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    int size = 0, espada = 0;
    vector<int> vetor;
    
    cin >> size >> espada;

    for (int i = 0; i < size; i++)
        vetor.push_back(i + 1);

    espada = espada - 1;
    show(vetor, espada);

    int qtd = size - 1;
    while (qtd--)
    {
        int posicao = prox_vivo(vetor, espada);
        vetor.erase(vetor.begin() + posicao);
        espada = prox_vivo(vetor, posicao - 1);
        show(vetor, espada);
    }
}