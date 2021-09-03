#include "Search.h"
#include <iostream>
#include <math.h>
#include <string>

void Search::binary(int* arr, int size, int value) {
	int low = 0, high = size - 1, half;
	
	half = (high + low) / 2;

	while (low <= high) {

		if (*(arr + half) > value) {
			high = half - 1;
		}
		else if (*(arr + half) < value) {
			low = half + 1;
		}
		
		if (*(arr + half) == value) {
			std::cout << "Hay una concidencia:\n";
			Search::print(value, half);
			break;
		}

		half = (high + low) / 2;
	}
	if (low > high) {
		std::cout << "No hay concidencias\n";
	}
}

void Search::secuencial(int* arr, int size, int value) {
	int matches = 0;
	for (int i = 0; i < size; i++) {
		if (*(arr + i) == value) {
			matches++;
		}
	}

	std::cout << "Hay " << matches << " coincidencias:\n";

	for (int i = 0; i < size; i++) {
		if (*(arr + i) == value) {
			Search::print(value, i);
		}
	}
}

void Search::print(int num, int index) {
	std::cout << "Un " << num << " en la posicion " << index + 1 << "\n";
}

