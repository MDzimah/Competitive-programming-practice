#include <iostream>
#include <vector>


void sol() {

	int N, numRot;
	std::cin >> N >> numRot;

	std::vector <int> v(N);
	std::vector <int> aux(N);

	while (N--) std::cin >> v[v.size() - N - 1];

	for (int i = 0; i < v.size(); ++i) {
		
		int id = (i + numRot) % v.size();

		aux[id] = v[i];
	}
	
	std::cout << aux[0];

	for (int i = 1; i < aux.size(); ++i) std::cout << ' ' << aux[i];

	std::cout << '\n';
}

int main() {

	int T;
	std::cin >> T;

	while (T--) sol();


	return 0;
}