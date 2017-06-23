#include "stdafx.h"
#include "Thing.h"


void Thing::Attack(Thing & object)
{
	int dmg = 0;
	srand(time(NULL));

	dmg = this->getStats().getDamage() - object.getStats().getDefense();
	if (dmg < 0) { cout << "High defense " << object.getName() << " zero dps" << endl; return; }

	if (rand() % 101 <= this->getStats().getCrit())
	{
		dmg *= 2;
		cout << "CRITICAL HIT! " << endl;
	}
	else
		if (rand() % 101 <= this->getStats().getMiss())
		{
			dmg = 0;
			cout << "Miss! :(" << endl;
		}
	dmg = dmg * (1.0 + (rand() % 50) / 10);
	cout << this->getName() << "(" << this->getHP() << ")" << " hit--> " << object.getName() << "(" << object.getHP() << ")" << " " << dmg << "dmg" << endl;
	object.setHP(object.getHP() - dmg);
}

Thing::Thing(string name, int cur_hp, int max_hp, int exp, int lvl)
{
	this->name = name;
	CurrentHP = cur_hp;
	MaxHP = max_hp;
	Exp = exp;
	level = lvl;
}

int Thing::getMaxHP()
{
	return MaxHP;
}

int Thing::getLevel()
{
	return level;
}

Stats & Thing::getStats()
{
	return stat;
}

int Thing::getHP()
{
	return CurrentHP;
}

void Thing::setHP(int health)
{
	this->CurrentHP = health;
}

string Thing::getName()
{
	return name;
}

int Thing::getExp()
{
	return Exp;
}