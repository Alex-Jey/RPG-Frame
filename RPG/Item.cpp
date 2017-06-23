#include "stdafx.h"
#include "Item.h"
#include <iostream>
#include <string>



Stats Item::getItemStats()
{
	return ItemStats;
}

void Item::ShowItem()
{
	cout << "Stats item " << ItemName << endl;
	this->ItemStats.PrintStats();
}

string Item::getItemName()
{
	return ItemName;
}

Item::Item(string item_name, Stats stats)
{
	this->ItemName = item_name;
	ItemStats = stats;
}

bool Item::operator==(Item & item)
{
	if (this->ItemName == item.ItemName)
		return true;
	return false;
}

int Item::getPriceItem(Item item)
{
	int result = 0;
	result += item.ItemStats.getDamage() / 10 + item.getItemStats().getDefense() / 2 + item.getItemStats().getCrit() + item.getItemStats().getMiss() / 2;
	return result;
}

