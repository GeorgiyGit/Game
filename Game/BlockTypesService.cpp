#include "BlockTypesService.h"
#include <iostream>
#include <windows.h>
#include "Colors.h"
BlockTypesService::BlockTypesService() {
	Initialize();
}
void BlockTypesService::Initialize() {
	BlockTypesService::blockTypesSize = 2;
	BlockTypesService::blockTypes = new BaseBlockType * [BlockTypesService::blockTypesSize];

	BaseBlockType* stone = new BaseBlockType(BlockTypes::Stone, "Stone", ' ', -1, -1, false, false);
	stone->setBColor(MyColors::gray);
	BlockTypesService::blockTypes[0] = stone;


	BaseBlockType* tree = new BaseBlockType(BlockTypes::Tree, "Tree", '&', 10, 1, true, true);
	tree->setFColor(MyColors::dark_green);
	BlockTypesService::blockTypes[1] = tree;
}
int BlockTypesService::blockTypesSize = 1;
BaseBlockType** BlockTypesService::blockTypes = new BaseBlockType * [BlockTypesService::blockTypesSize];

BaseBlockType* BlockTypesService::getBlockType(int id) {
	for (int i = 0;i < BlockTypesService::blockTypesSize;i++) {
		if (BlockTypesService::blockTypes[i]->getId() == id)return BlockTypesService::blockTypes[i];
	}
}