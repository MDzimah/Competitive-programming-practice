#include <iostream>

bool resolver() {
	int piso,pisoAux = 0,recorrido = 0;
	bool salir = false;
	std::cin >> piso;

	if (piso < 0) return false;

	
	while (pisoAux != -1 && salir == false) {
		std::cin >> pisoAux;
		if (pisoAux == -1) salir = true;
		else if (piso < pisoAux) recorrido += pisoAux - piso;
		else if (piso == pisoAux) recorrido = recorrido;
		else recorrido += piso - pisoAux;
		piso = pisoAux;
	}
	
	std::cout << recorrido << '\n';

	return true;
}

int main() {
	
	while (resolver());

	return 0;
}