#include <iostream>

long long int mcd(long long int num1,long long int num2) {
	if (num2 == 0) return num1;
	else return mcd(num2, num1 % num2);
}

bool resolver() {
	long long int numI, numV, numX,maxComDiv;
	std::cin >> numI >> numV >> numX;
	if (numI == 0 && numV == 0 && numX == 0) return false;

	maxComDiv = mcd(mcd(numI, numV), numX);

	std::cout << numI / maxComDiv + numV / maxComDiv + numX / maxComDiv << '\n';

	return true;
}

int main() {
	while (resolver());

	return 0;
}