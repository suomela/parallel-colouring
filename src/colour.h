#ifndef COLOUR_H
#define COLOUR_H

#include <limits>

using col_t = unsigned char;
constexpr col_t NONE {std::numeric_limits<col_t>::max()};

#endif
