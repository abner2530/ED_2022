#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mostrar(vector<string> mapa){
    for (auto linha : mapa)
        cout << linha << '\n';
    getchar();
}

void queimar(vector<string>& mapa, int pos_lin, int pos_col){
    int num_lin = mapa.size();
    int num_col = mapa[0].size();
    if ( pos_lin >= num_lin || pos_col >= num_col  || pos_lin < 0 || pos_col < 0)
        return;
    
    if (mapa[pos_lin][pos_col] != '#')
        return; 
    
    mapa[pos_lin][pos_col] = 'o';
    mostrar(mapa);
    
    queimar(mapa, pos_lin, pos_col - 1);
    queimar(mapa, pos_lin - 1, pos_col);
    queimar(mapa, pos_lin, pos_col + 1);
    queimar(mapa, pos_lin + 1, pos_col);

}

int main() {
    vector<string> mapa;
    ifstream arq("mapa.txt");
    int num_lin { }, num_col {} , lin_inc {}, col_inc {};
    arq >> num_lin >> num_col >> lin_inc >> col_inc;
    for(int i = 0; i < num_lin; i++) {
        string linha;
        arq >> linha;
        mapa.push_back(linha);
    } 
    mostrar(mapa);
    queimar(mapa, lin_inc, col_inc);
}
