#pragma once
#include "LoadedArea.h"
#include "Tile.h"
#include "Player.h"
#include "BaseCell.h"
#include <iostream>
#include <Windows.h>
class Visualizer {
public:
    void RedrawVisualization(LoadedArea& area);
    void ChangeVisualization(LoadedArea& area);
private:
    int tileWidth = 50;
    int tileHeight = 20;
};