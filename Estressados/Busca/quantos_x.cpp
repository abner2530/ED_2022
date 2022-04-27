#include <iostream>
#include <vector>

int contar(std::vector<int> vet, int num)
{
    int qtd = 0;
	for (int x : vet) {
	  if (x == num) {
	   qtd++;
	  }
	}
    
    return qtd;
}

int main()
{

	int recebe = contar({-1, -50, -1, -99}, 10);
    std::cout << "O numero apareceu " << recebe << "x" << '\n';
}