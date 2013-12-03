#!/usr/bin/env python

import itertools

print """#include "reduce.h"

constexpr unsigned b0 {0x01};
constexpr unsigned b1 {0x02};
constexpr unsigned b2 {0x04};
constexpr unsigned b3 {0x08};
constexpr unsigned b4 {0x10};
constexpr unsigned b5 {0x20};
constexpr unsigned b6 {0x40};
constexpr unsigned b7 {0x80};
"""

for n,k,c in ((4,2,6), (5,2,8), (6,3,12), (8,4,64)):
    l = sorted(list(itertools.combinations(range(n), k)), key=lambda x: tuple(reversed(x)))
    assert len(l) >= c
    print "// {}-subsets of {{1,...,{}}}".format(k, n)
    if len(l) > c:
        print "// (first {})".format(c)
    print
    print "const unsigned SET_{}_{}[{}] {{".format(c, n, c)
    for v in l[:c]:
        print "    " + ' | '.join("b{}".format(x) for x in v) + ","
    print "};"
    print
