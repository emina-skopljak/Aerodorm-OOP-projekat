#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	system("cls");
	string MeniPutovanja[8] = { "\n\t1. Berlin","\n\t2. Moskva","\n\t3. Budimpesta" ,"\n\t4. Istanbul","\n\t5. Zagreb","\n\t6.Lisabon","\n\t7.Ankara","\n\t8.Rim\n" };
	int pointer = 0;
	bool MeniProvjera = true;

	while (MeniProvjera)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Putovanja\n\n";
		for (int i = 0; i < 8; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << MeniPutovanja[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << MeniPutovanja[i] << endl;
			}
		}

		while (MeniProvjera)
		{
			if (GetAsyncKeyState(VK_UP) & 1)
			{
				pointer = pointer - 1;
				if (pointer == -1)
				{
					pointer = 7;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)
			{
				pointer += 1;
				if (pointer == 8)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 1)
			{
				switch (pointer)
				{
				case 0:
				{
					system("cls");
					std::cout << "Odabrali ste Berlin.\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 1:
				{
					system("cls");
					std::cout << "Odabrali ste Moskvu\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 2:
				{
					system("cls");
					std::cout << "Odabrali ste Budimpestu\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 3:
				{
					system("cls");
					std::cout << "Odabrali ste Istanbul\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 4:
				{
					system("cls");
					std::cout << "Odabrali ste Zagreb\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 5:
				{
					system("cls");
					std::cout << "Odabrali ste Lisabon\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 6:
				{
					system("cls");
					std::cout << "Odabrali ste Ankaru\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 7:
				{
					system("cls");
					std::cout << "Odabrali ste Rim\n";
					Sleep(1000);
					MeniProvjera = false;
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

	return 0;
}