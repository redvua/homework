/* 2. Вводиться рядок. Яких букв у рядку більше ’а’ чи ’о’ ? */
#include <iostream>
using namespace std;

void AoverO(char* str) {
	int out = 0;
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (str[i] == 'a' || str[i] == 'A') ++out;
		if (str[i] == 'o' || str[i] == 'O') --out;
	}
	if (out > 0) cout << "a > o" << endl;
	else if (out < 0) cout << "a < o" << endl;
	else cout << "a = o" << endl;
}
void main() {
	const size_t MaxStringSize = 255;
	char* string = new char[MaxStringSize];
	do {
		cout << "Enter the string (or empty to exit): ";
		cin.getline(string, MaxStringSize);
		if (*string == '\0') continue;
		AoverO(string);
	} while (*string != '\0');
}