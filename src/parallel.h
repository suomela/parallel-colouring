#ifndef PARALLEL_H
#define PARALLEL_H

#if defined(PARALLEL_TBB)

#include "tbb/tbb.h"

#define FOREACH(i,n,x) do { \
    parallel_for(tbb::blocked_range<unsigned>(0,n), \
        [=](const tbb::blocked_range<unsigned>& r_foreach) { \
            for (unsigned i {r_foreach.begin()}; i != r_foreach.end(); ++i) { \
                x; \
            } \
        } \
    ); \
} while (false);

#elif defined(PARALLEL_OPENMP)

#define FOREACH(i,n,x) do { \
    _Pragma("omp parallel for") \
    for (unsigned i = 0; i < n; ++i) { \
        x; \
    } \
} while (false);

#else

#define FOREACH(i,n,x) do { \
    for (unsigned i {0}; i < n; ++i) { \
        x; \
    } \
} while (false);

#endif

#endif
