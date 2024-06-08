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

            int differenceX = newX - loadedArea.getRenderedTile().getStartX();
            int differenceY = newY - loadedArea.getRenderedTile().getStartY();

            if (differenceY < 0) {
                loadedArea.changeRenderedTile(0, -1);
            }

            differenceX = newX - loadedArea.getRenderedTile().getStartX();
            differenceY = newY - loadedArea.getRenderedTile().getStartY();

            BaseCell cell = loadedArea.getRenderedTile().getCell(differenceX, differenceY);
            if (cell.getTopBlock()->getType()->getIsSolid())continue;
            player.setXY(newX, newY);
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('A') & 0x8000)
        {
            int newX = player.getX() - 1;
            int newY = player.getY();

            int differenceX = newX - loadedArea.getRenderedTile().getStartX();
            int differenceY = newY - loadedArea.getRenderedTile().getStartY();

            if (differenceX < 0) {
                loadedArea.changeRenderedTile(-1, 0);
            }

            differenceX = newX - loadedArea.getRenderedTile().getStartX();
            differenceY = newY - loadedArea.getRenderedTile().getStartY();

            BaseCell cell = loadedArea.getRenderedTile().getCell(differenceX, differenceY);
            if (cell.getTopBlock()->getType()->getIsSolid())continue;
            player.setXY(newX, newY);
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('S') & 0x8000)
        {
            int newX = player.getX();
            int newY = player.getY() + 1;

            int differenceX = newX - loadedArea.getRenderedTile().getStartX();
            int differenceY = newY - loadedArea.getRenderedTile().getStartY();

            if (differenceY >= Tile::height) {
                loadedArea.changeRenderedTile(0, 1);
            }

            differenceX = newX - loadedArea.getRenderedTile().getStartX();
            differenceY = newY - loadedArea.getRenderedTile().getStartY();

            BaseCell cell = loadedArea.getRenderedTile().getCell(differenceX, differenceY);
            if (cell.getTopBlock()->getType()->getIsSolid())continue;
            player.setXY(newX, newY);
            visualizer.ChangeVisualization(loadedArea);
        }
        if (GetKeyState('D') & 0x8000)
        {
            int newX = player.getX() + 1;
            int newY = player.getY();

            int differenceX = newX - loadedArea.getRenderedTile().getStartX();
            int differenceY = newY - loadedArea.getRenderedTile().getStartY();

            if (differenceX >= Tile::width) {
                loadedArea.changeRenderedTile(1, 0);
            }
            
            differenceX = newX - loadedArea.getRenderedTile().getStartX();
            differenceY = newY - loadedArea.getRenderedTile().getStartY();

            BaseCell cell = loadedArea.getRenderedTile().getCell(differenceX, differenceY);
            if (cell.getTopBlock()->getType()->getIsSolid())continue;
            player.setXY(newX, newY);
            visualizer.ChangeVisualization(loadedArea);
        }
    }
}







