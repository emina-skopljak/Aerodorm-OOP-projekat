#pragma once
#include <iostream>
#include "Putnik.cpp"
#include <fstream>
#include "Agencija.cpp"
#include "Radnik.cpp"
#include <windows.h>
#include <string>

using namespace std;

Putnik p;
Agencija a;
Radnik r;

void IzaberiMode();
void menuA();
void menuP();
void menuR();
void load();
void gotoxy();

void menuP() { //menu za putnika
	system("cls");
	string Meni[4] = { "\n\t1. Kupi kartu","\n\t2. Procitajte informacije o agenciji" ,
						"\n\t3. Promijeni mode","\n\t0. Izlaz"};
	int pointer = 0;
	bool MeniProvjera = true;

	while (MeniProvjera)
	{
		load();
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\n\t\t\tMENU PUTNIK\n\n";
		for (int i = 0; i < 4; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Meni[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Meni[i] << endl;
			}
		}
	
	while (MeniProvjera)
	{
		if (GetAsyncKeyState(VK_UP) & 1)
		{
			pointer = pointer - 1;
			if (pointer == -1)
			{
				pointer = 2;
			}
			break;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 1)
		{
			pointer += 1;
			if (pointer == 5)
			{
				pointer = 0;
			}
			break;
		}
		else if (GetAsyncKeyState(VK_SPACE) & 1)
		{
			try{
				switch (pointer)
				{
					case 0:
						system("cls");
						MeniProvjera = false;
						p.kupiKartu();
						Sleep(1000);
						menuP();
						Sleep(1000);
						break;
			
					case 1:
						system("cls");
						p.citajInfo();
						Sleep(1000);
						MeniProvjera = false;
						menuP();
						Sleep(1000);
						break;
					case 2:
						system("cls");
						IzaberiMode();
						Sleep(1000);
						MeniProvjera = false;
						break;
					case 3:
						system("cls");
						std::cout << "\n\n\n\t\tHvala Vam za koristenje nase aplikacije.\n\n";
						system("pause");
						Sleep(1000);
						MeniProvjera = false;
						break;
					default:
						std::cout << "Greska!";
					}
				if(pointer<0 || pointer>3){
					throw(pointer);
				}
			}
			catch(int pointer)
			{
				std::cout<<pointer<<" nije u rasponu, trebate unijeti broj izmedju 1 i 3\n";
			}
		  }
		}
		Sleep(1000);
	}
}

void menuR() {//menu za radnika na aerodromu
	system("cls");
	string MeniRadnik[4] = { "\n\t1. Izvrsi prodaju karte","\n\t2. Pregledaj spisak putnika","\n\t3. Promijeni mode" ,"\n\t0. Izlaz" };
	int pointer = 0;
	bool MeniProvjera = true;

	while (MeniProvjera)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\n\t\t\tMENU RADNIK\n\n";
		for (int i = 0; i < 4; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << MeniRadnik[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << MeniRadnik[i] << endl;
			}
		}

		while (MeniProvjera)
		{
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				pointer = pointer - 1;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) & 1)
			{
				switch (pointer)
				{
				case 0:
					system("cls");
					r.prodajKartu();
					MeniProvjera = false;
					menuR();
					break;
				case 1:
					system("cls");
					cout << "\n\n\n\tSpisak putnika mozete pogledati u fajlu lista.txt.";
					menuR();
					MeniProvjera = false;
					break;
				case 2:
					system("cls");
					IzaberiMode();
					MeniProvjera = false;
					break;
				case 3:
					system("cls");
					std::cout << "\n\n\n\t\tHvala Vam za koristenje nase aplikacije.\n\n";
					system("pause");
					MeniProvjera = false;
					break;
				default:
					std::cout << "Greska!";
				}
			}
		}
		Sleep(1000);
	}
	cin.ignore();
}
void menuA() {//menu za agenciju
	system("cls");
	string MeniAgencija[4] = { "\n\t1. Unesite informacije o agenciji","\n\t2. Uvid u spisak putnika","\n\t3. Promijeni mode" ,"\n\t0. Izlaz"};
	int pointerA = 0;
	bool MeniProvjera = true;

	while (MeniProvjera)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\n\t\t\tMENU AGENCIJA\n\n";
		for (int i = 0; i < 4; i++)
		{
			if (i == pointerA)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << MeniAgencija[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << MeniAgencija[i] << endl;
			}
		}

		while (MeniProvjera)
		{
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				pointerA = pointerA - 1;
				if (pointerA == -1)
				{
					pointerA = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				pointerA += 1;
				if (pointerA == 4)
				{
					pointerA = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) & 1)
			{
				switch (pointerA)
				{
				case 0:
					system("cls");
					MeniProvjera = false;
					a.postaviAgencija();
					menuA();
					break;
				case 1:
					system("cls");
					cout << "\n\n\n\tSpisak putnika mozete pogledati u fajlu lista.txt.";
					MeniProvjera = false;
					menuA();
					break;
				case 2:
					system("cls");
					MeniProvjera = false;
					IzaberiMode();
					break;
				case 3:
					system("cls");
					std::cout << "\n\n\n\t\tHvala Vam za koristenje nase aplikacije.\n\n";
					system("pause");
					MeniProvjera = false;
					break;
				default:
					std::cout << "Greska!";
				}
			}
		}
		Sleep(1000);
	}
}

void IzaberiMode()
{
	system("cls");
	string MeniOdabir[4] = { "\n\n\t\t\t1. PUTNIK","\n\t\t\t2. AGENCIJA","\n\t\t\t3. RADNIK" ,"\n\t\t\t4. IZLAZ" };
	int pointer = 0;
	bool MeniProvjera = true;
	int sifra;
	int brojac=0;
	while (MeniProvjera)
	{
		system("cls");
		std::cout << "\n\t\t Za zeljeni izbor mode koristite strelice (gore-dolje) i space\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 4; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << MeniOdabir[i] << endl;
		 	}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << MeniOdabir[i] << endl;
			}
		}

		while (MeniProvjera)
		{
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				pointer = pointer - 1;
				if (pointer == -1)
				{
					pointer = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) & 1)
			{
				switch (pointer)
				{
				case 0:
				{
					system("cls");
					menuP();
					MeniProvjera = false;
					break;
				}
				case 1:
				{
					system("cls");
					do {
						std::cout << "\n\n\n\t\t\tpassword: ";
						std::cin >> sifra;
						if (sifra != 1234) {
							system("cls");
							std::cout << "Neispravna sifra\t\t\t\tBroj pokusaja: " << 2 - brojac;
							brojac++;
						}
						else if (sifra == 1234) {
							menuA();
						}
						if (brojac == 3) {
							IzaberiMode();
						}
					} while (sifra!=1234);
					brojac = 0;
					MeniProvjera = false;
					break;
				}
				case 2:
				{
					system("cls");
					do {
						std::cout << "\n\n\n\t\t\tpassword: ";
						std::cin >> sifra;
						if (sifra != 5678) {
							system("cls");
							std::cout << "Neispravna sifra\t\t\t\tBroj pokusaja: " << 2 - brojac;
							brojac++;
						}
						else if (sifra == 5678) {
							menuR();
						}
						if (brojac == 3) {
							IzaberiMode();
						}
					} while (sifra != 5678);
					brojac = 0;
					MeniProvjera = false;
					break;
				}
				case 3:
				{
					system("cls");
					std::cout << "\n\n\n\t\tHvala Vam za koristenje nase aplikacije.\n\n";
					system("pause");
					break;
				}
				default:
				{
					std::cout << "Greska!";
				}
				}
			}
		}
		Sleep(150);
	}
	cin.ignore();
}
void gotoxy(int x, int y)
{
	COORD d;
	d.X = x;
	d.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

void load()
{
	char a = 219;
	gotoxy(36, 14);
	cout << "Loading..."<< endl;
	gotoxy(30,16);
	for(int r =1; r<=20; r++)
	{
		for(int q=0; q<=10000000; q++);
		cout << a;
	}
}

