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

int qtd_team(std::vector<int>& vet) 
{  
    std::vector<int> maior;
    int cout = 0, i = 0;
	  while ( i < vet.size()) {
        int soz = 0, sozi = 0;
          while (i < vet.size() && vet[i] > 0){
            i++;
            soz++;
          }
          while (i < vet.size() && vet[i] < 0) {
            i++;
            sozi++;
          }
          if (soz == 1)
           cout++;
          if (sozi == 1)
           cout++;
      }

    return cout;
}

int main()
{
  std::vector<int> a = {1, -3, 3, -3, -3, -3, -3};
  int recebe = qtd_team(a);
  std::cout<< "Qtd sozinhos: " << recebe << '\n';
}