#ifndef TILE_HPP
#define TILE_HPP

#include "populationsquare.hpp"

#include <vector>

using namespace std;

class Tile {
 private:
	int id;
	vector<PopulationSquare> squares;
	vector<Tile*> neighbours;
 public:
	Tile(int, vector<PopulationSquare>);
};

#endif
