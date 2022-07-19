#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <time.h>

using namespace std;
using matrix = vector<string>;

struct Pos {
    int l, c;
    Pos (int l, int c): l(l), c(c) {};
};

vector<Pos> get_neib(Pos p) {
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void queimar(matrix &matriz, Pos p) {
    srand(time(NULL));

    if (matriz[p.l][p.c] != '#') {
        return;
    }

    matriz[p.l][p.c] = 'o';

    stack<Pos> pilha;
    pilha.push(p);

    while (!pilha.empty()) {
        vector<Pos> queimaveis = pode_queimar(get_neib(pilha.top()), matriz);

        if (queimaveis.empty())
            pilha.pop();

        else {
            int qm = rand()%queimaveis.size();
            matriz[queimaveis[qm].l][queimaveis[qm].c] = 'o';
            pilha.push(queimaveis[qm]);
        }

    }    
}

vector<Pos> pode_queimar(vector<Pos> v, matrix matriz) {
    vector<Pos> arvores;

    int nl = matriz.size();
    int nc = matriz[0].size();

    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i].l < 0 || v[i].l >= nl || v[i].c < 0 || v[i].c >= nc) {
            continue;
        }

        if  (matriz[v[i].l][v[i].c] != '#') {
            continue;
        }

        arvores.push_back(v[i]);
    }

    return arvores;
}

void show(vector<string> mat){
    cout << '\n';
    for (auto line : mat) {
        cout << line << '\n';
    }
}

int main() {
    matrix mat;
    int nl {}, nc {}, li {}, ci {};
    
    cin >> nl >> nc >> li >> ci;

    for(int l = 0; l < nl; l++) {
        string line;
        cin >> line;
        mat.push_back(line);
    }

    Pos p_ini(li, ci);

    queimar(mat, p_ini);
    show(mat);

    return 0;
}