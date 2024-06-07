#include "BaseCell.h"

BaseCell::BaseCell() {

}
BaseCell::BaseCell(char symbol) {
    this->symbol = symbol;
}
char BaseCell::getSymbol() {
    return this->symbol;
}