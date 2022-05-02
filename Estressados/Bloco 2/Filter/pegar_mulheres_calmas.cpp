#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

std::vector<int> pegar_calmas(const std::vector<int>& vet)
{
	std::vector<int> calmas;
	for (int i = 0; i < vet.size(); i++) { 
	   if (vet[i] < 0 && vet[i] > -10)
         calmas.push_back(vet[i]);
    }

	return calmas;
}

int main()
{   
    std::vector<int> recebe = pegar_calmas({-9, -1, -10, 3, 1, 10, 21});
    std::cout << "Lista Calmas:"<< recebe << '\n';
}