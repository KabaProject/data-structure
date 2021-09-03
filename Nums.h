#pragma once

class Nums
{
public:
	int* arr, size;
	Nums();
	bool isSorted;
	void set(int);
	void sort(int, int);
	void search(int, int);
	void print();
	static void swap(int*, int*);
};

