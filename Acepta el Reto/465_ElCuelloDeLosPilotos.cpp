#include <iostream>
#include <vector>

struct posCoche {
	int f, c;
};

bool upSiguientePos(std::vector < std::vector <char>>const& circuito, posCoche &pos, bool &up, bool&down) {
	if (pos.f - 1 < 0) return false;
	else if (circuito[pos.f - 1][pos.c] == '#' || circuito[pos.f - 1][pos.c] == 'O') { --pos.f; up = true; down = false; return true; }
	else return false;
}

bool dchaSiguientePos(std::vector < std::vector <char>>const& circuito, int c, posCoche &pos, bool &dcha, bool & izq) {
	if (pos.c + 1 > c - 1) return false;
	else if (circuito[pos.f][pos.c + 1] == '#' || circuito[pos.f][pos.c + 1] == 'O') { ++pos.c; dcha = true; izq = false; return true; }
	else return false;
}

bool izqSiguientePos(std::vector < std::vector <char>>const& circuito, posCoche &pos, bool &izq, bool&dcha) {
	if (pos.c - 1 < 0) return false;
	else if (circuito[pos.f][pos.c - 1] == '#' || circuito[pos.f][pos.c - 1] == 'O') { --pos.c; izq = true; dcha = false;  return true; }
	else return false;
}

bool downSiguientePos(std::vector < std::vector <char>>const& circuito, int f, posCoche &pos, bool &down, bool& up) {
	if (pos.f + 1 > f - 1) return false;
	else if (circuito[pos.f + 1][pos.c] == '#' || circuito[pos.f + 1][pos.c] == 'O') { ++pos.f; down = true; up = false; return true; }
	else return false;
}

void leerEntrada(std::vector < std::vector <char>>& circuito, short int f, short int c, posCoche &pos) {

	for (int i = 0; i < f; ++i)
		for (int m = 0; m < c; ++m) {
			std::cin >> circuito[i][m];
			if (circuito[i][m] == 'O') {
				pos.f = i;
				pos.c = m;
			}
		}

}

bool resolver() {

	short int f, c;
	std::cin >> c >> f;

	if (!std::cin) return false;

	std::vector < std::vector <char>> circuito (f, std::vector <char>(c));
	posCoche posIni;

	leerEntrada(circuito, f, c, posIni);

	posCoche pos;
	pos.f = posIni.f;
	pos.c = posIni.c;

	bool izq = false, dcha = false, up = false, down = false;
	int i = 0;
	
	if (upSiguientePos(circuito, pos, up, down));
	else if (downSiguientePos(circuito, f, pos, down, up));
	else if (dchaSiguientePos(circuito, c, pos,dcha, izq));
	else if (izqSiguientePos(circuito, pos, izq, dcha));
	else ++i; // Para caso en el que no hay almohadillas en ninguna parte en torno a la posición inicial

	int curIzq = 0, curDcha = 0;
	
	if (i == 0) {
		while (pos.f != posIni.f || pos.c != posIni.c) {
			if (!down && upSiguientePos(circuito, pos, up, down)) {
				if (dcha) { ++curIzq; dcha = false; }
				else if (izq) { ++curDcha; izq = false; }
			}
			else if (!up && downSiguientePos(circuito, f, pos, down, up)) {
				if (dcha) { ++curDcha; dcha = false; }
				else if (izq) { ++curIzq; izq = false; }
			}
			else if (!izq && dchaSiguientePos(circuito, c, pos, dcha,izq)) {
				if (up) { ++curDcha; up = false; }
				else if (down) { ++curIzq; down = false; }
			}
			else if (!dcha && izqSiguientePos(circuito, pos, izq, dcha)) {
				if (up) { ++curIzq; up = false; }
				else if (down) { ++curDcha; down = false; }
			}
		}
	}
	

	if (curDcha < curIzq)  std::cout << curDcha << ' ' << curIzq << '\n';
	else std::cout << curIzq << ' ' << curDcha << '\n';

	return true;
}

int main() {

	while (resolver());

	return 0;
}


