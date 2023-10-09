#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Casos() {
	int burros, sacos, burrosMax = 0;
	
	cin >> burros >> sacos;
	vector <int> pesos(sacos);

	for (int i = 0; i < sacos; ++i) {
		cin >> pesos[i];
	}

	sort(pesos.begin(), pesos.end());

	for (int f = 0; f < sacos-1; ++f) {
		if (pesos[f] == pesos[f + 1]) {
			++burrosMax;
			pesos[f] = 0, pesos[f + 1] = 0;
		}
	}

	if (burrosMax > burros) burrosMax = burros;

	cout << burrosMax << '\n';
}


int main() {
	int numCasos;
	cin >> numCasos;

	for (int k = 0; k < numCasos; ++k) Casos();

	return 0;
}