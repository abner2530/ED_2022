#include <iostream>
#include <vector>

int pos(std::vector<int> vet, int num)
{ 
	for (int x = 0; x < vet.size(); x++) {
	  if (vet[ x ] == num) {
	    int pos = x;
        return pos;
	  }
	}
    
    return -1;
}

int main()
{

	int recebe = pos({-1, -50, -1, -99}, -1);
    std::cout << "O numero esta na pos " << recebe << '\n';
}