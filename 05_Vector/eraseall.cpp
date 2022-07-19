#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void sairam(int n_sai, vector<int>& fila) {
    int p_sai;

    cin >> p_sai;

    for (int i = 0; i < fila.size(); i++) {
        if (fila[i] == p_sai) {
            fila.erase(fila.begin() + i);
        }
    }
}

void show (vector<int>& vet) {
    cout << "[ ";
    for (int i = 0; i < vet.size(); i++) {
        cout << vet[i] << " ";
    }
    cout << "]\n";;
}

int main() {
    vector<int> fila;
    int tam, pessoas, n_sai, p_sai;

    cin >> tam;

    for (int i = 0; i < tam; i++) {
        cin >> pessoas;
        fila.push_back(pessoas);
    }

    cin >> n_sai;

    for (int i = 0; i < n_sai; i++) {
        sairam(n_sai, fila);
    }

    show(fila);

}