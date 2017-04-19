#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	int ch;
	enum action
	{

	};

	do
	{
	ch = getch();
	switch (ch)
	{
	case 49:
		system("cls");
		cout << "Vvod" << endl;
		break;
	case 50:
		system("cls");
		cout << "Udalenie" << endl;
		break;
	default:
		system("cls");
		break;
	}
	cout << "Esc from quit" << endl;
	} while (ch != 27);


}