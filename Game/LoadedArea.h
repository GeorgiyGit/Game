#pragma once
#include "Tile.h"
#include "Player.h"
class LoadedArea {
public:
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
};

