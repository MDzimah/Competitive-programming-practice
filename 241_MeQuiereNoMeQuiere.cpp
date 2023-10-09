#include <iostream>

void resolver() {
	int hojTreb,treb4hoj = 0;
	std::cin >> hojTreb;

	if (hojTreb < 3 || hojTreb == 5) std::cout << "IMPOSIBLE" << '\n';
	else {
		if (hojTreb % 3 == 0) treb4hoj = 0;
		else if ((hojTreb - 4) % 3 == 0) treb4hoj = 1;
		else if ((hojTreb - 8) % 3 == 0) treb4hoj = 2;
		std::cout << treb4hoj << '\n';
	}
}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) resolver();
}