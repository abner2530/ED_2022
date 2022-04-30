#include <iostream>
#include <vector>

std::string metade_maior(std::vector<int> vet)
{   
    int somax = 0, somay = 0, aux = 0;
	for (int x = 0; x < vet.size()/2; x++) {
	  if (vet[x] >= 0 ) {
          somax = somax + vet[x];
          aux = x;
	  } else {
          vet[x] = -vet[x];
          somax = somax + vet[x];
          aux = x;
      }
	}
    for (int y = aux+1; y < vet.size(); y++) {
      if (vet[y] < 0 ) {
          vet[y] = -vet[y];
          somay = somay + vet[y];
	  } else {
          somay = somay + vet[y];
      }
    }
    if ( somax > somay ){
        return "Primeira";
    } else if (somax < somay) {
        return "Segunda";
    }

    return "Empate";
}

int main()
{
	std::string recebe = metade_maior({-51, 99, 1, -50, -1, -99});
    std::cout << recebe << '\n';
}