#pragma once
#include <windows.h>
#include <iostream>
class BaseBlockType
{
private:
	int id;
	std::string name;
	char symbol;
	WORD color;

	float durability;
	int position;
	bool isDroping;
	bool isSolid;
public:
	BaseBlockType(int id, std::string name, char symbol, WORD color, float durability, int position, bool isDroping, bool isSolid);
	int getId();
	std::string getName();
	char getSymbol();
	WORD getColor();
	bool getIsSolid();
	float getDurability();
	int getPosition();
};

enum BlockTypes {
	Stone=1,
	Tree=2
};