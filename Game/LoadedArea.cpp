#include "LoadedArea.h"
#include "Generator.h"
LoadedArea::LoadedArea(Player* player) {
    this->player = player;
}
LoadedArea::~LoadedArea() {
    for (int y = 0;y < Tile::height;y++) {
        for (int x = 0;x < Tile::width;x++) {
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
            Tile* tile = Generator::generateTile(x - 1, y - 1);
            tiles[y][x] = *tile;
        }
    }
    this->renderedTile = tiles[1][1];
}
Tile** LoadedArea::getTiles() {
    return this->tiles;
}