#include <iostream>
#include <vector>

int pos(std::vector<int> vet, int num, int y)
{ 
	for (int x = y; x < vet.size(); x++) {
	  if (vet[ x ] == num) {
	    int pos = x;
        return pos;
	  }
	}
    return -1;
}

int main()
{

	int recebe = pos({5, 3, -1, -50, -1, -99}, -1, 4);
    std::cout << "O numero esta na pos " << recebe << '\n';
}