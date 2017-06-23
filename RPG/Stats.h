#pragma once
#include <iostream>

using namespace std;
class Stats
{
	int damage;
	int defense;
	float CritChance;
	float MissChance;

public:
	Stats(int dmg = 0, int def = 0, float crit = 0, float miss = 0);
	void PrintStats();
	void PrintAllStats();
	void setDamage(int);
	void setDefense(int);
	void setCrit(float);
	void setMiss(float);

	int getDamage();
	int getDefense();
	float getCrit();
	float getMiss();

	void operator+(Stats stat);
	void operator-(Stats stat);
};