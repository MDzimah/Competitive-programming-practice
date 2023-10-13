#include <iostream>
#include <string>

void resolver() {
	std::string nombreNieto,nombres;
	int numNombres,nombreNietoDicho = 0;

	std::cin >> nombreNieto >> numNombres;

	for (int n = 0; n < numNombres; ++n) { 
		std::cin >> nombres;
		if (nombres == nombreNieto) ++nombreNietoDicho;
	}
	

	if (numNombres == 1 || nombres != nombreNieto || nombreNietoDicho > 1) std::cout << "FALSA\n";
	else if (nombres == nombreNieto) std::cout << "VERDADERA\n";
}


int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) resolver();

	return 0;
}