#include <iostream>

void res() {
	unsigned long long int num; 
	int numCeros = 0;

	std::cin >> num;
	
	int numCincos = num / 5;
	while (numCincos > 0) {
		numCeros = numCeros + numCincos;
		numCincos = numCincos/5;
	}

	std::cout << numCeros << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) res();

	return 0;
}