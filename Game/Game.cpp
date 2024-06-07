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
    Player player(10, 25);
    Visualizer visualizer;
    LoadedArea loadedArea(&player);
    loadedArea.tilesInit();
    visualizer.Visualize(loadedArea);

    while (true) {
        Sleep(50);
        if (GetKeyState('W') & 0x8000)
        {
            player.setY(player.getY() - 1);
            visualizer.Visualize(loadedArea);
        }
        if (GetKeyState('A') & 0x8000)
        {
            player.setX(player.getX() - 1);
            visualizer.Visualize(loadedArea);
        }
        if (GetKeyState('S') & 0x8000)
        {
            player.setY(player.getY() + 1);
            visualizer.Visualize(loadedArea);
        }
        if (GetKeyState('D') & 0x8000)
        {
            player.setX(player.getX() + 1);
            visualizer.Visualize(loadedArea);
        }
    }
}









