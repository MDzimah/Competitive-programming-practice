#include <iostream>
#include <vector>

void resolver() {

	char elem;
	int cont = 0;

	std::vector <std::vector <bool>> sud(9, std::vector <bool>(9));

	for (int i = 0; i < 9; ++i) {
		for (int m = 0; m < 9; ++m) {
			sud[i][m] = false;
		}
	}
	for (int i = 0; i < 9; ++i) {
		for (int m = 0; m < 9; ++m) {
			std::cin >> elem;
			if (isalnum(elem)) { 
				sud[i][m] = true; 
				++cont;
			}
		}
	}

	if (cont <= 32) {
		bool rot = true;
		int i = 0;
		while (rot && i <= 4){

			int n = 0;
			while (rot && n < 9) {
				if (sud[i][8 - n] != sud[8 - i][n]) rot = false;
				++n;
			}

			++i;
		}
		if (rot) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
	else std::cout << "NO\n";
}


int main() {
	int numCasos;
	std::cin >> numCasos;
	
	for (int i = 0; i < numCasos; ++i) resolver();


	return 0;
}