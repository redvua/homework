#include <iostream>
using namespace std;

const size_t MaxStringSize = 255;

struct Date
{
	size_t	year;
	size_t	month;
	size_t	day;

	Date(size_t day=1, size_t month=1, size_t year=1970)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void Show() {
		printf("%d-%d-%d", year, month, day);
	}
};
struct Subscriber
{
	size_t	id;
	char*	name;
	char*	phone;
	Date	birthday;
	Subscriber(size_t id, char* name="", char* phone="", size_t day=1, size_t month=1, size_t year=1970)
	{
		this->id = id;
		this->name = name;
		this->phone = phone;
		this->birthday = Date(day,month,year);
	}
	Subscriber() : Subscriber(0) {
		this->name = new char[MaxStringSize];
		this->phone = new char[MaxStringSize];
	
	};
	void Show()
	{
		cout << id << " : ";
		cout << name << " : ";
		cout << phone << " : ";
		birthday.Show();
	}
	~Subscriber()
	{
		delete[]name;
		name = nullptr;
		delete[]phone;
		phone = nullptr;
	}
};
struct  Phonebook
{
	size_t size;
	Subscriber** item;
	Phonebook()
	{
		this->size = 0;
		this->item = new Subscriber*[size];
	}
	bool NewItem(char* name = "", char* phone = "", size_t day = 1, size_t month = 1, size_t year = 1970) {

		++size;
		Subscriber** tmp = new Subscriber*[size];
		for (size_t i = 0; i < size; i++)
		{
			tmp[i] = (i < size - 1) ? item[i] : new Subscriber(size - 1, name, phone, day, month, year);
			delete[]item[i];
		}
		
		delete[]item;
		item = tmp;
		return true;
	}
	bool DelItem(size_t idx) {
		--size;
		Subscriber** tmp = new Subscriber*[size];
		for (size_t i = 0; i < size; i++)
			tmp[i] = (i < idx) ? item[i] : item[i + 1];
		delete[]item;
		item = tmp;
		return true;
	}
	void Show() {

		for (size_t i = 0; i < size; i++)
		{
			item[i]->Show();
			cout << endl;
		}
		cout << endl;
	}
	~Phonebook()
	{
		delete[]item;
		item = nullptr;
	}
};
void main()
{
	setlocale(LC_CTYPE, "");
	Phonebook* my = new Phonebook;
	//Subscriber e;
	char*	name = new char[MaxStringSize];
	char*	phone = new char[MaxStringSize];
	size_t	year = 1970;
	size_t	month = 1;
	size_t	day = 1;

	size_t idx;

	char action = 'q';
	do
	{
		//cout << endl; ShowArr(arr, length);

		cout << endl << "\t\t«робiть вибiр:" << endl;
		cout << "1 - додати абонента в книгу" << endl;;
		//cout << "2 - видалити абонента з книги" << endl;
		//cout << "3 - змiнити ≥нформац≥ю про нього" << endl; //
		//cout << "4 - виведенн€ абонент≥в на л≥теру" << endl;
		cout << "q - закiнчити роботу з програмою" << endl;
		cin >> action;
		switch (action)
		{
		case '1':
			cin.clear();
			cin.ignore();
			cout << "¬ведiть iм'€: ";
			cin.getline(name, MaxStringSize);
			//cout << "¬ведiть номер телефона: ";
			//cin.getline(phone, MaxStringSize);
			// cout << "¬ведiть дату народженн€: ";
			my->NewItem(name, "123");
			my->Show();
			break;
		default:
			break;
		}
	} while (action != 'q');


}