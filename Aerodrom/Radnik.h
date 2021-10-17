#pragma once
#include <string>
#include "Putnik.h"
#include "osoba.h"
class Radnik : public osoba
{
private:
	Putnik putnik;
	Adresa adresa;
public:
	void setIme();
	void setPrezime();
	std::string getIme();
	std::string getPrezime();
	void postaviRadnik();
	void prodajKartu();
	//void pregledPutnika();
	//void chekiranjePutnika();
	//void provjeraLeta();
	Radnik();
	~Radnik() {};
};
