#include <iostream>
#include <vector>
#include <algorithm>

struct Tar {
	int p, t;
};
bool comparar(Tar t1, Tar t2) {
	if (t1.p < t2.p) return true;
	else if (t1.p == t2.p) return t1.t > t2.t;
	else return false;
}

bool res() {

	int numT;
	std::cin >> numT;


	if (numT == 0) return false;

	
	std::vector <Tar> tar;
	for (int i = 0; i < numT; ++i) {
		Tar t;
		std::cin >> t.p >> t.t;
		tar.push_back(t);
	}

	if (numT > 1) {
		std::sort(tar.begin(), tar.end(), comparar);

		for (int i = tar.size() - 1; i >= 0; --i)
			std::cout << tar[i].p << ' ' << tar[i].t << '\n';
	}
	else std::cout << tar[0].p << ' ' << tar[0].t << '\n';

	std::cout << "---\n";
	return true;
}


int main() {

	while (res());

	return 0;
}