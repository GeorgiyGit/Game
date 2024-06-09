#pragma once
#include "BaseBlock.h"
#include "Colors.h"
class BaseCell
{
public:
    BaseCell();

    void addBlock(BaseBlock* block);
    void removeBlock(BaseBlock* block);
    BaseBlock* getBlock(int pos);
    BaseBlock* getTopBlock();
    MyColors getFColor();
    MyColors getBColor();
protected:
    BaseBlock** blocks;
    int blocksSize = 0;

};

