#include <iostream>

const int DIM = 9;

using Sudoku = int[DIM][DIM];

void leer(Sudoku &sudoku) {

	for (int i = 0; i < 9; ++i)
		for (int m = 0; m < 9; ++m)
			std::cin >> sudoku[i][m];

}

bool checkearFila(Sudoku const& sudoku, int fila) {

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0;

	for (int i = 0; i < 9; ++i){
		if (sudoku[fila][i] == 1) ++num1;
		else if (sudoku[fila][i] == 2) ++num2;
		else if (sudoku[fila][i] == 3) ++num3;
		else if (sudoku[fila][i] == 4) ++num4;
		else if (sudoku[fila][i] == 5) ++num5;
		else if (sudoku[fila][i] == 6) ++num6;
		else if (sudoku[fila][i] == 7) ++num7;
		else if (sudoku[fila][i] == 8) ++num8;
		else if (sudoku[fila][i] == 9) ++num9;
	}

	return num1 >=1 && num2 >= 1 && num3 >= 1 && num4 >= 1 && num5 >= 1 && num6 >= 1 && num7 >= 1 && num8 >= 1 && num9 >= 1;

}

bool checkearColumnas(Sudoku const& sudoku, int c) {

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0;

	for (int i = 0; i < 9; ++i) {
		if (sudoku[i][c] == 1) ++num1;
		else if (sudoku[i][c] == 2) ++num2;
		else if (sudoku[i][c] == 3) ++num3;
		else if (sudoku[i][c] == 4) ++num4;
		else if (sudoku[i][c] == 5) ++num5;
		else if (sudoku[i][c] == 6) ++num6;
		else if (sudoku[i][c] == 7) ++num7;
		else if (sudoku[i][c] == 8) ++num8;
		else if (sudoku[i][c] == 9) ++num9;
	}

	return num1 >= 1 && num2 >= 1 && num3 >= 1 && num4 >= 1 && num5 >= 1 && num6 >= 1 && num7 >= 1 && num8 >= 1 && num9 >= 1;

}

bool checkearRegion(Sudoku const& sudoku, int f, int c) {

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0;

	for (int i = 0; i < 3; ++i) {
		for (int m = 0; m < 3; ++m) {
			if (sudoku[f+ i][m+c] == 1) ++num1;
			else if (sudoku[f+ i][m+c] == 2) ++num2;
			else if (sudoku[f + i][m+c] == 3) ++num3;
			else if (sudoku[f + i][m+c] == 4)  ++num4;
			else if (sudoku[f + i][m+c] == 5) ++num5;
			else if (sudoku[f + i][m+c] == 6)++num6;
			else if (sudoku[f + i][m + c] == 7) ++num7;
			else if (sudoku[f + i][m + c] == 8) ++num8;
			else if (sudoku[f + i][m + c] == 9) ++num9;
		}
	}

	return num1 >= 1 && num2 >= 1 && num3 >= 1 && num4 >= 1 && num5 >= 1 && num6 >= 1 && num7 >= 1 && num8 >= 1 && num9 >= 1;

}

void res() {
	Sudoku sudoku;

	leer(sudoku);

	
	bool fila = checkearFila(sudoku, 0);

	int i = 1;
	while (i < 9 && fila) {
		fila = checkearFila(sudoku, i);
		++i;
	}

	bool columna = false;
	if (fila) columna = checkearColumnas(sudoku, 0);

	int m = 1;
	while (m < 9 && fila && columna) {
		columna = checkearColumnas(sudoku, m);
		++m;
	}

	bool region = false;
	if (fila && columna) region = checkearRegion(sudoku, 0, 0);

	int f = 0, c = 1;
	while (f < 3 && region && fila && columna) {
		while (c < 3 && region) {
			region = checkearRegion(sudoku, f*3, c*3);
			++c;
		}
		c = 0;
		++f;
	}

	if (fila && columna && region) std::cout << "SI\n";
	else std::cout << "NO\n";

}

int main() {

	int casos;
	std::cin >> casos;
	for (int i = 0; i < casos; ++i) res();

	return 0;
}