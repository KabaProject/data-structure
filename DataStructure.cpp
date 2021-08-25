#include<iostream>

class Factorial {
private:
	int factor = 1;
public:
	Factorial() {};
	Factorial(int);
	void print(int);
};

Factorial::Factorial(int number) {
	for (int i = 1; i <= number; i++) {
		this->factor *= i;
	}
}

void Factorial::print(int number) {
	std::cout << "> El factorial de " << number << " es " << this->factor << "\n\n";
}

int main() {

	Factorial factor;
	int number;

	std::cout << "NOMBRE: Caculadora de Factorial\n";
	std::cout << "DESCRIPCION: Programa que se encarga de calcular el factorial del numero dado por el usuario.\n\n";
	std::cout << "Ingresa un numero entero: ";
	std::cin >> number;

	factor = Factorial(number);
	factor.print(number);

	system("pause");
	return 0;
}