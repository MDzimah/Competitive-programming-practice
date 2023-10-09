#include <iostream>
#include <math.h>

bool res() {
	long int leg;
	
	int escudos = 0;

	std::cin >> leg;

	if (leg == 0) return false;

	while (leg >0) {

		int i = 1;

		while (i * i <= leg) ++i;

		--i;

		if (leg > 1) escudos += i*i + 8 + 4 * (i-2);
		else escudos += 5;

		leg -= i * i;
	}

	std::cout << escudos << '\n';

	return true;
}

int main() {
	while (res());

	return 0;
}