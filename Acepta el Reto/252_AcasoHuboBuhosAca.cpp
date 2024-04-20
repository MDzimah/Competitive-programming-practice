#include <string>
#include <iostream>
//Aunque se puede hacer sin recursión, supongo que querrás que hagamos todos los problemas con recursión...

void desplazar_izq(std::string& s) {
	for (int i = 0; i < s.size()-1; ++i)
		s[i] = s[i + 1];
}

bool pal(std::string & f) {

	if (f.size() == 1 || f.size() == 0) return true;
	else {
		if (f[0] != f[f.size() - 1]) return false;
		else {
			f.pop_back();
			desplazar_izq(f);
			f.pop_back();
			return pal(f);
		}
	}
}

void minuscula(std::string& s) {
	for (int i = 0; i < s.size(); ++i)
		s[i] = (char)tolower(s[i]);
}

bool res() {

	std::string a;

	std::cin >> a;
	
	if (a == "XXX") return false;

	std::string f;
	char aux = ' ';

	f += a;

	std::cin.get(aux);

	while (aux != '\n') {
		std::cin >> a;
		f += a;
		std::cin.get(aux);
	}

	minuscula(f);

	if (pal(f)) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {

	while (res());

	return 0;
}