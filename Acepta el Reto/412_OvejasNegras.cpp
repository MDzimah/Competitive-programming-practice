#include <iostream>
#include <vector>

using Png = std::vector <std::vector<char>>;

bool imgOvBN(Png const& i) {
	for (int f = 0; f < i.size(); ++f) {
		int c = 0;
		while (c < i[0].size()) {
			if (i[f][c] == '.') return true;
			++c;
		}
	}

	return false;
}

void llenarImg(Png& i, int posF, int posC) {
	if (posC + 1 < i[0].size() && i[posF][posC + 1] == '.') {
		i[posF][posC+1] = 'X';
		llenarImg(i,posF, posC + 1);
	}
	if (posF + 1 < i.size() && i[posF + 1][posC] == '.') {
		i[posF + 1][posC] = 'X';
		llenarImg(i,posF + 1, posC);
	}
	if (posF - 1 >= 0 && i[posF - 1][posC] == '.') {
		i[posF - 1][posC] = 'X';
		llenarImg(i, posF - 1, posC);
	}
	if (posC - 1 >= 0 && i[posF][posC - 1] == '.') {
		i[posF][posC - 1] = 'X';
		llenarImg(i,posF, posC - 1);
	}
}

void leer(Png& i) {
	for (int f = 0; f < i.size(); ++f)
		for (int c = 0; c < i[0].size(); ++c)
			std::cin >> i[f][c];
}


bool res() {

	int f, c;
	std::cin >> c >> f;

	if (!std::cin) return false;

	Png img(f, std::vector<char>(c));

	leer(img);
	img[0][0] = 'X';
	llenarImg(img, 0, 0);

	if (imgOvBN(img)) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}


int main() {

	while (res());

	return 0;
}