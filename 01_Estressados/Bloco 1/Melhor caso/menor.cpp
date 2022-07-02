#include <iostream>
#include <vector>

int menor(std::vector<int> vet)
{   
	int mini = vet[0];
	for (int x = 0; x < vet.size(); x++) {
	  if (vet[ x ] < mini ) {
	   mini = vet[ x ];
	  }
	}
    
    return mini;
}

int main()
{

	int recebe = menor({5, 3, -1, -50, -1, -99});
    std::cout << "O menor numero e: " << recebe << '\n';
}