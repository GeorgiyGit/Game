#pragma once
#include "Tile.h"
#include "Player.h"
class LoadedArea {
public:
    void changeRenderedTile(int vectorX, int vectorY);
    LoadedArea(Player* player);
    ~LoadedArea();

    Player* getPlayer();
    Tile getRenderedTile();
    void tilesInit();
    Tile** getTiles();
private:
    Tile** tiles;
    Tile renderedTile;
    Player* player;
    int cX = 0;
    int cY = 0;
};

