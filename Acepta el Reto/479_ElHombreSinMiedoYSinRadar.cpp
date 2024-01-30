#include <iostream>
#include <vector>

bool avance(std::vector <std::vector<char>> const& mat, short int f, short int c, std::string dir, short int fila, short int col, short int& distancia) {

	bool villano = false;

	int i = 1;
	if (dir == "ARRIBA") {

		while (!villano && i <= fila) {
			if (mat[fila - i][col] == 'X') villano = true;
			++i;
		}

	}
	else if (dir == "DERECHA") {

		
		while (!villano && i <= c-col) {
			if (mat[fila][col+i] == 'X') villano = true;
			++i;
		}

	}
	else if (dir == "ABAJO") {

		
		while (!villano && i <= f - fila) {
			if (mat[fila + i][col] == 'X') villano = true;
			++i;
		}

	}
	else {

		while (!villano && i <= col) {
			if (mat[fila][col - i] == 'X') villano = true;
			++i;
		}

	}

	distancia = i-1;
	return villano;

}


int main() {

	int f, c;
	std::cin >> f >> c;

	while (f != 0 && c != 0) {
		std::vector <std::vector<char>> mat(f, std::vector<char>(c));

		char aux;
		for (int i = 0; i < f; ++i)
			for (int m = 0; m < c; ++m)
				std::cin >> mat[i][m];
		
		--f; --c;

		int cons;
		std::cin >> cons;

		std::vector <std::string> dir (cons);
		std::vector <short int> filaColDist (3*cons);
		
		
		for(int i = 0; i < cons; ++i){
			std::cin >> filaColDist[i] >> filaColDist[i + cons] >> dir[i];
			--filaColDist[i]; --filaColDist[i + cons];
		}
		
		for (int i = 0; i < cons; ++i) {
			if (avance(mat,f,c,dir[i], filaColDist[i], filaColDist[i+cons], filaColDist[i + 2 * cons])) std::cout << filaColDist[i + 2 * cons] << '\n';
			else std::cout << "NINGUNO\n";
		}

		std::cout << "---\n";

		std::cin >> f >> c;
		
	}

	
	return 0;
}