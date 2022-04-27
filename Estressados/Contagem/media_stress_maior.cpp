#include <iostream>
#include <vector>

std::string media_maior(std::vector<int> vet)
{   
    int somax = 0, somay = 0, qtdx = 0, qtdy = 0;
    float mediax = 0, mediay = 0;
	for (int x = 0; x < vet.size(); x++) {
	  if (vet[ x ] >= 0 ) {
          somax = somax + vet[ x ];
          qtdx++;
	  } else {
          vet[x] = -vet[ x ];
          somay = somay + vet[ x ];
          qtdy++;
      }
	}
    mediax = (float) somax/qtdx;
    mediay = (float) somay/qtdy;

    if ( mediax > mediay ){
        return "Media de stress do homens e Maior";
    } else if (mediax < mediay) {
        return "Media de stress das mulheres e Maior";
    }

    return "A media de stress dos dois sao iguais!";
}

int main()
{
	std::string receber = media_maior({50, 98, 2, -50, -2, -99});
    std::cout << receber << '\n';
}