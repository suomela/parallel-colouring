#ifndef PARALLEL_H
#define PARALLEL_H

#if defined(PARALLEL_TBB)

#include "tbb/tbb.h"

#define FOREACH(x) do { \
    parallel_for(tbb::blocked_range<unsigned>(0,n), \
        [=](const tbb::blocked_range<unsigned>& r) { \
            for (unsigned i {r.begin()}; i != r.end(); ++i) { \
                x; \
            } \
        } \
    ); \
} while (false);

#elif defined(PARALLEL_OPENMP)

#define FOREACH(x) do { \
    _Pragma("omp parallel for") \
    for (unsigned i = 0; i < n; ++i) { \
        x; \
    } \
} while (false);

#else

#define FOREACH(x) do { \
    for (unsigned i {0}; i < n; ++i) { \
        x; \
    } \
} while (false);

#endif

#endif
