//
// Created by arnaldur on 11/13/17.
//

#ifndef ECLIPSE_SHIP_H
#define ECLIPSE_SHIP_H

#include "utilities/types.hpp"

#include <utility>
#include <vector>
#include <array>

namespace Ship {

    typedef std::vector<if8> attacks;

    enum Feature {
        kCost,
        kInitiative,
        kHull,
        kPower,
        kTargeting,
        kShield,
        kRegen,
        kTypes,
        kGuns
    };

    struct Element {
        Feature feature;
        if8     value;
    };

    typedef std::vector<Element> Part;

    class Design {
        std::array<if8, kTypes> features;
        std::vector<Part>       parts;
        attacks                 guns;
      public:
        Design(
                const std::vector<Part> &parts, if8 cost, if8 initiative, if8 hull, if8 power, if8 targeting,
                if8 shield, if8 regen
        );

        void replacePart(if8, Part);

        std::tuple<if8, attacks> shoot();
    };


}
#endif //ECLIPSE_SHIP_H
