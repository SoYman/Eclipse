#pragma once

#include <cstdint>
#include <utility>

typedef int_fast16_t coordinates;

inline coordinates coord(int y, int x) {
    return static_cast<int_fast16_t>((y << 8) + x);
}
