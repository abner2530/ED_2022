#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

void reverter_inplace(std::vector<int>& vet)
{  
    int tam = (int) (vet.size() - 1);
	for(int i = 0; i < vet.size()/2; i++){
        std::swap(vet[tam - i], vet[i]);
    }

     std::cout << "Lista Replace:" << vet << '\n';
}

int main()
{
    std::vector<int> a {9, 30, -10, -50, -1, 20, 21};
	reverter_inplace(a);
 
}