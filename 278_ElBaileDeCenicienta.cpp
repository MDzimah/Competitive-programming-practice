#include <iostream>

void resuelveCasos() {
	int DD, HH, MM, SS, HHt, MMt, SSt;
	char aux;
	int tiempoBaile = 0;
	int tiempoTareas = 0;

	std::cin >> DD >> aux >> HH >> aux >> MM >> aux >> SS;
	tiempoBaile = DD * 86400 + HH * 3600 + MM * 60 + SS;

	std::cin >> HHt >> aux >> MMt >> aux >> SSt;
	while (HHt != 0 || MMt != 0 || SSt != 0) {
		tiempoTareas += HHt * 3600 + MMt * 60 + SSt;
		std::cin >> HHt >> aux >> MMt >> aux >> SSt;
	} 
	
	if (tiempoBaile > tiempoTareas) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) resuelveCasos();

	return 0;
}