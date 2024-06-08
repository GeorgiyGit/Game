#include "BaseBlock.h"
#include "BlockTypesService.h"
BaseBlock::BaseBlock() {

}
BaseBlock::BaseBlock(int x, int y, int typeId) {
	BaseBlockType* type = BlockTypesService::getBlockType(typeId);
	BaseBlock(x, y, type);
}
BaseBlock::BaseBlock(int x, int y, BaseBlockType* type) {
	this->x = x;
	this->y = y;
	this->type = type;
}

int BaseBlock::getX() {
	return this->x;
}
int BaseBlock::getY() {
	return this->y;
}
BaseBlockType* BaseBlock::getType() {
	return this->type;
}