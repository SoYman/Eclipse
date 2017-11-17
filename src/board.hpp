#ifndef BOARD_HPP
#define BOARD_HPP

#include "playerinclude.hpp"
#include "technology.hpp"
#include "mutation.hpp"
#include "tile.hpp"
#include "utilities/coordinates.hpp"

#include <unordered_map>
#include <vector>

// typedef tuple<signed char, signed char> coordinates;
typedef unordered_map<coordinates, Tile *> space;

using namespace std;

enum RaceEnum {
    terranDirectorate,
    eridaniEmpire,
    terranFederation,
    hydranProgress,
    /*    terranUnion,
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
    shapersOfDorad*/
};

class Setup {
  public:
    bool             riseOfTheAncients;
    bool             shadowOfTheRift;
    int              playerCount;
    vector<Player *> players;
    space            field;
    vector<Tile *>   inner;
    vector<Tile *>   middle;
    vector<Tile *>   outer;

    void setExpansions(int);

    void setPlayerCount(int);

    int raceCount();

    Player *assignRace(RaceEnum);

    void setupBaseTiles();

    void populateTilePiles();
};

class Board {
  private:
    int                round;
    vector<Player *>   players;
    vector<Player *>   nextorder;
    vector<Tile *>     inner;
    vector<Tile *>     middle;
    vector<Tile *>     outer;
    int                outerSectorsRemaining;
    vector<Technology> techBag;
    vector<Technology> techAvailable;
    vector<Mutation>   mutationBag;

  public:
    Board(Setup setup);

    ~Board();

    int getPlayerCount();
};

#endif
