#include <iostream>

long int max(long int a, long int b) {
	if (a >= b) return a;
	else return b;
}

void resolver() {
	short int antenas;
	
	long int longTun,distIni,radio;
	
	std::cin >> longTun >> antenas;

	int cubriendo = 0;
	for (int i = 0; i < antenas; ++i) {
		std::cin >> distIni >> radio;
		if (distIni - radio <= cubriendo) cubriendo = max(cubriendo, distIni + radio);
	}
	if (cubriendo >= longTun) std::cout << "SI\n";
	else std::cout << "NO\n";
	
}

int main() {
	int numCasos;

	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) resolver();

	return 0;
}