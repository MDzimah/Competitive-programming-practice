#include <iostream>

void resuelveCaso() {
	int pisoVivo, escPiso, pisosCompSub, escAdicionales;
	int escSubidos = 0;
	int escBajados = 0;

	std::cin >> pisoVivo >> escPiso >> pisosCompSub >> escAdicionales;

	escBajados = pisosCompSub * escPiso + escAdicionales;
	escSubidos = escBajados + pisoVivo * escPiso;

	std::cout << escBajados << ' ' << escSubidos << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) resuelveCaso();

	return 0;
}