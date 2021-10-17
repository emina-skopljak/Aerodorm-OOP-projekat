#pragma once
#include "Adresa.h"
#include<iostream>
#include <string>
class Agencija
{
private: 
	std::string naziv;
	Adresa adresa;
	std::string opis;
public:
	int tel;
	void setNaziv();
	void setOpis();
	void setTel();
	int getTel();
	std::string getNaziv();
	std::string getOpis(); 
	void postaviAgencija();
	void ispisAgencija();
	Agencija();
	~Agencija() {};

};

