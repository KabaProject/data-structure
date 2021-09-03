#include "Nums.h"
#include "Search.h"
#include <iostream>

Nums::Nums() {
    this->size = 0;
    this->isSorted = false;
}

void Nums::set(int n) {
	size = n;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		std::cout << "array[" << i + 1 << "] = ";
		std::cin >> *(arr + i);
	}
}

void Nums::search(int method, int n) {
    switch (method)
    {
    case 1:
        Search::binary(this->arr, this->size, n);
        break;
    case 2:
        Search::secuencial(this->arr, this->size, n);
        break;
    }
}

void Nums::print() {
	for (int i = 0; i < size; i++) {
		std::cout << "array[" << i + 1 << "] = " << *(arr + i) << "\n";
	}
}

void Nums::sort(int low, int high) {

    if (low < high) {
        int pi, pivot, i;
        pivot = *(this->arr + high);
        i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (*(arr + j) < pivot) {
                i++;
                Nums::swap((arr + i), (arr + j));
            }
        }
        Nums::swap((arr + i + 1), (arr + high));
        pi = i + 1;


        Nums::sort(low, pi - 1);
        Nums::sort(pi + 1, high);
    }
};

void Nums::swap(int* a, int* b) {
    if (*a != *b) {
        *a += *b; // a = a + b
        *b = *a - *b; // b = (a + b) - b = a
        *a = *a - *b; // a = (a + b) - a = b
    }
}