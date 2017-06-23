#pragma once
#include "Hero.h"
#include "Enemy.h"
#include <windows.h>
#include <conio.h>

using namespace std;

#define LUCK 2

class Action
{
	Item generateReward(Hero&);
public:
	void fight(Hero &, Enemy &);
};