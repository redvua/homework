/* 4. Розробити програму, яка зчитує з екрану рядок, а потім видає статистику:
кількість пробільних символів (whitespaces),
голосних, приголосних, знаків пунктуації. Введення передбачається англомовним. */
#include <iostream>
using namespace std;
enum spec { whitespace, symbol, number, vowel, consonant };

spec func(char symb) {
	int ascii[95] = { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,3,4,4,4,3,4,4,4,3,4,4,4,4,4,3,4,4,4,4,4,3,4,4,4,3,4,1,1,1,1,1,1,3,4,4,4,3,4,4,4,3,4,4,4,4,4,3,4,4,4,4,4,3,4,4,4,3,4,1,1,1,1 };
	return (spec)ascii[symb - 32];
}
void main() {
	char* string = new char[255];
	int specification[5] = { 0 };
	do {
		cout << "Enter the string (or nothing to exit): ";
		cin.getline(string, 255);
		if (*string == '\0') continue;
		fill(specification, specification + 5, 0);
		for (size_t i = 0; string[i] != '\0'; i++)
			++specification[func(string[i])];
		cout << "------------------------------------------------" << endl;
		cout << "Specification" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Whitespace:\t| " << specification[whitespace] << endl;
		cout << "Symbol:\t\t| " << specification[symbol] << endl;
		cout << "Number\t\t| " << specification[number] << endl;
		cout << "Vowel:\t\t| " << specification[vowel] << endl;
		cout << "Consonant:\t| " << specification[consonant] << endl;
		cout << "------------------------------------------------" << endl;
		cout << endl;
	} while (*string != '\0');
}