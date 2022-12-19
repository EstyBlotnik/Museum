using namespace std;
#include "date.h"
#include "picture.h"
#include "art.h"
#include "artist.h"
#include "sculpture.h"
#include "hanging_statue.h"
#include "museum.h"
#include <typeinfo>
#include <iostream>
#define N 20
Museum::Museum()
{
	this->artists = NULL;
	this->arts = NULL;
	this->num_of_artists = 0;
	this->num_of_arts = 0;
}
Museum::~Museum()
{
	delete[] this->artists;
	delete[] this->arts;
}
Museum& Museum::add_artist(char* name)
{
	Artist** new_artists = new Artist* [num_of_artists + 1];
	if (!new_artists)
		return *this;
	for (int i = 0; i < num_of_artists; ++i)
		new_artists[i] = this->artists[i];	
	int year, day, month;
	cout<<"enter date of birth (dd/mm/yyyy):"<<endl;
	cin >> day >> month >> year;
	Date date_birth(day, month, year);
	cout << "enter date of death (dd/mm/yyyy) if he is a life enter(00/00/0000):"<<endl;
	cin >> day >> month >> year;
	Date date_death(day, month, year);
	new_artists[num_of_artists] = new Artist(name, date_birth, date_death);
	delete[] artists;
	this->artists = new_artists;
	++this->num_of_artists;
	cout << "The artist was successfully added" << endl;
	return *this;
} 
Museum& Museum::add_art()
{
	char name_art[N],name_artist[N],season[N];
	int year,type,index=-1, num_of_screws;
	float high;

	cout << "Enter the new art:" << endl;
	
	cout << "enter name of artist: ";
	cin >> name_artist;
	for (int i = 0; i < num_of_artists; i++)
	{
		if (strcmp(this->artists[i]->get_name(), name_artist) == 0)
			index = i;
	}
	if (index == -1)
	{
		cout << "there is no artist whith that name" << endl;
		return *this;
	}

	cout << "Enter name of art:" << endl;
	cin >> name_art;
	for (int i = 0; i < num_of_arts; ++i)
		if (strcmp(this->arts[i]->get_name(), name_art) == 0)
			return *this;
	Art** new_arts = new Art * [num_of_arts + 1];
	if (!new_arts)
		return *this;
	for (int i = 0; i < num_of_arts; ++i)
		new_arts[i] = this->arts[i];
	cout << "Enter the year of creation:" << endl;
	cin >> year;
	cout << "Enter the season:" << endl;
	cin >> season;
	cout << "Enter the high:" << endl;
	cin >> high;
	
	cout << "enter type of art: 1=picture, 2=sculpture, 3=hanging statue" << endl;
	cin >> type;
	float area, weight, length;
	switch (type)
	{
	case 1:
		cout << "Enter length of picture ";
		cin >> length;
		new_arts[this->num_of_arts] = new Picture(name_art, year, season, high, this->artists[index], length);
		break;
	case 2:
		cout << "Enter area and weight of the sculpture ";
		cin >> area >> weight;
		new_arts[this->num_of_arts] = new Sculpture(name_art, year, season, high, this->artists[index], area, weight);
		break;
	case 3:
		cout << "Enter length , area , weight and number of screws of hanging statue ";
		cin >> length >> area >> weight>> num_of_screws;
		new_arts[this->num_of_arts] = new Hanging_statue(name_art, year, season, high, this->artists[index], length, area, weight, num_of_screws);
		break;
	default:
		break;
	}
	delete[] this->arts;
	this->arts = new_arts;
	++num_of_arts;
	*(this->artists[index]) += (this->arts[num_of_arts - 1]);
	cout << "The art was successfully added" << endl;
	return *this;
}
Museum& Museum::sub_art(int index)
{
	int i,j = 0;
	if (index < 0 || index >= num_of_arts)
		return *this;
	for (i = 0; i < num_of_artists; ++i)
	{
		if (strcmp(this->artists[i]->get_name() , this->arts[index]->get_arter()->get_name())==0)
		{
			*(artists[i] )-=(this->arts[index]->get_name());
		}
	}
	Art** new_arts = new Art * [num_of_arts - 1];
	if (!new_arts)
		return *this;
	for (int i = 0; i < num_of_arts; ++i)
	{
		if (index != i)
		{
			new_arts[j] = this->arts[i];
			++j;
		}
	}
	--num_of_arts;
	delete[] this->arts;
	this->arts = new_arts;
	cout << "The creation was successfully removed" << endl;
	return *this;
}
const void Museum::print_arts()const
{
	for (int i = 0; i < num_of_arts; ++i)
	{
		arts[i]->print();
		cout << endl;
	}

}
const void Museum::print_pictures()const
{
	for (int i = 0; i < num_of_arts; ++i)
	{
		if (typeid(*this->arts[i]) == typeid(Picture))
		{
			this->arts[i]->print();
			cout << endl;
		}
		else if (typeid(*this->arts[i]) == typeid(Hanging_statue))
		{
			this->arts[i]->print();
			cout << endl;
		}
			
	}
}
const void Museum::print_sculpture()const
{
	for (int i = 0; i < num_of_arts; ++i)
	{
		if (typeid(*this->arts[i]) == typeid(Sculpture))
		{
			this->arts[i]->print();
			cout << endl;
		}
		else if (typeid(*this->arts[i]) == typeid(Hanging_statue))
		{
			this->arts[i]->print();
			cout << endl;
		}
	}
}
const void Museum::print_art_of_artist()const
{
	int index;
	cout << "enter index of artist you want to know abaut him: ";
	cin >> index;
	for (int i = 0; i < this->artists[index]->get_size_arts(); ++i)
	{
		this->artists[index]->get_arts()[i]->print();
		cout << endl;
	}
}
const void Museum::print_art_by_Current()const
{
	int temp = 0;
	char season[N];
	cout << "enter season: ";
	cin >> season;
	for (int i = 0; i < num_of_arts; ++i)
	{
		if (strcmp(season, this->arts[i]->get_season()) == 0)
		{
			this->arts[i]->print();
			cout << endl;
			++temp;
		}
	}
	if (temp == 0)
		cout << "Requested stream does not exist" << endl;
}
const void Museum::print_sculpture_by_wight()const
{
	float min_wight;
	int counter = 0;
	cout << "enter the wight: ";
	cin >> min_wight;
	for (int i = 0; i < num_of_arts; ++i)
	{
		Sculpture* temp = dynamic_cast<Sculpture*>(this->arts[i]);
		if (temp)
		{
			if (temp->get_weight() >= min_wight)
			{
				temp->print();
				cout << endl;
				counter++;
			}
		}
	}
	if (counter == 0)
		cout << "There is no item above this weight" << endl;
}
const void Museum::print_artists()const
{
	int counter = 0;
	for (int i = 0; i < this->num_of_artists; ++i)
	{
		if (this->artists[i]->get_size_arts() > 0)
		{
			cout << *(this->artists[i]) << endl;
			++counter;
		}
	}
	if (counter == 0)
		cout << "There's no artist who created a piece." << endl;
}
const void Museum::print_artists_whith_pictures()const
{
	cout << "the artists that have a picture are:" << endl;
	int counter = 0;
	for (int i = 0; i < this->num_of_artists; ++i)
	{	
		for (int j = 0; j < this->artists[i]->get_size_arts(); ++j)
		{
			Art* temp1 = dynamic_cast<Picture*>(this->artists[i]->get_arts()[j]);
			if (temp1)
				++counter;
			Art* temp2 = dynamic_cast<Hanging_statue*>(this->artists[i]->get_arts()[j]);
			if (temp2)
				++counter;
		}
		if(counter>0)
			cout << *(this->artists[i]) << endl;
		counter = 0;
	}
}
const void Museum::print_artists_whith_sculptuor()const
{
	cout << "the artists that have a sculpture are:" << endl;
	int counter = 0;
	for (int i = 0; i < this->num_of_artists; ++i)
	{
		for (int j = 0; j < this->artists[i]->get_size_arts(); ++j)
		{
			Art* temp1 = dynamic_cast<Sculpture*>(this->artists[i]->get_arts()[j]);
			if (temp1)
				++counter;
			Art* temp2 = dynamic_cast<Hanging_statue*>(this->artists[i]->get_arts()[j]);
			if (temp2)
				++counter;
		}
		if (counter > 0)
			cout<<*(this->artists[i])<<endl;
		counter = 0;
	}
}

void Museum::menu()
{
	int choos;
	do {
		cout << endl<<"enter your choice:" << endl << "1. Add an artist with a blank set of works" << endl << "2= Add an art" << endl << "3= Remove an art"<<endl;
		cout << "4= Print all artists who have at least one piece"<<endl<<"5= Print all arts"<<endl<<"6= Print all pictures"<<endl<<"7= Print all sculptures"<<endl;
		cout << "8= Print all the arts of a particular artist" << endl<<"9= Print all arts from a particular stream"<<endl<<"10= Print all artists who have at least one picture"<<endl;
		cout << "11= Print all the artists who have at least one statue"<<endl<<"12= Print all sculptures above a certain weight"<<endl<<"13= end program"<<endl;
		cin >> choos;
		switch (choos)
		{
		case 1:
			char name[N];
			cout << "enter name of artist: ";
			cin >> name;
			add_artist(name);
			break;
		case 2:
			add_art();
			break;
		case 3:
			int index;
			cout << "enter index of art you want to sub: ";
			cin >> index;
			sub_art(index);
			break;
		case 4:
			print_artists();
			break;
		case 5:
			print_arts();
			break;
		case 6:
			print_pictures();
			break;
		case 7:
			print_sculpture();
			break;
		case 8:
			print_art_of_artist();
			break;
		case 9:
			print_art_by_Current();
			break;
		case 10:
			print_artists_whith_pictures();
			break;
		case 11:
			print_artists_whith_sculptuor();
			break;
		case 12:
			print_sculpture_by_wight();
			break;
		case 13:
			cout << "good buy :-)"<<endl;
			break;
		default:
			break;
		}
	} while (choos != 13);
}