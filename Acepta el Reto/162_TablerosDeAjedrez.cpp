#include <iostream>
#include <iomanip>

bool resolver() {
	int tamEscaque;
	char carcEscaque;

	std::cin >> tamEscaque >> carcEscaque;

	if (tamEscaque == 0) return false;

	std::cout << '|' << std::setw(tamEscaque * 8) << std::setfill('-') << '-' << "|\n";
	
	for (int i = 0; i < 4; ++i) {
		for (int n = 0; n < tamEscaque; ++n) {
			std::cout << '|';
			for (int j = 0; j < 4; ++j) std::cout << std::setw(tamEscaque) << std::setfill(' ') << ' ' << std::setw(tamEscaque) << std::setfill(carcEscaque) << carcEscaque;
			std::cout << "|\n";
		}
		for (int n = 0; n < tamEscaque; ++n) {
			std::cout << '|';
			for (int j = 0; j < 4; ++j) std::cout << std::setw(tamEscaque) << std::setfill(carcEscaque) << carcEscaque << std::setw(tamEscaque) << std::setfill(' ') << ' ';
			std::cout << "|\n";
		}
		
	}

	std::cout << '|' << std::setw(tamEscaque * 8) << std::setfill('-') << '-' << "|\n";

	return true;
}

int main() {

	while (resolver());

	return 0;
}