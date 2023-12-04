#include <iostream>
#include <algorithm>

const int TAM_MAX = 999;


bool resolver() {
	int perlas[TAM_MAX], leerPerlas;
	bool simetria = true;

	std::cin >> leerPerlas;
	if (leerPerlas == 0) return false;

	int tam = 0;
	while (leerPerlas != 0) {
		perlas[tam] = leerPerlas; 
		std::cin >> leerPerlas;
		++tam;
	} 

	if (tam % 2 == 0) std::cout << "NO\n";
	else {
		std::sort(perlas, perlas + tam);
		
		int n = 0;
		while (simetria && n < tam-1) {
			if (perlas[n] != perlas[n + 1]) simetria = false;
			n += 2;
		}
		
		if (simetria == false)  std::cout << "NO\n";
		else {
			for (int j = 0; j < tam - 1; j += 2) std::cout << perlas[j] << ' ';
			std::cout << perlas[tam - 1];
			for (int f = tam - 2; f > 0; f -= 2) std::cout << ' ' << perlas[f];
			std::cout << '\n';
		}
	}

	return true;
}


int main() {
	while (resolver());

	return 0;
}