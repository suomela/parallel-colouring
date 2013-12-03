#include "colour-interface.h"
#include <memory>
#include "parallel.h"
#include "reduce.h"
#include "timer.h"

static void colour64(unsigned n, const unsigned *p, col_t *c) {
    Timer t {"colour n -> 64"};
    FOREACH(i, n, c[i] = reduce(i, p[i]));
}

static void reduce64_8(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 64 -> 8"};
    FOREACH(i, n, c[i] = reduce64_8(cold[i], cold[p[i]]));
}

static void reduce8_5(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 8 -> 5"};
    FOREACH(i, n, c[i] = reduce12_6(cold[i], cold[p[i]]));
}

static void reduce6_4(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 6 -> 4"};
    FOREACH(i, n, c[i] = reduce6_4(cold[i], cold[p[i]]));
}

static void reduce4_3(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 4 -> 3"};
    FOREACH(i, n, c[i] = reduce4_3(p, cold, i));
}

void colour(unsigned n, const unsigned *p, col_t *c) {
    std::unique_ptr<col_t[]> tmp { new col_t[n] };
    col_t *c2 {tmp.get()};
    colour64(n, p, c);
    reduce64_8(n, p, c2, c);
    reduce8_5(n, p, c, c2);
    reduce6_4(n, p, c2, c);
    reduce4_3(n, p, c, c2);
}
