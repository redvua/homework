#include <iostream>
using namespace std;
const size_t MaxStringSize = 255;

struct Fraction
{
	int numerator;
	int denominator;
	//Fraction* (*act)(Fraction) = this.Inc;


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
	Fraction* Minus()
	{
		this->denominator *= -1;
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
		if (!numerator) cout << "0";
		// cout << endl;
	}
};
struct Solution
{
	enum State { Si, Sm, Sd, Re, Se, Begin, Count, End, States = End } state;
	char* buff; //
	bool error;
	// Solution* subject;
	Fraction result;
	Fraction subj;
	Fraction* (Fraction::*act)(Fraction) = &Fraction::Inc; // вот оно че

	Solution(char* buff)
	{
		cout << buff << " ";

		this->buff = buff;
		this->error = false;

		result = Fraction();
		state = Si;
		while (*this->buff != '\0' && !error) Step();

		if (error) cout << "Error: " << this->buff;
		else result.Show();
		cout << endl;
	}
	//Solution() :Solution(nullptr)
	//{
	//}
	//Fraction* Inc(char* buff, Fraction result) {
	//	result.Inc(this->result);// Parser(buff).Shift;
	//}
	//Fraction* Mul(char* buff, Fraction result) {
	//	this->result.Mul(result); // Parser(buff).Shift;
	//}
	void Step() {
		
		// только %d - +
		switch (state)
		{
		case Si:
			subj = Fraction();
			state = Sm;
			break;
		case Sm:
			// -
			if (*buff == ' ') ++buff;
			if (*buff == '-') subj.Minus(), ++buff; state = Sd; // subj = 0/-1
			if (isdigit(*buff)) state = Sd;
			break;
		case Sd:
			// %d
			if (*buff == ' ') ++buff;
			else if (isdigit(*buff)) subj.numerator = strtol(buff,&buff,10), state = Re; // subj.numerator = %d
				else error = true;
			break;
		case Re:
			if (*buff == ' ') ++buff;
			else if (*buff == '+') result.Inc(subj), ++buff, state = Si; // result += subj
				else if (*buff == '=') result.Inc(subj), ++buff, state = Si; // result += subj
					else if (*buff == '-') result.Inc(subj), state = Si; // result += subj
						else error = true; // ?
			break;
		// case End:
		default:
			error = true;

			break;
		}
		// this->subject = nullptr;
	}
};

void main()
{
	char* string = new char[MaxStringSize] {"1+2-12+20="}; //"-11/2+22/03"
	Solution wrap = Solution(string);
	wrap = Solution("3 - 5 + 0 =");
	wrap = Solution(" 12 - 5 + 10 = ");
	//Fraction{ 13,169 }.Show();
	//Fraction{ 5,4 }.Inc({ 1,2 })->Mul({1,2})->Show();
	//Fraction{ 3,4 }.Mul({ 11,18 })->Show();
	//Fraction{ 3,5 }.Dec({ 1,2 })->Show();
	//Fraction{ 9,2 }.Div({ 1,2 })->Show();
	cout << endl;

}