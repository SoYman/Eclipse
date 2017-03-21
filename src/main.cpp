#include "terminalinterface.hpp"
#include "board.hpp"

#include <iostream>
#include <string>

using namespace std;

int tests() {
	cout << "testing!" << endl;
	//	Board();
	//TODO: test stuff
	//TODO: make stuff to test
	return 0;
}

int terminal() {
	TerminalInterface terminal;
	return terminal.start();
}

int main(int argc, char *argv[]) {
	//cout << "argc = " << argc << endl;
    if (argc < 2) {
        return 0;
    } else if (argc < 3) {
		string first = argv[1];
		if (first == "--test" || first == "-t") {
			return tests();
		} else if (first == "--console" || first == "-c") {
			return terminal();
		}
    } else {
        return 0;
    }
}
