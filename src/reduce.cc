#include "reduce.h"

constexpr col_t b0 {0x01};
constexpr col_t b1 {0x02};
constexpr col_t b2 {0x04};
constexpr col_t b3 {0x08};
constexpr col_t b4 {0x10};
constexpr col_t b5 {0x20};

// 2-subsets of {1,...,4}

const unsigned SET_4[6] {
    b0 | b1,
    b0 | b2,
    b1 | b2,
    b0 | b3,
    b1 | b3,
    b2 | b3,
};

// 3-subsets of {1,...,6}
// (first 12)

const unsigned SET_6[12] {
    b0 | b1 | b2,
    b0 | b1 | b3,
    b0 | b2 | b3,
    b1 | b2 | b3,
    b0 | b1 | b4,
    b0 | b2 | b4,
    b1 | b2 | b4,
    b0 | b3 | b4,
    b1 | b3 | b4,
    b2 | b3 | b4,
    b0 | b1 | b5,
    b0 | b2 | b5,
};
