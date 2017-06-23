#pragma once
#include "Stats.h"
#include <string>
#include "Thing.h"
#include "Hero.h"

using namespace std;

class Enemy : public Thing
{
	Stats createEnemyStat(Hero & hero);

public:
	Enemy(Hero & hero, string name = "Enemy");
	void About();
	//int Exp --- подразумевается, как награда за победу 

};
