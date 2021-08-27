#pragma once
#include "Nums.h"
#include<string>

class Program
{
private:
	int w;
	char fill;
public:
	Program();
	Program(int, char);
	void setWidth(int);
	void setFill(char);
	void menu();
	void header(std::string);
	void blankLn();
	void divLn();
	void sortNums(Nums*, int);
	void textCenterLn(std::string);
	void textLn(int, std::string);
};

