#include <iostream>

void resuelveCaso() {
	int A, S, I;
	int SemComp = 0;

	std::cin >> A >> S >> I;

	int desfaseInicial = S - I + 1;
	A = A - desfaseInicial;
	
	if (I == 1)
		++SemComp;

	SemComp = SemComp + A / S;

	std::cout << SemComp << '\n';
}



int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k)
		resuelveCaso();
}