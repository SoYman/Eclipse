#ifndef BOARD_HPP
#define BOARD_HPP

#include "playerinclude.hpp"
#include "technology.hpp"
#include "tile.hpp"

#include <unordered_map>
#include <vector>
#include <tuple>
#include <cstdint>

typedef tuple<int_fast8_t, int_fast8_t> coordinates;
typedef unordered_map<coordinates, Tile*> map;

using namespace std;

enum RaceEnum {
    terranDirectorate,
    eridaniEmpire,
    terranFederation,
    hydranProgress,
    terranUnion,
    planta,
    terranRepublic,
    descendantsOfDraco,
    terranConglomerate,
    mechanema,
    terranAlliance,
    orionHegemony,
    wardensOfMagellan,
    theExiles,
    sentinelsOfMagellan,
    rhoIndiSyndicate,
    keepersOfMagellan,
    enligthtenedOfLyra,
    octanisAutonomy,
    pyxisUnity,
    octanisVanguard,
    shapersOfDorado
};

class Setup {
  public:
	bool riseOfTheAncients;
	bool shadowOfTheRift;
    int playerCount;
    vector<Player *> players;
	map field;
    vector<Tile*> inner;
    vector<Tile*> middle;
    vector<Tile*> outer;
	void setExpansions(int);
    void setPlayerCount(int);
    Player *assignRace(RaceEnum);
	void setupBaseTiles();
    void populateTilePiles();
};

class Board {
  private:
    int round;
    vector<Player *> players;
    vector<Player *> nextorder;
    vector<Tile*> inner;
    vector<Tile*> middle;
    vector<Tile*> outer;
    int outerSectorsRemaining;
    vector<Technology> techBag;
    vector<Technology> techAvailable;

  public:
    Board(Setup setup);
    ~Board();
    int getPlayerCount();
};

#endif
