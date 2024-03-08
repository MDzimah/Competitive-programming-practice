#include <iostream>
#include <algorithm>
#include <vector>

struct arma {
	int dI, dV, posIni;
};

bool comparar(arma a1, arma a2) {
	if (a1.dI < a2.dI) return true;
	else if (a1.dI > a2.dI) return false;
	else if (a1.dV < a2.dV) return false;
	else if (a1.dV > a2.dV) return true;
	return a1.posIni < a2.posIni;
}

bool res() {
	int V, N;
	std::cin >> V;

	if (V == 0) return false;

	std::cin >> N;

	std::vector <arma> inventario;
	for (int i = 0; i < N; ++i) {
		arma a;
		std::cin >> a.dI >> a.dV;
		a.posIni = i+1;
		inventario.push_back(a);
	}

	std::sort(inventario.begin(), inventario.end(), comparar);

	int M = 0; 
	while (M < inventario.size() && V > 0) {
		V -= inventario[M].dV;
		++M;
	}

	if (V > 0) std::cout << "MUERTE ESCAPA";
	else {
		for (int i = 0; i < M; ++i) {
			std::cout << inventario[i].posIni;
			if (i < M - 1) std::cout << ' ';
		}
	}

	std::cout << '\n';

	return true;
}


int main() {

	while (res());

	return 0;
}

