#pragma once
#include <string>
#include "Stats.h"
#include <time.h>
#include <iostream>

using namespace std;
class Thing //Базовый абстрактный класс
{

protected:
	string name;
	int CurrentHP;
	int MaxHP;
	int Exp;
	int level;
	Stats stat;

public:
	virtual void About() = 0;
	void Attack(Thing &);
	Thing(string name = "Thing", int cur_hp = 100, int max_hp = 100, int exp = 0, int lvl = 1);
	int getMaxHP();
	int getLevel();
	Stats & getStats();
	int getHP();
	string getName();
	int getExp();
	void setHP(int);

	virtual ~Thing()=0;

};


