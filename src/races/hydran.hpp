#ifndef HYDRAN_HPP
#define HYDRAN_HPP

class HydranProgress : public Player {
  public:
    Tile *homeSector() override {
        //TODO: make this the actual tile and calculate coord
        return new Tile(0, coord(0,0), true, {});
    }
};

#endif // HYDRAN_HPP
