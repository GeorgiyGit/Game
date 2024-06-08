#include "Tile.h"
#include "Generator.h"
Tile::Tile() {

}
Tile::Tile(int x, int y) {
    this->x = x;
    this->y = y;
    this->startX = Tile::width * x;
    this->startY = Tile::height * y;
}

int Tile::getStartX() {
    return this->startX;
}
int Tile::getStartY() {
    return this->startY;
}

int Tile::getX() {
    return this->x;
}
int Tile::getY() {
    return this->y;
}

void Tile::cellsInit() {
    this->cells = new BaseCell * [height];
    for (int y = 0;y < height;y++) {
        cells[y] = new BaseCell[width];
        for (int x = 0;x < width;x++) {
            BaseCell cell;
            this->cells[y][x] = cell;
        }
    }
}

void Tile::addBlockToCell(int x, int y, BaseBlock* block) {
    cells[y][x].addBlock(block);
}
BaseCell** Tile::getCells() {
    return this->cells;
}
BaseCell Tile::getCell(int x,int y) {
    return cells[y][x];
}
void Tile::deleteCells() {
    for (int y = 0;y < height;y++) {
        delete[] cells[y];
    }
    delete[] cells;
}