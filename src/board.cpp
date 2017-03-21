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

void Setup::setExpansions(int flags) {
    riseOfTheAncients = flags & 1;
    shadowOfTheRift = flags >> 1;
}

void Setup::setPlayerCount(int count) {
    playerCount = count;
    players.reserve(count);
}

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

void Setup::setupBaseTiles() {

}

void Setup::populateTilePiles() {
    // Base game
	// inner.push_back(new Tile())
    if (riseOfTheAncients) {

    }
	if (shadowOfTheRift) {

	}
}
