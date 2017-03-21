#include "technology.hpp"

#include <vector>

using namespace std;

Technology::Technology(TechnologyType type, int cost, int minimum) : type(type), cost(cost), minimum(minimum) {}

vector<Technology> fillTechBag(bool ROArare, bool ROAextra, bool SOR) {
    int bagSize = 96;
    if (ROArare) {
        bagSize += 10;
    }
    if (ROAextra) {
        bagSize += 18;
    }
    if (SOR) {
        bagSize += 6;
    }
    vector<Technology> techBag;
    techBag.reserve(bagSize);
    for (int i = 0; i < 5; ++i) {
		// Tier 1, 2, 3
    }
    for (int i = 0; i < 4; ++i) {
		// Tier 4, 5
    }
    for (int i = 0; i < 3; ++i) {
		// Tier 6, 7, 8
    }
    return techBag;
}
