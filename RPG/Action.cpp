#include "stdafx.h"
#include "Action.h"

void Action::fight(Hero & hero, Enemy & enemy)
{
	while (true) //����� �� �������, ����� ���������� ��������
	{
		//� ����� �������
		hero.Attack(enemy);
		if (enemy.getHP() > 0)
			enemy.Attack(hero);
		else				//WIN
		{
			cout << "Hero " << hero.getName() << " win + " << enemy.getExp() << "exp" << endl;
			hero.AddExp(enemy.getExp()); //�������� ����
			if (rand() % LUCK) //������� 50%
			{
				Item reward = generateReward(hero);
				cout << endl << "Hero found reward! "; reward.ShowItem(); cout << endl;
				//����� ������ ���� ��� ���������? 
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
			if (rand() % LUCK) //������ ��������� ���� 50%
			{
				hero.RemoveItem(hero.ItemBag[rand() % hero.getBagSize()].getItemName());
			}
			break;
		}
		Sleep(100 * 5);
	}
}

Item Action::generateReward(Hero & hero) //������ ������� ���������� ��� �����
{
	srand(time(NULL));
	Stats stat(					//����� � ��������� �� x0.7 - x2.0 �� ������
		hero.getStats().getDamage() * (rand() % 10 + 1) / 10,
		hero.getStats().getDefense() * (rand() % 10 + 1) / 10,
		hero.getStats().getCrit() * (rand() % 10) / 100,
		hero.getStats().getMiss() * (rand() % 10) / 100
	);
	Item item("Reward item", stat);
	return item;
}