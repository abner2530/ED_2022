#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

void ordena(std::vector<int>& vet)
{  
    int aux = 0;
    for (int tam = 0; tam < vet.size(); tam++) {
	 for (int i = 0; i < vet.size(); i++) { 
        if (vet[i] > vet[i + 1]) {
         aux = vet[i];
         vet[i] = vet[i + 1];
         vet[i + 1] = aux;
        }
     }
    }
    std::cout << "Lista Ordenada:" << vet << '\n';
}

int main()
{
    std::vector<int> a = {9, 30, -10, -50, -1, 20, 21};
	ordena(a);
}