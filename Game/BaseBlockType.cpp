#include "BaseBlockType.h"

BaseBlockType::BaseBlockType(int id, std::string name, char symbol, WORD color, float durability, int position, bool isDroping, bool isSolid) {
	this->id = id;
	this->name = name;
	this->symbol = symbol;
	this->color = color;
	this->durability = durability;
	this->position = position;
	this->isDroping = isDroping;
	this->isSolid = isSolid;
}
int BaseBlockType::getId() {
	return this->id;
}
std::string BaseBlockType::getName() {
	return this->name;
}
char BaseBlockType::getSymbol() {
	return this->symbol;
}
WORD BaseBlockType::getColor() {
	return this->color;
}
float BaseBlockType::getDurability() {
	return this->durability;
}
int BaseBlockType::getPosition() {
	return this->position;
}
bool BaseBlockType::getIsSolid() {
	return this->isSolid;
}