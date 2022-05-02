#include <iostream>
#include <vector>

int repeticao(std::vector<int>& vet, int value)
{  
    int rep = 0;
    for (int i = 0; i < (int) vet.size(); i++) { 
        if(abs(vet[i]) == abs(value))
          rep++;
        }

    return rep;
}

int Trios(std::vector<int>& vet)
{  
   int trio = 0;
	 for (int i = 0; i < (int) vet.size(); i++) { 
    int rep = 0;
    for (int x = i; x <= (int) vet.size(); x++) { 
      if(abs(vet[i]) == abs(vet[x]))
        rep++;
     }
     if (rep == 3)
      trio++;
    }

    return trio;
}

int main()
{
  std::vector<int> a = {1, 2, -2, -2, 1, 3, -3, 3, -1};
  int recebe = Trios(a);
  std::cout << "Qtd Casais e: " << recebe << '\n';
}