#pragma once
class Player {
public:
    Player();
    Player(int y, int x);

    int getX();
    int getY();

    void setX(int x);
    void setY(int y);
private:
    int x;
    int y;
};

