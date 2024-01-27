#include <iostream>
#include <vector>

bool tipoEspiral(int x, int &nV) {

	int i = 1;
	while (i < x) { 
		i += 4; 
		++nV; 
	}

	if (i == x) return true;
	else return false;

}

bool res() {

	int N, numVueltas = 0, sum = 0;
	std::cin >> N;

	if (N == 0) return false;

	std::vector <std::vector<int>> gal(N, std::vector<int>(N));

	for (int i = 0; i < N; ++i)
		for (int m = 0; m < N; ++m)
			std::cin >> gal[i][m];

	if (N == 3) {
		sum = gal[1][1] + gal[0][1] + gal[0][2];
	}
	else {

		if (tipoEspiral(N, numVueltas)) { //if true, tipo espiral como el 5. False, tipo espiral 7

			for (int i = 0; i < N; ++i)
				sum += gal[i][0];
		}
		else {

			--numVueltas;

			int a = N - 2;
			while (a >= 0) {
				sum += gal[a][1];
				--a;
			}

			int b = 2;
			while (b < N) {
				sum += gal[0][b];
				++b;
			}

		}

		
		int ind = 0, k = 0, i = 1;

		while (ind < numVueltas) {
		
			int up = 0;
			while (up < i) {
				sum += gal[N / 2 + k - up][N / 2 - k];
				++up;
			}
			int coordX = N / 2 + k - up;
			int coordY = N / 2 - k;
			++i;
			int right = 0;
			while (right < i) {
				sum += gal[coordX][coordY + right];
				++right;
			}
			++i;

			coordY = coordY + right;

			int down = 0;
			while (down < i) {
				sum += gal[coordX + down][coordY];
				++down;
			}

			++i;

			coordX = coordX + down;

			int left = 0;
			while (left < i) {
				sum += gal[coordX][coordY - left];
				++left;
			}
			++i;

			++ind;
			k += 2;
		}

	}
	

	std::cout << sum << '\n';

	return true;
}

int main (){

	while (res());

	return 0;
}