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
    Timer t {"colour"};
    colour(n, p.get(), c.get());
}

bool Tester::verify() const {
    Timer t{"verify"};
    unsigned bad {0};
    for (unsigned i {0}; i < n; ++i) {
        if (c[i] >= C) {
            ++bad;
        }
        if (c[i] == c[p[i]]) {
            ++bad;
        }
    }
    if (bad > 0) {
        std::cout << "bad: " << bad << std::endl;
        return false;
    } else {
        return true;
    }
}

void Tester::stat() const {
    std::vector<unsigned> stat(C);
    for (unsigned i {0}; i < n; ++i) {
        ++stat[c[i]];
    }
    std::cout << "histogram:";
    for (unsigned j {0}; j < C; ++j) {
        std::cout << " " << stat[j];
    }
    std::cout << std::endl;
}
