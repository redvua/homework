/* 5. Дано ціле число, записане як рядок. Знайти кількість цифр числа, суму цифр числа та реверс числа * 2.
Використати бібліотечні функції itoa(), strrev(), atoi(). */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void main() {
	const size_t MaxStringSize = 255;
	int num, sum;
	char OneCharString[2]="";
	char* string = new char[MaxStringSize];

	do {
		cout << "Enter a digits (or empty for exit): ";
		cin.getline(string, MaxStringSize);
		if (*string == '\0') continue;

		num = sum = 0;
		_itoa(atoi(string), string, 10); // take only digits

		while (string[num] != '\0')
		{
			OneCharString[0] = string[num];
			// another solution: _itoa((string[i] - '0'), OneCharString, 10);
			sum += atoi(OneCharString);
			num++;
		}

		cout << "------------------------------------------------" << endl;
		cout << " Description (" << string << ")\t\t| Result" << endl;
		cout << "------------------------------------------------" << endl;
		cout << " Number of digits\t\t| " << num << endl;
		cout << " Sum of digits of number\t| " << sum << endl;
		cout << " " << string << " * 2  \t\t\t| " << atoi(_strrev(string)) * 2 << endl;
		cout << "------------------------------------------------" << endl;
		cout << endl;
	} while (*string != '\0');
}