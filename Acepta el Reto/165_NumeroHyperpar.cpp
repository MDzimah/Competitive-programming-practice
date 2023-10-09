#include <iostream>

bool resolver() {
	int num;
	bool impar = false;

	std::cin >> num;

	if (num < 0) return false;

	while (impar == false && num > 0) {
		if (num % 2 != 0) impar = true;
		num /= 10;
	}

	if (impar) std::cout << "NO\n";
	else std::cout << "SI\n";

	return true;
}


int main() {
	while (resolver());

	return 0;
}