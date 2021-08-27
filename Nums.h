#pragma once
class Nums
{
public:
	int* arr, * backup, size;
	Nums();
	bool isEmpty;
	void set(int);
	void sort(int);
	void rollback();
	void print();
};

