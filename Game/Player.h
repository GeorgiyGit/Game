#pragma once
class Player {
public:
    Player();
    Player(int x, int y);

    int getX();
    int getY();

    int getPreviousX();
    int getPreviousY();

    void setX(int x);
    void setY(int y);
    void setXY(int x, int y);
private:
    int x;
    int y;
    int previousX;
    int previousY;
};

