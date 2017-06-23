// RPG.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "Action.h"
#include "Enemy.h"
#include "Hero.h"
#include "Item.h"
#include "Stats.h"
#include "Thing.h"

int main()
{
	string name_hero = "";
	cout << "Please, enter name: ";
	cin >> name_hero;
	Hero hero(name_hero);
	Action DO;

	do 
	{
		if (_kbhit)
		{
			system("cls");
			hero.About();
			cout <<  "F - find enemy" << endl;
			cout <<  "H - heal" << endl;
			cout << "B -  open bag" << endl;
			cout  << "S -  stats" << endl;

			switch ((char)_getch())
			{
			case 'f':
			{
				system("cls");
				Enemy enemy(hero);
				DO.fight(hero, enemy);
				cout << "E - back" << endl;
				while (_getch() != 'e');
				break;
			}
			case 'h':
			{
				system("cls");
				hero.Heal();
				Sleep(100 * 5);
				break;
			}
			case 'b':
			{
				system("cls");
				hero.ShowBag();
				cout << "E - back" << endl;
				while (_getch() != 'e');
				break;
			}
			case 's':
			{
				system("cls");
				hero.getStats().PrintAllStats();
				cout << "E - back" << endl;
				while (_getch() != 'e');
				break;
			}
			default:
				break;
			}

			//Sleep(1000 * 2);
			system("cls");
		}
		
	} while (true);

	system("pause");
	return 0;
}