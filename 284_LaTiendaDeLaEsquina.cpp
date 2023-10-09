#include <iostream>

void resuelveCasos() {

	int precio, dineroDado, resto;

	int _200cts = 0;
	int _100cts = 0;
	int _50cts = 0;
	int _20cts = 0;
	int _10cts = 0;
	int _5cts = 0;
	int _2cts = 0;
	int _1cts = 0;

	std::cin >> precio >> dineroDado;

	if (precio > dineroDado) std::cout << "DEBE " << precio - dineroDado << '\n';

	else {

		_200cts = (dineroDado - precio) / 200;

		resto = (dineroDado - precio) % 200;

		_100cts = resto / 100;
		resto %= 100;

		_50cts = resto / 50;
		resto %= 50;

		_20cts = resto / 20;
		resto %= 20;

		_10cts = resto / 10;
		resto %= 10;

		_5cts = resto / 5;
		resto %= 5;

		_2cts = resto / 2;
		resto %= 2;

		_1cts = resto;

		std::cout << _200cts << ' ' << _100cts << ' ' << _50cts << ' ' << _20cts << ' ' << _10cts << ' ' << _5cts << ' ' << _2cts << ' ' << _1cts << '\n';
	}
	
}


int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) resuelveCasos();

	return 0;
}