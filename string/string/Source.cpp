#include <iostream>
#define LINE (cout << endl << endl << "----------------------" << endl << endl)
using namespace std;

class String
{
	char* value;
	size_t size;
public:
	String(const char*);
	String(const String &);
	void Print() const;

	String operator * (const String &) const;
	String operator / (const String &) const;
	String operator + (const String &) const;
	String operator + (const char*) const;

	String & operator = (const String &);
	String & operator = (const char*);
	String & operator *= (const String &);
	String & operator /= (const String &);
	String & operator += (const String &);

	String operator ! () const;
	String & operator ++ ();
	String operator ++ (int);

	bool operator < (const String &) const;
	bool operator > (const String &) const;
	bool operator <= (const String &) const;
	bool operator >= (const String &) const;
	bool operator == (const String &) const;
	bool operator != (const String &) const;

	char operator [] (size_t) const;
	char & operator [] (size_t);
	String operator () (size_t) const;
	String operator () (size_t, size_t) const;

	~String();

private:
	int Compare(const String &) const;
	int inString(char) const;

	friend ostream & operator << (ostream &, const String &);
	friend istream & operator >> (istream &, const String &);
};

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

ostream & operator << (ostream & out, const String & b) 
{
	out << b.value;
	return out;
}

istream & operator >> (istream & in, const String & b)
{
	in >> b.value;
	return in;
}

String String::operator * (const String & b) const
{

	const String & min = (size <= b.size) ? *this : b;
	const String & max = (size > b.size) ? *this : b;
	char* buff = new char[min.size + 1] {};
	size_t sze = 0;

	for (size_t i = 0; max.value[i]; ++i) {
		if ( min.inString(max.value[i]) != -1 ) {
			buff[sze] = max.value[i];
			++sze;
		}
	}
	return String( buff );
}

String String::operator / (const String & b) const
{
	char* buff = new char[size + 1] {};
	size_t sze = 0;

	for (size_t i = 0; value[i]; ++i) {
		if (b.inString(value[i]) == -1) {
			buff[sze] = value[i];
			++sze;
		}
	}
	return String( buff );
}

String String::operator + (const String & b) const
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

String operator + (const char* a, const String & b)
{
	return String{ a } + b;
}

String & String::operator = (const String & b)
{
	if (this == &b) return *this;
	size = b.size;
	delete[]value;
	// value = nullptr;
	value = new char[size + 1]{};
	memcpy(value, b.value, size);
	return *this;
}

String & String::operator = (const char* b)
{
	*this = String{ b };
	return *this;
}

String & String::operator *= (const String & b)
{
	*this = *this * b;
	return *this;
}

String & String::operator /= (const String & b)
{
	*this = *this / b;
	return *this;
}

String & String::operator += (const String & b)
{
	*this = *this + b;
	return *this;
}

String String::operator ! () const
{
	char* buff = new char[size + 1]{};

	for (size_t i = 0; value[i]; ++i) {
			buff[i] = value[size - i -1];
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

bool String::operator < (const String & b) const
{
	return Compare(b) < 0;
}

bool String::operator > (const String & b) const
{
	return Compare(b) > 0;
}

bool String::operator <= (const String & b) const
{
	return Compare(b) <= 0;
}

bool String::operator >= (const String & b) const
{
	return Compare(b) >= 0;
}

bool String::operator == (const String & b) const
{
	return Compare(b) == 0;
}

bool String::operator != (const String & b) const
{
	return Compare(b) != 0;
}

int String::Compare(const String & b) const
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

char String::operator [](size_t i) const // ?
{
	if (i > size - 1) {
		// std::cerr << "Error: out of range";
		return 0;
	}
	return value[i];
}

char & String::operator [](size_t i)
{
	if (i > size - 1) {
		std::cerr << "Error: out of range";
	}
	return value[i];
}

String String::operator () (size_t start) const
{ 
	return (start > size) ? String{} : String{ value + start };
}

String String::operator () (size_t start, size_t length) const
{
	if (start > size) start = size;
	if (start + length > size) length = size - start;
	if (!length || start == size) return String{};

	char* buff = new char[length + 1]{};
	memcpy(buff, value + start, length);
	return  String{ buff };
}

String::~String()
{
	delete[]value;
	value = nullptr;
}
void main()
{

	String a("Microsoft");
	String b("Windows");

	cout << "\n\tHomework 05\n\n";
	cout << a << " = " << b, a = b, cout << " -> " << a;
	a = "Microsoft";
	LINE;
	cout << a << " *= " << b, a *= b, cout << " -> " << a;
	a = "Microsoft";
	LINE;
	cout << a << " /= " << b, a /= b, cout << " -> " << a;
	a = "Microsoft";
	LINE;
	cout << a << " += " << b, a += b, cout << " -> " << a;
	a = "Microsoft";
	LINE;
	cout << a << " += asdfg ", a += "asdfg", cout << " -> " << a;
	a = "Microsoft";
	LINE;
	cout << a << " [0] = ", cout << a[0] << endl;
	cout << a << " [5] = $ -> ", a[5] = '$', cout << a << endl;
	a = "Microsoft";
	cout << a << " [9] = " << a[9];
	LINE;

	cout << a << "(3) = " << a(3);
	LINE;
	cout << a << "(2, 4) = " << a(2, 4);
	LINE;
	cout << a << "(10, 10) = " << a(10,10);
	LINE;
	cout << "Input String: ";
	cin >> a;
	cout << a << ": String(1,3) = " << a(1,3);
	LINE;

}