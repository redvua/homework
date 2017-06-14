#include <iostream>
#define LINE (cout << endl << endl << "----------------------" << endl << endl)
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int, int, int);

	// get
	int Numerator() const;
	int Denominator() const;
	// set
	int & Numerator();
	int & Denominator();

	void Show(bool) const;
	Fraction & Reduction();
	// Fraction Reduction() const; // ?

	Fraction operator * (const Fraction) const;
	Fraction operator / (const Fraction) const;

	Fraction & operator ++ ();
	Fraction operator ++ (int);
	Fraction & operator -- ();
	Fraction operator -- (int);

	bool operator > (const Fraction) const;
	bool operator < (const Fraction) const;

	operator int() const;
	operator double() const;

	~Fraction();

private:
	friend Fraction operator - (const Fraction, const Fraction);
};

Fraction::Fraction(int numerator_ = 0, int denominator_ = 1, int integer = 0) : numerator(numerator_), denominator(denominator_)
{
	if (denominator_ == 0)
		std::cerr << "Error: Division by zero\n", exit(1);

	if (denominator < 0) { // перенос знака в числитель
		numerator *= -1;
		denominator *= -1;
	}
	if (integer < 0 && numerator > 0) numerator *= -1; // сохранение знака

	numerator += integer * denominator;
}

int Fraction::Numerator() const {
	return numerator;
}
int Fraction::Denominator() const {
	return denominator;
}
// )-:
int & Fraction::Numerator() {
	return numerator;
}
int & Fraction::Denominator() {
	return denominator;
}

void Fraction::Show(bool induction = false) const
{
	int integer{ this->numerator / denominator };
	int numerator{ this->numerator % denominator };
	if (integer < 0) numerator *= -1; // сохранение знака
	if (numerator == 0) cout << integer;
		else if (induction) cout << this->numerator << "/" << denominator; // без выделения целой части
			else if (integer == 0) cout << numerator << "/" << denominator;
				else cout << integer << "_" << numerator << "/" << denominator;
}

Fraction Fraction::operator * (const Fraction b) const
{
	return Fraction(numerator * b.numerator, denominator * b.denominator);
}
Fraction Fraction::operator / (const Fraction b) const
{
	return Fraction(numerator * b.denominator, denominator * b.numerator);
	//return (*this * Fraction{ b.denominator, b.numerator });
}

Fraction & Fraction::operator ++()
{
	numerator += denominator;
	return *this;
}
Fraction Fraction::operator ++(int)
{
	Fraction old{ *this };
	numerator += denominator;
	return old;
}
Fraction & Fraction::operator --()
{
	numerator -= denominator;
	return *this;
}
Fraction Fraction::operator --(int)
{
	Fraction old{ *this };
	numerator -= denominator;
	return old;
}
bool Fraction::operator > (const Fraction b) const
{
	return ((*this - b).numerator > 0);
}
bool Fraction::operator < (const Fraction b) const
{
	return ((*this - b).numerator < 0);
}

Fraction::operator int() const
{
	return numerator / denominator;
}
Fraction::operator double() const {
	return double(numerator) / denominator;
}

Fraction::~Fraction() {}

Fraction & Fraction::Reduction()
{
	// сохранение знака
	int sign{ (numerator < 0) ? -1 : 1 };
	numerator *= sign;

	// сокращение дробной части
	int min{ (numerator < denominator) ? numerator : denominator };
	for (; min > 1; --min)
	{
		if (!(numerator%min || denominator%min))
		{
			numerator /= min;
			denominator /= min;
		}
	}
	numerator *= sign;
	return *this;
}
//Fraction Fraction::Reduction() const
//{
//	return Fraction (numerator, denominator).Reduction();
//}

Fraction operator + (const Fraction a, const Fraction b)
{
	return Fraction(
		a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator(),
		a.Denominator() * b.Denominator()
	);
}
Fraction operator - (const Fraction a, const Fraction b) // friend
{
	return Fraction(
		a.numerator * b.denominator - b.numerator * a.denominator,
		a.denominator * b.denominator
	);
}
bool operator == (const Fraction a, const Fraction b)
{
	return ((a - b).Numerator() == 0);
}
bool operator != (const Fraction a, const Fraction b)
{
	// Fraction left{ a.Reduction() }, right{ b.Reduction() };
	return !(a == b);
}

void main()
{
	Fraction z({}), a(1, 5, 1), b(1, 2), c(-4, -8);
	cout << "Fraction({}) = ", z.Show();
	LINE;
	cout << "Fraction(1, 5, 1) = ", a.Show();
	LINE;
	Fraction si(156,-144), pi(1, -3, 3);
	cout << "(" , si.Show(), cout << ").Reduction() = ", si.Reduction().Show();
	LINE;
	cout << "(" , si.Show(), cout << ").Induction() = ", si.Reduction().Show(true);
	LINE;
	cout << "(" , si.Show(), cout << ").setNumerator() = 14  -> ", si.Numerator() = 14, si.Show();
	LINE;

	pi.Show(), cout << " * ", a.Show(), cout << " = ";
	pi.Show(true), cout << " * ", a.Show(true), cout << " = ";
	(pi * a).Show(true), cout << " = ", (pi * a).Show();
	LINE;
	pi.Show(), cout << " / ", a.Show(), cout << " = ";
	pi.Show(true), cout << " / ", a.Show(true), cout << " = ";
	(pi / a).Show(true), cout << " = ", (pi / a).Show();
	LINE;
	pi.Show(), cout << " + ", a.Show(), cout << " = ";
	pi.Show(true), cout << " + ", a.Show(true), cout << " = ";
	(pi + a).Show(true), cout << " = ", (pi + a).Show();
	LINE;
	pi.Show(), cout << " - ", a.Show(), cout << " = ";
	pi.Show(true), cout << " - ", a.Show(true), cout << " = ";
	(pi - a).Show(true), cout << " = ", (pi - a).Show();
	LINE;
	a.Show(), cout << " - ", pi.Show(), cout << " = ";
	a.Show(true), cout << " - ", pi.Show(true), cout << " = ";
	(a - pi).Show(true), cout << " = ", (a - pi).Show();
	LINE;

	b.Show(true), cout << " == ", c.Show(true), cout << " = ";
	cout << boolalpha << (b == c);
	LINE;
	b.Show(true), cout << " != ", c.Show(true), cout << " = ";
	cout << boolalpha << (b != c);
	LINE;
	a.Show(), cout << " < ", c.Show(), cout << " = ";
	cout << boolalpha << (a < c);
	LINE;
	a.Show(), cout << " > ", c.Show(), cout << " = ";
	cout << boolalpha << (a > c);
	LINE;

	cout << "int(", pi.Show(), cout << ") = " << int(pi);
	LINE;
	cout << "double(", pi.Show(), cout << ") = " << double(pi);
	LINE;

	cout << "--(", si.Show(), cout << ") = ", (--si).Show(), cout << " -> ", si.Show();
	LINE;
	cout << "(", si.Show(), cout << ")-- = ", (si--).Show(), cout << " -> ", si.Show();
	LINE;

	cout << "++(", pi.Show(), cout << ") = ", (++pi).Show(), cout << " -> ", pi.Show();
	LINE;
	cout << "(", pi.Show(), cout << ")++ = ", (pi++).Show(), cout << " -> ", pi.Show();
	LINE;
}