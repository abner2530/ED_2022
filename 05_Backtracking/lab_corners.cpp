#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
using matrix = vector<string>;

struct Pos {
    int l, c;
    Pos (int l, int c): l(l), c(c) {};
};

vector<Pos> get_neib(Pos p){
    auto [l, c] = p;
    return {{l, c -1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};
}

vector<Pos> suffle(vector<Pos> vet){
    random_shuffle(begin(vet), end(vet));
    return vet;
}

void show(matrix& mat) {
    for (auto line : mat)
        cout << line << '\n';
    getchar();
}

bool pode_furar(matrix& mat, Pos p){
    int nl = mat.size();
    int nc = mat[0].size();
    {
        auto [l, c] = p;
        if (l < 0 || l >= nl || c < 0 || c >= nc)
            return false;
        if(mat[l][c] != '#')
            return false;

    }
    int count { 0 };
    for( auto viz : get_neib(p)) {
        auto [l, c] = viz;
        if (l < 0 || l >= nl || c < 0 || c >= nc)
        continue;
        if(mat[viz.l][viz.c] == '#')
            count+=1;
    }
    return (count >= 3);
}

vector<Pos> get_neib_furaveis(matrix& mat, Pos p){
    vector<Pos> furaveis;
    for (auto viz : get_neib(p))
        if(pode_furar(mat, viz))
            furaveis.push_back(viz);
    return furaveis;
} 

void furar(matrix& mat, Pos p){
    auto [l, c] = p;
    vector<Pos> pilha;
    mat[p.l][p.c] = ' ';
    pilha.push_back(p);
    while (!pilha.empty()) {
        auto topo = pilha.back();
        auto furaveis = suffle(get_neib_furaveis(mat, topo));
        if (furaveis.size() != 0) {
            auto escolhido = furaveis[0];
            mat[escolhido.l][escolhido.c] = ' ';
            show(mat);
            pilha.push_back(escolhido);
        } else {
            pilha.pop_back();
        }
    }
}


int main (int argc, char * argv[]) {
    if (argc != 3 ){
        cout << "Numero de argumentos invalidos.\n";
        cout << "./executavel nl nc\n";
        exit(1);
    }
    int nl { 0 }, nc { 0 };
    stringstream(argv[1]) >> nl;
    stringstream(argv[2]) >> nc;
    vector<string> mat (nl, string(nc, '#'));

    furar(mat, Pos(1,1));
}