#include "BlockTypesService.h"
#include <iostream>
#include <windows.h>
BlockTypesService::BlockTypesService() {
	Initialize();
}
void BlockTypesService::Initialize() {
	BlockTypesService::blockTypesSize = 2;
	BlockTypesService::blockTypes = new BaseBlockType * [BlockTypesService::blockTypesSize];
	BlockTypesService::blockTypes[0] = new BaseBlockType(BlockTypes::Stone, "Stone", ' ', BACKGROUND_INTENSITY, -1, -1, false, false);
	BlockTypesService::blockTypes[1] = new BaseBlockType(BlockTypes::Tree, "Tree", '&', FOREGROUND_GREEN, 10, 1, true, true);
}
int BlockTypesService::blockTypesSize = 1;
BaseBlockType** BlockTypesService::blockTypes = new BaseBlockType * [BlockTypesService::blockTypesSize];

BaseBlockType* BlockTypesService::getBlockType(int id) {
	for (int i = 0;i < BlockTypesService::blockTypesSize;i++) {
		if (BlockTypesService::blockTypes[i]->getId() == id)return BlockTypesService::blockTypes[i];
	}
}