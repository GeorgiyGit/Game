#pragma once
#include "BaseBlock.h"
class BaseCell
{
public:
    BaseCell();

    void addBlock(BaseBlock* block);
    void removeBlock(BaseBlock* block);
    BaseBlock* getBlock(int pos);
    BaseBlock* getTopBlock();
protected:
    BaseBlock** blocks;
    int blocksSize;

};

