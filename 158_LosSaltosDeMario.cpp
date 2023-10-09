#include <iostream>

void res() {
	int muros,altMuro,altMuroAux,salA = 0,salB = 0;
	std::cin >> muros;

	std::cin >> altMuro;

	for (int f = 1; f < muros; ++f) {
		std::cin >> altMuroAux;
		if (altMuro < altMuroAux) ++salA;
		else if (altMuro > altMuroAux) ++salB;
		altMuro = altMuroAux;
	}

	std::cout << salA << ' ' << salB << '\n';
}


int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) res();
}