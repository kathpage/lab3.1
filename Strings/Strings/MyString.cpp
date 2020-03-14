#include "pch.h"
#include "MyString.h"


MyString::MyString(const char* _string)
{
	length = strlen(_string);
	str = new char[length + strlen(_string)+1];
	strcpy(str, _string);
}

MyString::MyString(const char _char)
{
	length = 1; 
	str = new char[2];
	str[0] = _char;
	str[1] = '\0';
}

MyString::MyString(const MyString& _string)
{
	length = _string.length;
	str = new char[length + 1];
	strcpy(str, _string.str);
}

MyString& MyString::operator = (const MyString& rightString) {
	if (*this == rightString) {
		return *this;
	}
	if (length != rightString.length) {
		delete[] str;
		str = new char[rightString.length + 1];
	}
	strcpy(str, rightString.str);
	length = rightString.length;
	return *this;
}

MyString& MyString::operator = (const char* rightChars)
{
	if (length != strlen(rightChars)) {
		delete[] str;
		str = new char[strlen(rightChars) + 1];
	}
	strcpy(str, rightChars);
	length = strlen(rightChars);
	return *this;
}

MyString& MyString::operator = (const char rightChar)
{
	if (length != 1) {
		delete[] str;
		str = new char[2];
	}
	str[0] = rightChar;
	str[1] = '\0';
	length = 1;
	return *this;
}

bool MyString::operator == (const MyString& rightString) const
{
	if (length == rightString.length) {
		if (strcmp(str, rightString.str) == 0) {
			return 1;
		}
	}
	return 0;
}

bool MyString::operator != (const MyString& rightString) const 
{
	return !(*this == rightString);
}

MyString& MyString::operator += (const MyString& rightString)
{
	MyString a(*this);
	delete [] str;
	str = new char[length + rightString.length + 1];
	strcpy(str, a.str);
	strcat(str, rightString.str);
	length += rightString.length;
	return *this;
}

MyString& MyString::operator += (const char* rightString)
{
	MyString a(*this);
	delete[] str;
	str = new char[length + strlen(rightString) + 1];
	strcpy(str, a.str);
	strcat(str, rightString);
	length += strlen(rightString);
	return *this;
}

MyString& MyString::operator += (const char rightChar)
{
	MyString a(*this);
	delete[] str;
	str = new char[length + 2];
	strcpy(str, a.str);
	str[length] = rightChar;
	str[length + 1] = '\0';
	length += 1;
	return *this;
}

const MyString MyString::operator + (const MyString& rightString) const
{
	MyString a(*this);
	a += rightString;
	return a;
}

const MyString MyString::operator + (const char* rightString) const
{
	MyString a(*this);
	a += rightString;
	return a;
}

const MyString MyString::operator + (const char rightChar) const
{
	MyString a(*this);
	a += rightChar;
	return a;
}

ostream& operator << (ostream& os, const MyString& myString)
{
	cout << endl;
	return os << myString.str << endl;
}

istream& operator >> (istream& is, MyString& myString)
{
	cout << endl;
	cout << "Enter string: ";
	myString.str = new char[255];
	is >> myString.str;
	char *s = new char[strlen(myString.str + 1)];
	strcpy(s, myString.str);
	delete[] myString.str;
	myString.str = new char[strlen(s) + 1];
	strcpy(myString.str, s);
	myString.length = strlen(s);
	cout << endl;
	return is;
}

MyString::~MyString()
{
	delete[] str;
}
