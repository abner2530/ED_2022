#include <iostream>
#include <vector>

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


int main()
{
  std::vector<int> a = {1, 3, 3, 4, 5, -1, -5, -5};
	int recebe = mais_ocorrencia(a);
  std::cout << "QtdMax Ocorrencias e " << recebe << '\n';
}