#include <iostream>
using namespace std;

struct Fraction
{
	int integer;
	int numerator;
	int denominator;
	bool division_by_zero;

	Fraction(int numerator = 0, int denominator = 1, int integer = 0)
	{
		this->division_by_zero = (denominator == 0);
		this->numerator = numerator;
		this->denominator = denominator;
		this->integer = integer;
	}
	Fraction* Inc(Fraction item)
	{
		Induction();
		item.Induction();
		this->integer = integer + item.integer;
		this->numerator = numerator*item.denominator + item.numerator*denominator;
		this->denominator *= item.denominator;
		return this;
	}
	Fraction* Dec(Fraction item)
	{
		Induction();
		item.Induction();
		this->numerator = numerator*item.denominator - item.numerator*denominator;
		this->denominator *= item.denominator;
		return this;
	}
	Fraction* Mul(Fraction item)
	{
		Induction();
		item.Induction();
		this->numerator = numerator * item.numerator;
		this->denominator *= item.denominator;
		return this;
	}
	Fraction* Div(Fraction item)
	{
		Induction();
		item.Induction();
		this->division_by_zero = division_by_zero || item.numerator == 0;
		this->numerator = numerator * item.denominator;
		this->denominator *= item.numerator;
		return this;
	}
	Fraction* Induction()
	{
		numerator = numerator + integer*denominator;
		integer = 0;
		return this;
	}
	Fraction* Reduction()
	{
		Induction();
		if (division_by_zero) return this;
		// целая часть
		integer = numerator / denominator;

		// сокращение знака
		if (integer) numerator = numerator%denominator;
		if (integer < 0 ) numerator *= -1;
		if (numerator < 0 && denominator < 0) this->Mul({-1, -1}); 

		// сокращение дробной части
		int min = (numerator < denominator) ? numerator : denominator;
		for (; min > 1; --min)
		{
			if (!(numerator%min || denominator%min))
			{
				numerator /= min;
				denominator /= min;
			}
		}
		return this;
	}
	void Show()
	{
		if (division_by_zero)
		{
			cout << "error: Division by zero" << endl;
			return;
		}
		Reduction(); // сокращение
		if (integer) cout << integer; // целая часть
		if (integer && numerator) cout << "_"; // разделитель
		if (numerator) cout << numerator << "/" << denominator; // дробная часть
		if (!integer && !numerator) cout << "0";
		cout << endl << endl;
	}
};

void main()
{
	// Проверки
	cout << "Inc:" << endl;
	cout << "1_1/2 + 3_5/8 = ";		Fraction({ 1,2,1 }).Inc({5,8,3})->Show();
	cout << "Dec:" << endl;
	cout << "1_1/2 - 3_5/8 = ";		Fraction({ 1,2,1 }).Dec({ 5,8,3 })->Show();
	cout << "Mul:" << endl;
	cout << "1_1/2 * 3_5/8 = ";		Fraction({ 1,2,1 }).Mul({ 5,8,3 })->Show();
	cout << "Div:" << endl;
	cout << "1_1/2 / 3_5/8 = ";		Fraction({ 1,2,1 }).Div({ 5,8,3 })->Show();
	cout << "Reduction:" << endl;
	cout << "5_-13/-169 = ";		Fraction({ -13,-169,5 }).Reduction()->Show();
	cout << "Division by zero:" << endl;
	cout << "1/0 = ";				Fraction({ 1,0 }).Show();
	cout << "1/2 / 0/8 = ";			Fraction({ 1,2 }).Div({ 0,8 })->Show();
	cout << endl;
}