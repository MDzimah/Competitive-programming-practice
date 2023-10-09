#include <iostream>
#include <iomanip>

bool resolver() {
	int numNoches,HHi,MMi,HHf,MMf,HHd = 0,MMd = 0,horQuit = 0;
	char aux;

	std::cin >> numNoches;

	if (numNoches == 0) return false;

	for (int i = 0; i < numNoches; ++i) {
		std::cin >> HHi >> aux >> MMi >> aux >> HHf>> aux >> MMf;
		if (HHi == 23) HHi = -1;
		else if (HHi == 22) HHi = -2;
		
		if (HHf == 23) HHf = -1;
		else if (HHf == 22) HHf = -2;

		HHd += HHf - HHi;

		if (MMf < MMi) { 
			MMf += 60;
			++horQuit;
		}

		MMd += MMf - MMi;
	}

	if (MMd >= 60) {
		HHd += MMd / 60;
		MMd = MMd % 60;
	}

	std::cout << std::setw(2) << std::setfill('0') << HHd - horQuit << aux << std::setw(2) << std::setfill('0') << MMd << '\n';
	return true;
}

int main(){
	
	while (resolver());

	return 0;

}