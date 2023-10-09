#include <iostream>

bool resolver() {
    long long int est_Pais, paises, parejas;
    long long int estudTot = 0, parejQuit = 0;
    std::cin >> paises;

    if (paises == 0) return false;

    for (int i = 0; i < paises; ++i) {
        std::cin >> est_Pais;
        estudTot += est_Pais;
        parejQuit += (est_Pais * (est_Pais - 1)) / 2; //combinacion de los estudiantes de cada pais tomados de 2 en 2, lo que resulta en las parejas de la misma nacionalidad que hay que quitar del nº total de parejas
    }

    parejas = (estudTot * (estudTot - 1)) / 2 - parejQuit; //combinacion de estTot tomados de 2 en 2 (quitando las parejas de la misma nacionalidad)

    std::cout << parejas << '\n';

    return true;
}

int main() {
    while (resolver());

    return 0;
}
