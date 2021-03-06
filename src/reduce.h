#ifndef REDUCE_H
#define REDUCE_H

#include "colour.h"
#include "pack.h"

// Cole-Vishkin

inline static col_t reduce(unsigned x, unsigned y) {
    unsigned diff {x ^ y};
    unsigned bit {static_cast<unsigned>(__builtin_ctz(diff))};
    unsigned value {(x >> bit) & 1};
    return static_cast<col_t>((bit << 1) | value);
}

// Naor-Stockmeyer

#define GEN_REDUCE(a,b) \
\
extern const unsigned SET_##a##_##b[a]; \
\
inline static col_t reduce##a##_##b(col_t x, col_t y) { \
    unsigned available {SET_##a##_##b[x] & ~SET_##a##_##b[y]}; \
    unsigned bit {static_cast<unsigned>(__builtin_ctz(available))}; \
    return static_cast<col_t>(bit); \
}

GEN_REDUCE(64,8)
GEN_REDUCE(12,6)
GEN_REDUCE(8,5)
GEN_REDUCE(6,4)

// Trivial

inline col_t pickfree(col_t x, col_t y) {
    if (x != 0 && y != 0) {
        return 0;
    } else if (x != 1 && y != 1) {
        return 1;
    } else {
        return 2;
    }
}

inline constexpr col_t pickfree_3(unsigned x, unsigned y) {
    return static_cast<col_t>(
        // output 1
        ((~(x | y)) & 1)
        // output 2
      | ((x + y == 1) << 1)
    );
}

static_assert(pickfree_3(0,0) == 1, "pickfree_3");
static_assert(pickfree_3(1,0) == 2, "pickfree_3");
static_assert(pickfree_3(2,0) == 1, "pickfree_3");
static_assert(pickfree_3(0,1) == 2, "pickfree_3");
static_assert(pickfree_3(1,1) == 0, "pickfree_3");
static_assert(pickfree_3(2,1) == 0, "pickfree_3");
static_assert(pickfree_3(0,2) == 1, "pickfree_3");
static_assert(pickfree_3(1,2) == 0, "pickfree_3");
static_assert(pickfree_3(2,2) == 1, "pickfree_3");

// Avoid reading what is not needed

inline col_t reduce4_3(const unsigned *p, const col_t *cold, unsigned i) {
    unsigned parent {p[i]};
    col_t cparent {cold[parent]};
    if (cparent == 3) {
        return pickfree_3(cold[i], cold[p[parent]]);
    } else {
        return cparent;
    }
}

inline col_t reduce4_3_pack(const unsigned *p, const col_t *cold, unsigned i) {
    unsigned parent {p[i]};
    col_t cparent {get4(cold, parent)};
    if (cparent == 3) {
        return pickfree_3(get4(cold, i), get4(cold, p[parent]));
    } else {
        return cparent;
    }
}

inline col_t reduce4_3_comb(const unsigned *p, const col_t *ccold, unsigned i) {
    auto cc = unpack2(ccold[i]);
    if (cc.second == 3) {
        auto ccparent = unpack2(ccold[p[i]]);
        return pickfree_3(cc.first, ccparent.second);
    } else {
        return cc.second;
    }
}

#endif
