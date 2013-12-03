#ifndef PACK_H
#define PACK_H

#include <utility>
#include "colour.h"

inline col_t pack2(col_t a, col_t b) {
    return static_cast<col_t>(a | (b << 4));
}

inline col_t pack4(col_t a, col_t b, col_t c, col_t d) {
    return static_cast<col_t>(a | (b << 2) | (c << 4) | (d << 6));
}

inline std::pair<col_t, col_t> unpack2(col_t a) {
    return std::make_pair(a & 0xF, (a >> 4) & 0xF);
}

inline col_t unpack2(col_t a, unsigned which) {
    return (a >> (4*which)) & 0xF;
}

inline col_t unpack4(col_t a, unsigned which) {
    return (a >> (2*which)) & 0x3;
}

inline col_t get2(const col_t *c, unsigned i) {
    return unpack2(c[i >> 1], i & 1);
}

inline col_t get4(const col_t *c, unsigned i) {
    return unpack4(c[i >> 2], i & 3);
}

#endif
