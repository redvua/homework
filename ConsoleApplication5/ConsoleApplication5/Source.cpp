#define _CRT_SECURE_NO_WARNINGS
/* 5. Дано ціле число, записане як рядок. Знайти кількість цифр числа, суму цифр числа та реверс числа * 2. Використати бібліотечні функції itoa(), strrev(), atoi(). */
#include <iostream>
using namespace std;

void main() {
	const size_t MaxStringSize = 255;
	int i, sum;
	char* OneCharString = new char[2];
	char* string = new char[MaxStringSize];
	do {
		cout << "Enter a digits (or nothing for exit): ";
		cin.getline(string, MaxStringSize);
		if (*string == '\0') continue;
		i = sum = 0;
		for (; string[i] != '\0'; i++)
		{
			*OneCharString = string[i];
			// itoa(string[i] + '0')
			sum += atoi(OneCharString);
		}
		cout << "------------------------------------------------" << endl;
		cout << " Description\t\t\t| Result" << endl;
		cout << "------------------------------------------------" << endl;
		cout << " Number of digits\t\t| " << i << endl;
		cout << " Sum of digits of number\t| " << sum << endl;
		cout << " strrev * 2\t\t\t| " << atoi(_strrev(string)) * 2 << endl;
		cout << "------------------------------------------------" << endl;
		cout << endl;
	} while (*string != '\0');
}