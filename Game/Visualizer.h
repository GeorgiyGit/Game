#pragma once
#include "LoadedArea.h"
#include "Tile.h"
#include "Player.h"
#include "BaseCell.h"
#include <iostream>
#include <Windows.h>

struct VisualizationCell
{
public:
    MyColors fColor;
    MyColors bColor;
    char symbol;
};
class Visualizer {
public:
    Visualizer();
    void RedrawVisualization(LoadedArea& area);
    void ChangeVisualization(LoadedArea& area);
    void DrawCords(int playerX, int playerY);
private:
    void restoreColor();
    VisualizationCell*** getMapStr(LoadedArea& area);
    int tileWidth = 50;
    int tileHeight = 20;
    VisualizationCell** gameMap;
    VisualizationCell** oldGameMap;
    WORD originalAttributes;
};