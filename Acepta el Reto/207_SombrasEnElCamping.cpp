#include <iostream>
#include <vector>

bool centroFila(short int col, short int c) {
	return col > 0 && col < c - 1;
}

bool centroColumna(short int fil, short int f) {
	return fil > 0 && fil < f - 1;
}

bool centro(short int fil, short int col, short int f, short int c) {
	return centroColumna(fil,f) && centroFila(col,c);
}

bool ladoIzq(short int col) {
	return col == 0;
}

bool ladoDcho(short int col, short int c) {
	return col == c-1;
}

bool arriba(short int fila) {
	return fila == 0;
}


int esquinaSupIzq(std::vector <std::vector <char>> & m, short int fil, short int col) {

	short int cont1 = 0;

	if (m[fil][col - 1] == '\0') { ++cont1; m[fil][col - 1] = 's'; }
	for (int i = 0; i < 2; ++i) {
		if (m[fil - 1][col - i] == '\0') { ++cont1; m[fil - 1][col-i] = 's'; }
	}

	return cont1;

}
int esquinaSupDcha(std::vector <std::vector <char>>& m, short int fil, short int col) {

	short int cont2 = 0;

	if (m[fil][col + 1] == '\0') { ++cont2; m[fil][col + 1] = 's'; }
	for (short int i = 0; i < 2; ++i) {
		if (m[fil - 1][col + i] == '\0') { ++cont2; m[fil - 1][col + i] = 's';  }
	}

	return cont2;

}
int esquinaInfIzq(std::vector <std::vector <char>>& m, short int fil, short int col) {

	short int cont3 = 0;

	if (m[fil][col - 1] == '\0') { ++cont3; m[fil][col - 1] = 's'; }
	for (short int i = 0; i < 2; ++i) {
		if (m[fil + 1][col - i] == '\0') { ++cont3;  m[fil + 1][col - i] = 's'; }
	}

	return cont3;

}
int esquinaInfDcha(std::vector <std::vector <char>>& m, short int fil, short int col) {

	short int cont4 = 0;

	if (m[fil][col + 1] == '\0') { ++cont4; m[fil][col + 1] = 's';}
	for (short int i = 0; i < 2; ++i) {
		if (m[fil + 1][col + i] == '\0') { ++cont4; m[fil + 1][col + i] = 's'; }
	}

	return cont4;
}

int sombrasCentro(std::vector <std::vector <char>>& m, short int fil, short int col) {

	int sombras = esquinaSupIzq(m, fil, col) + esquinaInfDcha(m, fil, col);
	if (m[fil - 1][col + 1] == '\0') { ++sombras; m[fil - 1][col + 1] = 's'; }
	if (m[fil + 1][col - 1] == '\0') { ++sombras; m[fil + 1][col - 1] = 's'; }
	
	return sombras;

}

int SombrasCentroCasoEsp(std::vector <std::vector <char>>& m, short int fil, short int col, bool casoFila) {

	int cont = 0;

	if (casoFila) {
		if (m[fil][col + 1] == '\0') { ++cont; m[fil][col + 1] = 's'; }
		if (m[fil][col - 1] == '\0') { ++cont; m[fil][col - 1] = 's'; }
	}
	else {
		if (m[fil + 1][col] == '\0') { ++cont; m[fil + 1][col] = 's'; }
		if (m[fil-1][col] == '\0') { ++cont; m[fil-1][col] = 's'; }
	}

	return cont;
}

bool resolver() {

	short int c, f, a;
	std::cin >> c >> f >> a;

	if (c == 0 && f == 0 && a == 0) return false;
	
	short int som = 0, fil, col;

	if (a > 0 && (c > 1 || f > 1)) {
		std::vector <std::vector <char>> m(f, std::vector<char>(c));

		bool casoFila = true;
		if (f > 1) casoFila = false;

		if (f == 1) {
			
			for (short int i = 0; i < a; ++i) {
				std::cin >> col >> fil;
				--fil; --col;

				if (m[fil][col] == 's') --som;
				m[fil][col] = 'i';

				if (centroFila(col,c)) som += SombrasCentroCasoEsp(m, fil, col, casoFila);
				else if (ladoIzq(col)){
					if (m[fil][col + 1] == '\0') { ++som; m[fil][col + 1] = 's'; }
				}
				else { 
					if (m[fil][col - 1] == '\0') { ++som; m[fil][col - 1] = 's'; } 
				}

			}
		}
		else if (c == 1) {

			for (short int i = 0; i < a; ++i) {
				std::cin >> col >> fil;
				--fil; --col;

				if (m[fil][col] == 's') --som;
				m[fil][col] = 'i';

				if (centroColumna(fil,f)) som += SombrasCentroCasoEsp(m, fil, col, casoFila);
				else if (arriba(fil)) {
					if (m[fil + 1][col] == '\0') { ++som; m[fil+1][col] = 's'; }
				}
				else {
					if (m[fil-1][col] == '\0') { ++som; m[fil-1][col] = 's'; }
				}
			}
		}
		else {
			for (short int i = 0; i < a; ++i) {
				std::cin >> col >> fil;
				--fil; --col;

				if (m[fil][col] == 's') --som;
				m[fil][col] = 'i';

				if (centro(fil, col, f, c)) som += sombrasCentro(m, fil, col);
				else {

					if (ladoIzq(col)) {
						if (fil != 0) som += esquinaSupDcha(m, fil, col);
						if (fil < f - 1) {
							som += esquinaInfDcha(m, fil, col);
						}
					}
					else if (ladoDcho(col, c)) {
						if (fil != 0) som += esquinaSupIzq(m, fil, col);
						if (fil < f - 1) {
							som += esquinaInfIzq(m, fil, col);
						}
					}
					else if (arriba(fil)) {
						som = som + esquinaInfIzq(m, fil, col) + esquinaInfDcha(m, fil, col);
					}
					else {
						som = som + esquinaSupIzq(m, fil, col) + esquinaSupDcha(m, fil, col);
					}
				}
			}
		}
	}
	else {
		for (short int i = 0; i < a; ++i) 
			std::cin >> col >> fil;
	}

	std::cout << som << '\n';
	return true;
}




int main() {

	while (resolver());

	return 0;
}

