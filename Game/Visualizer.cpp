#include "Visualizer.h"
#include <string>
#include "Colors.h"


Visualizer::Visualizer() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    this->originalAttributes = consoleInfo.wAttributes;
}
void setcolor(int textcol, int backcol)
{
    textcol %= 16;backcol %= 16;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    unsigned short wAttributes = ((unsigned)backcol << 4) | (unsigned)textcol;
    SetConsoleTextAttribute(hConsole, wAttributes);
}
void Visualizer::restoreColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, this->originalAttributes);
}
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
    VisualizationCell** newMap = *getMapStr(area);
    SetCursorVisibility(false);
    system("cls");

    int oldY = 0;
    int oldX = 0;
    std::string str;
    for (int y = 0;y < Tile::height;y++) {
        for (int x = 0;x < Tile::width;x++) {
            newMap[y][x].symbol = 'Ž';
        }
    }
    oldGameMap = newMap;
    ChangeVisualization(area);
}

void deleteMap(VisualizationCell** map) {
    for (int i = 0;i < Tile::height;i++) {
        delete[] map[i];
    }
    delete[] map;
}

VisualizationCell*** Visualizer::getMapStr(LoadedArea& area) {
    Tile tile = area.getRenderedTile();
    Player* player = area.getPlayer();

    BaseCell** cells = tile.getCells();
    int playerX = player->getX();
    int playerY = player->getY();
    VisualizationCell** map = new VisualizationCell * [Tile::height];

    for (int y = 0;y < Tile::height;y++) {
        map[y] = new VisualizationCell[Tile::width];
        for (int x = 0;x < Tile::width;x++) {
            VisualizationCell cell;
            if (playerX - tile.getStartX() == x && playerY - tile.getStartY() == y)
            {
                cell.fColor = MyColors::red;
                cell.bColor = cells[y][x].getBColor();
                cell.symbol = '#';
            }
            else {
                cell.symbol = cells[y][x].getTopBlock()->getType()->getSymbol();

                cell.fColor = cells[y][x].getFColor();
                cell.bColor = cells[y][x].getBColor();
            }
            map[y][x] = cell;
        }
    }

    return &map;
}

void Visualizer::DrawCords(int playerX, int playerY) {
    SetCursorPosition(0, Tile::height);
    std::cout << "                         ";
    SetCursorPosition(0, Tile::height);
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

    VisualizationCell** newMap = *getMapStr(area);

    SetCursorVisibility(false);
    std::string redrawArea = "";
    
    int startX = 0;
    int startY = 0;

    int oldY = 0;
    int oldX = 0;
    std::string str;
    for (int y = 0;y < Tile::height;y++) {
        for (int x = 0;x < Tile::width;x++) {
            if (oldGameMap[y][x].symbol != newMap[y][x].symbol) {
                if (redrawArea == "") {
                    redrawArea += newMap[y][x].symbol;
                    oldX = x;
                    oldY = y;
                    startX = x;
                    startY = y;
                }
                else if (newMap[oldY][oldX].fColor != newMap[y][x].fColor ||
                    newMap[oldY][oldX].bColor != newMap[y][x].bColor) {
                    setcolor(newMap[oldY][oldX].fColor, newMap[oldY][oldX].bColor);
                    SetCursorPosition(startX, startY);
                    std::cout << redrawArea;
                    redrawArea = "";

                    redrawArea += newMap[y][x].symbol;
                    oldX = x;
                    oldY = y;
                    startX = x;
                    startY = y;
                }
                else {
                    redrawArea += newMap[y][x].symbol;
                }
            }
            else if (redrawArea != "") {
                setcolor(newMap[oldY][oldX].fColor, newMap[oldY][oldX].bColor);
                SetCursorPosition(startX, startY);
                std::cout << redrawArea;
                redrawArea = "";
            }
        }
        if (redrawArea != "") {
            redrawArea += '\n';
        }
    }
    if (redrawArea != "") {
        setcolor(newMap[oldY][oldX].fColor, newMap[oldY][oldX].bColor);
        SetCursorPosition(startX, startY);
        std::cout << redrawArea;
        redrawArea = "";
    }
    deleteMap(oldGameMap);
    oldGameMap = newMap;
    restoreColor();
    DrawCords(playerX, playerY);
}