#pragma once
#include "LoadedArea.h"
#include "Tile.h"
#include "Player.h"
#include "BaseCell.h"
#include <iostream>
class Visualizer {
public:
    void Visualize(LoadedArea& area);
private:
    int tileWidth = 50;
    int tileHeight = 20;
};