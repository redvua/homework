#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

const size_t MaxStringSize = 255;

struct Price
{
	unsigned int	kop;

	Price(unsigned int	_kop = 0) {
		kop = _kop;
	}
	void Set(unsigned int	_kop = 0)
	{
		kop = _kop;
	}
	unsigned int Get()
	{
		return kop;
	}
};

struct Brand
{
	char*		name;

	Brand(char* _name = "") {
		name = new char[MaxStringSize];
		strcpy(name, _name);
	}
	~Brand() {
		delete[]name;
		name = nullptr;
	}
};

struct Brands
{
	Brand**		index;
	unsigned int size;

	Brands()
	{
		size = 0;
		index = nullptr;
	}

	Brand* New(char* _name = "")
	{
		++size;
		Brand** tmp = new Brand*[size];
		for (size_t i = 0; i < size; i++)
		{
			if (i < size - 1) {
				tmp[i] = index[i];
			}
			else {
				tmp[i] = new Brand(_name);
			}
		}
		if (index) delete[]index;
		index = tmp;
		return tmp[size - 1];
	}

	void CinNew() {
		cin.ignore();
		cout << "¬ведiть iм'€ виробника: ";
		cin.getline( New()->name, MaxStringSize );
	}

	bool Del(size_t idx)
	{
		if (size > idx) {
			--size;
			Brand** tmp = new Brand*[size];
			for (size_t i = 0; i < size; i++)
				tmp[i] = (i < idx) ? index[i] : index[i + 1];
			delete[]index;
			index = tmp;
			return true;
		}
		else return false;
	}
	void CinDel() {
		size_t idx;
		cout << "¬ведiть #: ";
		cin >> idx;
		if (Del(idx)) {
			cout << "«апис " << idx << " видалено" << endl;
		}
		else cout << "Error, case 2" << endl;
	}

	void CinMod() {
		size_t idx;
		cout << "¬ведiть #: ";
		cin >> idx;
		cin.ignore();
		if (size > idx) {
			Brand* item = Select(idx);
			item->Show();
			cout << "¬ведiть нове iм'€: ";
			cin.getline(item->name, MaxStringSize);
		}
		else cout << "Error, case 3" << endl;
	}



	~Brands() {
		delete[]index;
		index = nullptr;
	}
};

struct Product
{
	char*			name;
	Brand*			brand;
	Price*			cost;
	unsigned int	vol;
	char*			description;

	Product(char* _name = "", Brand* _brand = nullptr, unsigned int _cost = 0, unsigned int _vol = 0, char* _description = "") {
		name = new char[MaxStringSize];
		strcpy(name, _name);
	}
	void Set(unsigned int	_id = 0)
	{
		id = _id;
	}
	unsigned int Get()
	{
		return id;
	}
};

struct Base
{
	Product** index;
	unsigned int size;

	Base()
	{
		size = 0;
		//this->item = nullptr;
		index = nullptr;
	}

	bool NewItem(char* name = "", char* phone = "", size_t day = 1, size_t month = 1, size_t year = 1970) {
		++size;
		Product** tmp = new Product*[size];
		for (size_t i = 0; i < size; i++)
		{
			if (i < size - 1) {
				tmp[i] = index[i];
				//delete index[i];
			}
			else {
				// ? item = tmp[i] = new Subscriber(name, phone, day, month, year);
				tmp[i] = new Product(name, phone, day, month, year);
			}
		}
		if (index) delete[]index;
		index = tmp;
		return true;
	}

	~Base() {
		delete[]index;
		index = nullptr;
	}
};

struct Subscriber
{
	char*	name;
	char*	phone;
	//Date	birthday;

	Subscriber(char* name = "", char* phone = "", size_t day = 1, size_t month = 1, size_t year = 1970)
	{
		this->name = new char[MaxStringSize];
		this->phone = new char[MaxStringSize];
		strcpy(this->name, name);
		strcpy(this->phone, phone);
		//this->birthday = Date(day, month, year);
	}

	void Show()
	{
		cout << this->name << " : ";
		cout << this->phone << " : ";
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

	bool NewItem(char* name = "", char* phone = "", size_t day = 1, size_t month = 1, size_t year = 1970) {
		++size;
		Subscriber** tmp = new Subscriber*[size];
		for (size_t i = 0; i < size; i++)
		{
			if (i < size - 1) {
				tmp[i] = index[i];
				//delete index[i];
			}
			else {
				item = tmp[i] = new Subscriber(name, phone, day, month, year);
			}
		}
		if (index) delete[]index;
		index = tmp;
		return true;
	}
	void CinItem() {
		NewItem();
		cin.ignore();
		cout << "¬ведiть iм'€: ";
		cin.getline(item->name, MaxStringSize);
		cout << "¬ведiть номер телефона: ";
		cin.getline(item->phone, MaxStringSize);
		cout << "¬ведiть рiк народженн€: ";
		cin >> item->birthday.year;
		cout << "¬ведiть мiс€ць народженн€: ";
		cin >> item->birthday.month;
		cout << "¬ведiть день народженн€: ";
		cin >> item->birthday.day;
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
	void CinDelItem() {
		size_t idx;
		cout << "¬ведiть #: ";
		cin >> idx;
		if (DelItem(idx)) {
			cout << "јбонента " << idx << " видалено" << endl;
		}
		else cout << "Error, case 2" << endl;
	}
	void CinModItem() {
		size_t idx;
		cout << "¬ведiть #: ";
		cin >> idx;
		cin.ignore();
		if (SelectItem(idx)) {
			item->Show();
			cout << "¬ведiть нове iм'€: ";
			cin.getline(item->name, MaxStringSize);
			cout << "¬ведiть новий номер телефона: ";
			cin.getline(item->phone, MaxStringSize);
			cout << "¬ведiть новий рiк народженн€: ";
			cin >> item->birthday.year;
			cout << "¬ведiть новий мiс€ць народженн€: ";
			cin >> item->birthday.month;
			cout << "¬ведiть новий день народженн€: ";
			cin >> item->birthday.day;
		}
		else cout << "Error, case 3" << endl;
	}
	void CinSelectItem() {
		char letter = 'A';
		cout << "¬ведiть лiтеру: ";
		cin >> letter;
		Show(letter);
		cout << "Press any key";
		getch();
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
	void Save() {
		ofstream fout;
		fout.open("phb.txt");
		if (!fout.is_open())
		{
			cout << "Can not open file for writing!" << endl;
		}
		else
		{
			fout << size << endl;
			for (size_t i = 0; i < size; i++)
			{
				fout << strlen(index[i]->name) << endl;
				fout << index[i]->name << endl;
				fout << strlen(index[i]->phone) << endl;
				fout << index[i]->phone << endl;
				fout << index[i]->birthday.year << endl;
				fout << index[i]->birthday.month << endl;
				fout << index[i]->birthday.day << endl;
			}
			fout.close();
			cout << "Phonebook wrote to file!" << endl;
		}
	}

	void Read() {
		ifstream fin;
		fin.open("phb.txt");
		if (!fin.is_open())
		{
			cout << "Can not open file for reading!" << endl;
		}
		else
		{
			size_t _size;
			size_t _stringsize;
			size_t	_year;
			size_t	_month;
			size_t	_day;

			fin >> _size;
			for (size_t i = 0; i < _size; i++)
			{
				fin >> _stringsize;
				char* _name = new char[_stringsize + 1];
				fin.ignore();
				fin.getline(_name, _stringsize + 1);

				fin >> _stringsize;
				char* _phone = new char[_stringsize + 1];
				fin.ignore();
				fin.getline(_phone, _stringsize + 1);

				fin >> _year;
				fin >> _month;
				fin >> _day;

				this->NewItem(_name, _phone, _day, _month, _year);
				delete[]_name;
				delete[]_phone;
			}
			fin.close();
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

	//my->NewItem("Ivan", "050-984-56-84", 1, 2, 2002);
	//my->NewItem("Petro", "068-408-39-56", 12, 11, 1978);
	//my->NewItem("Olena", "068-464-20-46", 31, 7, 2000);
	//my->NewItem("Anna", "096-722-63-79", 17, 12, 2001);

	//my->Save();

	my->Read();

	char action = 'q';
	do
	{
		system("cls");
		my->Show();

		cout << endl << "\t\t«робiть вибiр:" << endl;
		cout << "1 - додати абонента в книгу" << endl;;
		cout << "2 - видалити абонента з книги" << endl;
		cout << "3 - змiнити iнформацiю про абонента" << endl;
		cout << "4 - виведенн€ абонентiв на лiтеру" << endl;
		cout << "5 - зберегти книгу у файл" << endl;
		cout << "q - закiнчити роботу з програмою" << endl;
		cin >> action;
		switch (action)
		{
		case '1':
			my->CinItem();
			break;
		case '2':
			my->CinDelItem();
			break;
		case '3':
			my->CinModItem();
			break;
		case '4':
			my->CinSelectItem();
			break;
		case '5':
			my->Save();
			break;
		default:
			break;
		}
	} while (action != 'q');

}