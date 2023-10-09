#include <iostream>
#include <string>

bool resolver() {

	long long int muestras, valEco,valAux;
	std::string result = "SI";

	std::cin >> muestras;
	if (muestras == 0) return false;

	std::cin >> valEco;

	for (int k = 1; k < muestras; ++k) {
		std::cin >> valAux;
		if (valEco >= valAux) result = "NO";
		valEco = valAux;
	}

	std::cout << result << '\n';

	return true;
}

int main() {

	while (resolver());

	return 0;
}