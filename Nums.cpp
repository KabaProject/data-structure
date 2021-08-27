#include "Nums.h"
#include "Sort.h"
#include <iostream>

Nums::Nums() {
    this->size = 0;
    this->isEmpty = true;
}

void Nums::set(int n) {
	size = n;
	arr = new int[size];
	backup = new int[size];
	for (int i = 0; i < size; i++) {
		std::cout << "array[" << i << "] = ";
		std::cin >> *(arr + i);
		*(backup + i) = *(arr + i);
        std::cout << *(backup + i) << "\n";
	}
}

void Nums::rollback() {
    std::cout << size << "\n";
    for (int i = 0; i < size; i++) {
        *(arr + i) = *(backup + i);
    }
}

void Nums::sort(int method) {
	switch (method)
	{
    case 1:
        Sort::bubble(arr, size);
        break;
    case 2:
        Sort::selection(arr, size);
        break;
    case 3:
        Sort::cocktail(arr, size);
        break;
    case 4:
        Sort::severalUnique(arr, size);
        break;
    case 5:
        Sort::counting(arr, size);
        break;
    case 6:
        Sort::insertion(arr, size);
        break;
    case 7:
        Sort::quick(arr, 0, size - 1);
        break;
    case 8:
        Sort::merge(arr, size);
        break;
    case 9:
        Sort::radix(arr, size);
        break;
    case 10:
        Sort::shell(arr, size);
        break;
	default:
        throw "La opcion elegida no existe";
		break;
	}
}

void Nums::print() {
	for (int i = 0; i < size; i++) {
		std::cout << "array[" << i << "] = " << *(arr + i) << "\n";
	}
}