#include "stdafx.h"
#include "Hero.h"



void Hero::lvlUp()
{
	Exp = 0;
	level += 1;
	ExpForNextLvl = ExpForNextLvl + (ExpForNextLvl * 0.5);
}

void Hero::AddExp(int bonus_exp)
{
	while (bonus_exp > 0)
	{
		if (bonus_exp < (ExpForNextLvl - Exp))
		{
			Exp = Exp + bonus_exp;
			bonus_exp = 0;
		}
		else
		{
			bonus_exp = bonus_exp - (ExpForNextLvl - Exp);
			lvlUp();
		}
	}
}

Hero::Hero(string name, int cur_hp, int max_hp, int exp, int lvl, int set_size)
{
	this->name = name;
	CurrentHP = cur_hp;
	MaxHP = max_hp;
	Exp = exp;
	level = lvl;
	ExpForNextLvl = lvl * 10;
	BagSizeMax = 3; //Размер сумки
	ItemBag.resize(set_size);
	BagSize = 0;// Всего вещей

	Stats hero_stat(10, 1, 10, 3); // Начальные боевые аракетристики 
	stat = hero_stat;

	Stats noob_sword_stat(2, 0, 0, 0); //Вручаем начальное оружие
	Item noob_sword("Sword of noob", noob_sword_stat);
	WearItem(noob_sword);
	//ItemBag.push_back(noob_sword);

	Stats noob_armor_stat(0, 1, 0, 0); //Вручаем начальную броню
	Item noob_armor("Light Armor", noob_armor_stat);
	WearItem(noob_armor);
	//ItemBag.push_back(noob_armor);

}

void Hero::About()
{
	cout << "Hero " << name << " " << level << " lvl" << endl;
	cout << "HP " << CurrentHP << "/" << MaxHP << endl;
	cout << "Exp " << Exp << "/" << ExpForNextLvl << endl << endl;
	cout << endl << endl;
}

void Hero::WearItem(Item item)
{
	if (BagSize < BagSizeMax)
	{
		ItemBag[BagSize] = item;
		BagSize++;
		this->getStats() + item.getItemStats();
		cout << "Item " << item.getItemName() << " was wore" << endl;
	}
	else
		cout << "Bag is full =(";
}

void Hero::RemoveItem(string ItemName) //
{
	for (int i = 0; i<BagSize; i++)
		if (ItemBag[i].getItemName() == ItemName)
		{
			cout << ItemBag[i].getItemName() << " was dropeed" << endl;
			for (int k = i; k < BagSize - 1; k++)
				ItemBag[k] = ItemBag[k + 1];

			this->getStats() - ItemBag[i].getItemStats();
			BagSize--;
			return;
		}
	cout << "Item " << ItemName << " not found" << endl;
}

void Hero::Heal()
{
	CurrentHP += MaxHP / 4;
	if (CurrentHP >= MaxHP) { CurrentHP = MaxHP; cout << "Full HP" << endl; }
	else
		cout << "+" << MaxHP / 10 << " hp" << endl;
}

string Hero::FindMostBadItem()
{
	int min = INT16_MAX; int MinIndex = 0;
	for (int i = 0; i < BagSize; i++)
		if (ItemBag[i].getPriceItem(ItemBag[i]) < min)
		{
			min = ItemBag[i].getPriceItem(ItemBag[i]);
			MinIndex = i;
		}
	cout << "Most bad item" << ItemBag[MinIndex].getItemName() << endl;
	return ItemBag[MinIndex].getItemName();
}

void Hero::ShowBag()
{
	cout << endl << "Items " << BagSize << "/" << BagSizeMax << endl;
	for (int i = 0; i < BagSize; i++)
	{
		ItemBag[i].ShowItem();
	}
	cout << endl;
}

int Hero::getExpForNextLvl()
{
	return ExpForNextLvl;
}

int Hero::getBagSize()
{
	return BagSize;
}

int Hero::getMaxBagSize()
{
	return BagSizeMax;
}

