#include <iostream>
#include <vector>
#include <stack>
#include <time.h>

using namespace std;
using matrix = vector<string>;

struct Pos{
    int l;
    int c;
};

vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool valida_caminho(matrix mat, Pos p) {
    if (mat[p.l][p.c] != ' ') {
        return false;
    }

    return true;
}

vector<Pos> caminho(vector<Pos> viz, matrix mat) {
    vector<Pos> caminho;
    for (auto vizi : viz) {
        if (valida_caminho(mat, vizi)) {
            caminho.push_back(vizi);
        }
    }
    return caminho;
}

void procurar_saida(matrix &mat, Pos inicio, Pos fim){
    srand(time(NULL));
    mat[inicio.l][inicio.c] = '.';

    stack<Pos> pilha;
    pilha.push(inicio);

    while ( !pilha.empty() ) {
        if (pilha.top().l == fim.l && pilha.top().c == fim.c) {
            return;
        }

        vector<Pos> vizinhos = caminho(get_vizinhos(pilha.top()), mat);

        if (vizinhos.empty()) {
            mat[pilha.top().l][pilha.top().c] = '_';
            pilha.pop();

        } else {
            int rd = rand()%vizinhos.size();
            mat[vizinhos[rd].l][vizinhos[rd].c] = '.';
            pilha.push(vizinhos[rd]);
        }
    }
}

void errados(matrix& mat) {
    int nl = mat.size();
    int nc = mat[0].size();

    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (mat[l][c] == '_') {
                mat[l][c] = ' ';
            }
        }
    }
}

int main() {
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, "");
    getchar();
    Pos inicio, fim;

    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }
    procurar_saida(mat, inicio, fim);
    errados(mat);
    for(string line : mat)
        cout << line << endl;
}