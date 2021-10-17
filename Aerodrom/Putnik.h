#pragma once
#include "Adresa.cpp"
#include "osoba.h"
enum Placanje{karticno=1, gotovinski, rate};
enum Destinacija { Berlin = 1, Moska, Budimpesta, Istanbul, Zagreb, Lisabon, Ankara, Rim };
enum Klasa {ekonomska=1, biznis, prva};
/*kilometri(Berlin = 1032.65 km; Moskva = 1898.38 km; Budimpesta = 408.12 km; Istanbul = 923km; Zagreb = 290.49 km; Lisabon = 2359.66 km;
Ankara = 1270.69 km; Rim = 530.72 km)*/

//koeficijent karte 0.7
class Putnik : public osoba
{
private:
	std::string  brPasosa;
	Placanje placanje;
	
public:
	Adresa adresa;
	int brKarta;
	Destinacija destinacija;
	std::string datumLeta;
	Klasa klasa;
	float koeficijent=0.7, cijena;
	void setBrKarta();
	int getBrKarta();
	void setDatumLeta();
	std::string getDatumLeta();
	void setKlasa();
	Klasa getKlasa();
	void setDestinacija();
	Destinacija getDestinacija();
	void postaviKarta();
	void setIme();
	void setPrezime();
	void setBrPasosa();
	void setPlacanje();
	std::string getIme();
	std::string getPrezime();
	std::string getBrPasosa();
	Placanje getPlacanje();
	void postaviPutnik();
	void kupiKartu();
	void citajInfo();
	void otkaziLet();
	friend std::ostream& operator <<(std::ostream& os, const Putnik& p);
	Putnik();
	~Putnik() {};

};

