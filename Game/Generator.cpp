#include "Generator.h"
#include <stdlib.h>
#include "SeedService.h"
#include "BlockTypesService.h"
Tile* Generator::generateTile(int x, int y) {
	srand(x * Tile::width + y * Tile::height + SeedService::getSeed());
	Tile* tile = new Tile(x, y);
	tile->cellsInit();
	for (int y = 0;y < Tile::height;y++) {
		for (int x = 0;x < Tile::width;x++) {
			BaseBlockType* type = BlockTypesService::getBlockType(BlockTypes::Stone);
			BaseBlock* block = new BaseBlock(tile->getStartX() + x, tile->getStartY() + y, type);
			tile->addBlockToCell(x, y, block);
		}
	}
	for (int i = 0;i < 50;i++) {
		int x = rand() % Tile::width;
		int y = rand() % Tile::height;

		BaseBlockType* type = BlockTypesService::getBlockType(BlockTypes::Tree);
		BaseBlock* block = new BaseBlock(tile->getStartX() + x, tile->getStartY() + y, type);
		tile->addBlockToCell(x, y, block);
	}
	return tile;
}