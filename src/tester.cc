#include "tester.h"
#include <random>
#include "colour.h"
#include "colour-interface.h"
#include "timer.h"

constexpr col_t C {3};

Tester::Tester(unsigned bits_)
 : n {1U << bits_}, mask {n - 1},
   p { new unsigned[n] }, c { new col_t[n] }
{}

void Tester::gen_input() {
    Timer t{"generate input"};
    std::mt19937 rng {1};
    static_assert(rng.min() == 0, "rng.min");
    static_assert(rng.max() == std::numeric_limits<unsigned>::max(), "rng.max");
    p[0] = 1;
    p[1] = 0;
    for (unsigned i {2}; i < n; ++i) {
        unsigned x {static_cast<unsigned>(rng()) & mask};
        if (x == i) {
            x = 0;
        }
        p[i] = x;
    }
}

void Tester::do_colour() {
    Timer t {"3-colouring (total)"};
    colour(n, p.get(), c.get());
}

bool Tester::verify() const {
    unsigned bad {0};
    {
        Timer t{"verify"};
        for (unsigned i {0}; i < n; ++i) {
            if (c[i] >= C) {
                ++bad;
            }
            if (c[i] == c[p[i]]) {
                ++bad;
            }
        }
    }
    std::cout << "\n";
    if (bad > 0) {
        std::cout << "invalid output (" << bad << " nodes)" << std::endl;
        return false;
    } else {
        std::cout << "output OK" << std::endl;
        return true;
    }
}

void Tester::stat() const {
    std::vector<unsigned> stat(C);
    for (unsigned i {0}; i < n; ++i) {
        ++stat[c[i]];
    }
    std::cout << "histogram:\n";
    for (unsigned j {0}; j < C; ++j) {
        std::cout << j << ": " << stat[j] << "\n";
    }
    std::cout << std::flush;
}
