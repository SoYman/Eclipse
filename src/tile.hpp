#pragma once

//#include "populationsquare.hpp"
#include "utilities/coordinates.hpp"
#include "utilities/types.hpp"

#include <bitset>
#include <utility>
#include <vector>

using namespace std;

class Planet {
    enum PlanetType {
        money,
        science,
        materials,
        orbital
    };
    bool destroyed;
    PlanetType type;
    bool two;
};

typedef bitset<5> popSquare;

enum PopType {
    money     = 1 << 0,
    science   = 1 << 1,
    materials = 1 << 2,
    advanced  = 1 << 3,
    populated = 1 << 4
};

class Tile {
    const uf16        id;
    const coordinates location;
    const bool        artifact;
    uf8               vp;
    vector<popSquare> squares;
    vector<Tile *>    neighbours;
    // vector<Design> ships;
  public:

    Tile(const uf16 id, const coordinates location, const bool artifact, uf8 vp, vector<popSquare> squares) :
            id(id), location(location), artifact(artifact), vp(vp), squares(std::move(squares)) {}

    Tile(
            const uf16 id, const coordinates location, const bool artifact, uf8 vp, vector<popSquare> squares,
            const vector<Tile *> &neighbours
    ) : id(id), location(location), artifact(artifact), vp(vp), squares(std::move(squares)) {}

    void addNeighbour(Tile &neighbour) {
        neighbours.push_back(&neighbour);
    }
};
