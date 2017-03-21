#ifndef TERMINALINTERFACE_HPP
#define TERMINALINTERFACE_HPP

#include "board.hpp"

#include <iostream>

using namespace std;

class TerminalInterface {
  private:
    template <typename T> T query(string text);

  public:
    TerminalInterface();
	int start();
};

#endif
