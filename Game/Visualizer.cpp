#include "Visualizer.h"
void Visualizer::Visualize(LoadedArea& area) {
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