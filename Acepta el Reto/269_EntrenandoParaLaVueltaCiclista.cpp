#include <iostream>

void resolver() {
	int kmDesdePuntoAlcanzado,kmAlcanzadosTotal = 0,kmRecorridos = 0;

	std::cin >> kmDesdePuntoAlcanzado;
	while (kmDesdePuntoAlcanzado != 0) {
		kmAlcanzadosTotal += kmDesdePuntoAlcanzado;
		kmRecorridos += 2 * kmAlcanzadosTotal;
		std::cin >> kmDesdePuntoAlcanzado;
	}

	std::cout << kmRecorridos << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	
	for (int k = 0; k < numCasos; ++k) resolver();

	return 0;
}