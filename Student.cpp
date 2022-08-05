#include "Student.h"

bool Student::operator<(Student S)
{
	if (S.Lname == this->Lname)
		return this->Fname < S.Fname;
	return this->Lname < S.Lname;
}

bool Student::operator<=(Student S)
{
	if (S.Lname == this->Lname)
		return this->Fname <= S.Fname;
	return this->Lname <= S.Lname;
}

bool Student:: operator>(Student S)
{
	if (S.Lname == this->Lname)
		return this->Fname > S.Fname;
	return this->Lname > S.Lname;
}
bool Student::operator >= (Student S)
{
	if (S.Lname == this->Lname)
		return this->Fname >= S.Fname;
	return this->Lname >= S.Lname;
}
bool Student::operator == (Student S)
{
	return this->Fname == S.Fname && this->Lname == S.Lname && this->id == S.id;
}
void Student::operator =(Student S)
{ 
	this->id = S.id; this->Fname = S.Fname; this->Lname = S.Lname; 
}

ostream& operator<<(ostream& out, Student& S)
{ 
	out << S.id << '\t' << S.Fname << '\t' << S.Lname; return out; 
}

istream& operator>>(istream& in, Student& S)
{ 
	in >> S.id >> S.Fname >> S.Lname; return in; 
}