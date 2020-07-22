#include "board.hpp"

Board::Board(const& Setup setup) : round(1) {
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
    shadowOfTheRift   = flags >> 1;
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
    // should never happen
    return new TerranDirectorate();
}

void Setup::setupBaseTiles() {
    unsigned spots = 19;
    if (playerCount == 2) {
        spots += 5;
    } else if (playerCount == 3) {
        spots += 10;
    } else if (playerCount < 7) {
        spots += 6 + 2 * playerCount;
    } else if (playerCount < 9) {
        spots += 8 + 2 * playerCount;
    } else {
        spots += 24;
    }
    field.reserve(spots);
    field.at(coord(0, 0)) = new Tile(
            1, coord(0, 0), true,
            {
                    science, science | advanced, materials, materials | advanced,
                    money | science | materials, money | science | materials
            }
    );
}

void Setup::populateTilePiles() {
    // Base game
    // inner.push_back(new Tile())
    if (riseOfTheAncients) {
    }
    if (shadowOfTheRift) {
    }
}

int Setup::raceCount() {
    int count = 7;
    if (riseOfTheAncients) {
        count += 4;
    }
    if (shadowOfTheRift) {
        count += 3;
    }
    return count;
}
