#pragma once
#include "art.h"
class Sculpture:virtual public Art
{
public:
	Sculpture(char* name, int year, char* season, float high, Artist* arter, float area, float weight);
	virtual ~Sculpture();
	virtual void print();
	const float get_weight()const { return weight; }
private:
	float area;
	float weight;
};
