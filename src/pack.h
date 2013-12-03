#ifndef PACK_H
#define PACK_H

#include <utility>
#include "colour.h"

inline col_t pack2(col_t a, col_t b) {
    return static_cast<col_t>(a | (b << 4));
}

inline std::pair<col_t, col_t> unpack2(col_t a) {
    return std::make_pair(a & 0xF, (a >> 4) & 0xF);
}

#endif
