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

void qtd_team(std::vector<int>& vet) 
{  
    std::vector<int> maior;
    int i = 0, sozmx = 0, inicio = 0;
	  while ( i < vet.size()) {
        int soz = 0;
          while (i < vet.size() && vet[i] > 0){
            i++;
            soz++;
          }
          if (soz > sozmx ) {
           sozmx = soz;
           inicio = i - sozmx;
          }
          soz = 0;
          while (i < vet.size() && vet[i] < 0) {
            i++;
            soz++;
          }
          if (soz > sozmx ){
           sozmx = soz;
           inicio = i - sozmx;
          }
      }
     for (int i = inicio; i < inicio + sozmx; i++) {
          maior.push_back(vet[i]);
     }

      std::cout << "Maior time: " << maior << '\n';
}

int main()
{
  std::vector<int> a = {1, -3, 3, -3, -3, -3, -3};
  qtd_team(a);
 
}