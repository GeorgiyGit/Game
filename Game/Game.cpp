// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

#include "LoadedArea.h"
#include "Tile.h"
#include "Player.h"
#include "BaseCell.h"
#include "Visualizer.h"
#include "BlockTypesService.h"
#include "SeedService.h"
int main()
{
    SeedService::setSeed(1234);
    BlockTypesService::Initialize();

    Player player(25, 10);
    Visualizer visualizer;
    LoadedArea loadedArea(&player);
    loadedArea.tilesInit();


    visualizer.RedrawVisualization(loadedArea);
    while (true) {
        Sleep(100);
        if (GetKeyState('W') & 0x8000)
        {
            int newX = player.getX();
            int newY = player.getY() - 1;
            BaseCell cell = loadedArea.getRenderedTile().getCell(newX, newY);
            if (cell.getTopBlock()->getType()->getIsSolid())continue;
            player.setXY(newX, newY);
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('A') & 0x8000)
        {
            int newX = player.getX() - 1;
            int newY = player.getY();
            BaseCell cell = loadedArea.getRenderedTile().getCell(newX, newY);
            if (cell.getTopBlock()->getType()->getIsSolid())continue;
            player.setXY(newX, newY);
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('S') & 0x8000)
        {
            int newX = player.getX();
            int newY = player.getY() + 1;
            BaseCell cell = loadedArea.getRenderedTile().getCell(newX, newY);
            if (cell.getTopBlock()->getType()->getIsSolid())continue;
            player.setXY(newX, newY);
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('D') & 0x8000)
        {
            int newX = player.getX() + 1;
            int newY = player.getY();
            BaseCell cell = loadedArea.getRenderedTile().getCell(newX, newY);
            if (cell.getTopBlock()->getType()->getIsSolid())continue;
            player.setXY(newX, newY);
            visualizer.ChangeVisualization(loadedArea);
        }
    }
}







