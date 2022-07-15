#include <iostream>
#include <vector>

using namespace std;

int prox_vivo(vector<int> vet, int pos, int dir) {
    if (dir == 1)
     return (pos + 1) % vet.size();
    return (pos + vet.size() - 1) % vet.size();
}

void show(vector<int> vet, int espada) {
    cout << "[";
    for (int i = 0; i < vet.size(); i++) {
        if (i == espada && vet[i] > 0)
            cout << vet[i] << "> ";
        else if(i == espada && vet[i] < 0)
            cout << "<" << vet[i] << " ";
        else
            cout << vet[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    int size = 0, espada = 0, fase = 0;
    vector<int> vet;
    
    cin >> size >> espada >> fase;

    for (int i = 0; i < size; i++) {
        vet.push_back((i + 1) * fase);
        fase *= -1;
    }

    espada = espada - 1;
    show(vet, espada);

    int qtd = size - 1;
    while (qtd--)
    {
        int dir = vet[espada] > 0 ? 1 : -1;
        int posicao = prox_vivo(vet, espada, dir);
        vet.erase(vet.begin() + posicao);
        espada = prox_vivo(vet, posicao - 1, dir);
        show(vet, espada);
    }
}