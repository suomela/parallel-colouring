#include "hist.h"
#include <iostream>
#include <vector>

void histogram(unsigned n, const col_t *c, col_t colours) {
    std::vector<unsigned> stat(colours);
    for (unsigned i {0}; i < n; ++i) {
        ++stat[c[i]];
    }
    std::cout << "histogram:\n";
    for (unsigned j {0}; j < colours; ++j) {
        std::cout << j << ": " << stat[j] << "\n";
    }
    std::cout << std::flush;
}
