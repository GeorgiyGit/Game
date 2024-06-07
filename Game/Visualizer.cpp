#include "Visualizer.h"
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
    Tile tile = area.getRenderedTile();
    Player* player = area.getPlayer();

    int playerX = player->getX();
    int playerY = player->getY();

    BaseCell** cells = tile.getCells();
    std::string str;

    for (int y = 0;y < tileHeight;y++) {
        for (int x = 0;x < tileWidth;x++) {
            if (playerX - tile.getStartX() == x && playerY - tile.getStartY() == y)
            {
                str += '#';
                str += ' ';
            }
            else {
                str += cells[y][x].getSymbol();
                str += ' ';
            }
        }
        str += '\n';
    }
    system("cls");
    std::cout << str;
    std::cout << playerX - tile.getStartX() << " " << playerX << " " << tile.getStartX() << std::endl;
    std::cout << playerY - tile.getStartY() << " " << playerY << " " << tile.getStartY() << std::endl;
}

void Visualizer::ChangeVisualization(LoadedArea& area) {
    Tile tile = area.getRenderedTile();
    Player* player = area.getPlayer();

    int playerX = player->getX();
    int playerY = player->getY();

    int playerPrevX = player->getPreviousX();
    int playerPrevY = player->getPreviousY();

    BaseCell** cells = tile.getCells();
    std::string str;

    SetCursorVisibility(false);
    if (playerPrevX != playerX || playerPrevY != playerY) {
        int lXPrev = playerPrevX - tile.getStartX();
        int lYPrev = playerPrevY - tile.getStartY();

        int lX = playerX - tile.getStartX();
        int lY = playerY - tile.getStartY();

        SetCursorPosition(lXPrev * 2, lYPrev);

        std::cout << cells[lYPrev][lXPrev].getSymbol();

        SetCursorPosition(lX * 2, lY);
        std::cout << '#';
    }
    //SetCursorVisibility(true);
}