#include "Tile.h"
Tile::Tile() {

}
Tile::Tile(int startX, int startY) {
    this->startX = startX;
    this->startY = startY;
}

int Tile::getStartX() {
    return this->startX;
}
int Tile::getStartY() {
    return this->startY;
}
void Tile::cellsInit() {
    this->cells = new BaseCell * [height];
    for (int y = 0;y < height;y++) {
        cells[y] = new BaseCell[width];
        for (int x = 0;x < width;x++) {
            BaseCell cell('-');
            this->cells[y][x] = cell;
        }
    }
}
BaseCell** Tile::getCells() {
    return this->cells;
}
void Tile::deleteCells() {
    for (int y = 0;y < height;y++) {
        delete[] cells[y];
    }
    delete[] cells;
}