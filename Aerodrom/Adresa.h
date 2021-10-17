#pragma once
#include<string>
class Adresa
{
private:
	std::string ulica, grad, drzava;
	int broj;
	int postanskiBr;
public:
	void setUlica();
	void setBroj();
	void setGrad();
	void setDrzava();
	void setPostanskiBr();
	std::string getUlica();
	int getBroj();
	std::string getGrad();
	std::string getDrzava();
	int getPostanskiBr();
	void postaviAdresu();
	Adresa();
	~Adresa() {};
};

