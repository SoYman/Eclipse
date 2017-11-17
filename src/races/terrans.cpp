
#include "../tile.hpp"
#include "terrans.hpp"

Tile *TerranDirectorate::homeSector() {
    return new Tile(0, coord(0,0), true, {});
}

Tile *TerranFederation::homeSector() {
    return new Tile(0, coord(0,0), true, {});
}

Tile *TerranUnion::homeSector() {
    return new Tile(0, coord(0,0), true, {});
}

Tile *TerranRepublic::homeSector() {
    return new Tile(0, coord(0,0), true, {});
}

Tile *TerranConglomerate::homeSector() {
    return new Tile(0, coord(0,0), true, {});
}

Tile *TerranAlliance::homeSector() {
    return new Tile(0, coord(0,0), true, {});
}
