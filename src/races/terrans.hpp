#ifndef TERRANS_HPP
#define TERRANS_HPP

class Terran : public Player {};

class TerranDirectorate : public Terran {};
class TerranFederation : public Terran {};
class TerranUnion : public Terran {};
class TerranRepublic : public Terran {};
class TerranConglomerate : public Terran {};
class TerranAlliance : public Terran {};

#endif
