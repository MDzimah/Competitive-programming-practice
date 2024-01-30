#include <iostream>
#include <vector>

int compMinasAlrededor(std::vector <std::vector <char>> const& matriz, int f, int c) {

	int contMinas = 0;

	if (matriz[f][c + 1] == '*') ++contMinas;
	if (matriz[f][c - 1] == '*') ++contMinas;

	int i = 0;
	while (contMinas < 6 && i < 3) {
		if (matriz[f - 1][c - 1 + i] == '*') ++contMinas;
		if (matriz[f + 1][c - 1 + i] == '*') ++contMinas;
		++i;
	}

	if (contMinas >= 6) return 1;
	else return 0;
}

void leerMat(std::vector <std::vector <char>>& matriz, int alto, int ancho) {

	for (int f = 0; f < alto; ++f) {
		for (int c = 0; c < ancho; ++c)
			std::cin >> matriz[f][c];
	}

}

bool resolver() {
	short int ancho, alto, espRod = 0;

	std::cin >> ancho >> alto;

	if (ancho == 0 || alto == 0) return false;
	else {
		std::vector <std::vector <char>> matriz(alto, std::vector <char>(ancho));

		leerMat(matriz, alto, ancho);

		for (int f = 1; f < alto - 1; ++f) {
			for (int c = 1; c < ancho - 1; ++c)
				if (matriz[f][c] == '-') espRod += compMinasAlrededor(matriz, f, c);
		}

		std::cout << espRod << '\n';
	}
	return true;
}

int main() {

	while (resolver());

	return 0;
}