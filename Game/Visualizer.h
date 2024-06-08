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
    void DrawCords(int playerX, int playerY);
private:
    std::string getMapStr(LoadedArea& area);
    int tileWidth = 50;
    int tileHeight = 20;
    std::string oldMap = "";
};