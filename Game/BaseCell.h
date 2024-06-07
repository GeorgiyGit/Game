#pragma once
class BaseCell
{
public:
    BaseCell();
    BaseCell(char symbol);

    char getSymbol();
private:
    char symbol;
};

