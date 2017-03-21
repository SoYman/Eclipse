#ifndef PLAYER_HPP
#define PLAYER_HPP

//#include "race.hpp"
#include "tile.hpp"

#include <vector>

using namespace std;

class Player {
  protected:
    int id;
	int victoryPoints;
    Tile *home; // questionable
    vector<Tile *> Hexes;
	unsigned colonyShips;

  public:
	Player();
	virtual ~Player();
	virtual void upkeep();
    virtual void explore();
    virtual void influence();
    virtual void research();
    virtual void upgrade();
    virtual void build();
    virtual void move();
};

class Influence {
  private:
    int discs;

  public:
    int getUpkeep();
    void removeDisc();
    void returnDisc();
};

#endif
