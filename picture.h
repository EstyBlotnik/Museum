#pragma once
#include "art.h"
class Picture:virtual public Art
{
public:
	Picture(char* name, int year, char* season, float high, Artist* arter,float length);
	virtual ~Picture();
	virtual void print();
	float get_length() { return length; }
private:
	float length;
};


