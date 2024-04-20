#include <iostream>

int op() {

	char n;
	std::cin >> n;
	
	if (std::isalnum(n)) {
		return n - '0';
	}
	else {
		int operandoIZQ = op();
		int operandoDCHO = op();

		switch (n) {
			case '+': return operandoIZQ + operandoDCHO; break;
			case '-': return operandoIZQ - operandoDCHO; break;
			case '*': return operandoIZQ * operandoDCHO; break;
			case '/': return operandoIZQ / operandoDCHO; break;
		}
	}
}

void res() {
	std::cout << op() << '\n';
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		res();

	return 0;
}