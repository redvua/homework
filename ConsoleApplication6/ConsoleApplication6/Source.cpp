#include <iostream>
using namespace std;
struct Fraction
{
	enum Action { Sum, Sub, Mul, Div, Actions = Div };
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


		for (size_t i = 0; buff[i] != '\0'; i++)
		{
			int num = 0;
			if (isdigit(buff[i])) // проверить отрицательные -12
			{
				num = atoi(buff);
			}
		}


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
	const size_t MaxStringSize = 255;
	char* string = new char[MaxStringSize] {"1/2 + 2/3"};
	Solution wrap = Solution(string);


}