#ifndef TECHNOLOGY_HPP
#define TECHNOLOGY_HPP

#include <vector>

class Technology {
  private:
	int id;
    enum TechnologyType { military, grid, nano, rare };
	TechnologyType type;
    int cost;
    int minimum;

  public:
    Technology(TechnologyType type, int cost, int minimum);
};

#endif
