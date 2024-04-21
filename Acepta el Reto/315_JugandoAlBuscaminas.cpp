#include <iostream>
#include <vector>
#include <utility>
#include <string>

using Tab = std::vector <std::vector<char>>;
using vecPar = std::vector <std::pair <short int, short int>>;
using uSi = short int;
vecPar dirs = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };

bool posEvCorrecta(Tab const& t, uSi f, uSi c, uSi i) {
	return f + dirs[i].first < t.size() && f + dirs[i].first >= 0 && c + dirs[i].second < t[0].size() && c + dirs[i].second >= 0;
}

bool bombaEnPosEv(Tab const& t, uSi f, uSi c, uSi i) {
	return t[f + dirs[i].first][c + dirs[i].second] == '*';
}

bool plazaADescubrir(Tab const& t, uSi f, uSi c, uSi i) {
	return t[f + dirs[i].first][c + dirs[i].second] == 'X';
}

void hacerJugada(Tab& t, uSi f, uSi c) {
	uSi nB = 0;
	vecPar posParaContinuar;
	for (uSi i = 0; i < dirs.size(); ++i) {
		if (posEvCorrecta(t, f, c, i)) {
			if (bombaEnPosEv(t, f, c, i)) ++nB;
			else if (nB == 0 && plazaADescubrir(t, f, c, i)) posParaContinuar.push_back({ f + dirs[i].first, c + dirs[i].second });
		}
	}

	if (nB == 0) {
		t[f][c] = '-';
		for (uSi i = 0; i < posParaContinuar.size(); ++i) {
			hacerJugada(t, posParaContinuar[i].first, posParaContinuar[i].second);
		}
	}
	else {
		std::string aux = std::to_string(nB);
		t[f][c] = aux[0];
	}
}

void leer(Tab& t) {
	for (uSi i = 0; i < t.size(); ++i)
		for (uSi j = 0; j < t[0].size(); ++j) {
			char aux;
			std::cin >> aux;
			if (aux == '-')
				t[i][j] = 'X';
			else t[i][j] = aux;
		}
}
void imprimir(Tab const& t) {
	for (uSi i = 0; i < t.size(); ++i) {
		for (uSi j = 0; j < t[0].size(); ++j) {
			if (t[i][j] == '*') std::cout << 'X';
			else std::cout << t[i][j];
		}
		std::cout << '\n';
	}
}

bool res() {

	uSi f, c;
	std::cin >> f >> c;

	if (!std::cin) return false;

	Tab t(f, std::vector<char>(c));
	leer(t);

	uSi k;
	std::cin >> k;

	vecPar jugadas(k);

	for (uSi i = 0; i < k; ++i)
		std::cin >> jugadas[i].first >> jugadas[i].second;

	if (k == 0) imprimir(t);
	else if (t[jugadas[jugadas.size() - 1].first - 1][jugadas[jugadas.size() - 1].second - 1] == '*') std::cout << "GAME OVER\n";
	else {
		for (uSi i = 0; i < k; ++i) {
			if (t[jugadas[i].first - 1][jugadas[i].second - 1] == 'X')
				hacerJugada(t, jugadas[i].first - 1, jugadas[i].second - 1);
		}
		imprimir(t);
	}

	return true;
}

int main() {
	while (res());

	return 0;
}