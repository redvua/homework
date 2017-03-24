/* 1. Написати функцію, яка отримує рядок і повертає довжину рядка. Без використання функції strlen() */
#include <iostream>
using namespace std;

size_t StringLength(char* str) {
	size_t out = 0;
	while (str[out] != '\0') ++out;
	return out;
}
void main() {
	const size_t MaxStringSize = 255;
	char* string = new char[MaxStringSize];
	do {
		cout << "Enter the string (or empty to exit): ";
		cin.getline(string, MaxStringSize);
		if (*string == '\0') continue;
		cout << "String Length = " << StringLength(string) << endl;
	} while (*string != '\0');
}