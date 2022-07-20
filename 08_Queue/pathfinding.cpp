#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int l;
    int c;
};

vector<Pos> get_neib(Pos p) {
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void rastros(vector<string>& mat, vector<vector<int>>& back, Pos pos, int index) {
    if ((mat[pos.l][pos.c] != '_') || back[pos.l][pos.c] != index)
        return;

    mat[pos.l][pos.c] = '.';

    for (Pos viz : get_neib(pos))
        rastros(mat, back, viz, index - 1);
}

bool procurar_saida(vector<string>& mat, Pos inicio, Pos fim) {
    int nl = mat.size();
    int nc = mat[0].size();
    
    vector<vector<int>> back(nl, vector<int>(nc, -1));
    queue<Pos> fila; 

    fila.push(inicio);

    mat[inicio.l][inicio.c] = '_';
    back[inicio.l][inicio.c] = 0;
    
    while (!fila.empty()) {
        vector<Pos> vizinhos = get_neib(fila.front());

        for (auto viz : vizinhos) {
            if (mat[viz.l][viz.c] == ' ') {
                fila.push(viz);
                mat[viz.l][viz.c] = '_';
                back[viz.l][viz.c] = back[fila.front().l][fila.front().c] + 1;

                if (viz.l == fim.l && viz.c == fim.c) {
                    rastros(mat, back, fim, back[fila.front().l][fila.front().c] + 1);
                    return true;
                }

            }
        }
        
        fila.pop();
    }

    return false;

}

void errados(vector<string> &mat) {
    int nl = mat.size();
    int nc = mat[0].size();
    
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            if(mat[l][c] == '_')
                mat[l][c] = ' ';
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