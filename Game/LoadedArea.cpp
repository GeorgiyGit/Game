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
void LoadedArea::changeRenderedTile(int vectorX, int vectorY) {
    Tile** newTiles = new Tile * [3];
    cX += vectorX;
    cY += vectorY;
    for (int y = 0;y < 3;y++) {
        newTiles[y] = new Tile[3];
        for (int x = 0;x < 3;x++) {
            if (y + vectorY >= 0 && y + vectorY < 3 && x + vectorX >= 0 && x + vectorX < 3) {
                newTiles[y][x]= tiles[y + vectorY][x + vectorX];
            }
            else {
                Tile* tile = Generator::generateTile(cX + x - 1, cY + y - 1);
                newTiles[y][x] = *tile;
            }
            //if (x - vectorX >= 0 && x - vectorX < 3 && y - vectorY >= 0 && y - vectorY < 3) {
            //    newTiles[y][x] = tiles[y - vectorY][x - vectorX];
            //}
        }
    }
    //0 1
     
    //0;0 0;1 0;2
    //1;0 1;1 1;2
    //2;0 2;1 2;2

    //0;1 0;2 new
    //1;1 1;2 new
    //2;1 2;2 new

    tiles = newTiles;
    renderedTile = tiles[1][1];
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