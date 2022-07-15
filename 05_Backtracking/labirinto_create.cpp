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

void furar(matrix& mat, Pos p){
    int nl = mat.size();
    int nc = mat[0].size();
    auto [l, c] = p;
    if (l < 0 || l >= nl || c < 0 || c >= nc)
        return;
    if (mat[l][c] != '#')
        return;
    if (!pode_furar(mat, p))
        return;
    mat[l][c] = ' ';
    show(mat);
    for(auto vizi : suffle(get_neib(p)))
        furar(mat, vizi);
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