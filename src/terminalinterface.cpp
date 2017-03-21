#include "terminalinterface.hpp"

#include <random>

template <typename T> T TerminalInterface::query(string text) {
    T input;
    cout << text;
    cin >> input;
    return input;
}

TerminalInterface::TerminalInterface() {}

int TerminalInterface::start() {
    Setup setup;
    setup.playerCount = 0;
    while (setup.playerCount < 2 || setup.playerCount > 6) {
        setup.setPlayerCount(query<int>("Number of players: "));
    }

    bool randomRaces = query<bool>("Should races be randomised? ");
    if (randomRaces) {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0, 3);
        for (int i = 0; i < setup.playerCount; ++i) {
            setup.players.push_back(setup.assignRace(
                static_cast<RaceEnum>(distribution(generator))));
        }
    } else {
        for (int i = 0; i < setup.playerCount; ++i) {
            setup.players.push_back(setup.assignRace(static_cast<RaceEnum>(query<int>("which race should the player be? "))));
        }
    }
    Board board(setup);
    return 0;
}
