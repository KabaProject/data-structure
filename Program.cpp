#include "Program.h"
#include "Nums.h"
#include <iostream>
#include <iomanip>
#include <string>

Program::Program() {
	this->w = 0;
	this->fill = ' ';
};
Program::Program(int w, char fill) {
	this->w = w;
	this->fill = fill;
};

void Program::setWidth(int width) { this->w = width; }
void Program::setFill(char simbol) { this->fill = simbol; }

void Program::menu() {
	this->divLn();

	this->textCenterLn("Google pero más cool");

	this->divLn();
	this->blankLn();

	this->textLn(3, "Elige un metodo de busqueda:");

	this->blankLn();

	this->textLn(3, "1.- Metodo Binario");
	this->textLn(3, "2.- Metodo Secuencial");

	this->blankLn();

	this->textLn(3, "O tambien puedes:");

	this->blankLn();

	this->textLn(3, "3.- Salir del Programa");

	this->blankLn();
	this->divLn();
}

void Program::header(std::string title) {
	this->divLn();
	this->textCenterLn(title);
	this->divLn();
	std::cout << "\n";
}

void Program::blankLn() {
	int width = this->w - 1;
	std::cout << "#" << std::setfill(' ') << std::setw(width) << "#" << "\n";
}

void Program::divLn() {
	int width = this->w - 1;
	std::cout << std::right;
	std::cout << "#" << std::setfill('=') << std::setw(width) << "#" << "\n";
	std::cout << std::setfill(' ');
}

void Program::textCenterLn(std::string text) {
	int padding[2];
	if (text.size() % 2 == 0) {
		padding[0] = padding[1] = (this->w - text.size()) / 2;
	}
	else {
		padding[0] = (this->w - text.size()) / 2;
		padding[1] = ((this->w - text.size()) / 2) + 1;
	}
	std::cout << std::setw(padding[0]) << std::left << "#" << text << std::setw(padding[1]) << std::right << "#" << "\n";
}

void Program::textLn(int padding, std::string text) {
	int left = this->w - (padding + text.size());
	std::cout << std::setw(padding) << std::left << "#" << text << std::setw(left) << std::right << "#" << "\n";
}

void Program::searchNums(Nums* nums, int method) {
	int n;

	std::cout << "Ingresa el valor a buscar: ";
	std::cin >> n;
	std::cout << "\n";

	(*nums).search(method, n);
}

void Program::setNums(Nums* nums) {
	int n;

	Program::header("Registro de Numeros");
	while (true) {
		std::cout << "Ingresa el total de numeros: ";
		std::cin >> n;

		if (n <= 0) {
			std::cout << "El valor debe ser mayor o igual a 1\n";
			continue;
		}
		break;
	}
	(*nums).set(n);
	(*nums).sort(0, n - 1);
}
