#include <iostream>
#include <vector>

using namespace std;

void mostrar(vector<int> vet) {
    cout << '[';
    for (auto linha : vet)
        cout << linha << ", ";
    cout << "]\n";
}

void rmostra(vector<int> vet) {
    cout << '[';
    for(int i = vet.size() - 1; i >= 0; i--) {
        cout << vet[i] << ", ";
    }
    cout << "]\n";
}

int sum(vector<int> vet, int size) {
    if ( size == 0 )
        return 0;
    return vet[size - 1] + sum(vet, size -1);
}

int mult(vector<int> vet, int size) {
    if ( size == 0)
        return 1;
    return vet[size - 1] * mult(vet, size -1);
}

int menor_valor(vector<int> vet, int size) {
    if ( size == 1)
        return vet[0];
    int menor_resto = menor_valor(vet, size - 1) + vet[size - 1];
    return min(vet[0], menor_resto);
}

void inverte(vector<int>& vet, int i, int j) {
    int aux;
    if (i < j) {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        inverte(vet, i + 1, j - 1);
    }
}

int main(){
    vector<int> vet {1, 2, 3, 4, 5, 6};
    int size = vet.size();

    cout << "Vetor normal: ";
    mostrar(vet);
    cout << "Vetor contrário: ";
    rmostra(vet);
    cout << "Sum: " << sum(vet, size) << '\n';
    cout << "Mult: " << mult(vet, size) << '\n';
    cout << "Min: " << menor_valor(vet, size) << '\n';
    cout << "Vetor invertido: ";
    inverte(vet, 0, (int) vet.size() - 1);
    mostrar(vet);

}