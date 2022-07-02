#include <iostream>
#include <vector>

int casais(std::vector<int>& vet)
{  
    int casal = 0;
	 for (int i = 0; i < (int) vet.size(); i++) { 
        for (int x = i; x <= (int) vet.size(); x++) {
         if (abs(vet[i]) == abs(vet[x])){
          if(vet[i] == -vet[x+1] || -vet[i] == vet[x+1]){
          casal++;
          continue;
          }
          if(vet[i] == -vet[x] || -vet[i] == vet[x]){
          casal++;
          }
         } 
        }
     }

    return casal;
}

int main()
{
  std::vector<int> a = {-1, 2, 3, 4, 2, -3, 1};
  int recebe = casais(a);
  std::cout << "Qtd Casais e: " << recebe << '\n';
}