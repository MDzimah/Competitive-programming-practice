#include <iostream>

void resolver() {

	int numTemp,picos = 0,valles = 0,regTemp1,regTemp2,regTemp3;

	std::cin >> numTemp;

	if (numTemp > 2) {

		std::cin >> regTemp1 >> regTemp2;

		for (int i = 2; i < numTemp; ++i) {
			std::cin >> regTemp3;

			if (regTemp1 < regTemp2 && regTemp2 > regTemp3) ++picos;
			else if (regTemp1 > regTemp2 && regTemp2 < regTemp3) ++valles;

			regTemp1 = regTemp2;
			regTemp2 = regTemp3;
		}
	}
	else if (numTemp == 2) std::cin >> regTemp1 >> regTemp2;
	else  std::cin >> regTemp1;
	
	std::cout << picos << ' ' << valles << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) resolver();

	return 0;
}