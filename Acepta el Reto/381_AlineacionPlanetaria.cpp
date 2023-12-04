#include <iostream>

int mcd(int a, int b) {
	while (b > 0) {
		int aux = a;
		a = b;
		b = aux % b;
	}
	return a;
}


bool resolver() {
	int numDiasCoinciden;
	short int numPlan, periodo1,periodo2,periodoAux;

	std::cin >> numPlan;
	if (numPlan == 0) return false;

	std::cin >> periodo1 >> periodo2;
	numDiasCoinciden = periodo1*(periodo2/mcd(periodo1, periodo2));

	for (int i = 0; i < numPlan - 2; ++i) {
		std::cin >> periodoAux;
		numDiasCoinciden = numDiasCoinciden * (periodoAux / mcd(numDiasCoinciden, periodoAux));
	}
	
	std::cout << numDiasCoinciden << '\n';
	
	return true;
}

int main() {
	while (resolver());

	return 0;
}