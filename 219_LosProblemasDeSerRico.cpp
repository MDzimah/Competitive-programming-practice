#include <iostream>

void resuelveCaso() {
	int comp, VolCompMasG, DifCompAdys;
	int NumLAguaComp = 0;

	std::cin >> comp >> VolCompMasG >> DifCompAdys;

	for (int i = 0; i < comp; ++i) {
		NumLAguaComp += VolCompMasG;
		VolCompMasG -= DifCompAdys;
	}
		
	std::cout << NumLAguaComp << '\n';
}

int main() {

	int numCasos;
	std::cin >> numCasos;

	for (int k = 0; k < numCasos; ++k)
		resuelveCaso();

}