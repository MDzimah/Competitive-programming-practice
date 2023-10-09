#include <iostream>

void resuelveCasos() {
	int ins, arac, crus, escolo, anillos,patasTot;
	std::cin >> ins >> arac >> crus >> escolo >> anillos;

	patasTot = ins * 6 + arac * 8 + crus * 10 + (escolo * anillos) * 2;
	std::cout << patasTot << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) resuelveCasos();

	return 0;
}
