#include <iostream>
#include <vector>

bool res() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector < std::vector< char>> mat (n, std::vector<char>(n));

	for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
			std::cin >> mat[i][k];

	char op; int v;

	std::cin >> op;

	while (op != 'x') {

		std::cin >> v;

		
		if (op == 'f') {

			if (v > 0) {

				char aux;
				aux = mat[v - 1][n - 1];
				for (int i = n - 1; i > 0; --i) {
					mat[v - 1][i] = mat[v - 1][i - 1];
				}
				mat[v - 1][0] = aux;

			}
			else {
				v = abs(v);
				char aux;
				aux = mat[v - 1][0];
				for (int i = 0; i < n-1; ++i) {
					mat[v - 1][i] = mat[v - 1][i + 1];
				}
				mat[v - 1][n - 1] = aux;

			}

		}
		else {
			
			if (v > 0) {
				char aux;
				aux = mat[n-1][v - 1];
				for (int i = n - 1; i > 0; --i) {
					mat[i][v - 1] = mat[i - 1][v - 1];
				}
				mat[0][v - 1] = aux;

			}
			else {

				v = abs(v);

				char aux;
				aux = mat[0][v-1];
				for (int i = 0; i < n - 1; ++i) {
					mat[i][v - 1] = mat[i + 1][v - 1];
				}
				mat[n - 1][v - 1] = aux;
				
			}

		}



		std::cin >> op;
	}


	for (int i = 0; i < n; ++i) {
		for (int m = 0; m < n; ++m)
			std::cout << mat[i][m];
		std::cout << '\n';
	}
	std::cout << "---\n";


	return true;
}

int main() {

	while (res());

	return 0;
}