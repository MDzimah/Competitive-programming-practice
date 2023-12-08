#include <iostream>

bool resolver() {

	short int x;
	int n;
	std::cin >> x >> n;

	if (!std::cin) return false;

	int resultado = 1, exp = 1;

	for (int i = 1; i <= n; ++i) {
		exp = (exp * x)%1000007;
		resultado = (resultado + exp)%1000007;
	}
	
	std::cout << resultado << '\n';

	return true;
}

int main() {
	while (resolver());

	return 0;
}