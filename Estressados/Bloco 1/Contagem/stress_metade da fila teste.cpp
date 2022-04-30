#include <iostream>
#include <vector>

std::string metade_maior(std::vector<int> vet)
{   
 if(vet.size() % 2 == 0) {
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
        return "primeira";
    } else if (somax < somay) {
        return "segunda";
    }

    return "empate";
 }

 if(vet.size() % 2 == 1) {

    int somax = 0, somay = 0, aux = 0;
	for (int x = 0; x < (vet.size()-1)/2; x++) {
	  if (vet[x] >= 0 ) {
          somax = somax + vet[x];
          aux = x;
	  } else {
          vet[x] = -vet[x];
          somax = somax + vet[x];
          aux = x;
      }
	}
    for (int y = aux+2; y < vet.size(); y++) {
      if (vet[y] < 0 ) {
          vet[y] = -vet[y];
          somay = somay + vet[y];
	  } else {
          somay = somay + vet[y];
      }
    }
    if ( somax > somay ){
        return "primeira";
    } else if (somax < somay) {
        return "segunda";
    }

    return "empate";

 }

}

int main()
{
	std::string result = metade_maior({50, 98, 2, 0, -50, -1, -99});
    std::cout << result << '\n';
}