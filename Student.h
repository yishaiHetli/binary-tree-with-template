#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Student
{
	string id;
	string Fname;
	string Lname;
public:
	Student(string ID = "0", string F_name = "", string L_name = "")//ctor with a defult values 
		:id(ID), Fname(F_name), Lname(L_name) {}
	bool operator < (Student S);
	bool operator <= (Student S);
	bool operator > (Student S);
	bool operator >= (Student S);
	bool operator == (Student S);
	void operator =(Student S);
	string getID() { return id; }
	friend ostream& operator<<(ostream& out, Student& S);
	friend istream& operator>>(istream& in, Student& S);

};
