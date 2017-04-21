#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct MyStruct
{
	int a;
	double d;
	bool b;
	MyStruct(int _a, double _d, bool _b)
	{
		a = _a;
		d = _d;
		b = _b;
	}
	MyStruct() {};
	void Show()
	{
		cout << "A: " << a << endl;
		cout << "D: " << d << endl;
		cout << "B: " << b << endl;
		cout << endl;
	}
};


void main()
{
	// C write to file
	//FILE * file = fopen("file.dat", "wb");
	//char * text = "Some text for writing!";
	//int val;
	//cout << "E";
	//cin >> val;
	//double d = 23.33;
	//int size = strlen(text);
	//fwrite((char*)&size, sizeof(int), 1, file);
	//fwrite(text, strlen(text), 1, file);
	//fwrite((char*)&val, sizeof(int), 1, file);
	//fwrite((char*)&d, sizeof(double), 1, file);
	//fclose(file);

	// C read from file
	FILE * file = fopen("file.dat", "rb");
	int size, val;
	//double d;
	fread((char*)&size, sizeof(int), 1, file);
	cout << size << endl;
	char * text = new char[size + 1];
	cout << fread(text, size, 1, file) << endl;
	//fread((char*)&val, sizeof(int), 1, file);
	//fread((char*)&d, sizeof(double), 1, file);
	fclose(file);
	cout << text << endl;
	//cout << val << endl;
	//cout << d << endl;



	//size_t size = 3;
	//MyStruct** arr = new MyStruct*[size];
	//arr[0] = new MyStruct(12, 23.34, true);
	//arr[1] = new MyStruct(876, 33.34, false);
	//arr[2] = new MyStruct(999, 15.04, true);
	//cout << boolalpha; // ! :)
	//for (size_t i = 0; i < size; i++)
	//{
	//	arr[i]->Show();
	//}

	//char * name2 = "2.txt";
	//ofstream fout;
	//fout.open(name2);
	//if (!fout.is_open())
	//{
	//	cout << "Can not open file!" << endl;
	//}
	//else
	//{
	//	fout << size << endl;
	//	for (size_t i = 0; i < size; i++)
	//	{
	//		fout << arr[i]->a << endl;
	//		fout << arr[i]->d << endl;
	//		fout << arr[i]->b << endl;
	//	}
	//	fout.close();
	//	cout << "Array wrote to file!" << endl;
	//}

	//ifstream fin;
	//fin.open(name2);
	//if (!fin.is_open())
	//{
	//	cout << "Can not open file for reading!";
	//}
	//else
	//{
	//	int size;
	//	fin >> size;
	//	MyStruct** arr = new MyStruct*[size];
	//	cout << boolalpha; // ! :)
	//	for (size_t i = 0; i < size; i++)
	//	{
	//		arr[i] = new MyStruct();
	//		fin >> arr[i]->a;
	//		fin >> arr[i]->d;
	//		fin >> arr[i]->b;
	//		arr[i]->Show();
	//	}
	//	fin.close();
	//}


	// char * name = "1.txt";

	/*  // Write to file
	ofstream fout;
	fout.open(name);
	if (!fout.is_open())
	{
	cout << "Can not open file!" << endl;
	}
	else
	{
	char * text = "Some text for writing!";
	int val;
	cout << "Enter val: ";
	double d = 3.23;
	fout << strlen(text);
	cin >> val;
	fout << text << endl;
	fout << val << endl;
	fout << d << endl;
	fout.close();
	}
	*/

	/*
	ifstream fin;
	fin.open(name);
	if (!fin.is_open())
	{
	cout << "Can not open file for reading!";
	}
	else
	{
	int size;
	fin >> size;
	fin.ignore();
	char * text = new char[size + 1];
	fin.getline(text,size + 1);
	int val;
	fin >> val;
	double d;
	fin >> d;
	cout << text << endl;
	cout << val << endl;
	cout << d << endl;
	fin.close();
	}
	*/
}