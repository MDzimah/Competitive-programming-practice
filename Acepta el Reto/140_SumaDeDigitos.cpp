#include <iostream>
#include <string>


void op(std::string s, int &suma, int &ind, bool const& par) {

	if (ind == s.size()-1) {
		suma += (s[ind] - '0');
		std::cout << s[ind] << " = " << suma << '\n';
		return;
	}
	else {
		suma = suma + (s[ind] - '0') + (s[ind + 1] - '0');
		if (par && ind == s.size() - 2) {
			std::cout << s[ind] << " + " << s[ind + 1] << " = " << suma << '\n';
			return;
		}
		else {
			std::cout << s[ind] << " + " << s[ind + 1] << " + ";
			ind += 2;
			op(s, suma, ind, par);
		}
	}
}


bool res() {

	int n;
	std::cin >> n;

	if (n < 0) return false;
	
	
	std::string s = std::to_string(n);
	
	bool par;
	if (s.size() % 2 == 0) par = true;
	else par = false;

	int suma = 0, ind = 0;
	op(s, suma, ind, par);

	return true;
}


int main() {

	while (res());

	return 0;
}