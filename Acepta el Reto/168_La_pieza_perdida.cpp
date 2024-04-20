#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	int n;
	std::cin >> n;

	while (n != 0) {
		
		std::vector <int> p(n-1);
		for (int i = 0; i < n-1; ++i)
			std::cin >> p[i];

		std::sort(p.begin(), p.end());
		
		if (p[0] == 1) {
			int j = 0;
			while (j < p.size() - 1) {
				if (p[j] + 1 != p[j + 1]) break;
				++j;
			}
			std::cout << p[j] + 1 << '\n';
		}
		else std::cout << 1 << '\n';
		
		std::cin >> n;
	}

	return 0;
}