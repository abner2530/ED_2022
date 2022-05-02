#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
using matrix = vector<string>;

bool pode_furar(matrix mat, Pos p){

}

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

void furar(matrix& mat, Pos p){
    int nl = mat.size();
    int nc = mat[0].size();
    auto [l, c] = p;
    if (l < 0 || l >= nl || c < 0 || c >= nc)
        return;
    if (mat[l][c] != '#')
        return;
    if (! pode_furar(mat, p))
        return;
    mat[l][c] = '.';
    suffle(get_neib(p));
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

    cout << nl << " " << nc << "\n";

    vector<string> mat (nl, string(nc, '#'));

    for (auto line : mat)
        cout << line << '\n';

}