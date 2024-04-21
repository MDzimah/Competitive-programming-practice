#include <iostream>
#include <cmath>

struct Cord {
	int x, y;
};

bool enCirc(int radio, Cord c, Cord punto) {
	return sqrt(pow(c.x - punto.x, 2) + pow(c.y - punto.y, 2)) <= radio;
}

void resuelve(int &numCirculos, Cord& c, Cord p, int r) {

	if (enCirc(r, c, p)) numCirculos++;

	if (r == 1 || (p.y - c.y == p.x - c.x) || (p.y - c.y == -p.x + c.x)) return;
	else if ((p.y - c.y > p.x - c.x) && (p.y - c.y > -p.x + c.x)) c.y += r;
	else if ((p.y - c.y < p.x - c.x) && (p.y - c.y > -p.x + c.x)) c.x += r;
	else if ((p.y - c.y < p.x - c.x) && (p.y - c.y < -p.x + c.x)) c.y -= r;
	else c.x -= r;

	r /= 2;
	resuelve(numCirculos, c, p, r);
}

bool res() {
	Cord p;
	int r;

	std::cin >> r >> p.x >> p.y;

	if (!std::cin) return false;

	int numCirculos = 0;
	Cord c = { 0, 0 };
	
	resuelve(numCirculos, c, p, r);
	std::cout << numCirculos << '\n';

	return true;
}


int main() {
	
	while (res());
	return 0;
}