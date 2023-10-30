#include <iostream>
#include <algorithm>


bool resolver() {
	const int TAM = 7;
	double leerNotas;
	double notas[TAM];

	std::cin >> leerNotas;

	if (!std::cin) return false;
	notas[0] = leerNotas;

	for (int i = 1; i < 7; ++i) {
		std::cin >> leerNotas;
		notas[i] = leerNotas;
	}

	std::sort(notas, notas + TAM);

	std::cout << (notas[2] + notas[3] + notas[4]) * 2 << '\n';

	return true;
}

int main() {
	while (resolver());

	return 0;
}