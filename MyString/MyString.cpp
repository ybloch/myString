#include <iostream>
#include "MyString.h"
#include <string>

using namespace std;


MyString::MyString():m_size(1), m_string('\0')
{
}

MyString::~MyString()
{
	delete m_string;
}

void MyString::Append(char* myString)
{
	if (myString && myString[strlen(myString)] == '\0')
	{
		int myStringSize = 0;
		int tmpStringSize = 0;
		char* tmpString = new char[m_size];

		// copy the string to temp 
		strncpy_s(tmpString, m_size, m_string, m_size);
		delete m_string;
		// resize the string
		m_string = new char[strlen(tmpString) + strlen(myString) + 2];
		// return the original value
		strncpy_s(m_string, strlen(tmpString) + 1, tmpString, strlen(tmpString) + 1);
		m_string[strlen(tmpString)] = '\0';

		myStringSize = strlen(myString);
		tmpStringSize = strlen(tmpString);
		// append the new value
		strncat_s(m_string, myStringSize + tmpStringSize + 1, myString, myStringSize + tmpStringSize + 1);
		m_size = strlen(m_string) + 1;
		m_string[m_size] = '\0';
		// free temp memory
		delete tmpString;
	}
	else
	{
		throw exception("string not valid! must end with null terminator");
	}
}

size_t MyString::GetLength()
{
	return strlen(m_string);
}

void MyString::Assign(char* myString)
{
	if (myString && myString[strlen(myString)] == '\0')
	{
		// if there no need to allocate new memory
		if (strlen(myString) < m_size)
		{
			// copy the new value and append null terminator
			strncpy_s(m_string, strlen(myString), myString, strlen(myString));
			m_string[strlen(myString) - 1] = '\0';
		}
		else
		{
			// free old memory and allocate new one
			delete m_string;
			m_size = strlen(myString) + 1;
			m_string = new char[m_size];
			// copy new value
			strncpy_s(m_string, m_size, myString, m_size);
		}		
	}
	else
	{
		throw exception("string not valid! must end with null terminator");
	}
}

char MyString::CharAt(size_t index)
{
	char res = '\0';
	// check valid index
	if (strlen(m_string) > index && 0 <= index)
	{
		res = m_string[index];
	}
	else
	{
		throw exception("invalid index!");
	}
	return res;
}

int MyString::Compare(char* myString)
{
	int res = 0;
	if (myString && myString[strlen(myString)] == '\0')
	{
		if (strlen(myString) != strlen(m_string))
		{
			res = -1;
		}
		else
		{
			res = strncmp(m_string, myString, strlen(m_string));
		}
	}
	else
	{
		throw exception("string not valid! must end with null terminator");
	}
	return res;
}

bool MyString::IsEmpty()
{
	return NULL == m_string;
}

void MyString::Clear() 
{
	delete m_string;
	m_string = new char[1];
	m_string = '\0';
	m_size = 1;
}

void MyString::print()
{
	cout << m_string << endl;
}

void main(void)
{
	try
	{
		char userString[256];
		MyString myString;
		myString.Assign("my name is Yinon");
		myString.print();
		myString.Append(", my last name is Bloch");
		myString.print();
		char c = myString.CharAt(1);
		cout << "the first char is: " << c << "\n";
		if (myString.Compare("my name is Moshe") == 0)
		{
			cout << "my string equel to: my name is Moshe\n";
		}
		else
		{
			cout << "my string not equel to: my name is Moshe\n";
		}
		if (myString.Compare("my name is Yinon, my last name is Bloch") == 0)
		{
			cout << "my string equel to: my name is Yinon, my last name is Bloch\n";
		}
		else
		{
			cout << "my string not equel to: my name is Yinon, my last name is Bloch\n";
		}
		int l = myString.GetLength();
		cout << "the length of my string is: " << to_string(l) << "\n";
		myString.Clear();

		if (myString.IsEmpty())
		{
			cout << "my string empty\n";
		}
		else
		{
			cout << "clear not work\n";
		}

		cout << "enter some string:\n";
		cin.get(userString, 256);
		myString.Assign(userString);
		cout << "your enter:\n";
		myString.print();
		myString.Append(" - this string append to your string");
		myString.print();
	}
	catch (const std::exception& exp)
	{
		cout << exp.what();
	}
}
