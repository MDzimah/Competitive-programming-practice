#include <iostream>

bool resolver() {
	long long int tramoPrimero, tramoSegundoYSucesivos, personas, mesas, mcd = 1;

	std::cin >> tramoPrimero;
	if (tramoPrimero == 0) return false; //evaluacion del valor centinela
	else std::cin >> tramoSegundoYSucesivos;

	personas = tramoPrimero + tramoSegundoYSucesivos;

	if (tramoSegundoYSucesivos == 0) personas = 1; //tratamiento del caso en el que solo hay un tramo de personas
	else {
		while (tramoSegundoYSucesivos > 0) { //calcula el m.c.d de los dos primeros tramos si son distintos a cero
			long long int aux = tramoPrimero;
			tramoPrimero = tramoSegundoYSucesivos;
			tramoSegundoYSucesivos = aux % tramoSegundoYSucesivos;
		}
		mcd = tramoPrimero;
	

		std::cin >> tramoSegundoYSucesivos;
		while (tramoSegundoYSucesivos != 0) { //con el m.c.d calculado para los dos primeros tramos, se hace de nuevo el m.c.d entre el viejo m.c.d y el nuevo valor que se lee sucesivamente hasta que "tramoSegundoYSucesivos" sea 0
			personas += tramoSegundoYSucesivos;
			while (tramoSegundoYSucesivos > 0) {
			long long int aux = mcd;
			mcd = tramoSegundoYSucesivos;
			tramoSegundoYSucesivos = aux % tramoSegundoYSucesivos;
			}
		std::cin >> tramoSegundoYSucesivos;
		}
	}

	mesas = personas / mcd; //las personas calculadas dividido por el m.c.d global de todos los valores leidos en el caso

	std::cout << mesas << '\n';

	return true;
}

int main() {
	while (resolver());

	return 0;
}
