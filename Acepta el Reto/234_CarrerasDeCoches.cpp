#include <iostream>
#include <algorithm>
#include <vector>

void res() {
	int N, V;
	std::cin >> N >> V;
	std::vector <int> volt(N);
	for (int i = 0; i < volt.size(); ++i)
		std::cin >> volt[i];

	std::sort(volt.begin(), volt.end());

	int i = 0, j = 1;
	bool pareja = false;
	int cont = 0;
	while (i < volt.size() && cont < volt.size()/2) {
		while (j < volt.size()-i && !pareja && cont < volt.size() / 2) {
			if (volt[i] + volt[i + j] >= V) {
				pareja = true;
				volt[i + j] = -999;
				++cont;
			}
			++j;
		}
		++i;
		pareja = false;
		j = 1;
	}

	std::cout << cont << '\n';
}

int main() {
	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i) res();

	return 0;
}