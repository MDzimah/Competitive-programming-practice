#include <iostream>

const std::string tab = "   ";

int fib(int n) {
	if (n <= 1) {
		return n;
	} 
	return fib(n - 2) + fib(n - 1) ;
}

void imprimirArbol(int tam, int nivelActual) {

	for (int i = 0; i < nivelActual; ++i)
		std::cout << tab; 

	if (tam == 0 || tam == 1) { 
		std::cout << tam << '\n'; 
		return;
	}
	
	std::cout << fib(tam) << '\n';

	imprimirArbol(tam - 2, nivelActual + 1);
	imprimirArbol(tam - 1, nivelActual + 1);
}

bool res() {

	int tam;
	std::cin >> tam;

	if (tam < 0) return false;

	imprimirArbol(tam, 0);

	std::cout << "====\n";

	return true;
}


int main() {

	while (res());


	return 0;
}
