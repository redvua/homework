#include <iostream>
#include "string.h"
using namespace std;

size_t strlen(char* val)
{
	size_t i = 0;
	while (val[i]) ++i;
	return i;
}

String::String(const char* val = "")
{
	size = strlen(val);
	value = new char[size + 1]{}; // {0}
	for (size_t i = 0; val[i]; ++i) value[i] = val[i]; // strcpy
}

String::String(const String & obj)
{
	size = obj.size;
	value = new char[size + 1]{};
	for (size_t i = 0; obj.value[i]; ++i) value[i] = obj.value[i];
}

void String::Print() const
{
	cout << value;
}

String String::operator * (const String b) const
{

	const String & min = (size <= b.size) ? *this : b;
	const String & max = (size > b.size) ? *this : b;
	char* buff = new char[min.size + 1]{};
	size_t sze = 0;

	for (size_t i = 0; max.value[i]; ++i) {
		if (min.inString(max.value[i]) != -1) {
			buff[sze] = max.value[i];
			++sze;
		}
	}
	return String(buff);
}

String String::operator / (const String b) const
{
	char* buff = new char[size + 1]{};
	size_t sze = 0;

	for (size_t i = 0; value[i]; ++i) {
		if (b.inString(value[i]) == -1) {
			buff[sze] = value[i];
			++sze;
		}
	}
	return String(buff);
}

String String::operator + (const String b) const
{
	char* buff = new char[size + b.size + 1]{};

	memcpy(buff, value, size);
	memcpy(buff + size, b.value, b.size);
	return String(buff);
}

String String::operator + (const char* b) const
{
	return *this + String{ b };
}

String operator + (const char* a, const String b)
{
	return String{ a } +b;
}

String String::operator ! () const
{
	char* buff = new char[size + 1]{};

	for (size_t i = 0; value[i]; ++i) {
		buff[i] = value[size - i - 1];
	}
	return String(buff);
}

String & String::operator ++ ()
{
	for (size_t i = 0; value[i]; ++i)
	{
		value[i] = ++value[i]; // граничные значения
	}
	return *this;
}

String String::operator ++ (int)
{
	String old{ *this };
	++(*this);
	return old;
}

bool String::operator < (const String b) const
{
	return Compare(b) < 0;
}

bool String::operator > (const String b) const
{
	return Compare(b) > 0;
}

bool String::operator <= (const String b) const
{
	return Compare(b) <= 0;
}

bool String::operator >= (const String b) const
{
	return Compare(b) >= 0;
}

bool String::operator == (const String b) const
{
	return Compare(b) == 0;
}

bool String::operator != (const String b) const
{
	return Compare(b) != 0;
}

int String::Compare(const String b) const
{
	int out = size - b.size;
	for (size_t i = 0; out == 0 && value[i]; ++i)
	{
		out += value[i] - b.value[i];
	}
	return out;
}

int String::inString(char search) const
{
	for (size_t i = 0; value[i]; ++i)
	{
		if (value[i] == search) return i;
	}
	return -1;
}

String::~String()
{
	delete[]value;
	value = nullptr;
}