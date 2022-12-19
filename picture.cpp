#include "picture.h"
#include "artist.h"
#include<iostream>
using namespace std; 
Picture::Picture(char* name, int year, char* season, float high, Artist* arter, float length) :Art(name, year, season, high, arter)
{
	this->length = length;
}
void Picture::print()
{
	Art::print();
	cout << "The length is: " << this->length << endl;
}
Picture::~Picture()
{

}
