#include "Agencija.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include <ctime>
#include <memory>
#include <time.h> 
void Agencija::setNaziv()
{
	std::cout << "\n\tUneiste naziv agencije: ";
	std::getline(std::cin, this->naziv);
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->naziv.length(); i++)//provjera da li je ime bez brojeva
		{
			if (isdigit(this->naziv.at(i)))
			{
				std::cout << "\n\tNaziv ne moze imati brojeve u sebi!\n";
				std::cout << "\n\tPonovite unos: ";
				std::getline(std::cin, this->naziv);
				provjera = true;
				break;
			}
			else
			{
				provjera = false;
			}
		}
	}

	for (int i = 0; i < this->naziv.length(); i++)//postavljanje da je uvijek pocetno slovo veliko
	{
		if (i == 0)
		{
			if (this->naziv.at(i) >= 97 && this->naziv.at(i) <= 122)
			{
				this->naziv.at(i) = this->naziv.at(i) - 32;
			}
		}
		else
		{
			if (this->naziv.at(i) >= 65 && this->naziv.at(i) <= 90)
			{
				this->naziv.at(i) = this->naziv.at(i) + 32;
			}
		}

	}
}

void Agencija::setOpis()
{
	std::cout << "\tUnesite opis: ";
	getline(std::cin, this->opis);
}


std::string Agencija::getNaziv()
{
	return this->naziv;
}

std::string Agencija::getOpis()
{
	return this->opis;
}



void Agencija::ispisAgencija()
{
	std::ofstream podaci("info.txt");
	podaci << "\n====================================================================\n";
	podaci << "Podaci o agenciji\n";
	podaci << "\n\t\tINFORMACIJE O AGENCIJI";
	podaci << "\n\n\tPutujte sa " << getNaziv() << " \n";
	podaci << "\n\tO nama: \n\t";
	int brojac = 1;
	for(int i = 0; i < opis.length(); i++){
		podaci << opis.at(i);
		if (i >= brojac * 50 && opis.at(i)==32) {
			podaci << "\n\t";
			brojac++;
		}
	}
	podaci << "\n\n\n\tKontakt telefon: " << this->tel;
	podaci << "\n\n\n\tPotrazite nas na adresi: \n\t\t" << this->adresa.getUlica() << " " << this->adresa.getBroj();
	podaci << "\n\t\t" << this->adresa.getPostanskiBr() << " " << this->adresa.getGrad() << ", " << this->adresa.getDrzava(); 
	podaci << "\n\n====================================================================\n";
	podaci << "\tZa ugodan let potrudit ce se osoblje " << this->getNaziv();
	podaci << "\n====================================================================\n";
	podaci.close();
}

void Agencija::postaviAgencija()
{
	std::cin.ignore();
	std::cout << "\n\t\tPODACI O AGENCIJI\n";
	this->setNaziv();
	this->setOpis();
	std::cout<<"\tUnesite broj telefona: ";
	std::cin>>tel;
	std::cin.ignore();
	this->adresa.postaviAdresu();
	this->ispisAgencija();
}

Agencija::Agencija()
{
	this->naziv = "";
	this->opis = "";
	this->tel=0;
	Adresa();
}
