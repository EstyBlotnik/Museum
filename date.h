#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int  day;
	int month;
	int year;
public:
	Date() { year = 2000; month = 1; day = 1; }
	Date(int day, int month, int year) { this->year = year; this->month = month; this->day = day; }
	virtual ~Date() { }
	const void print()const
	{
		if (day < 10)
			cout << "0" << day << "/";
		else
			cout << day << "/";
		if (month < 10)
			cout << "0" << month << "/";
		else
			cout << month << "/";
		if (year == 0)
			cout << "0000" << endl;
		else
			cout << year << endl;
	}
};
