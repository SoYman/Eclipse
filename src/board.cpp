#include "board.hpp"

Board::Board(Setup setup) : round(1) {
    // for (int i = 0; i < setup.playerCount; ++i) {
    players = setup.players;
    // players.push_back(Player(i));
    //}
    for (int i = 0; i < setup.playerCount * 2 + 8; ++i) {
        // TODO: addTech();
    }
}

Board::~Board() {
    for (unsigned i = 0; i < players.size(); ++i) {
        delete players[i];
    }
}

int Board::getPlayerCount() { return players.size(); }

Player *Setup::assignRace(RaceEnum race) {
    switch (race) {
    case terranDirectorate:
        return new TerranDirectorate();
    case eridaniEmpire:
        return new EridaniEmpire();
    case terranFederation:
        return new TerranFederation();
    case hydranProgress:
        return new HydranProgress();
    }
}

void Setup::setPlayerCount(int count) {
    playerCount = count;
    players.reserve(count);
}

void Setup::populateTilePiles() {

}
