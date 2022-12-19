#include "sculpture.h"
#include "artist.h"
#include<iostream>
using namespace std;
Sculpture::Sculpture(char* name, int year, char* season, float high, Artist* arter, float area, float weight) :Art(name, year, season, high, arter)
{
	this->area = area;
	this->weight = weight;
}
void Sculpture::print()
{
	Art::print();
	cout << "The area is: " << this->area << endl;
	cout << "The weight is: " << this->weight << endl;
}
Sculpture::~Sculpture()
{

}