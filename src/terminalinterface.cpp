#include "terminalinterface.hpp"

#include <limits>
#include <random>

template <typename T> T TerminalInterface::query(string text) {
    T input;
    while (true) {
        cout << text << flush;
        cin >> input;
        if (cin.fail()) {
            cerr << "Sorry, I cannot read that. Please try again." << std::endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
    return input;
}

TerminalInterface::TerminalInterface() {}

int TerminalInterface::start() {
    Setup setup;
    cout << "Which expansions should be included" << endl;
    cout << "0 -> Base game" << endl;
    cout << "1 -> Rise of the Ancients" << endl;
    cout << "2 -> Shadow of the Rift" << endl;
    cout << "3 -> Both expansions" << endl;
    int choice = 4;
    while (0 > choice || choice > 3) {
        choice = query<int>("Number of players: ");
    }
    setup.setExpansions(choice);
    if (setup.riseOfTheAncients) {
        cout << "Rise of the Ancients included" << endl;
    }
    if (setup.shadowOfTheRift) {
        cout << "Shadow of the Rift included" << endl;
    }
    while (2 > choice || choice > 6) {
        choice = query<int>("Number of players: ");
    }
    setup.setPlayerCount(choice);
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
            setup.players.push_back(setup.assignRace(static_cast<RaceEnum>(
                query<int>("which race should the player be? "))));
        }
    }
    Board board(setup);
    return 0;
}
