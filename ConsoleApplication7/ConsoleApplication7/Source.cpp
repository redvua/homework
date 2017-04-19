#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

const size_t MaxStringSize = 255;

struct Date
{
	size_t	year;
	size_t	month;
	size_t	day;

	Date(size_t day = 1, size_t month = 1, size_t year = 1970) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
};
struct Address
{
	char*	city;
	char*	street;
	char*	building;
	Address(char* city = "", char* street = "", char* building = "") {
		this->city = new char[MaxStringSize];
		this->street = new char[MaxStringSize];
		this->building = new char[MaxStringSize];
		strcpy(this->city, city);
		strcpy(this->street, street);
		strcpy(this->building, building);
	}
	// Address() : Address("", "", "") {};
	~Address()
	{
		delete[]city, city = nullptr;
		delete[]street, street = nullptr;
		delete[]building, building = nullptr;
	}
};
struct Subscriber
{
	char*	name;
	char*	phone;
	Date	birthday;
	//Address	location;

	Subscriber(char* name = "", char* phone = "", char* city = "", char* street = "", char* building = "", size_t day = 1, size_t month = 1, size_t year = 1970)
	{
		this->name = new char[MaxStringSize];
		this->phone = new char[MaxStringSize];
		strcpy(this->name, name);
		strcpy(this->phone, phone);
		//this->location = Address(city, street, building);
		this->birthday = Date(day, month, year);
	}
	//Subscriber() : Subscriber(0) {
	//};
	void Show()
	{
		cout << this->name << " : ";
		cout << this->phone << " : ";
		//printf("%s %s, %s : ", location.city, location.street, location.building);
		printf("%d-%d-%d", birthday.year, birthday.month, birthday.day);
		cout << endl;
	}
	~Subscriber()
	{
		delete[]name, name = nullptr;
		delete[]phone, phone = nullptr;
	}
};
struct  Phonebook
{
	size_t size;
	Subscriber* item;
	Subscriber** index;
	Phonebook() {
		this->size = 0;
		this->item = nullptr;
		this->index = nullptr;
	}

	bool NewItem(char* name = "", char* phone = "", char* city = "", char* street = "", char* building = "", size_t day = 1, size_t month = 1, size_t year = 1970) {
		++size;
		Subscriber** tmp = new Subscriber*[size];
		for (size_t i = 0; i < size; i++)
		{
			if (i < size - 1) {
				tmp[i] = index[i];
				//delete index[i];
			}
			else {
				item = tmp[i] = new Subscriber(name, phone, city, street, building, day, month, year); 
			}
		}
		if (index) delete[]index;
		index = tmp;
		return true;
	}

	bool SelectItem(size_t idx) {
		if (size > idx) {
			item = index[idx];
		}
		else return false;
	}
	bool DelItem(size_t idx) {
		if (size > idx) {
			--size;
			Subscriber** tmp = new Subscriber*[size];
			for (size_t i = 0; i < size; i++)
				tmp[i] = (i < idx) ? index[i] : index[i + 1];
			delete[]index;
			index = tmp;
			return true;
		}
		else return false;
	}
	void Show(char letter) {
		int num = 0;
		if (size) {
			for (size_t i = 0; i < size; ++i)
			{
				if (letter == index[i]->name[0]) {
				cout << i << " : ";
				index[i]->Show();
				++num;
				}
			}
			if (!num) cout << "јбонентiв на лiтеру " << letter << " не знайдено";
			cout << endl;
		}
	}
	void Show() {
		cout << "size: " << size << endl;
		if (size) {
			for (size_t i = 0; i < size; ++i)
			{
				cout << i << " : ";
				index[i]->Show();
			}
			cout << endl;
		}
	}
	~Phonebook() {
		delete[]index;
		index = nullptr;
	}
};
void main()
{
	setlocale(LC_CTYPE, "");

	Phonebook* my = new Phonebook;

	my->NewItem("Ivan", "050-984-56-84");
	my->NewItem("Petro", "068-408-39-56");
	my->NewItem("Olena", "068-464-20-46");
	my->NewItem("Anna", "096-722-63-79");

	size_t idx;
	char action = 'q';
	char letter = 'A';
	do
	{
		system("cls");
		my->Show();

		cout << endl << "\t\t«робiть вибiр:" << endl;
		cout << "1 - додати абонента в книгу" << endl;;
		cout << "2 - видалити абонента з книги" << endl;
		cout << "3 - змiнити iнформацiю про абонента" << endl;
		cout << "4 - виведенн€ абонентiв на лiтеру" << endl;
		cout << "q - закiнчити роботу з програмою" << endl;
		cin >> action;
		switch (action)
		{
		case '1':
			my->NewItem();
			cin.ignore();
			cout << "¬ведiть iм'€: ";
			cin.getline(my->item->name, MaxStringSize);
			cout << "¬ведiть номер телефона: ";
			cin.getline(my->item->phone, MaxStringSize);
			cout << "¬ведiть рiк народженн€: ";
			cin >> my->item->birthday.year;
			cout << "¬ведiть мiс€ць народженн€: ";
			cin >> my->item->birthday.month;
			cout << "¬ведiть день народженн€: ";
			cin >> my->item->birthday.day;
			break;
		case '2':
			cout << "¬ведiть #: ";
			cin >> idx;
			if (my->DelItem(idx)) {
				cout << "јбонента " << idx << " видалено" << endl;
			}
			else cout << "Error, case 2" << endl;
			break;
		case '3':
			cout << "¬ведiть #: ";
			cin >> idx;
			cin.ignore();
			if (my->SelectItem(idx)) {
				my->item->Show();
				cout << "¬ведiть нове iм'€: ";
				cin.getline(my->item->name, MaxStringSize);
				cout << "¬ведiть новий номер телефона: ";
				cin.getline(my->item->phone, MaxStringSize);
				cout << "¬ведiть новий рiк народженн€: ";
				cin >> my->item->birthday.year;
				cout << "¬ведiть новий мiс€ць народженн€: ";
				cin >> my->item->birthday.month;
				cout << "¬ведiть новий день народженн€: ";
				cin >> my->item->birthday.day;
			}
			else cout << "Error, case 3" << endl;
			break;
		case '4':
			cout << "¬ведiть лiтеру: ";
			cin >> letter;
			my->Show(letter);
			cout << "Press any key";
			getch();
			break;
		default:
			break;
		}
	} while (action != 'q');

}