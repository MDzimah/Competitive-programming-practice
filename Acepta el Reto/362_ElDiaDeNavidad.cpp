#include <iostream>

void res() {
	int DD, MM;
	std::cin >> DD >> MM;

	if (DD == 25 && MM == 12) std::cout << "SI" << '\n';
	else  std::cout << "NO" << '\n';
}

int main() {
	int numCasos;

	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) res();

}