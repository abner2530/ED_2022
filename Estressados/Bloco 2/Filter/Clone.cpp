#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

std::vector<int> clone(const std::vector<int>& vet)
{  

    return vet;
}

int main()
{
	std::vector<int> recebe = clone({9, 10, -10, -50, -1, 10, 21});
    std::cout << "Lista Clone:" << recebe << '\n';
}