#include <iostream>
#include <vector>

using Matriz = std::vector <std::vector<int>>;

bool chequearPuntoSilla(Matriz const& mat, short int fila, short int columna) {

	bool fMayorIg = true, fMenorIg = true;

	int c = 0;
	while (c < mat[0].size() && (fMayorIg || fMenorIg)) {
		
		if (fMayorIg) {
			if (c != columna) {
				if (mat[fila][columna] >= mat[fila][c]) fMayorIg = true;
				else fMayorIg = false;
			}
		}

		if (fMenorIg) {
			if (c != columna) {
				if (mat[fila][columna] <= mat[fila][c]) fMenorIg = true;
				else fMenorIg = false;
			}
		}
		++c;
	}

	bool cMayorIg = false, cMenorIg = false;

	if (fMayorIg) cMenorIg = true;
	if (fMenorIg) cMayorIg = true;


	if (fMayorIg || fMenorIg) {

		int f = 0;

		while (f < mat.size() && (cMayorIg || cMenorIg)) {

			if (cMayorIg && fMenorIg) {
				if (f != fila) {
					if (mat[fila][columna] >= mat[f][columna]) cMayorIg = true;
					else cMayorIg = false;
				}
			}

			if (cMenorIg && fMayorIg) {
				if (f != fila) {
					if (mat[fila][columna] <= mat[f][columna]) cMenorIg = true;
					else cMenorIg = false;
				}
			}
			++f;
		}
	}

	return (fMayorIg && cMenorIg) || ((fMenorIg && cMayorIg));
}

void leer (Matriz &mat){

	for (int i = 0; i < mat.size(); ++i)
		for (int m = 0; m < mat[0].size(); ++m)
			std::cin >> mat[i][m];

}

bool res() {

	short int f, c;
	

	std::cin >> f >> c;

	if (f == 0 && c == 0) return false;

	Matriz mat(f, std::vector<int>(c));
	leer(mat);
	
	bool ptoSilla = false;

	if (f != 1 && c != 1) {

		short int fila = 0;
		while (fila < mat.size() && !ptoSilla) {
			short int columna = 0;
			while (columna < mat[0].size() && !ptoSilla) {
				ptoSilla = chequearPuntoSilla(mat, fila, columna);
				++columna;
			}
			++fila;
		}
	}
	else ptoSilla = true;

	if (ptoSilla) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}


int main() {

	while (res());
	return 0;
}