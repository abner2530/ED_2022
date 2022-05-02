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

void sozinhos(std::vector<int>& vet)
{  
    std::vector<int> solos;
    for (int i = 0; i < (int) vet.size(); i++) { 
     int rep = 0;
     for (int x = 0; x < (int) vet.size(); x++) {
        if (abs(vet[i]) == abs(vet[x])) {
         rep++; 
        } 
      } 

    if (rep == 1) 
     solos.push_back(vet[i]);

    }

    std::cout << "Lista Sozinhos:" << solos << '\n';
}

int main()
{
  std::vector<int> a = {1, 3, 4, 3, -1, -3, -3};
	sozinhos(a);
}