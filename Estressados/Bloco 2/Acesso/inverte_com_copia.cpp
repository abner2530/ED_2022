#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

std::vector<int> inverte_copia(const std::vector<int>& vet)
{  
    std::vector<int> copia;
	for (int i = 1; i <= (int) vet.size(); i++) { 
        copia.push_back(vet[vet.size() - i]);
        
    }

    return copia;
}

int main()
{
    std::vector<int> a {9, 10, -30, -50, -1, 20, 21};
	std::vector<int> recebe = inverte_copia(a);

    std::cout << "Lista Clone Invertida:" << recebe << '\n';
}