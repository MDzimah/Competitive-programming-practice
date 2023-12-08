#include <iostream>
#include <algorithm>

bool resolver() {

	int numValores;
	std::cin >> numValores;
	if (numValores == 0) return false;

	int moda, valores;

	if (numValores > 1) {
		int lista[25000], cont = 1, contModa = 1;

		for (int i = 0; i < numValores; ++i) {
			std::cin >> valores;
			lista[i] = valores;
		}

		std::sort(lista, lista + numValores);

		for (int j = 0; j < numValores; ++j) {

			if (lista[j] == lista[j + 1]) ++cont;
			else if (contModa < cont) {
				contModa = cont;
				moda = lista[j];
				cont = 1;
			}
			else cont = 1;

		}
	}
	else {
		std::cin >> valores;
		moda = valores;
	}

	std::cout << moda << '\n';


	return true;
}




int main() {

	while (resolver());

	return 0;
}