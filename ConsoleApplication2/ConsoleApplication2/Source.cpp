/* 4. Розробити програму, яка зчитує з екрану рядок, а потім видає статистику:
кількість пробільних символів (whitespaces),
голосних, приголосних, знаків пунктуації. Введення передбачається англомовним. */
#include <iostream>
using namespace std;
enum CharacterGroup { Control, Whitespace, Punctuation, Digit, Vowel, Consonant, CharacterGroups = Consonant + 1 };

CharacterGroup IsThis(char glyph) {
	const size_t ASCII = 128;
	int GroupSign[ASCII] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,4,5,5,5,4,5,5,5,4,5,5,5,5,5,4,5,5,5,5,5,4,5,5,5,4,5,2,2,2,2,2,2,4,5,5,5,4,5,5,5,4,5,5,5,5,5,4,5,5,5,5,5,4,5,5,5,4,5,2,2,2,2,0 };
	return (CharacterGroup)GroupSign[glyph];
}
void main() {
	const size_t MaxStringSize = 255;
	char* string = new char[MaxStringSize];
	int sum[CharacterGroups] = { 0 };
	do {
		cout << "Enter the string (or empty to exit): ";
		cin.getline(string, MaxStringSize);
		if (*string == '\0') continue;
		fill(sum, sum + CharacterGroups, 0);

		for (size_t i = 0; string[i] != '\0'; i++ )
			++sum[IsThis(string[i])];

		cout << "------------------------------------------------" << endl;
		cout << " Character Group\t| Sum"  << endl;
		cout << "------------------------------------------------" << endl;
		cout << " Whitespace\t\t| " << sum[Whitespace] << endl;
		cout << " Punctuation\t\t| " << sum[Punctuation] << endl;
		cout << " Digit\t\t\t| " << sum[Digit] << endl;
		cout << " Vowel\t\t\t| " << sum[Vowel] << endl;
		cout << " Consonant\t\t| " << sum[Consonant] << endl;
		cout << "------------------------------------------------" << endl;
		cout << endl;
	} while (*string != '\0');
}