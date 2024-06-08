#pragma once
#include "BaseCell.h"
class Tile {
public:
    static const int width = 50;
    static const int height = 20;

    Tile();
    Tile(int x, int y);

    int getStartX();
    int getStartY();
    int getX();
    int getY();

    void cellsInit();
    void deleteCells();
    BaseCell** getCells();
    BaseCell getCell(int x, int y);
    void addBlockToCell(int x, int y, BaseBlock* block);
private:
    BaseCell** cells;

    int startX;
    int startY;
    int x;
    int y;
};

