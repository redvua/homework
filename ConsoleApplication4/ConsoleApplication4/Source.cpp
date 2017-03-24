/* 3. Дано рядок. Замінити у рядку всі великі букви на малі і навпаки. Рядок вводиться з клавіатури (динамічний масив) */
#include <iostream>
using namespace std;
const int RegisterOffset = 32;
bool IsUpper(char symb) {
	return (symb >= 65 && symb <= 90);
}
bool IsLower(char symb) {
	return (symb >= 97 && symb <= 122);
}
char LowerCase(char symb) {
	return (IsUpper(symb)) ? symb + RegisterOffset : symb;
}
char UpperCase(char symb) {
	return (IsLower(symb)) ? symb - RegisterOffset : symb;
}
char SwapCase(char symb) {
	return (IsLower(symb)) ? UpperCase(symb) : LowerCase(symb);
}
void main() {
	const size_t MaxStringSize = 255;
	char* string = new char[MaxStringSize];
	do {
		cout << "Enter the string (or empty to exit): ";
		cin.getline(string, MaxStringSize);
		if (*string == '\0') continue;
		for (size_t i = 0; string[i] != '\0'; i++)
			cout << SwapCase(string[i]);
		cout << endl;
	} while (*string != '\0');
}