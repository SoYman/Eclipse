#ifndef TERRANS_HPP
#define TERRANS_HPP

#include "../player.hpp"

class Terran : public Player {};

//TODO: make these the actual tile and calculate coord
class TerranDirectorate : public Terran {
  public:
    Tile *homeSector() override;
};
class TerranFederation : public Terran {
  public:
    Tile *homeSector() override;
};
class TerranUnion : public Terran {
  public:
    Tile *homeSector() override;
};
class TerranRepublic : public Terran {
  public:
    Tile *homeSector() override;
};
class TerranConglomerate : public Terran {
  public:
    Tile *homeSector() override;
};
class TerranAlliance : public Terran {
  public:
    Tile *homeSector() override;
};

#endif
