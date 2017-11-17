#ifndef TILE_HPP
#define TILE_HPP

//#include "populationsquare.hpp"
#include "utilities/coordinates.hpp"
#include "utilities/types.hpp"

#include <bitset>
#include <utility>
#include <vector>

using namespace std;

typedef bitset<5> popSquare;

enum PopType {
    money     = 0x01,
    science   = 0x02,
    materials = 0x04,
    advanced  = 0x08,
    populated = 0x10
};

class Tile {
  private:
    const uf16        id;
    const coordinates location;
    const bool        artifact;
    vector<popSquare> squares;
    vector<Tile *>    neighbours;
    // vector<Design> ships;
  public:

    Tile(const uf16 id, const coordinates location, const bool artifact, vector<popSquare> squares) :
            id(id), location(location), artifact(artifact), squares(std::move(squares)) {}

    Tile(
            const uf16 id, const coordinates location, const bool artifact, vector<popSquare> squares,
            const vector<Tile *> &neighbours
    ) : id(id), location(location), artifact(artifact), squares(std::move(squares)) {}

    void addNeighbour(Tile &neighbour) {
        neighbours.push_back(&neighbour);
    }
};

#endif // TILE_HPP
