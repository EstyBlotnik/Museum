#pragma once
#include"Art.h"
#include "Artist.h"
class Museum
{
private:
	Art** arts;
	Artist** artists;
	int num_of_artists;
	int num_of_arts;
public:
	Museum();
	virtual ~Museum();
	Museum& add_artist(char* name);
	Museum& add_art();
	Museum& sub_art(int index);
	const void print_arts()const;
	const void print_artists()const;
	const void print_pictures()const;
	const void print_sculpture()const;
	const void print_art_of_artist()const;
	const void print_art_by_Current()const;	
	const void print_sculpture_by_wight()const;
	const void print_artists_whith_pictures()const;
	const void print_artists_whith_sculptuor()const;
	void menu();
};