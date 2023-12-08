#include <iostream>
#include <vector>



bool resolver() {

	int numMont,abadias = 0, max = 0;
	std::cin >> numMont;
	std::vector <int> alt(numMont);
	

	if (numMont == 0) return false;

	for (int k = 0; k < numMont; ++k)
		std::cin >> alt[k];
	

	for (int i = numMont - 1; i >= 0; --i) {
		if (alt[i] > max) { 
			++abadias;
			max = alt[i];
		}
	}
	
	std::cout << abadias << '\n';


	return true;
}

int main() {

	while (resolver());
}