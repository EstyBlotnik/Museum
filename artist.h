#pragma once
#include"Date.h"
#include"Art.h"
class Art;
class Artist
{
public:
	Artist(char* name, Date date_birth, Date date_death);
	virtual ~Artist();
	//Artist& operator++();
	Artist& operator+=(Art* arty);
	Artist& operator-=(const char* name);
	const void print()const;
	friend ostream& operator<<(ostream& os, const Artist& a);
	const char* get_name()const { return name; }
	const int get_size_arts()const { return size_arts; }
	Art** get_arts() {  return arts; }

private:
	char* name;
	Date date_birth;
	Date date_death;
	Art** arts;
	int size_arts;
};




