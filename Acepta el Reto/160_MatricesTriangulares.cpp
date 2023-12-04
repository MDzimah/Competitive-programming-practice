#include <iostream>
#include <vector>

bool resolver() {
	short int numFilas;
	int num1 = 0,num2 = 0, eleMatriz;
	bool triangular1 = true, triangular2 = true;
	std::cin >> numFilas;
	std::vector <int> matriz (numFilas * numFilas);

	
	if (numFilas == 0) return false;
	else if (numFilas == 1) {
		std::cin >> eleMatriz;
		matriz[0] = eleMatriz;
		std::cout << "SI\n";
		return true;
	}
	else {
		for (int i = 0; i < numFilas * numFilas; ++i) {
			std::cin >> eleMatriz;
			matriz[i] = eleMatriz;
		}

		int n = 1;
		while (triangular1 == true && n < numFilas) {
			for (int k = 0; k < n; ++k) {
				num1 = matriz[k + numFilas * n];
				if (num1 != 0) {
					triangular1 = false;
					break;
				}
			}
			++n;
		}

		int j = 1;
		while (triangular1 == false && triangular2 == true && j < numFilas) {
			for (int f = numFilas * numFilas - 1, l = 0; l < j; --f, ++l) {
				num2 = matriz[f - numFilas * j];
				if (num2 != 0) {
					triangular2 = false;
					break;
				}
			}
			++j;
		}


		if (triangular1 == true || triangular2 == true) std::cout << "SI\n";
		else std::cout << "NO\n";

		return true;
	}

}


int main() {
	while (resolver());

	return 0;
}