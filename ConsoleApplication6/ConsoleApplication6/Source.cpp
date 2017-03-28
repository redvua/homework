#include <iostream>
using namespace std;
const size_t MaxStringSize = 255;

struct Fraction
{
	// enum Action { Sum, Sub, Mul, Div, Actions = Div };
	int numerator;
	int denominator;

	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	Fraction () :Fraction(0,1)
	{

	}
	Fraction* Inc(Fraction item)
	{
		this->numerator = numerator*item.denominator + item.numerator*denominator;
		this->denominator *= item.denominator;
		return this;
	}
	Fraction* Dec(Fraction item)
	{
		this->numerator = numerator*item.denominator - item.numerator*denominator;
		this->denominator *= item.denominator;
		return this;
	}
	Fraction* Mul(Fraction item)
	{
		this->numerator = numerator * item.numerator;
		this->denominator *= item.denominator;
		return this;
	}
	Fraction* Div(Fraction item)
	{
		this->numerator = numerator * item.denominator;
		this->denominator *= item.numerator;
		return this;
	}
	void Reduction() {	
		int min = (numerator < denominator) ? numerator : denominator;
		for (; min > 1; --min)
		{
			if (!(numerator%min || denominator%min))
			{
				numerator /= min;
				denominator /= min;
			}
		}
	}
	void Show()
	{
		if (numerator / denominator) printf("%d ", numerator / denominator); // целая часть
		Reduction(); // сокращение
		if (numerator%denominator) printf("%d/%d", numerator%denominator, denominator); // дробная часть
		cout << endl;
	}
};
struct Solution
{
	const char* buff; //
	bool error;
	Solution* subject;
	Fraction result;

	Solution(char* buff)
	{
		this->buff = buff;
		this->error = false;
		this->subject = nullptr;

		this->result = Fraction(); //
	}
	Solution() :Solution(nullptr)
	{
	}
};
struct Parser
{
	const char* buff; //
	bool error;
	//Solution* subject;
	//Fraction result;
	Parser(char* buff)
	{
		this->buff = buff;
		this->error = false;
		//this->subject = nullptr;


		for (size_t i = 0; buff[i] != '\0'; i++)
		{
			int num = 0;
			if (isdigit(buff[i])) // проверить отрицательные -12
			{
				num = atoi(buff);
			}
		}


		//  this->result = Fraction(); //
	}
};
void main()
{
	char* string = new char[MaxStringSize] {"1/2 + 2/3 ="};
	// Solution wrap = Solution(string);
	Fraction{ 13,169 }.Show();
	Fraction{ 5,4 }.Inc({ 1,2 })->Mul({1,2})->Show();
	Fraction{ 3,4 }.Mul({ 11,18 })->Show();
	//Fraction{ 3,5 }.Dec({ 1,2 })->Show();
	//Fraction{ 9,2 }.Div({ 1,2 })->Show();
	cout << endl;


}