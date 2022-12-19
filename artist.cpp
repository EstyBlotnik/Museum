#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include "date.h"
#include <string>
#include "picture.h"
#include "art.h"
#include "artist.h"
#include "sculpture.h"
#include "hanging_statue.h"
#include <iostream>
#define N 20

Artist::Artist(char* name, Date date_birth, Date date_death)
{
	this->name = new char[(strlen(name)) + 1];
	if(this->name)
		strcpy(this->name, name);
	this->date_birth = date_birth;
	this->date_death = date_death;
	Art** arts = NULL;
	size_arts = 0;
}

Artist::~Artist()
{
	delete[]name;
	for (int i = 0; i < size_arts; ++i)
		delete[] arts[i];
	delete[] arts;
}

Artist& Artist::operator-=(const char* name)
{
	int k = 0,temp=0;
	for (int i = 0; i < size_arts; ++i)
	{
		if (strcmp(this->arts[i]->get_name(), name) == 0)
		{
			++temp;
		}
	}
	if (temp == 0)
		return *this;
	Art** new_arts = new Art * [size_arts - 1];
	if (!new_arts)
		return *this;
	for (int i = 0; i < size_arts; ++i)
	{
		if (strcmp(this->arts[i]->get_name(), name) != 0)
		{
			new_arts[k] = this->arts[i];
			++k;
		}
	}
	delete[] this->arts;
	this->arts = new_arts;
	--size_arts;
	return *this;
}
Artist& Artist::operator+=(Art* arty)
{
	Art** new_arts = new Art * [size_arts + 1];
	if (!new_arts)
		return(*this);
	int new_size_arts = size_arts + 1;
	for (int i = 0; i < size_arts; ++i)
		new_arts[i] = arts[i];
	new_arts[size_arts] = arty;
	delete[] this->arts;
	this->arts = new_arts;
	++size_arts;
	return (*this);
}
ostream& operator<<(ostream& os, const Artist& a)
{
	os << "The name of the artist: " << a.name << endl;
	os << "His date of birth: ";
	a.date_birth.Date::print();
	os << "His date of death: ";
	a.date_death.Date::print();
	os << "the arts are:" << endl;
	for (int i = 0; i < a.size_arts; ++i)
	{
		os <<a.arts[i]->get_name()<<endl;
	}
	return os;
}