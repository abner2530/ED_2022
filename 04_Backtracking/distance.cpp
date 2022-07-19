#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool se_aplica(string& line, int it, int valor, int prox) {
    for( int i = it + 1; i < it + 1 + prox; i++) {
        if(i < line.size() && line[i] == valor + '0')
            return false;
    }

    for( int i = it - prox; i < it; i++) {
        if(i >= 0 && line[i] == valor + '0')
            return false;
    }

    return true;
}

bool preencher(string& line, int it, int lim, int prox) {
    if ((int) line.size() == it ){
        cout << line << " <--- Deu certo\n";
        return true;
    }

    if (line[it] != '.')
        return preencher(line, it + 1, lim, prox);
        
    for (int valor = 0; valor <= lim; valor ++) {
        if (se_aplica(line, it, valor, prox)){
            line[it] = valor + '0';
            cout << line << '\n';
            if(preencher(line, it + 1, lim, prox))
                return true;
        }
    }

    line[it] = '.';
    cout << line << '\n';
    
    return false;
}

int main () {
    string line;
    int lim; 
    int prox = 0;
    cin >> line >> lim;
    prox = lim;
    while (!preencher(line, 0, lim, prox)) {
        lim++;
    }
}