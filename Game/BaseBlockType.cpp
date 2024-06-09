#include "BaseBlockType.h"
#include "Colors.h"

BaseBlockType::~BaseBlockType() {

}
BaseBlockType::BaseBlockType(int id, std::string name, char symbol, float durability, int position, bool isDroping, bool isSolid) {
	this->id = id;
	this->name = name;
	this->symbol = symbol;
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
float BaseBlockType::getDurability() {
	return this->durability;
}
int BaseBlockType::getPosition() {
	return this->position;
}
bool BaseBlockType::getIsSolid() {
	return this->isSolid;
}
void BaseBlockType::setFColor(MyColors fColor) {
	this->foregroundColor = fColor;
	this->isForeground = true;
}
void BaseBlockType::setBColor(MyColors bColor) {
	this->backgroundColor = bColor;
	this->isBackground = true;
}

MyColors BaseBlockType::getFColor() {
	return this->foregroundColor;
}
bool BaseBlockType::getIsFColor() {
	return this->isForeground;
}
MyColors BaseBlockType::getBColor() {
	return this->backgroundColor;
}
bool BaseBlockType::getIsBColor() {
	return this->isBackground;
}