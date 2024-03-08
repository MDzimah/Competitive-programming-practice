#include <iostream>
#include <algorithm>
#include <vector>

bool res() {

	short int F;
	std::cin >> F;

	if (F == 0) return false;

	std::vector <int> hijosDeFamiliasConMaxMidiclo;
	for (int i = 0; i < F; ++i) {
		int nH, cM;
		std::cin >> nH >> cM;
		
		int max;
		std::cin >> max;
		for (int j = 1; j < nH; ++j) {
			int aux;
			std::cin >> aux;
			if (aux > max) max = aux;
		}
		hijosDeFamiliasConMaxMidiclo.push_back(max*cM);
	}
	std::sort(hijosDeFamiliasConMaxMidiclo.begin(), hijosDeFamiliasConMaxMidiclo.end(),std::greater<int>());

	for (int i = 0; i < hijosDeFamiliasConMaxMidiclo.size(); ++i) {
		std::cout << hijosDeFamiliasConMaxMidiclo[i];
		if (i < hijosDeFamiliasConMaxMidiclo.size() - 1) std::cout << " ";
	}

	std::cout << '\n';

	return true;
}

int main() {

	while (res());
	return 0;
}