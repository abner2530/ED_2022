#include <iostream>
#include <stack>

using namespace std;

struct Fila {
    stack<int> deposito;
    stack<int> prateleira;
};

int main() {
    int qtd_c, consulta, x;
    Fila fila;

    cin >> qtd_c;

    for(int i = 0; i < qtd_c; i++) {

        cin >> consulta;

        // insere no deposito
        if(consulta == 1) {
            cin >> x;
            fila.deposito.push(x);
            continue;
        }

        // Movendo o primeiro do deposito, para a prateleira.
        if(fila.prateleira.empty()) {
            while(!(fila.deposito.empty())){
                fila.prateleira.push(fila.deposito.top());
                fila.deposito.pop();
            }
        }

        
        if(!fila.prateleira.empty()) {
            // Removendo o topo da prateleira
            if(consulta==2)
                fila.prateleira.pop();

            // Exibindo o topo da prateleira
            if(consulta==3)
                cout<< fila.prateleira.top() << endl;
        }
    }

}