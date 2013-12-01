#include "colour-interface.h"
#include "reduce.h"

void colour(unsigned n, const unsigned *p, col_t *c) {
    for (unsigned i {0}; i < n; ++i) {
        c[i] = NONE;
    }
    for (unsigned j {0}; j < n; ++j) {
        unsigned i {j};
        col_t cprev {2};
        col_t cthis {c[i]};
        while (cthis == NONE) {
            unsigned next {p[i]};
            col_t cnext {c[next]};
            col_t cnew {pickfree(cprev, cnext)};
            c[i] = cnew;
            i = next;
            cprev = cnew;
            cthis = cnext;
        }
    }
}
