#include "player.hpp"

Player::Player() {
	colonyShips = 3;
}

Player::~Player() {}

void Player::upkeep() {
	colonyShips = 3;
}

void Player::explore() {}
void Player::influence() {}
void Player::research() {}
void Player::upgrade() {}
void Player::build() {}
void Player::move() {}
