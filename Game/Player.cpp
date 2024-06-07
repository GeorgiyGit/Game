#include "Player.h"

Player::Player() {
    this->y = -10;
    this->x = -10;
}
Player::Player(int x, int y) {
    this->y = y;
    this->x = x;
    this->previousX = x;
    this->previousY = y;
}
int Player::getX() {
    return this->x;
}
int Player::getY() {
    return this->y;
}
int Player::getPreviousX() {
    return this->previousX;
}
int Player::getPreviousY() {
    return this->previousY;
}

void Player::setX(int x) {
    this->previousX = this->x;
    this->x = x;
}
void Player::setY(int y) {
    this->previousY = this->y;
    this->y = y;
}

void Player::setXY(int x, int y) {
    this->previousX = this->x;
    this->previousY = this->y;
    this->y = y;
    this->x = x;
}