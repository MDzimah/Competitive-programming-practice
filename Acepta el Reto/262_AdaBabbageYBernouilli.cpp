#include <iostream>

bool resolver() {
	unsigned long long int n, p, resultado = 1, potencia = 1;

	std::cin >> n >> p;
	if (n == 0 && p == 0) return false;

	for (int k = 2; k <= n; ++k) {
		for (int f = 0; f < p; ++f) potencia = (potencia * k) % 46337;
		resultado = (resultado + potencia) % 46337;
		potencia = 1;
	}

	std::cout << resultado << '\n';

	return true;
}

int main() {

	while (resolver());

	return 0;
}