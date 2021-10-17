#include "Adresa.h"
#include <iostream>
#include <string>
void Adresa::setUlica()
{
	std::cout << "\tUnesite naziv ulice: ";
	std::getline(std::cin, this->ulica);
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->ulica.length(); i++)//provjera da li je ime bez brojeva
		{
			if (isdigit(this->ulica.at(i)))
			{
				std::cout << "\n\tNaziv ne moze sadrzavati brojeve u sebi!\n";
				std::cout << "\n\tPonovite unos: ";
				std::getline(std::cin, this->ulica);
				provjera = true;
				break;
			}
			else
			{
				provjera = false;
			}
		}
	}

	for (int i = 0; i < this->ulica.length(); i++)//postavljanje da je uvijek pocetno slovo veliko
	{
		if (i == 0)
		{
			if (this->ulica.at(i) >= 97 && this->ulica.at(i) <= 122)
			{
				this->ulica.at(i) = this->ulica.at(i) - 32;
			}
		}
		else
		{
			if (this->ulica.at(i) >= 65 && this->ulica.at(i) <= 90)
			{
				this->ulica.at(i) = this->ulica.at(i) + 32;
			}
		}

	}
}

void Adresa::setBroj()
{
	std::cout << "\tUneiste broj adrese: ";
	std::cin >> this->broj;
	std::cin.ignore();
}

void Adresa::setGrad()
{
	std::cout << "\tUneiste naziv grada: ";
	std::getline(std::cin, this->grad);
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->grad.length(); i++)//provjera da li je ime bez brojeva
		{
			if (isdigit(this->grad.at(i)))
			{
				std::cout << "\n\tNaziv ne moze sadrzavati brojeve u sebi!\n";
				std::cout << "\n\tPonovite unos: ";
				std::getline(std::cin, this->grad);
				provjera = true;
				break;
			}
			else
			{
				provjera = false;
			}
		}
	}

	for (int i = 0; i < this->grad.length(); i++)//postavljanje da je uvijek pocetno slovo veliko
	{
		if (i == 0)
		{
			if (this->grad.at(i) >= 97 && this->grad.at(i) <= 122)
			{
				this->grad.at(i) = this->grad.at(i) - 32;
			}
		}
		else
		{
			if (this->grad.at(i) >= 65 && this->grad.at(i) <= 90)
			{
				this->grad.at(i) = this->grad.at(i) + 32;
			}
		}

	}
}

void Adresa::setDrzava()
{
	std::cout << "\tUnesite naziv drzave: ";
	std::getline(std::cin, this->drzava);
	bool provjera = true;

	while (provjera)
	{
		for (int i = 0; i < this->drzava.length(); i++)//provjera da li je ime bez brojeva
		{
			if (isdigit(this->drzava.at(i)))
			{
				std::cout << "\n\tNaziv ne moze imati brojeve u sebi!\n";
				std::cout << "\n\tPonovite unos: ";
				std::getline(std::cin, this->drzava);
				provjera = true;
				break;
			}
			else
			{
				provjera = false;
			}
		}
	}

	for (int i = 0; i < this->drzava.length(); i++)//postavljanje da je uvijek pocetno slovo veliko
	{
		if (i==0 || drzava.at(i-1)==32)
		{
			if (this->drzava.at(i) >= 97 && this->drzava.at(i) <= 122)
			{
				this->drzava.at(i) = this->drzava.at(i) - 32;
			}
		}
		else
		{
			if (this->drzava.at(i) >= 65 && this->drzava.at(i) <= 90)
			{
				this->drzava.at(i) = this->drzava.at(i) + 32;
			}
		}

	}
}

void Adresa::setPostanskiBr()
{
	std::cout << "\tUnesite postanski broj mjesta: ";
	std::cin >> this->postanskiBr;//provjera da je samo broj
	std::cin.ignore();
}

std::string Adresa::getUlica()
{
	return this->ulica;
}

int Adresa::getBroj()
{
	return this->broj;
}

std::string Adresa::getGrad()
{
	return this->grad;
}

std::string Adresa::getDrzava()
{
	return this->drzava;
}

int Adresa::getPostanskiBr()
{
	return this->postanskiBr;
}

void Adresa::postaviAdresu()
{
	std::cout << "\n\t\tPODACI O ADRESI\n\n";
	this->setDrzava();
	this->setGrad();
	this->setPostanskiBr();
	this->setUlica();
	this->setBroj();
	std::cout << "\nPodaci su uspjesno uneseni!";
}

Adresa::Adresa()
{
	this->ulica="nije uneseno";
	this->grad= "nije uneseno";
	this->drzava= "nije uneseno";
	this->broj= 0;
	this->postanskiBr= 0;
}
