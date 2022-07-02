#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

void embaralhar(std::vector<int>& vet)
{  
    std::srand(std::time(0));
    for (int i = 0; i < (int) vet.size(); i++) {
        int posi = rand() % vet.size();
        std::swap(vet[i], vet[posi]);
    }
    
    std::cout << "Lista Emb: " << vet << '\n';
   
}

int main()
{
    std::vector<int> a {9, 30, -10, -50, -1, 20, 21};
	embaralhar(a);
}