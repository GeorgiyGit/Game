#pragma once
#include <windows.h>
#include <iostream>
#include "BaseBlockType.h"
class BaseBlock
{
protected:
	int x;
	int y;

	BaseBlockType* type;
public:
	BaseBlock();
	BaseBlock(int x, int y, int typeId);
	BaseBlock(int x, int y, BaseBlockType* type);
	int getX();
	int getY();
	BaseBlockType* getType();
};

