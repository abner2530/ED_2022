#include <iostream>
#include <vector>

int Briga(std::vector<int>& vet)
{  
    int brig = 0;
	  for (int i = 0; i < (int) vet.size(); i++) { 
          if(i == 0 || i == vet.size()-1)
           continue;
          if (vet[i-1] > 30 && vet[i] > 50 && vet[i+1] > 30)
           brig++;
      }

    return brig;
}

int main()
{
  std::vector<int> a = {31, 51, 31, 51, 31, 51, 52};
  int recebe = Briga(a);
  std::cout << "Qtd Brigas foi " << recebe << '\n';
}