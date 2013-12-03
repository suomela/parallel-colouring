#include "reduce.h"

constexpr unsigned b0 {0x01};
constexpr unsigned b1 {0x02};
constexpr unsigned b2 {0x04};
constexpr unsigned b3 {0x08};
constexpr unsigned b4 {0x10};
constexpr unsigned b5 {0x20};
constexpr unsigned b6 {0x40};
constexpr unsigned b7 {0x80};

// 2-subsets of {1,...,4}

const unsigned SET_6_4[6] {
    b0 | b1,
    b0 | b2,
    b1 | b2,
    b0 | b3,
    b1 | b3,
    b2 | b3,
};

// 2-subsets of {1,...,5}
// (first 8)

const unsigned SET_8_5[8] {
    b0 | b1,
    b0 | b2,
    b1 | b2,
    b0 | b3,
    b1 | b3,
    b2 | b3,
    b0 | b4,
    b1 | b4,
};

// 3-subsets of {1,...,6}
// (first 12)

const unsigned SET_12_6[12] {
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

// 4-subsets of {1,...,8}
// (first 64)

const unsigned SET_64_8[64] {
    b0 | b1 | b2 | b3,
    b0 | b1 | b2 | b4,
    b0 | b1 | b3 | b4,
    b0 | b2 | b3 | b4,
    b1 | b2 | b3 | b4,
    b0 | b1 | b2 | b5,
    b0 | b1 | b3 | b5,
    b0 | b2 | b3 | b5,
    b1 | b2 | b3 | b5,
    b0 | b1 | b4 | b5,
    b0 | b2 | b4 | b5,
    b1 | b2 | b4 | b5,
    b0 | b3 | b4 | b5,
    b1 | b3 | b4 | b5,
    b2 | b3 | b4 | b5,
    b0 | b1 | b2 | b6,
    b0 | b1 | b3 | b6,
    b0 | b2 | b3 | b6,
    b1 | b2 | b3 | b6,
    b0 | b1 | b4 | b6,
    b0 | b2 | b4 | b6,
    b1 | b2 | b4 | b6,
    b0 | b3 | b4 | b6,
    b1 | b3 | b4 | b6,
    b2 | b3 | b4 | b6,
    b0 | b1 | b5 | b6,
    b0 | b2 | b5 | b6,
    b1 | b2 | b5 | b6,
    b0 | b3 | b5 | b6,
    b1 | b3 | b5 | b6,
    b2 | b3 | b5 | b6,
    b0 | b4 | b5 | b6,
    b1 | b4 | b5 | b6,
    b2 | b4 | b5 | b6,
    b3 | b4 | b5 | b6,
    b0 | b1 | b2 | b7,
    b0 | b1 | b3 | b7,
    b0 | b2 | b3 | b7,
    b1 | b2 | b3 | b7,
    b0 | b1 | b4 | b7,
    b0 | b2 | b4 | b7,
    b1 | b2 | b4 | b7,
    b0 | b3 | b4 | b7,
    b1 | b3 | b4 | b7,
    b2 | b3 | b4 | b7,
    b0 | b1 | b5 | b7,
    b0 | b2 | b5 | b7,
    b1 | b2 | b5 | b7,
    b0 | b3 | b5 | b7,
    b1 | b3 | b5 | b7,
    b2 | b3 | b5 | b7,
    b0 | b4 | b5 | b7,
    b1 | b4 | b5 | b7,
    b2 | b4 | b5 | b7,
    b3 | b4 | b5 | b7,
    b0 | b1 | b6 | b7,
    b0 | b2 | b6 | b7,
    b1 | b2 | b6 | b7,
    b0 | b3 | b6 | b7,
    b1 | b3 | b6 | b7,
    b2 | b3 | b6 | b7,
    b0 | b4 | b6 | b7,
    b1 | b4 | b6 | b7,
    b2 | b4 | b6 | b7,
};

