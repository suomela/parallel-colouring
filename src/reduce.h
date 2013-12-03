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

extern const unsigned SET_4[6];
extern const unsigned SET_6[12];

inline static col_t reduce12_6(col_t x, col_t y) {
    unsigned available {SET_6[x] & ~SET_6[y]};
    unsigned bit {static_cast<unsigned>(__builtin_ctz(available))};
    return static_cast<col_t>(bit);
}

inline static col_t reduce6_4(col_t x, col_t y) {
    unsigned available {SET_4[x] & ~SET_4[y]};
    unsigned bit {static_cast<unsigned>(__builtin_ctz(available))};
    return static_cast<col_t>(bit);
}

// Trivial

inline static col_t pickfree(col_t x, col_t y) {
    if (x != 0 && y != 0) {
        return 0;
    } else if (x != 1 && y != 1) {
        return 1;
    } else {
        return 2;
    }
}

// Avoid reading what is not needed

inline col_t reduce4_3(const unsigned *p, const col_t *cold, unsigned i) {
    unsigned parent {p[i]};
    col_t cparent {cold[parent]};
    if (cparent == 3) {
        return pickfree(cold[i], cold[p[parent]]);
    } else {
        return cparent;
    }
}

inline col_t reduce4_3_pack(const unsigned *p, const col_t *cold, unsigned i) {
    unsigned parent {p[i]};
    col_t cparent {get4(cold, parent)};
    if (cparent == 3) {
        return pickfree(get4(cold, i), get4(cold, p[parent]));
    } else {
        return cparent;
    }
}

inline col_t reduce4_3_comb(const unsigned *p, const col_t *ccold, unsigned i) {
    auto cc = unpack2(ccold[i]);
    if (cc.second == 3) {
        auto ccparent = unpack2(ccold[p[i]]);
        return pickfree(cc.first, ccparent.second);
    } else {
        return cc.second;
    }
}

#endif
