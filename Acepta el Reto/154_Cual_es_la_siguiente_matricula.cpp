#include <iostream>
#include <string>

void insertBeg(std::string &s) {

	int sizeOriginal = s.size();

	for (int j = 0; j < (4 - sizeOriginal); ++j)
		s.push_back(' ');

	for (int k = sizeOriginal - 1, i = 1; k >= 0; --k, ++i)
		s[s.size() - i] = s[k];

	for (int m = 0; m < s.size() - sizeOriginal; ++m)
		s[m] = '0';
}

int operator+(std::string s, int n) {

	int aux = std::stoi(s);

	aux += n;

	return aux;
}



bool res() {
 std::string l, n;

	std::cin >> n >> l;

	if (n == "9999" && l == "ZZZ") return false;

	int m = (n + 1) % 10000;
	n = std::to_string(m);
	insertBeg(n);

	if (n == "0000") {
		if (l[2] == 'Z') {
			l[2] = 'B';
			if (l[1] == 'Z') {
				l[1] = 'B';

				if (l[0] + 1 == 'A' || l[0] + 1 == 'E' || l[0] + 1 == 'I' || l[0] + 1 == 'O' || l[0] + 1 == 'U')
					l[0] += 2;
				else l[0] += 1;

			}
			else {
				if (l[1] + 1 == 'A' || l[1] + 1 == 'E' || l[1] + 1 == 'I' || l[1] + 1 == 'O' || l[1] + 1 == 'U')
					l[1] += 2;
				else l[1] += 1;
			}
		}
		else {
			if (l[2] + 1 == 'A' || l[2] + 1 == 'E' || l[2] + 1 == 'I' || l[2] + 1 == 'O' || l[2] + 1 == 'U')
				l[2] += 2;
			else l[2] += 1;
		}
	}

	std::cout << n << ' ' << l << '\n';
	

}


int main() {
	while (res());
	return 0;
}