#include "LoadedArea.h"

LoadedArea::LoadedArea(Player* player) {
    this->player = player;
}
LoadedArea::~LoadedArea() {
    for (int y = 0;y < 50;y++) {
        for (int x = 0;x < 50;x++) {
            tiles[y][x].deleteCells();
        }
        delete[] tiles[y];
    }
    delete[] tiles;
}
Player* LoadedArea::getPlayer() {
    return player;
}
Tile LoadedArea::getRenderedTile() {
    return renderedTile;
}
void LoadedArea::tilesInit() {
    tiles = new Tile * [3];
    for (int y = 0;y < 3;y++) {
        tiles[y] = new Tile[3];
        for (int x = 0;x < 3;x++) {
            Tile tile(x * 50 - 50, y * 20 - 20);
            tile.cellsInit();
            tiles[y][x] = tile;
        }
    }
    this->renderedTile = tiles[1][1];
}
Tile** LoadedArea::getTiles() {
    return this->tiles;
}