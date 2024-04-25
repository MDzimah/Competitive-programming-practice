#include <iostream>

long long int tam(long long int numero) {
    if (numero == 0) return 0;
    return 2 * tam(numero - 1) + numero + 2;
}

void resolver(long long int numero, long long int posicion) {

    if (numero > 1) {
        if (posicion <= tam(numero - 1))
            return resolver(numero - 1, posicion);
        if (posicion > tam(numero - 1) + 2 + numero)
            return resolver(numero - 1, posicion - tam(numero - 1) - numero - 2);
    }

    if (posicion == tam(numero - 1) + 1) std::cout << "B\n";
    else if (posicion == tam(numero - 1) + numero + 2) std::cout << "H\n";
    else std::cout << "U\n";

}

int main() {

    long long int numero, posicion;

    while (std::cin >> numero >> posicion) {
        resolver(numero, posicion);
    }

    return 0;

}