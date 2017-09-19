#include <iostream>
#include "string.h"
using namespace std;

char & String::operator [] (const unsigned int i)
{
	static char badValue = 0;
	return (i >= size) ? badValue : *(value + i);
}

String String::operator () (unsigned int i, unsigned int k) const
{
	k = (k <= size - i) ? k : size - i;
	char* buff = new char[k + 1]{};
	while (k--) {
		buff[k] = value[i + k];
	}

	if (i >= size) exit(1);
	return String(buff);
}

String String::operator () (unsigned int i) const
{
	return (*this)(i, size - i);
}

String & String::operator = (const String & obj)
{
	if (this == &obj)
		return *this;

	return *this = obj.value;
	//delete[]value;
	//size = obj.size;
	//value = new char[size + 1]{};
	//memcpy(value, obj.value, size);
	//return *this;
}

String & String::operator = (const char * val)
{
	delete[]value;
	size = strlen(val);
	value = new char[size + 1]{};
	memcpy(value, val, size);
	return *this;
}

String & String::operator *= (const String & obj)
{
	*this = *this * obj;
	return *this;
}

String & String::operator /= (const String & obj)
{
	*this = *this / obj;
	return *this;
}

String & String::operator += (const String & obj)
{
	*this = *this + obj;
	return *this;
}

String & String::operator += (const char * val)
{
	*this = *this + val;
	return *this;
}