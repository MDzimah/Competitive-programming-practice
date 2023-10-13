#include <iostream>

void resolver() {
	int conchas = 0,mejillones = 0, LectMejillones;

	std::cin >> LectMejillones;

	while (LectMejillones != -1) {
		mejillones += LectMejillones;
		++conchas;
		std::cin >> LectMejillones;
	}

	if (conchas == mejillones) std::cout << "Justo\n";
	else if (conchas > mejillones) std::cout << "Timo\n";
	else std::cout << "Suerte\n";
}

int main() {
	int diasCompraMejillones;
	std::cin >> diasCompraMejillones;

	for (int k = 0; k < diasCompraMejillones; ++k) resolver();

	return 0;
}