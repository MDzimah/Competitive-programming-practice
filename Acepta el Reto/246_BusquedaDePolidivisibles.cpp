#include <iostream>

void polDiv(long long int N, short unsigned D, int numCifras) {

	if (numCifras <= D && N % numCifras == 0) {
		std::cout << N << '\n';
		for (int i = 0; i < 10; ++i) {
			polDiv(N * 10 + i, D, numCifras + 1);

		}
	}

}

int nCifras(long long n) {
	int c = 1;
	while (n / 10 != 0) {
		++c;
		n /= 10;
	}
	return c;
}

bool res() {

	long long int N;
	short unsigned D;

	std::cin >> N >> D;

	if (!std::cin) return false;

	polDiv(N,D,nCifras(N));
	std::cout << "---\n";

	return true;
}


int main() {

	while (res());

	return 0;
}