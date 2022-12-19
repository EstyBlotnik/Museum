#include "hanging_statue.h"
#include "sculpture.h"
#include "picture.h"
#include "artist.h"
#include<iostream>
Hanging_statue::Hanging_statue(char* name, int year, char* season, float high, Artist* arter, float length, float area, float weight,int num_of_screws):Art(name, year, season, high, arter),Picture(name, year, season, high, arter, length), Sculpture(name, year, season, high, arter,area, weight)
{
	this->num_of_screws = num_of_screws;
}
void Hanging_statue::print()//לוודא שאכן עשיתי נכון את הפונקציה
{
	Sculpture::print();
	cout << "The length is: " << this->get_length() << endl;
	cout << "The num of screws is: " << this->num_of_screws << endl;
}
Hanging_statue::~Hanging_statue()
{

}