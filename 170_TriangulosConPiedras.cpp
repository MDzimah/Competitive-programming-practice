#include <iostream>

bool resolver() {
	int piedras, piedUsadas = 0;
	std::cin >> piedras;

	if (piedras == 0) return false;

	int k = 1;
	while (piedUsadas < piedras) {
		piedUsadas += k;
		++k;
	}

	if (piedUsadas > piedras) {
		piedUsadas = piedUsadas - k + 1;
		k -= 2;
	}
	else k -= 1;

	std::cout << k << ' ' << piedras - piedUsadas << '\n';

	return true;
}


int main() {

	while (resolver());

	return 0;
}