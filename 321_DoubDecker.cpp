#include <iostream>

void resuelveCaso() {
    int N, M;
    int rango = 1;
    std::cin >> N >> M;

    if (N == 0) for (int i = 1; i <= (N + M); ++i) rango += i;
    
    else {
       for (int i = 1; i <= (N + M); ++i) rango += i;
       rango += N;         
    }

    std::cout << rango << '\n';
}

int main() {
    int A;
    std::cin >> A;

    for (int k = 0; k < A; ++k) resuelveCaso();

    return 0;
}
