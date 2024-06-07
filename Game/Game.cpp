// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

#include "LoadedArea.h"
#include "Tile.h"
#include "Player.h"
#include "BaseCell.h"
#include "Visualizer.h"

int main()
{
    Player player(25, 10);
    Visualizer visualizer;
    LoadedArea loadedArea(&player);
    loadedArea.tilesInit();
    visualizer.RedrawVisualization(loadedArea);
    while (true) {
        Sleep(100);
        if (GetKeyState('W') & 0x8000)
        {
            player.setXY(player.getX(), player.getY() - 1);
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('A') & 0x8000)
        {
            player.setXY(player.getX() - 1, player.getY());
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('S') & 0x8000)
        {
            player.setXY(player.getX(), player.getY() + 1);
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('D') & 0x8000)
        {
            player.setXY(player.getX() + 1, player.getY());
            visualizer.ChangeVisualization(loadedArea);
        }
    }
}







