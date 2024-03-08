#include <iostream>
#include <vector>
#include <algorithm>

void res() {
	int numCniv, cand;
	std::cin >> numCniv >> cand;

	std::vector <int> alt(cand);

	for (int i = 0; i < cand; ++i)
		std::cin >> alt[i];

	int cont = 0;
	if (numCniv <= cand) {

		sort(alt.begin(), alt.end());

		int i = 0;
		while (i < alt.size() - numCniv + 1) {
			if (alt[i + numCniv - 1] - alt[i] <= 15) {
				i += numCniv;
				++cont;
			}
			else ++i;
		}
	}

	std::cout << cont << '\n';
}

int main() {

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) res();

	return 0;
}