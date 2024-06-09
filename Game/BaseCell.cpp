#include "BaseCell.h"

BaseCell::BaseCell() {

}
void BaseCell::addBlock(BaseBlock* block) {
    bool inserted = false;
    int j = 0;
    BaseBlock** newArr = new BaseBlock * [blocksSize + 1];

    for (int i = 0; i < blocksSize; ++i) {
        if (!inserted && this->blocks[i]->getType()->getPosition() > block->getType()->getPosition()) {
            newArr[j++] = block;
            inserted = true;
        }
        newArr[j++] = blocks[i];
    }

    if (!inserted) {
        newArr[j] = block;  // If the element is the largest, insert it at the end
    }
    delete blocks;

    blocks = newArr;
    blocksSize++;
}
void BaseCell::removeBlock(BaseBlock* block) {
    int j = 0;
    BaseBlock** newArr = new BaseBlock * [blocksSize - 1];

    for (int i = 0; i < blocksSize; ++i) {
        if (blocks[i] != block) {
            newArr[j++] = blocks[i];
        }
    }
    delete blocks;

    blocks = newArr;
    blocksSize--;
}
BaseBlock* BaseCell::getBlock(int pos) {
    for (int i = blocksSize - 1;i >= 0;i--) {
        if (blocks[i]->getType()->getPosition() == pos)return blocks[i];
    }
}
BaseBlock* BaseCell::getTopBlock() {
    return blocks[blocksSize - 1];
}

MyColors BaseCell::getFColor() {
    for (int i = blocksSize - 1;i >= 0;i--) {
        if (blocks[i]->getType()->getIsFColor())return blocks[i]->getType()->getFColor();
    }
    return MyColors::gray;
}
MyColors BaseCell::getBColor() {
    for (int i = blocksSize - 1;i >= 0;i--) {
        if (blocks[i]->getType()->getIsBColor())return blocks[i]->getType()->getBColor();
    }
    return MyColors::black;
}