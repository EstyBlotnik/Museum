#pragma once
#include "artist.h"
class Artist;
class Art
{
private:
	char* name;
	int year;
	char* season;
	float high;
	Artist* arter;
public:
	Art(char* name,int year,char* season, float high, Artist* arter);
	virtual ~Art();
	virtual void print();
	const char* get_name()const { return name; }
	const char* get_season()const { return season; }
	const Artist* get_arter()const { return arter; }
};
