#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

std::vector<int> pegar_homens(const std::vector<int>& vet)
{
	std::vector<int> homens;
	for (int i = 0; i < vet.size(); i++) { 
	   if (vet[i] > 0) 
         homens.push_back(vet[i]);
    }

	return homens;
}

int main()
{
    std::vector<int> recebe = pegar_homens({9, 10, -10, -50, -1, 10, 21});
    std::cout << "Lista Homens:"<< recebe << '\n';
}