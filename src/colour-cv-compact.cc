#include "colour-interface.h"
#include <cassert>
#include <memory>
#include "parallel.h"
#include "reduce.h"
#include "timer.h"

static void colour64(unsigned n, const unsigned *p, col_t *c) {
    Timer t {"colour n -> 64"};
    FOREACH(i, n, c[i] = reduce(i, p[i]));
}

static void reduce64_12(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 64 -> 12"};
    unsigned n2 {n/2};
    FOREACH(i, n2, c[i] = pack2(
        reduce(cold[2*i + 0], cold[p[2*i + 0]]),
        reduce(cold[2*i + 1], cold[p[2*i + 1]])
    ));
}

static void reduce12_6(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 12 -> 6"};
    unsigned n2 {n/2};
    FOREACH(i, n2, c[i] = pack2(
        reduce12_6(unpack2(cold[i], 0), get2(cold, p[2*i + 0])),
        reduce12_6(unpack2(cold[i], 1), get2(cold, p[2*i + 1]))
    ));
}

static void reduce6_4(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 6 -> 4"};
    unsigned n4 {n/4};
    FOREACH(i, n4, c[i] = pack4(
        reduce6_4(unpack2(cold[2*i + 0], 0), get2(cold, p[4*i + 0])),
        reduce6_4(unpack2(cold[2*i + 0], 1), get2(cold, p[4*i + 1])),
        reduce6_4(unpack2(cold[2*i + 1], 0), get2(cold, p[4*i + 2])),
        reduce6_4(unpack2(cold[2*i + 1], 1), get2(cold, p[4*i + 3]))
    ));
}

static void reduce4_3(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 4 -> 3"};
    FOREACH(i, n, c[i] = reduce4_3_pack(p, cold, i));
}

void colour(unsigned n, const unsigned *p, col_t *c) {
    assert((n & 3) == 0);

    std::unique_ptr<col_t[]> tmp { new col_t[n/2] };
    col_t *c2 {tmp.get()};
    colour64(n, p, c);
    reduce64_12(n, p, c2, c);
    reduce12_6(n, p, c, c2);
    reduce6_4(n, p, c2, c);
    reduce4_3(n, p, c, c2);
}
