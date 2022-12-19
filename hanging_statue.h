#pragma once
#include "picture.h"
#include "sculpture.h"
class Hanging_statue:public Picture,public Sculpture
{
private:
	int num_of_screws;
public:
	Hanging_statue(char* name, int year, char* season, float high, Artist* arter, float length,float area, float weight,int num_of_screws);
	virtual ~Hanging_statue();
	virtual void print();
};
