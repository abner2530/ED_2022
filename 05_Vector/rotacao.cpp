#include <iostream>
#include <vector>

using namespace std;

void rotacao (vector<int>& vet, int rota) {
    int size = vet.size();

    for (int i = 0; i < rota; i++) {
        int temp = vet[size - 1];
        for (int j = size - 1; j > 0; j--) {
            vet[j] = vet[j - 1];
        }
        
        vet[0] = temp;
    }
}

void show (vector<int>& vet) {
    cout << "[ ";
    for (int i = 0; i < vet.size(); i++) {
        cout << vet[i] << " ";
    }
    cout << "]\n";;
}

int main () {
    int size, rota;
    cin >> size >> rota;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    rotacao(vet, rota);
    show(vet);
}