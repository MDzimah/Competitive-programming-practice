#include <iostream>

void resuelveCaso() {
	int cuadHor, cuadVert, cerillas;

	std::cin >> cuadHor >> cuadVert;

	cerillas = (cuadHor + 1) * cuadVert + cuadHor * (cuadVert + 1);
	std::cout << cerillas << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k)
		resuelveCaso();

	return 0;
}


