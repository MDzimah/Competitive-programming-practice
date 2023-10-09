#include <iostream>

void resolver() {
	int nPersonas, nPares = 0;
	bool primerImpar = false, posible = true;

	std::cin >> nPersonas;

	int i = 0, butaca;
	while (i < nPersonas && posible) {
		std::cin >> butaca;
		if (butaca % 2 == 0) {
			if (primerImpar) posible = false;
			else ++nPares;
		}
		else {
			primerImpar = true;
		}
		++i;
	}
	while (i < nPersonas) { //consumimos el resto de la entrada
		std::cin >> butaca;
		++i;
	}
	if (posible) std::cout << "SI " << nPares << '\n';
	else std::cout << "NO\n";
} 

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) resolver();

	return 0;
}