#include <iostream>
using namespace std;
const size_t MaxStringSize = 255;

struct Fraction
{
	int integer;
	int numerator;
	int denominator;

	Fraction(int numerator = 0, int denominator = 1, int integer = 0)
	{
		this->numerator = numerator;
		this->denominator = denominator; // !=0
		this->integer = integer;
	}
	Fraction* Inc(Fraction item)
	{
		this->integer = integer + item.integer;
		this->numerator = numerator*item.denominator + item.numerator*denominator;
		this->denominator *= item.denominator;
		return this;
	}
	Fraction* Dec(Fraction item)
	{
		this->integer = integer - item.integer;
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
		this->numerator = numerator * item.denominator;
		this->denominator *= item.numerator; // !=0
		return this;
	}
	void Induction()
	{
		numerator = numerator + integer*denominator;
		integer = 0;
	}
	void Reduction()
	{
		Induction();
		if (numerator < 0 && denominator < 0) this->Mul({-1, -1}); // сокращение знака
		integer = numerator / denominator;
		if (integer) numerator = numerator%denominator;

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
		Reduction(); // сокращение
		if (integer) cout << integer; // целая часть
		if (integer && numerator) cout << "_"; // разделитель
		if (numerator) cout << numerator << "/" << denominator; // дробная часть
		if (!integer && !numerator) cout << "0";
		cout << endl;
	}
};
struct Solution
{
	enum State { Sstate, Astate, Mstate, Dstate, End, States = End } state;
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
		subj = Fraction();
		state = Sstate;
		while (*this->buff != '\0' && !error) Step();

		if (error) cout << "error ->" << this->buff << endl;
		else result.Show();
		//cout << endl;
	}
	//Solution() :Solution(nullptr)
	//{
	//}
	int GetNum() // long
	{
		char* offset = buff;
		int out;
		out = strtol(buff, &buff, 10); // обрабатывает цифру ноль в том числе
		error = (offset == buff);
		return out;
	}
	void Step() {
		
		// только %d - +
		switch (state)
		{

		case Sstate:
			if (*buff == ' ') ++buff;
			//else if (*buff == '(') ++buff, subj = Solution(buff).result;
			else subj.numerator = GetNum(), state = Astate;
			break;
		case Astate:
			if (*buff == ' ') ++buff;
			else if (*buff == '*') ++buff, state = Mstate;
			else if (*buff == '/') ++buff, state = Dstate;
			else if (*buff == '+') result.Inc(subj), ++buff, subj = { 0,1 }, state = Sstate;
			else if (*buff == '-') result.Inc(subj), ++buff, subj = { 0,-1 }, state = Sstate;
			else if (*buff == '=') result.Inc(subj), ++buff, subj = { 0,1 }, error = (*buff != '\0'), state = End;
			else error = true;
			break;
		case Mstate:
			subj.Mul( GetNum() );
			break;
		case Dstate:
			subj.Div( GetNum() ), state = Astate;
			break;
		case End:
			break;
		default:
			error = true;

			break;
		}
	}
};

void main()
{
	char* string = new char[MaxStringSize] {"1 + 2/3 -12 + 20 ="}; //"-11/2+22/03"
	Solution wrap = Solution(string);
	//wrap = Solution("3 - 5 + 0 =");
	//wrap = Solution(" 12 - 5 + 10 =");
	wrap = Solution(" 0*2 -5 * -3/-6 + 10 =");
	//wrap = Solution(" ( - 5 + 10 =");
	//Fraction{ 13,169 }.Show();
	//Fraction{ 5,4 }.Inc({ 1,2 })->Mul({1,2})->Show();
	//Fraction{ 3,4 }.Mul({ 11,18 })->Show();
	//Fraction{ 3,5 }.Dec({ 1,2 })->Show();
	Fraction{ 9,2 }.Div({ 1,2 })->Show();
	cout << endl;

}