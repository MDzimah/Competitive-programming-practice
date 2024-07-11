#include <iostream>
#include <vector>

void leer(std::vector <std::vector <int>>& v) {
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v.size(); ++j)
			std::cin >> v[i][j];
}

void contNumRot(std::vector <std::vector <int>> const& v, int &cont, int i, int j) {

	for (int m = i; m < v.size(); ++m)
		for (int n = j; n < v.size(); ++n)
			if (v[i][j] > v[m][n]) ++cont;

}

void sol() {
	
	int dim;
	std::cin >> dim;
	
	std::vector <std::vector<int>> mat(dim, std::vector <int>(dim));
	
	leer(mat);

	int cont = 0;

	for (int i = 0; i < mat.size(); ++i)
		for (int j = 0; j < mat.size(); ++j)
			contNumRot(mat, cont, i, j);

	std::cout << cont << '\n';
}

int main() {

	int T;
	std::cin >> T;

	while (T--) sol();


	return 0;
}