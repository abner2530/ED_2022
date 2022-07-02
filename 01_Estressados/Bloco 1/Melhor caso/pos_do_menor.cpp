#include <iostream>
#include <vector>

int pos(std::vector<int> vet)
{   
	int mini = vet[ 0 ], posi;
	for (int x = 0; x < (int) vet.size(); x++) {
	  if (vet[ x ] < mini ) {
	   mini = vet[ x ];
       posi = x;
	  }
	}

    return posi;
}

int main()
{

	int recebe = pos({5, 3, -1, -50, -1, -99});
    std::cout << "A posicao do menor num e: " << recebe << '\n';
}