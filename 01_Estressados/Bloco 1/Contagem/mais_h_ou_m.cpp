#include <iostream>
#include <vector>

std::string contar(std::vector<int> vet)
{   
    int qtdh = 0, qtdm = 0;
	for (int x = 0; x < vet.size(); x++) {
	  if (vet[x] >= 0 ) {
       qtdh++;
	  } else {
       qtdm++;
      }
	}
    
    if ( qtdh < qtdm) {
        return "Tem mais mulheres";
    } else if (qtdh > qtdm) {
        return "Tem mais homens";
    }

    return "Empate";
}

int main()
{
	std::string recebe = contar({5, 3, -1, -50, -1, -99});
    std::cout << recebe << '\n';
    
}