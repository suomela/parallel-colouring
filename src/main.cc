#include <cstdlib>
#include <iostream>
#include "tester.h"

static bool test(unsigned bits)
{
    Tester t {bits};
    t.gen_input();
    t.do_colour();
    if (!t.verify()) {
        return false;
    } else {
        t.stat();
        return true;
    }
}

int main(int argc, const char **argv) {
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " BITS" << std::endl;
        return EXIT_FAILURE;
    }
    long bits {std::strtol(argv[1], NULL, 10)};
    if (bits < BITS_MIN || bits > BITS_MAX) {
        std::cerr << "BITS must be between " << BITS_MIN << " and " << BITS_MAX << std::endl;
        return EXIT_FAILURE;
    }
    return test(static_cast<unsigned>(bits)) ? EXIT_SUCCESS : EXIT_FAILURE;
}
