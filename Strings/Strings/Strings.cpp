#include "pch.h"
#include <iostream>
#include "MyString.h"

int main()
{
	const char *s = "abcd";
	MyString a(s);
	char ss = 'b';
	MyString b(ss);
	MyString c = b + a;
	cout << c;
	MyString d;
	c += b;
	c+=ss;
	d = c + ss;
	cout << c;
	cout << d;
	MyString e;
	e = d + s;
	e = ss;
	e = s;
	e = c;
	if (c == d)
		cout << c;
	if (e == c)
		cout << d;
	MyString f;
	cin >> f;
	f += a;
	cout << f;
}

