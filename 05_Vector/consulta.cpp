#include <iostream>
#include <vector>

using namespace std;

vector<int> matchingStrings(vector<string> consultas, vector<string> buscas) {
    int sizeb = buscas.size();
    int sizec = consultas.size();

    vector<int> vet;
    int count = 0;
    
    for (int i = 0; i < sizeb; i++) {
        for (int j = 0; j < sizec; j++) {
            if (buscas[i] == consultas[j]) {
                count++;
            }
        }
        vet.push_back(count);
        count = 0;
    }
    return vet;
}

int main(){
    int sizec {};
    int sizeb {};

    //Preencher Vetor Consulta
    cin >> sizec;
    vector<string> consultas(sizec, "");
    for(int i = 0; i < sizec; i++)
        cin >> consultas[i];

    //Preencher Vetor Busca
    cin >> sizeb;
    vector<string> buscas(sizeb, "");
    for(int j = 0; j < sizeb; j++)
        cin >> buscas[j];
    
    vector<int> vet = matchingStrings(consultas, buscas);
    for(int i = 0; i < (int) vet.size(); i++) {
        cout << vet[i] << " ";
    }
    cout << "\n";
    return 0;
}