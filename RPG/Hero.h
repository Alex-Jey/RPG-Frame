#pragma once
#include "Thing.h"
#include <vector>
#include <string>
#include "Stats.h"
#include "Item.h"

using namespace std;

class Hero : public Thing
{
	void lvlUp();
	int ExpForNextLvl;
	int BagSizeMax;
	int BagSize;
	vector<Item> ItemBag;

	void WearItem(Item item);
	void AddExp(int exp);
public:

	Hero(string name = "Hero", int cur_hp = 100, int max_hp = 100, int exp = 0, int lvl = 1, int SetSize = 10);
	void About();

	void RemoveItem(string ItemName);
	void Heal();
	string FindMostBadItem();
	void ShowBag();

	int getExpForNextLvl();
	int getBagSize();
	int getMaxBagSize();

	friend class Action;
};
