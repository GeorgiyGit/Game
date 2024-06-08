#pragma once
#include "BaseBlockType.h"
class BlockTypesService
{
private:
	static BaseBlockType** blockTypes;
	static int blockTypesSize;
public:
    BlockTypesService();
	static void Initialize();
	static BaseBlockType* getBlockType(int id);
};

