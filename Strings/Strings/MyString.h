#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ostream>

using namespace std;

class MyString
{
private:
	char* str;
	size_t length;
public:
	MyString() { length = 0; }
	MyString(const char _char);
	MyString(const char* _string);
	MyString(const MyString& _string);
	~MyString();

	int GetLength() const { return length; }
	const char* GetString() const { return str; }

	char& operator [] (const size_t index) const{	return str[index];}
	

	friend ostream& operator << (ostream& os, const MyString& myString);
	friend istream& operator >> (istream& is, MyString& myString);  

	MyString& operator = (const MyString& rightString);
	MyString& operator = (const char* rightChars);
	MyString& operator = (const char rightChar);

	bool operator == (const MyString& rightString) const;
	bool operator != (const MyString& rightString) const;

	MyString& operator += (const MyString& rightString);
	MyString& operator += (const char* rightString);
	MyString& operator += (const char rightChar);

	const MyString operator + (const MyString& rightString) const;
	const MyString operator + (const char* rightString) const;
	const MyString operator + (const char rightChar) const;

};

