cmake_minimum_required(VERSION 3.9)
project(Eclipse)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/races/eridani.hpp
        src/races/hydran.hpp
        src/races/terrans.cpp
        src/races/terrans.hpp
        src/utilities/coordinates.hpp
        src/board.cpp
        src/board.hpp
        src/main.cpp
        src/mutation.hpp
        src/player.cpp
        src/player.hpp
        src/playerinclude.hpp
        src/populationsquare.cpp
        src/populationsquare.hpp
        src/race.cpp
        src/race.hpp
        src/technology.cpp
        src/technology.hpp
        src/terminalinterface.cpp
        src/terminalinterface.hpp
        src/tile.hpp src/ship.cpp src/ship.hpp src/utilities/types.hpp)

add_executable(Eclipse ${SOURCE_FILES})