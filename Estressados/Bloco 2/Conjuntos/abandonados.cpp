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
    std::vector<int> aban;
    for (int i = 0; i < (int) vet.size(); i++) { 
     int rep = 0;
     for (int x = i; x < (int) vet.size(); x++) {
        if (vet[i] == vet[x] && presente(aban, vet[i]) == 0) 
         rep++; 

      }

    if (rep != 1 && presente(aban, vet[i]) == 0) 
     aban.push_back(vet[i]);

    }

    std::cout << "Lista diferente:" << aban << '\n';
}

int main()
{
  std::vector<int> a = {1, 3, 4, 3, -1, -2, -2};
	exclusivos(a);
}