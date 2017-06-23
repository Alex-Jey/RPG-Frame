#include "stdafx.h"
#include "Action.h"

void Action::fight(Hero & hero, Enemy & enemy)
{
	while (true) //Герои не умирают, герои тактически отсупают
	{
		//и ходят первыми
		hero.Attack(enemy);
		if (enemy.getHP() > 0)
			enemy.Attack(hero);
		else				//WIN
		{
			cout << "Hero " << hero.getName() << " win + " << enemy.getExp() << "exp" << endl;
			hero.AddExp(enemy.getExp()); //Получает опыт
			if (rand() % LUCK) //Награда 50%
			{
				Item reward = generateReward(hero);
				cout << endl << "Hero found reward! "; reward.ShowItem(); cout << endl;
				//Выбор надеть вещь или выбросить? 
				if (hero.getBagSize() == hero.getMaxBagSize())
				{
					cout << "Bag is full" << endl;
					hero.RemoveItem(hero.FindMostBadItem());
				}
				hero.WearItem(reward);
			}
			break;
		}
		if (hero.getHP() < 2) //LOSE
		{
			hero.setHP(1);
			cout << "Hero escaped..." << endl;
			if (rand() % LUCK) //Потеря случайной вещи 50%
			{
				hero.RemoveItem(hero.ItemBag[rand() % hero.getBagSize()].getItemName());
			}
			break;
		}
		Sleep(100 * 5);
	}
}

Item Action::generateReward(Hero & hero) //Делаем награду актуальной для героя
{
	srand(time(NULL));
	Stats stat(					//Статы в диапазоне от x0.7 - x2.0 от текуих
		hero.getStats().getDamage() * (rand() % 10 + 1) / 10,
		hero.getStats().getDefense() * (rand() % 10 + 1) / 10,
		hero.getStats().getCrit() * (rand() % 10) / 100,
		hero.getStats().getMiss() * (rand() % 10) / 100
	);
	Item item("Reward item", stat);
	return item;
}