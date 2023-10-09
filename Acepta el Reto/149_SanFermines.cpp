#include <iostream>

bool resuelveCaso() {
    long int toros,velocidad,velocidadAux;
    std::cin >> toros;
    std::cin >> velocidad;
   
    if (!std::cin)
        return false;

    for (int k = 1; k < toros; ++k) {
        std::cin >> velocidadAux;
        if (velocidadAux > velocidad) velocidad = velocidadAux;
    }

    std::cout << velocidad << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
