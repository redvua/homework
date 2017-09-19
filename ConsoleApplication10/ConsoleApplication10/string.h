#ifndef __STRING_H__
#define __STRING_H__

#define LINE (cout << endl << endl << "----------------------" << endl << endl)

class String
{
	char* value;
	size_t size;
public:
	String(const char*);
	String(const String &);
	void Print() const;
	String operator * (const String) const;
	String operator / (const String) const;
	String operator + (const String) const;
	String operator + (const char*) const;

	String operator ! () const;
	String & operator ++ ();
	String operator ++ (int);

	bool operator < (const String) const;
	bool operator > (const String) const;
	bool operator <= (const String) const;
	bool operator >= (const String) const;
	bool operator == (const String) const;
	bool operator != (const String) const;

	char & operator [] (const unsigned int); // ?
	String operator () (unsigned int, unsigned int) const;
	String operator () (unsigned int) const;

	String & operator = (const String &);
	String & operator = (const char *);

	String & operator *= (const String &);
	String & operator /= (const String &);
	String & operator += (const String &);
	String & operator += (const char*);

	~String();

private:
	int Compare(const String) const;
	int inString(char) const;
};

String operator + (const char*, const String);

#endif