#include <iostream>

std::ostream& operator<<(std::ostream& sal, std::string const& s) {
	for (int i = 0; i < s.size(); ++i)
		sal << s[i];

	return sal;
}

void combinaciones(int C, int V, std::string s) {

	if (C == 0 && V == 0) {
		std::cout << s << ' ';
	}
	else {
		if (C > 0) combinaciones(C - 1, V, s + 'C');
		if (V > 0) combinaciones(C, V - 1, s + 'V');
	}
}

void res() {
	int C, V;
	std::cin >> C >> V;

	std::string s;
	combinaciones(C, V, s);
	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		res();

	return 0;
}
