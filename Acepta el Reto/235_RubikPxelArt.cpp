#include <iostream>
#include <vector>

const short int DIM = 150;

struct Matriz {
	char mat[DIM][DIM];
	short int f, c;
};

Matriz leer(short int f, short int c) {
	Matriz m;
	m.f = f;
	m.c = c;

	for (int i = 0; i < f; ++i)
		for (int j = 0; j < c; ++j)
			std::cin >> m.mat[i][j];

	return m;
}

bool encontradoFun(std::vector <std::vector <char>> const& matCasos, Matriz const& m, short int fila, short int columna, short int filaVector) {
	bool encontrado = true;

	int i = 0, c = 0;
	while (c < 3 && encontrado) {
		if (m.mat[fila][columna+c] != matCasos[filaVector][c]) encontrado = false;
			++c;
	}
	++fila; ++filaVector;
	c = 0;
	while (c < 3 && encontrado) {
		if (m.mat[fila][columna+c] != matCasos[filaVector][c]) encontrado = false;
		++c;
	}
	++fila; ++filaVector;
	c = 0; 
	while (c < 3 && encontrado) {
		if (m.mat[fila][columna+c] != matCasos[filaVector][c]) encontrado = false;
		++c;
	}

	return encontrado;
}

bool res() {

	short int f, c;

	std::cin >> f >> c;

	if (f == 0 || c == 0) return false;

	Matriz cubo;

	cubo.f = f*3;
	cubo.c = c*3;


	cubo = leer(cubo.f, cubo.c);

	int casos;
	std::cin >> casos;

	std::vector <std::vector <char>> matCasos(3 * casos, std::vector <char>(3));
	
	for (int i = 0; i < 3 * casos; ++i)
		for (int m = 0; m < 3; ++m)
			std::cin >> matCasos[i][m];

	bool encontrado = false; 
	short int i = 0, indColum = 0;

	for (int l = 0; l < casos; ++l){

		while (i < cubo.f && !encontrado) {

			int m = 0;
			while (!encontrado && m < cubo.c) {
				encontrado = encontradoFun(matCasos, cubo, i, m, l * 3);
				m += 3;
			}
			indColum = m;
			
			i += 3;
		}
		if (encontrado) std::cout << (i - 3) / 3 + 1 << ' ' << (indColum - 3) / 3 + 1 << '\n';
		else std::cout << "NO SE USA\n";
		encontrado = false;

		i = 0;
	}

	return true;
}


int main() {

	while (res());

		return 0;
}