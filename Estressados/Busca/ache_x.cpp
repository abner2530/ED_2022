#include <iostream>
#include <vector>

bool achou(std::vector<int> vet, int num)
{
	for (int x : vet) {
	  if (x == num) {
	   return true;
	  }
	}
    
    return false;
}

int main()
{

	int recebe = achou({-1, -50, -99}, 10);
    if (recebe == 1) {
        printf("O numero esta presente!");
    } else {
        printf("O numero nao esta presente!");
    }
}