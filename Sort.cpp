#include "Sort.h"
#include <iostream>
#include <math.h>
#include <string>

void Sort::bubble(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if ( *(arr + j) > *(arr + i)) {
				*(arr + i) += *(arr + j); // a = a + b
				*(arr + j) = *(arr + i) - *(arr + j); // b = (a + b) - b = a
				*(arr + i) = *(arr + i) - *(arr + j); // a = (a + b) - a = b
			}
		}
	}
};
void Sort::selection(int* arr, int size) {
	int minIdx;

	for (int i = 0; i < size - 1; i++) {
		minIdx = i;
		for (int j = i + 1; j < size; j++) {
			std::cout << *(arr + j) << " " << *(arr + minIdx) << minIdx <<"\n";
			if (*(arr + j) < *(arr + minIdx)) {
				minIdx = j;
			}
		}
		*(arr + i) += *(arr + minIdx);
		*(arr + minIdx) = *(arr + i) - *(arr + minIdx);
		*(arr + i) = *(arr + i) - *(arr + minIdx);
		
	}
};
void Sort::cocktail(int* arr, int size) {
	bool hadChange = true;
	int start = 0, end = size - 1;

	while (hadChange) {
		hadChange = false;
		for (int i = start; i < end; i++) {
			if (*(arr + i) > *(arr + i + 1)) {
				*(arr + i) += *(arr + i + 1);
				*(arr + i + 1) = *(arr + i) - *(arr + i + 1);
				*(arr + i) = *(arr + i) - *(arr + i + 1);
				hadChange = true;
			}
		}

		if (!hadChange) break;
		end--;

		for (int i = end - 1; i >= start; i--){
			if (*(arr + i) > *(arr + i + 1)) {
				*(arr + i) += *(arr + i + 1);
				*(arr + i + 1) = *(arr + i) - *(arr + i + 1);
				*(arr + i) = *(arr + i) - *(arr + i + 1);
				hadChange = true;
			}
		}

		start++;
	}
};
void Sort::severalUnique(int* arr, int size) {
	int endIdx = size - 1;
	int pos, highValue, newValue;
	int swapIdx = 0;

	do {
		highValue = INT_MIN;
		pos = -1;
		while (pos < endIdx) {
			pos++;
			newValue = *(arr + pos);
			if (newValue < highValue) {
				*(arr + swapIdx) = newValue;
				swapIdx++;
				*(arr + pos) = highValue;
			}
			else if(newValue > highValue) {
				swapIdx = pos;
				highValue = *(arr + pos);
			}
		}
		endIdx = swapIdx - 1;
	} while (pos >= swapIdx);
};
void Sort::counting(int* arr, int size) {
	int n = Sort::getMax(arr, size) + 1;
	int index, places;
	int* count = new int[n];
	int* arrSorted = new int[size];

	for (int i = 0; i < n; i++) *(count + i) = 0;
	for (int i = 0; i < size; i++) {
		index = *(arr + i);
		*(count + index) += 1;
	}

	for (int i = 1; i < n; i++) {
		*(count + i) += *(count + i - 1);
	}

	for (int i = 0; i < size; i++) {
		index = *(arr + i);
		places = *(count + index) - 1;
		*(arrSorted + places) = index;
		*(count + index) -= 1;
	}

	for (int i = 0; i < size; i++) {
		*(arr + i) = *(arrSorted + i);
	}
};
void Sort::insertion(int* arr, int size) {
	int i, key, j;

	for (i = 0; i < size; i++) {
		key = *(arr + i);
		j = i - 1;

		while (j >= 0 && *(arr + j) > key) {
			*(arr + j + 1) = *(arr + j);
			j -= 1;
		}

		*(arr + j + 1) = key;
	}
};
void Sort::quick(int* arr, int low, int high) {

	if (low < high) {
		int pi, pivot, i;
		pivot = *(arr + high);
		i = low - 1;

		for (int j = low; j <= high - 1; j++) {
			if(*(arr + j) < pivot){
				i++;
				Sort::swap((arr + i), (arr + j));
			}
		}
		Sort::swap((arr + i + 1), (arr + high));
		pi = i + 1;


		Sort::quick(arr, low, pi - 1);
		Sort::quick(arr, pi + 1, high);
	}
};
void Sort::merge(int* arr, int size) {

};
void Sort::radix(int* arr, int size) {
	int max = Sort::getMax(arr, size);
	
	for (int exp = 1; max / exp > 0; exp *= 10) {
		int* output = new int[size];
		int* count = new int[10];
		int i, index, place;

		for (i = 0; i < 10; i++) *(count + i) = 0;

		for (i = 0; i < size; i++) {
			index = (*(arr + i) / exp) % 10;
			*(count + index) += 1;
		}

		for (i = 1; i < 10; i++) {
			*(count + i) += *(count + i - 1);
		}

		for (i = size - 1; i >= 0; i--) {
			index = (*(arr + i) / exp) % 10;
			place = *(count + index) - 1;
			*(output + place) = *(arr + i);
			*(count + index) -= 1;
		}


		for (i = 0; i < size; i++) {
			*(arr + i) = *(output + i);
		}
	}
};
void Sort::shell(int* arr, int size) {
	
};

int Sort::getMax(int* arr, int size) {
	int max = *arr;
	for (int i = 1; i < size; i++) {
		if (max < *(arr + i)) {
			max = *(arr + i);
		}
	}
	return max;
}

int Sort::getMin(int* arr, int size) {
	int min = *arr;
	for (int i = 1; i < size; i++) {
		if (min > *(arr + i)) {
			min = *(arr + i);
		}
	}
	return min;
}

void Sort::swap(int* a, int* b) {
	std::cout << *a << " " << *b << " -> ";
	if (*a != *b) {
		*a += *b; // a = a + b
		*b = *a - *b; // b = (a + b) - b = a
		*a = *a - *b; // a = (a + b) - a = b
	}
	std::cout << *a << " " << *b << "\n";
}
