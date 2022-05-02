#include <iostream>
#include <vector>

int qtd_team(std::vector<int>& vet) 
{  
    int qtdti = 0;
	  for (int i = 0; i < (int) vet.size(); i++) { 
     if (i == 0) {
        if (vet[i] > 0 && vet[i+1] > 0) {
         qtdti++;
         continue;
        } 
        else if (vet[i] < 0 && vet[i+1] < 0) {
         qtdti++;
         continue;
        }
        else if (vet[i] < 0 && vet[i+1] > 0) {
         continue;
        }
      }
      else if (i == (vet.size()-1)) break;
      else if(vet[i-1] > 0 && vet[i+1] > 0) continue;
      else if(vet[i-1] < 0 && vet[i+1] < 0) continue;

      else if(vet[i] > 0 && vet[i+1] > 0) {
       qtdti++;
       i++;
       if(vet[i-1] > 0 && vet[i+1] > 0) {
        i++;
       }
      }
      
      else if(vet[i] < 0 && vet[i+1] < 0) {
       qtdti++;
       i++;
       if(vet[i-1] < 0 && vet[i+1] < 0) {
        i++;
       }
      }
    }

    return qtdti;
}

int main()
{
  std::vector<int> a = {1, 2, -3, -3, 3, 3, -3, -3, 3, -3, -3};
  int recebe = qtd_team(a);
  std::cout << "Qtd Times e: " << recebe << '\n';
}