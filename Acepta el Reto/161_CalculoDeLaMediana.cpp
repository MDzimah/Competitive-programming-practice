#include <iostream>
#include <vector>
#include <algorithm>

bool resolver() {
	int numEle, valoresMuestras, mediana;
	std::cin >> numEle;

	if (numEle == 0) return false;

	std::vector <int> valMuestras(numEle);
	
	
	for (int i = 0; i < numEle; ++i) {
		std::cin >> valoresMuestras;
		valMuestras[i] = valoresMuestras;
	}
	std::sort (valMuestras.begin(), valMuestras.end());

	if (numEle % 2 == 0) mediana = valMuestras[numEle / 2 - 1] + valMuestras[numEle / 2];
	else mediana = 2*valMuestras[numEle / 2];

	std::cout << mediana << '\n';

	return true;
}

int main() {

	while (resolver());

	return 0;
}