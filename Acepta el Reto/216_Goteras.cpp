#include <iostream>
#include <iomanip>


void resuelveCaso() {

	int gotasCubo;

	int SS = 0;
	int MM = 0;
	int HH = 0;
	
	std::cin >> gotasCubo;
	
	HH = gotasCubo / 3600;
	MM = (gotasCubo % 3600)/60;
	SS = (gotasCubo % 3600)%60;

	std::cout << std::setfill('0') << std::setw(2) << HH << ":" << std::setfill('0') << std::setw(2) << MM << ":" << std::setfill('0') << std::setw(2) << SS << '\n';
}

int main() {

	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k)
		resuelveCaso();
}