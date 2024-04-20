#include <iostream>

bool balanceado(int pi, int di, int pd, int dd, int &suma) {
	bool ladoIzq = true, ladoDcho = true;

	int piI, diI, pdI, ddI, piD, diD, pdD, ddD;

	if (pi == 0) {
		std::cin >> piI >> diI >> pdI >> ddI;
		ladoIzq = balanceado(piI, diI, pdI, ddI, pi);
	}
	if (pd == 0) {
		std::cin >> piD >> diD >> pdD >> ddD;
		ladoDcho = balanceado(piD, diD, pdD, ddD,pd);
	}
	suma = pi + pd;
	if (ladoIzq && ladoDcho && pi*di == pd*dd) return true;
	else return false;
}


bool res() {

	int pi, di, pd, dd,suma;

	std::cin >> pi >> di >> pd >> dd;

	if (pi == 0 && di == 0 && pd == 0 && dd == 0) return false;

	if (balanceado(pi, di, pd, dd,suma)) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}


int main() {

	while (res());

	return 0;
}