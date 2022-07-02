#include <iostream>
#include <vector>

float media_stress(std::vector<int> vet)
{   
    float soma = 0, media = 0;
	for (int x = 0; x < vet.size(); x++) {
	  if (vet[x] < 0 ) {
	   vet[x] = -vet[x];
       soma = soma + vet[x];
	  } else {
       soma = soma + vet[x];
      }
	}

    media = (float) soma/vet.size();

    return media;
}

int main()
{
	float recebe = media_stress({5, 3, -1, -50, -1, 10});
    std::cout << "A media do stress e: " << recebe << '\n';
}