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

int mais_ocorrencia(std::vector<int>& vet)
{  
    int repmx = 0;
    for (int i = 0; i < (int) vet.size(); i++) { 
      int rep = 0;
      for (int x = 0; x < (int) vet.size(); x++) {
        if(abs(vet[i]) == abs(vet[x]))
          rep++;
        }

    if (repmx < rep)
      repmx = rep;
    }

    return repmx;
}

void mais_recorrente(std::vector<int>& vet)
{  
    std::vector<int> rec;
    for (int i = 0; i < (int) vet.size(); i++) { 
      int rep = 0;
      for (int x = 0; x < (int) vet.size(); x++) {
        if(abs(vet[i]) == abs(vet[x]))
          rep++;
      }
    if (rep == mais_ocorrencia(vet) && presente(rec, vet[i]) == 0 && presente(rec, abs(vet[i])) == 0) 
     rec.push_back(vet[i]);

    }
    std::cout << "Lista Recorrentes" << rec << '\n';
}

int main()
{
  std::vector<int> a = {1, 4, 5, -1, -5, -5, 3, -3};
  mais_recorrente(a);
}