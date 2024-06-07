#pragma once
#include "BaseCell.h"
class Tile {
public:
    Tile();
    Tile(int startX, int startY);

    int getStartX();
    int getStartY();
    void cellsInit();
    void deleteCells();
    BaseCell** getCells();
private:
    BaseCell** cells;

    int startX;
    int startY;
    int width = 50;
    int height = 20;
};

