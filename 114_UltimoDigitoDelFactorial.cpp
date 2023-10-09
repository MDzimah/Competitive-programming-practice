#include <iostream>

void resuelveCasos() {
	int num, ultD;
	std::cin >> num;

	if (num == 0 || num == 1) ultD = 1;
	else if (num == 2) ultD = 2;
	else if (num == 3) ultD = 6;
	else if (num == 4) ultD = 4;
	else ultD = 0;

	std::cout << ultD << '\n';
}


int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) resuelveCasos();

	return 0;
}
