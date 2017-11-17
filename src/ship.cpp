//
// Created by arnaldur on 11/13/17.
//

#include <tuple>
#include <algorithm>
#include "ship.hpp"

namespace Ship {


    Design::Design(
            const std::vector<Part> &parts, if8 cost, if8 initiative = 0, if8 hull = 0, if8 power = 0,
            if8 targeting = 0, if8 shield = 0, if8 regen = 0
    ) : parts(parts) {
        features[kCost]       = cost;
        features[kInitiative] = initiative;
        features[kHull]       = hull;
        features[kPower]      = power;
        features[kTargeting]  = targeting;
        features[kShield]     = shield;
        features[kRegen]      = regen;

        for (auto &&part : parts) {
            for (auto &&element : part) {
                if (element.feature == kGuns) {
                    guns.push_back(element.value);
                } else {
                    features[element.feature] += element.value;
                }
            }
        }
    }

    std::tuple<if8, attacks> Design::shoot() {
        std::tuple<if8, attacks> out(features[kTargeting], guns);
        return out;
    }

    void Design::replacePart(if8 index, Part newPart) {
        for (auto &&element : parts[index]) {
            if (element.feature != kGuns) {
                features[element.feature] -= element.value;
            } else {
                auto it = std::find(guns.begin(), guns.end(), element.value);
                //std::iter_swap(it, guns.end() - 1);
                std::swap(*it, guns.back());
                guns.pop_back();
            }
        }
        for (auto &&element : newPart) {
            if (element.feature != kGuns) {
                features[element.feature] += element.value;
            } else {
                guns.push_back(element.value);
            }
        }
        parts[index] = newPart;
    }

}