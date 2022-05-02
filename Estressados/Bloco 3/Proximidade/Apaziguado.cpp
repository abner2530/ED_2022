#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

int Apag(std::vector<int>& vet)
{  
    std::vector<int> clm;
    int posi = 0;
	  for (int i = 0; i < (int) vet.size(); i++) { 
          if ((vet[i-1] < 10 && vet[i] > 80) || (vet[i] > 80 && vet[i+1] < 10))
           clm.push_back(i);
      }

    std::cout << "Temos apaziguados nas posicoes: " << clm << '\n';
}

int main()
{
  std::vector<int> a = {81, 9, 81, 81, 9, 9, 81};
  Apag(a);
}