#include <iostream>
#include <vector>

using namespace std;

struct Pos{
    int l;
    int c;
};

vector<Pos> get_neib(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool andar(vector<string>& mat, Pos inicio, Pos fim) {
    if (inicio.l == fim.l && inicio.c == fim.c) {
        mat[inicio.l][inicio.c] = '.';
        return true;
    }
    if (mat[inicio.l][inicio.c] != '_')
        return false;
        
    mat[inicio.l][inicio.c] = '.';
    
    for(auto viz : get_neib(inicio)) {
        if(andar(mat, viz, fim)){
            return true;
        }
    }
    mat[inicio.l][inicio.c] = 'e';
    return false;
}

void errados(vector<string> &mat){
    int nl = mat.size();
    int nc = mat[0].size();
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            if(mat[l][c] == 'e')
                mat[l][c] = '_';
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
                mat[l][c] = '_';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = '_';
                fim = Pos {l, c};
            }
        }
    }
    andar(mat, inicio, fim);
    errados(mat);
    for(string line : mat)
        cout << line << endl;
}