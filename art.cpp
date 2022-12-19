#define _CRT_SECURE_NO_WARNINGS
#include"art.h"
#include "artist.h"
#include<string.h>
#include<iostream>
using namespace std;
Art::Art(char* name, int year, char* season, float high, Artist* arter)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->year = year;
	this->season= new char[strlen(season) + 1];
	strcpy(this->season, season);
	this->high = high;
	this->arter = arter;
}
Art::~Art()
{
	delete[] name;
	delete[] season;
}
void Art::print()
{
	cout << "Name of art: " << this->name << endl;
	cout << "Year of creation: " << this->year << endl;
	cout << "The season is: " << this->season << endl;
	cout << "The high is: " << this->high << endl;
	cout << "The name of the artist is: " << this->arter->get_name() << endl;
}
