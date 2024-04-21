#include <iostream>

int rN(int a, int b, int n) {

	switch (n % 6) {
	case 0: return a;
	case 1: return b;
	case 2: return b - a;
	case 3: return -a;
	case 4: return -b;
	case 5: return a - b;
	}
}

bool res() {

	int a, b, n;
	std::cin >> a >> b >> n;

	if (a == 0 && b == 0 && n == 0) return false;
	std::cout << rN(a, b, n) << '\n';

	return true;
}


int main() {

	while (res());

}