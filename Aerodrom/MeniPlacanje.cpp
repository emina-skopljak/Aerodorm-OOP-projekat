#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	system("cls");
	string Meni[3] = { "\n\t1. Karticno","\n\t2. Gotovinsko","\n\t3. Na rate\n"};
	int pointer = 0;
	bool MeniProvjera = true;

	while (MeniProvjera)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Nacin placanja:\n\n";
		for (int i = 0; i < 5; ++i)
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
				if (pointer == 3)
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
					std::cout << "Odabrali ste opciju KARTICNO\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 1:
				{
					system("cls");
					std::cout << "Odabrali ste opciju GOTOVINSKO\n";
					Sleep(1000);
					MeniProvjera = false;
					break;
				}
				case 2:
				{
					system("cls");
					std::cout << "Odabrali ste opciju NA RATE\n";
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