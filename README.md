Parallel Colouring
==================

Requirements
------------

Linux:

- G++ 4.7
- Threading Building Blocks (apt-get install libtbb-dev)

OS X:

- XCode
- Threading Building Blocks (brew install tbb)


Compilation
-----------

    scons

Usage
-----

Sequential versions:

    build/colour-cv BITS
    build/colour-naive BITS

Parallel version (with Threading Building Blocks):

    build-tbb/colour-cv BITS

Parallel version (with OpenMP):

    build-omp/colour-cv BITS

Instance size: 2^BITS nodes.

Memory usage: approx. 6 x 2^BITS bytes. For example:

- BITS = 30: approx. 6 GB
- BITS = 31: approx. 12 GB

Try BITS = 25 first, it should take a couple of seconds.
