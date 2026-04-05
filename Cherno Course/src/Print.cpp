#include <iostream>
#include "../headers/Print.h"

void InitPrint() {
	std::cout << "Iintialized Print" << std::endl;
}

void Print(const char* message) {
	std::cout << message << std::endl;
}