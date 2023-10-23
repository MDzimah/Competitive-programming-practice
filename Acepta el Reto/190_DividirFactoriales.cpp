#include <iostream>

bool resolver() {
	int num, den;
	unsigned long long int resultado = 1;

	std::cin >> num >> den;

	if (num < den) return false;
	else if (num == den) resultado = 1;
	else if (num - den == 1) resultado = num;
	else { 
		for (int i = den + 1; i <= num; ++i) 
			resultado *= i; 
	}
	
	std::cout << resultado << '\n';

	return true;
}

int main() {

	while( resolver());

	return 0;
}