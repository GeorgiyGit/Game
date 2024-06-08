#include "Visualizer.h"
#include <string>

void SetCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Could not get console handle." << std::endl;
        return;
    }

    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;

    SetConsoleCursorPosition(hConsole, coordinates);
}
void SetCursorVisibility(bool visible) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Could not get console handle." << std::endl;
        return;
    }

    CONSOLE_CURSOR_INFO cursorInfo;
    if (!GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        std::cerr << "Error: Could not get cursor info." << std::endl;
        return;
    }

    cursorInfo.bVisible = visible;

    if (!SetConsoleCursorInfo(hConsole, &cursorInfo)) {
        std::cerr << "Error: Could not set cursor visibility." << std::endl;
        return;
    }
}
void Visualizer::RedrawVisualization(LoadedArea& area) {
    std::string str= getMapStr(area);
    SetCursorVisibility(false);
    system("cls");
    std::cout << str;
    oldMap = str;

    Player* player = area.getPlayer();
    int playerX = player->getX();
    int playerY = player->getY();

    DrawCords(playerX, playerY);
}

std::string Visualizer::getMapStr(LoadedArea& area) {
    Tile tile = area.getRenderedTile();
    Player* player = area.getPlayer();

    BaseCell** cells = tile.getCells();
    int playerX = player->getX();
    int playerY = player->getY();
    std::string str;

    for (int y = 0;y < tileHeight;y++) {
        for (int x = 0;x < tileWidth;x++) {
            if (playerX - tile.getStartX() == x && playerY - tile.getStartY() == y)
            {
                str += '#';
            }
            else {
                str += cells[y][x].getSymbol();
            }
        }
        str += '\n';
    }

    return str;
}

void Visualizer::DrawCords(int playerX, int playerY) {
    SetCursorPosition(0, 20);
    std::cout << "                         ";
    SetCursorPosition(0, 20);
    std::cout << playerX << " " << playerY << std::endl;
}
void Visualizer::ChangeVisualization(LoadedArea& area) {
    Tile tile = area.getRenderedTile();
    Player* player = area.getPlayer();

    int playerX = player->getX();
    int playerY = player->getY();

    int playerPrevX = player->getPreviousX();
    int playerPrevY = player->getPreviousY();

    BaseCell** cells = tile.getCells();

    std::string str = getMapStr(area);

    SetCursorVisibility(false);
    std::string redrawArea = "";
    
    int startX = 0;
    int startY = 0;

    for (int y = 0;y < tileHeight;y++) {
        for (int x = 0;x < tileWidth;x++) {
            if (oldMap[y * (tileWidth + 1) + x] != str[y * (tileWidth + 1) + x]) {
                redrawArea += str[y * (tileWidth + 1) + x];
            }
            else if (redrawArea != "") {
                SetCursorPosition(startX, startY);
                std::cout << redrawArea;
                redrawArea = "";
                startX = x + 1;
                startY = y;
            }
            else {
                startX = x + 1;
                startY = y;
            }
        }
        if (redrawArea != "") {
            redrawArea += '\n';
        }
        else {
            startX = 0;
            startY = y + 1;
        }
    }
    oldMap = str;
    DrawCords(playerX, playerY);
}