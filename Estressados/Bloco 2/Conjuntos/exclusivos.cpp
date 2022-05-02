#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << ", ";
    os << "]";

    return os;
}

int presente (std::vector<int> v, int value) 
{
  for (int i = 0; i < (int) v.size(); i++) {
      if (value == v[i]){
        return 1;
      }
  }
  return 0;
}

void exclusivos(std::vector<int>& vet)
{  
    std::vector<int> exclu;
	  for (int i = 0; i < vet.size(); i++) { 
        for (int x = 0; x < vet.size(); x++) {
          if (vet[i] == vet[x] && presente(exclu, vet[i]) == 0) {
              exclu.push_back(vet[i]);
          }
        }
      }

    std::cout << "Lista exclusiva:" << exclu << '\n';
}

int main()
{
    std::vector<int> a = {1, 3, 4, 3, -1, -2, -2};
	exclusivos(a);
}