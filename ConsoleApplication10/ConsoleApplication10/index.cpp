#include <iostream>
#include "string.h"
using namespace std;

void main()
{
	//LINE;

	String a("Microsoft");
	String b("Windows");
	cout << "a[12]: " << a[12] << endl;
	a.Print();
	LINE;

	cout << "a[0] = P" << endl;
	a[0] = 'P';
	a.Print();

	LINE;

	cout << "(\"My program\")(3, 4) = ", String("My program")(3, 4).Print();
	LINE;
	cout << "(\"My program\")(3) = ", String("My program")(3).Print();

	LINE;

	a = String("Abrvalg");
	a.Print();
	LINE;

	a = "VisualStudio";
	a.Print();
	LINE;

	a += "=+=+=";
	a.Print();
	LINE;

	a *= "V+S="; // ???
	a.Print();
	LINE;
	//a.Print(), cout << " * ", b.Print(), cout << " = ", (a * b).Print();
	//LINE;
	//a.Print(), cout << " / ", b.Print(), cout << " = ", (a / b).Print();
	//LINE;
	//a.Print(), cout << " + ", b.Print(), cout << " = ", (a + b).Print();
	//LINE;
	//a.Print(), cout << " + asdfg = ", (a + "asdfg").Print();
	//LINE;
	//cout << "asdfg + ", a.Print(), cout << " = ", ("asdfg" + a).Print();
	//LINE;
	//cout << "!", b.Print(), cout << " = ", (!b).Print();
	//LINE;

	//String c("Abcd");
	//String d("Abcd");
	//cout << "++", c.Print(), cout << " = ", (++c).Print(), cout << " -> ", c.Print();
	//LINE;
	//d.Print(), cout << "++ = ", (d++).Print(), cout << " -> ", d.Print();
	//LINE;

	//String e("microsoft");
	//a.Print(), cout << " > ", e.Print(), cout << " = " << boolalpha << (a > e);
	//LINE;
	//a.Print(), cout << " < ", e.Print(), cout << " = " << boolalpha << (a < e);
	//LINE;
	//a.Print(), cout << " >= ", e.Print(), cout << " = " << boolalpha << (a >= e);
	//LINE;
	//a.Print(), cout << " <= ", e.Print(), cout << " = " << boolalpha << (a <= e);
	//LINE;
	//a.Print(), cout << " == ", e.Print(), cout << " = " << boolalpha << (a == e);
	//LINE;
	//a.Print(), cout << " != ", e.Print(), cout << " = " << boolalpha << (a != e);
	//LINE;
}