#include <iostream>
#include <vector>

int menor(std::vector<int> vet, int y)
{   
	int mini = vet[ y ], posi = y;
	for (int x = y; x < (int) vet.size(); x++) {
	  if (vet[ x ] < mini ) {
	   mini = vet[ x ];
	   posi = x;
	  }
	}
    
    return posi;
}

int main()
{

	int recebe = menor({5, 3, -1, -50, -1, 10}, 3);
    std::cout << "A pos do menor numero e: " << recebe << '\n';
}