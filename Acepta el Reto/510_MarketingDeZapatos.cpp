#include <iostream>
#include <vector>
#include <algorithm>

bool res() {
	
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::vector<bool> visMerch(N, false);

	std::vector<int> Th, Tm;
	
	int talla;
	for (int i = 0; i < N; ++i) {
		std::cin >> talla;
		
		if (talla > 0) {
			Th.push_back(talla);
			visMerch[i] = true;
		}
		else Tm.push_back(talla);
	}

	std::sort(Tm.begin(), Tm.end(), std::greater<int>());
	std::sort(Th.begin(), Th.end());
	

	int IndHombre = 0, indMuj = 0;
	for (int j = 0; j < N; ++j) {
		if (visMerch[j]) { std::cout << Th[IndHombre]; ++IndHombre; }
		else { std::cout << Tm[indMuj]; ++indMuj;}

		if (j < N - 1) std::cout << ' ';
	}

	std::cout << '\n';

	return true;
}


int main() {

	while (res());

	return 0;
}