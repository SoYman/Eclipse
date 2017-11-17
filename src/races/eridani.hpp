#ifndef ERIDANI_HPP
#define ERIDANI_HPP

class EridaniEmpire : public Player {
  public:
    Tile *homeSector() override {
        //TODO: make this the actual tile and calculate coord
        return new Tile(0, coord(0,0), true, {});
    }
};

#endif // ERIDANI_HPP
