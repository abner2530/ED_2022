#include <iostream>
#include <vector>

int pos(std::vector<int> vet)
{   
    int posi = -1;
	int mini = vet[0];
	for (int x = 0; x < (int) vet.size(); x++) {
	  if (vet[ x ] <= mini && vet[ x ] > 0) {
	   mini = vet[ x ];
       posi = x;
	  } 
	}

    return posi;
}

int main()
{

	int recebe = pos({-1, -50, -1, -99});
    std::cout << "A posicao do H menos estressado e: " << recebe << '\n';
}