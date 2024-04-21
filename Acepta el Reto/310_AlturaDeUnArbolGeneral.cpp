#include <iostream>

int altHijo() {

	int n;
	std::cin >> n;

	if (n == 0) {
		return 1;
	}
	else if (n != 0) {
		int altH, altMax = 0;
		for (int i = 0; i < n; ++i) {
			altH = altHijo();
			if (altMax < altH) altMax = altH;

		}

		return 1 + altMax;
	}
}



void res() {

	std::cout << altHijo() << '\n';

}


int main() {

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		res();

	return 0;
}