#pragma once
#include "Stats.h"
#include <string>

using namespace std;

class Item
{
	string ItemName;
	Stats ItemStats;
public:

	Item(string item_name = "Item", Stats item_stat = 0);
	void ShowItem();
	Stats getItemStats();
	string getItemName();
	bool operator== (Item & item);
	int getPriceItem(Item item);
};

class Poison_Stats
{
protected:
	bool time_action; //Const\Onetime\>>
	int hp_bonus;
	int dmg_bonus;
	int dfns_bonus;
	float crit_bonus;
	double miss_bonus;


public:
	int getHPBonus() { return hp_bonus; }
	int getDmgBonus() { return dmg_bonus; }
	int getDfnsBonus() { return dfns_bonus; }
	float getCritBonus() { return crit_bonus; }
	double getMissBonus() { return miss_bonus; }

	void ShowPStat()
	{
		if (hp_bonus) cout << "HP +" << hp_bonus << " ";
		if (dmg_bonus) cout << "DMG +" << dmg_bonus << " ";
		if (dfns_bonus) cout << "DEF +" << dfns_bonus << " ";
		if (crit_bonus) cout << "CRIT +" << crit_bonus << " ";
		if (miss_bonus) cout << "MISS +" << miss_bonus << " ";
	}
};

class Poison
{
public:
	Poison_Stats p_stat;
	string poison_name;

	void AboutPoison()
	{
		cout << "Poison " << poison_name << " ";
		p_stat.ShowPStat();
	}
	Poison(string name = "Default poison", Poison_Stats p_stat = 0);

};
