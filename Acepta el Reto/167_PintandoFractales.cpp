#include <iostream>

int tinta(int l, int &nCuad, int &length) {

	if (l == 1) {
		return length + nCuad * 4 * l;
	}
	else {
		
		length += nCuad * 4 * l;

		nCuad *= 4;
		l /= 2;
		
		tinta(l, nCuad, length);
	}
}

bool res() {

	int l;
	std::cin >> l;
	
	if (!std::cin) return false;

	int length = 0, nC = 1;

	if (l != 0) {
		std::cout << tinta(l, nC, length) << '\n';
	}
	else std::cout << 0 << '\n';

	return true;
}

int main() {

	while (res());

	return 0;

}