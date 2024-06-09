#pragma once
#include <windows.h>
#include <iostream>
#include "Colors.h"

class BaseBlockType
{
private:
	int id;
	std::string name;
	char symbol;
	MyColors foregroundColor;
	bool isForeground = false;
	bool isBackground = false;
	MyColors backgroundColor;

	float durability = -1;
	int position = 0;
	bool isDroping = true;
	bool isSolid = true;
public:
	BaseBlockType(int id, std::string name, char symbol, float durability, int position, bool isDroping, bool isSolid);
	~BaseBlockType();

	void setFColor(MyColors fColor);
	void setBColor(MyColors bColor);

	int getId();
	std::string getName();
	char getSymbol();
	
	MyColors getFColor();
	bool getIsFColor();

	MyColors getBColor();
	bool getIsBColor();

	bool getIsSolid();
	float getDurability();
	int getPosition();
};

enum BlockTypes {
	Stone=1,
	Tree=2
};