//�������� ��������, ��� ������ ��������� ����� � �������� ������������ ������� �������� � ���� ����������� ���������. ����������� ������� ��������� //(��� ������ �� ϲ�). ���������� ��������� ������ �������� � �����, �������� �������� � �����, ������ ���������� ��� �����.
//����� ������ ��������� ��������� �������� ��'� ���� ���������� �� ������� ������������ �����

#include <iostream>
#include <fstream>
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

struct Subscriber
{
	char*	name;
	char*	phone;
	Date	birthday;

	Subscriber(char* name = "", char* phone = "", size_t day = 1, size_t month = 1, size_t year = 1970)
	{
		this->name = new char[MaxStringSize];
		this->phone = new char[MaxStringSize];
		strcpy(this->name, name);
		strcpy(this->phone, phone);
		this->birthday = Date(day, month, year);
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
		cout << "����i�� i�'�: ";
		cin.getline(item->name, MaxStringSize);
		cout << "����i�� ����� ��������: ";
		cin.getline(item->phone, MaxStringSize);
		cout << "����i�� �i� ����������: ";
		cin >> item->birthday.year;
		cout << "����i�� �i���� ����������: ";
		cin >> item->birthday.month;
		cout << "����i�� ���� ����������: ";
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
		cout << "����i�� #: ";
		cin >> idx;
		if (DelItem(idx)) {
			cout << "�������� " << idx << " ��������" << endl;
		}
		else cout << "Error, case 2" << endl;
	}
	void CinModItem() {
		size_t idx;
		cout << "����i�� #: ";
		cin >> idx;
		cin.ignore();
		if (SelectItem(idx)) {
			item->Show();
			cout << "����i�� ���� i�'�: ";
			cin.getline(item->name, MaxStringSize);
			cout << "����i�� ����� ����� ��������: ";
			cin.getline(item->phone, MaxStringSize);
			cout << "����i�� ����� �i� ����������: ";
			cin >> item->birthday.year;
			cout << "����i�� ����� �i���� ����������: ";
			cin >> item->birthday.month;
			cout << "����i�� ����� ���� ����������: ";
			cin >> item->birthday.day;
		}
		else cout << "Error, case 3" << endl;
	}
	void CinSelectItem() {
		char letter = 'A';
		cout << "����i�� �i����: ";
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
			if (!num) cout << "�������i� �� �i���� " << letter << " �� ��������";
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

		cout << endl << "\t\t����i�� ���i�:" << endl;
		cout << "1 - ������ �������� � �����" << endl;;
		cout << "2 - �������� �������� � �����" << endl;
		cout << "3 - ��i���� i�������i� ��� ��������" << endl;
		cout << "4 - ��������� �������i� �� �i����" << endl;
		cout << "5 - �������� ����� � ����" << endl;
		cout << "q - ���i����� ������ � ���������" << endl;
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