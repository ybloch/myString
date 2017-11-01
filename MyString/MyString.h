#pragma once
//  Yinon Bloch
// This class is an imitation of the original String class with some of its functionality


class  MyString
{
public:
	/*
	c-tor init char array pointer and size
	*/
	 MyString();
	 /*
	 d-tor delete char array pointer
	 */
	~ MyString();
	/*
	This method return a char in the given index in string
	agruments: int index
	return: int length
	*/
	size_t GetLength();
	/*
	This method Assign a new string
	agruments: string to Assign
	return: void
	*/
	void Assign(char* otherString);
	/*
	This method Assign a new string
	agruments: string to Assign
	return: void
	*/
	void Assign(MyString& otherString);
	/*
	This method return a char in the given index in string 
	agruments: int index
	return: char in index
	*/
	char CharAt(size_t index);
	/*
	 This method append a new string to the existing string
	 agruments: string to append
	 return: void
	*/
	void Append(char* otherString);
	/*
	This method append a new string to the existing string
	agruments: string to append
	return: void
	*/
	void Append(MyString& otherString);
	/*
	This method Compare between 2 strings
	agruments: string to Compare with
	return: 0 if equal, -1 if there not same size
	*/
	int Compare(char* otherString);
	/*
	This method Compare between 2 strings
	agruments: string to Compare with
	return: 0 if equal, -1 if there not same size
	*/
	int Compare(MyString& otherString);
	/*
	This method check if the string is empty
	agruments: none
	return: true if empty
	*/
	bool IsEmpty();
	/*
	This method clear the string
	agruments: none
	return: void
	*/
	void Clear();
	/*
	This method print the string
	agruments: none
	return: void
	*/
	void print();

private:
	/*
	size of the memory allocated
	*/
	size_t m_size;
	/*
	the string
	*/
	char* m_string;
};

