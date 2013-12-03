#include "colour-interface.h"
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
    FOREACH(i, n, c[i] = reduce(cold[i], cold[p[i]]));
}

static void reduce12_6(unsigned n, const unsigned *p, col_t *c, const col_t *cold) {
    Timer t {"colour 12 -> 6"};
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
    reduce64_12(n, p, c2, c);
    reduce12_6(n, p, c, c2);
    reduce6_4(n, p, c2, c);
    reduce4_3(n, p, c, c2);
}
