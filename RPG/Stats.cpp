#include "stdafx.h"
#include "Stats.h"


Stats::Stats(int dmg, int def, float crit, float miss)
{
	damage = dmg;
	defense = def;
	CritChance = crit;
	MissChance = miss;
}

void Stats::PrintAllStats()
{
	cout << "Damage " << damage << endl;
	cout << "Defense " << defense << endl;
	cout << "Crit " << CritChance << " %" << endl;
	cout << "Miss " << MissChance << " %" << endl << endl;
}

void Stats::setDamage(int dmg)
{
	damage = dmg;
}

void Stats::setDefense(int def)
{
	defense = def;
}

void Stats::setCrit(float crit)
{
	CritChance = crit;
}

void Stats::setMiss(float miss)
{
	MissChance = miss;
}

int Stats::getDamage()
{
	return damage;
}

int Stats::getDefense()
{
	return defense;
}

float Stats::getCrit()
{
	return CritChance;
}

float Stats::getMiss()
{
	return MissChance;
}

void Stats::operator+(Stats stat)
{
	this->CritChance += stat.CritChance;
	this->damage += stat.damage;
	this->defense += stat.defense;
	this->MissChance += stat.MissChance;
}

void Stats::operator-(Stats stat)
{

	this->CritChance -= stat.CritChance;
	this->damage -= stat.damage;
	this->defense -= stat.defense;
	this->MissChance -= stat.MissChance;
}

void Stats::PrintStats() //Вывод только полезных статов
{
	damage != 0 ? (cout << "Damage +" << damage << endl) : (cout << "");
	defense != 0 ? (cout << "Defense +" << defense << endl) : (cout << "");
	CritChance != 0 ? (cout << "Crit " << CritChance << " %" << endl) : (cout << "");
	MissChance != 0 ? (cout << "Miss " << MissChance << " %" << endl << endl) : (cout << "");
}
