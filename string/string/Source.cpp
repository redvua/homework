#include <iostream>
using namespace std;
const size_t MaxStringSize = 255;

class String
{
	char* value;
	size_t size;
public:
	String(char*);
	String(const String &);
	void Print() const;
	String operator * (const String) const;
	~String();

private:

};
size_t strlen(char* val)
{
	size_t i = 0;
	while (val[i]) ++i;
	return i;
}
String::String(char* val = "")
{
	size = strlen(val);
	value = new char[size + 1]{}; // {0}
	for (size_t i = 0; val[i]; ++i) value[i] = val[i]; // strcpy
}
String::String(const String & obj)
{
	size = strlen(obj.value);
	value = new char[size + 1]{}; // {0}
	for (size_t i = 0; obj.value[i]; ++i) value[i] = obj.value[i]; // strcpy
}
void String::Print() const
{
	cout << value << endl;
}

String String::operator * (const String b) const
{
	char* buff = new char[MaxStringSize] {};
	size_t sze = 0;

	for (size_t i = 0; value[i]; ++i) {
		if (value[i] == b.value[i]) {
			++sze;
			buff[sze] = value[i];
		}
	}
	return String( buff );
}

String::~String()
{
	delete[]value;
	value = nullptr;
}
void main()
{
	String a{ String{ "Microsoft" } *String{ "Windows" } };
	a.Print();
}