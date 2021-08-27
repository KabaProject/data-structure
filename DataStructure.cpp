#include<iostream>
#include<iomanip>
#include "Nums.h"
#include "Program.h"

int main() {

	Nums nums;
	Program program(40, '=');
	int n, opt;
	char key;
	do {
		// Reset values
		key = 'n';
		if (!(nums.isEmpty)) { 
			nums.rollback(); 
		}

		program.menu();
		std::cout << "\n" << std::setw(3) << std::left << "" << "Ingresar Opcion: ";
		std::cin >> opt;

		system("cls");

		switch (opt) {
		case 1:
			program.header("Metodo Burbuja"); // Correjir 
			program.sortNums(&nums, opt);
			break;
		case 2:
			program.header("Metodo Selection");
			program.sortNums(&nums, opt);
			break;
		case 3:
			program.header("Metodo Cocktail");
			program.sortNums(&nums, opt);
			break;
		case 4:
			program.header("Metodo Several Unique");
			program.sortNums(&nums, opt);
			break;
		case 5:
			program.header("Metodo Counting"); 
			program.sortNums(&nums, opt);
			break;
		case 6:
			program.header("Metodo Bucket");
			program.sortNums(&nums, opt);
			break;
		case 7:
			program.header("Metodo Quick");
			program.sortNums(&nums, opt);
			break;
		case 8:
			program.header("Metodo Merge");
			program.sortNums(&nums, opt);
			break;
		case 9:
			program.header("Metodo Radix");
			program.sortNums(&nums, opt);
			break;
		case 10:
			program.header("Metodo Shell");
			program.sortNums(&nums, opt);
			break;
		case 11:
			key = 'n';
			break;
		}

		if (opt != 11) {
			std::cout << "Quieres intentar de nuevo? (y/n):";
			std::cin >> key;
			key = tolower(key);
		}

		std::cin.ignore();
		system("cls");

	} while (key != 'n' && key == 'y');

	program.header("Gracias por su visita!");

	std::cin.get();
	return 0;
}