#include <iostream>

void cycSh(std::string& s) {
	s = s.substr(1,s.size()-1) + s[0];
}


void sol() {
	long int N, K;
	std::string A;
	std::cin >> N >> K >> A;
	
	std::string s = A, maxS = A;
	long long int cyShToMax = 0, per = 0;

	cycSh(s);
	if (s > maxS) {
		++cyShToMax;
		maxS = s;
	}
	
	if (s != A) {
		per = 2;
		while (s != A) {
			cycSh(s);
			++per;
			if (s > maxS) {
				cyShToMax = per - 1;
				maxS = s;
			}

		}
		std::cout << cyShToMax + (K - 1) * (per - 1) << '\n';
	}
	else std::cout << K-1 << '\n';
	
}

int main() {

	int T;
	std::cin >> T;

	while (T--) sol();


	return 0;
}