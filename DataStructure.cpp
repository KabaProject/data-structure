#include<iostream>
#include<iomanip>
#include "Nums.h"
#include "Program.h"

int main() {

	Nums nums;
	Program program(40, '=');
	int n, opt;
	char key;

	program.setNums(&nums);
	system("cls");

	do {
		program.menu();

		while (true) {
			std::cout << "\n" << std::setw(3) << std::left << "" << "Ingresar Opcion: ";
			std::cin >> opt;
			if (opt < 1 && opt > 3) {
				std::cout << std::setw(3) << "" << "Opcion no disponible, intente de nuevo\n\n";
				continue;
			}
			break;
		}

		system("cls");

		switch (opt) {
		case 1:
			program.header("Metodo Binario"); // Correjir 
			std::cout << "\n";
			nums.print();
			std::cout << "\n";
			program.searchNums(&nums, opt);
			break;
		case 2:
			program.header("Metodo Secuencial");
			std::cout << "\n";
			nums.print();
			std::cout << "\n";
			program.searchNums(&nums, opt);
			break;
		case 3:
			key = 'n';
			break;
		}
		if (opt != 3) {
			while (true) {
				std::cout << "\nQuiere intentarlo de nuevo? (y/n): ";
				std::cin >> key;
				key = tolower(key);
				if (key != 'n' && key != 'y') {
					std::cout << "Opcion no disponible, intente de nuevo\n";
					continue;
				}
				break;
			}
		}
		std::cin.ignore();
		system("cls");

	} while (key != 'n');

	program.header("Gracias por su visita!");

	std::cin.get();
	return 0;
}