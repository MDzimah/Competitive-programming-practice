#include <iostream>
#include <algorithm>

void resolverCasos() {

	int numCal,cal,calPerd = 0, listaCal[60];

	std::cin >> numCal;

	for (int i = 0; i < numCal; ++i) {
		std::cin >> cal;
		listaCal[i] = cal;
	}

	
	if (numCal > 1){
	std::sort(listaCal, listaCal + numCal);

	for (int i = 0; i < numCal - 1; ++i) 
		calPerd += (listaCal[i + 1] - listaCal[i])-1;

	}
	
	std::cout << calPerd << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) resolverCasos();

	return 0;
}