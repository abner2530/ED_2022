#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int sortear(const std::vector<int>& vet)
{  
    std::srand(std::time(0));
	int sorteado = rand() % vet.size();
    int num = vet[sorteado];
 
   return num;
}

int main()
{
	int recebe = sortear({9, 30, -10, -50, -1, 20, 21});
    std::cout << "Sorteado foi: " << recebe << '\n';
}