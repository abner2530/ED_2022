#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

std::vector<int> pegar_calmos(const std::vector<int>& vet)
{
	std::vector<int> calmos;
	for (int i = 0; i < vet.size(); i++) { 
	   if (vet[i] > 0 && vet[i] < 10)
         calmos.push_back(vet[i]);
    }

	return calmos;
}

int main()
{   
    std::vector<int> recebe = pegar_calmos({9, 10, -10, 3, 1, 10, 21});
    std::cout << "Lista Calmos:"<< recebe << '\n';
}