#include "stdafx.h"
#include "Enemy.h"


Stats Enemy::createEnemyStat(Hero & hero)
{
	Stats EnemyStat;
	EnemyStat.setDamage(hero.getStats().getDamage() / 2);
	EnemyStat.setDefense(hero.getStats().getDefense() / 2);
	EnemyStat.setCrit(hero.getStats().getCrit() - 5);
	EnemyStat.setMiss(hero.getStats().getMiss() + 5);
	return EnemyStat;
}

Enemy::Enemy(Hero & hero, string name)
{
	MaxHP = hero.getMaxHP() / 2 + hero.getStats().getDamage() / 2;
	level = hero.getLevel();
	CurrentHP = MaxHP;
	Exp = hero.getExpForNextLvl() * (rand() % 5) / 10 + 1;
	this->name = name;
	this->stat = createEnemyStat(hero);
}

void Enemy::About()
{
	cout << "Enemy " << name << " " << level << " lvl" << endl;
	cout << "HP " << CurrentHP << "/" << MaxHP << endl;
	cout << "Exp for reward " << Exp << endl;
	stat.PrintAllStats();
}