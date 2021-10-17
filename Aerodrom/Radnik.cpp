#include "Radnik.h"
#include <iostream>
#include<fstream>
#include <ctime>
#include <iomanip>
#include <vector>
using std::cout;
using std::cin;

void Radnik::setIme()
{
	cout << "\n\tUnesite ime: ";
	getline(cin, this->ime);
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->ime.length(); i++)//provjera da li je ime bez brojeva
		{
			if (isdigit(this->ime.at(i)))
			{
				std::cout << "\n\tIme ne moze imati brojeve u sebi!\n";
				std::cout << "\n\tPonovite unos: ";
				std::getline(std::cin, this->ime);
				provjera = true;
				break;
			}
			else
			{
				provjera = false;
			}
		}
	}

	for (int i = 0; i < this->ime.length(); i++)//postavljanje da je uvijek pocetno slovo veliko
	{
		if (i == 0)
		{
			if (this->ime.at(i) >= 97 && this->ime.at(i) <= 122)
			{
				this->ime.at(i) = this->ime.at(i) - 32;
			}
		}
		else
		{
			if (this->ime.at(i) >= 65 && this->ime.at(i) <= 90)
			{
				this->ime.at(i) = this->ime.at(i) + 32;
			}
		}

	}
	cin.ignore();
}

void Radnik::setPrezime()
{
	cout << "\n\tUnesite prezime: ";
	getline(cin, this->prezime);
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->prezime.length(); i++)
		{
			if (isdigit(this->prezime.at(i)))
			{
				std::cout << "\n\tPrezime ne moze imati brojeve u sebi!\n";
				std::cout << "\n\tPonovite unos: ";
				std::getline(std::cin, this->prezime);
				provjera = true;
				break;
			}
			else
			{
				provjera = false;
			}
		}
	}

	for (int i = 0; i < this->prezime.length(); i++)
	{
		if (i == 0)
		{
			if (this->prezime.at(i) >= 97 && this->prezime.at(i) <= 122)
			{
				this->prezime.at(i) = this->prezime.at(i) - 32;
			}
		}
		else
		{
			if (this->prezime.at(i) >= 65 && this->prezime.at(i) <= 90)
			{
				this->prezime.at(i) = this->prezime.at(i) + 32;
			}
		}

	}
	cin.ignore();
}

std::string Radnik::getIme()
{
	return this->ime;
}

std::string Radnik::getPrezime()
{
	return this->prezime;
}

void Radnik::postaviRadnik()
{
	cout << "\n\t\tPODACI O RADNIKU\n";
	this->setIme();
	this->setPrezime();
	cout << "\nPodaci su uspješno uneseni!";
}

void Radnik::prodajKartu() //treba dorada
{
	system("cls");
	std::cin.ignore();
	putnik.postaviPutnik();
	std::ofstream karta("karta.txt");
	time_t now=time(0);			//funkcije za racunanje vemena
    tm *ltm=localtime(&now);
	karta << "\n====================================================================\n";
	karta << "Datum kupovine:	" << ltm->tm_mday << "." << 1+ltm->tm_mon << "." << 1900+ltm->tm_year<< ".\t\t";
	karta << "Vrijeme kupovine: " << 1+ltm->tm_hour << ":" << 1+ltm->tm_min << ":" << 1+ltm->tm_sec << "\n";
	karta << "\n\t\t\tKARTA";
	karta << "\n\n\t\tPodaci o putniku: \n";
	karta << "\n\tIme i prezime: " << putnik.getIme() << " " << putnik.getPrezime();
	karta << "\n\tBroj pasosa: " << putnik.getBrPasosa();
	karta << "\n\tNacin placanja: ";
		if (putnik.getPlacanje() == 1) karta << "karticno\n";
		else if (putnik.getPlacanje() == 2) karta << "gotovinsko\n";
		else karta << "na rate\n";
	karta << "\n\n\t\t\t Broj karte: " << putnik.getBrKarta();
	karta << "\n\n\tDestinacija: ";
		switch(putnik.getDestinacija()){
			case 1:
				karta << "Berlin";
				break;
			case 2:
				karta << "Moskva";
				break;
			case 3:
				karta << "Budimpesta";
				break;
			case 4:
				karta << "Istanbul";
				break;
			case 5:
				karta << "Zagreb";
				break;
			case 6:
				karta << "Lisabon";
				break;
			case 7:
				karta << "Ankara";
				break;
			case 8:
				karta << "Rim";
				break;
		}
	karta << "\n\tDatum Vaseg leta: " << putnik.getDatumLeta();
	karta << "\n\tKlasa: ";
		if (putnik.getKlasa() == 1) karta << "ekonomska\n";
		else if (putnik.getKlasa() == 2) karta << "biznis\n";
		else karta << "prva\n";
	karta << "\n\tCijena Vase karte: " << putnik.cijena << " KM";
	karta << "\n\n\tU slucaju da prtljag izgubite na aerodromu, \n\ton ce Vam biti poslan na adresu koju ste unijeli.\n";
	karta << "\n\tUlica i broj: " << putnik.adresa.getUlica() << " " << putnik.adresa.getBroj();
	karta << "\n\tGrad, drzava: " << putnik.adresa.getPostanskiBr() << " " << putnik.adresa.getGrad() << ", " << putnik.adresa.getDrzava();
	karta << "\n\n\n====================================================================\n";
	karta << "\n\tZelimo Vam sretan put i ugodan let. Vasa agencija\n";
	karta << "\n====================================================================\n";
	std::cout << "Karta je uspjesno rezervisana.";
	karta.close();
	
	std::ofstream lista("lista.txt");
	lista << "\n====================================================================\n";
	lista << "\n\n\t\tLista putnika: \n";
	lista << "\n\tIme i prezime: " << getIme() << " " << getPrezime();
	lista << "\n\tBroj pasosa: " << putnik.getBrPasosa();	
	lista << "\n====================================================================\n";
	lista.close();
	
	std::ofstream spisak("spisak.txt", std::ios::app);
	spisak << std::left << std::setw(20) << putnik.getIme();
	spisak << std::left << std::setw(20) << putnik.getPrezime();
	spisak << std::left << std::setw(12) << putnik.getBrPasosa();
	spisak.close();
}
/*
void Radnik::pregledPutnika()
{
	std::ifstream spisak ("spisak.txt");
	while(spisak>>putnik.getIme()){
		spisak>>putnik.getPrezime();
		spisak>>putnik.getBrPasosa();
		
		std::shared_ptr<Putnik> putnik(new Putnik(getIme(), getPrezime(), getBrPasosa()));
		putnik.push_back(putnik);
	}
	for(int i=0; i<br; i++){
		std::cout<<i+1<<nizPutnika[i].getIme()<<" "<<nizPutnika[i].getPrezime()<<" "<<nizPutnika[i].getBrPasosa()<<"\n";
	}
	
}
void Radnik::chekiranjePutnika(){
	vector<Putnik> putnik;
	int br=0;
	std::ifstream spisak ("spisak.txt");
	while(spisak>>getIme()){
		spisak>>getPrezime();
		spisak>>getBrPasosa();
		
		std::shared_ptr<Putnik> putnik(new Putnik(getIme(), getPrezime(), getBrPasosa()));
	}
	
	std::string provjeraI, provjerP, probjeraBr;
	do{
		std::cout << "Unesite ime: ";
		getline(std::cin, provjeraI);
		for(int i=0; i<br; i++){//nije zavrseno
		
			
		}
	}while();
	
	
}
*/
Radnik::Radnik()
{
	Putnik();
	Adresa();
}
