#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct ciclistas {
	int tiempo, pel, posIni;
};

int convertidor(std::string hora) {
	return ((hora[0]- '0') * 10 + hora[1] - '0') * 3600 + ((hora[3] - '0') * 10 + hora[4] - '0') * 60 + ((hora[6] - '0') * 10 + hora[7] - '0');
}


int findCiclista(std::vector <ciclistas> const& tiempos, int i) {
	
	int n = 0;
	while (n < tiempos.size() && tiempos[n].posIni != i) ++n;

	return tiempos[n].pel;
}

bool comparar(ciclistas c1, ciclistas c2) {
	return (c1.tiempo < c2.tiempo);
}

bool res() {
	
	int n;
	std::cin >> n;

	if (!std::cin) return false;
	
	std::vector <ciclistas> tiempos (n);

	std::string hora;
	for (int i = 0; i < n; ++i) {
		std::cin >> hora;
		tiempos[i].tiempo = convertidor(hora);
		tiempos[i].posIni = i;
	}
	
	if (tiempos.size() > 1) {
		std::sort(tiempos.begin(), tiempos.end(), comparar);

		int pel = 1, dif;
		for (int i = 0; i < tiempos.size() - 1; ++i) {
			dif = tiempos[i + 1].tiempo - tiempos[i].tiempo;
			if (dif <= 1) {
				tiempos[i].pel = tiempos[i + 1].pel = pel;
			}
			else {
				tiempos[i].pel = pel;
				pel = i + 2;
				tiempos[i + 1].pel = pel;
			}
		}

		for (int i = 0; i < tiempos.size(); ++i) {
			std::cout << findCiclista(tiempos, i) << '\n';
		}
	}
	else std::cout << "1\n";

	std::cout << "---\n";
	return true;
}


int main() {

	while (res());

	return 0;
}