#include "Player.h"

Player::Player() {
    this->y = -10;
    this->x = -10;
}
Player::Player(int y, int x) {
    this->y = y;
    this->x = x;
}
int Player::getX() {
    return this->x;
}
int Player::getY() {
    return this->y;
}

void Player::setX(int x) {
    this->x = x;
}
void Player::setY(int y) {
    this->y = y;
}
