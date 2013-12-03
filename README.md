Parallel Colouring
==================

3-colouring directed pseudoforests (each node has 1 parent).


Requirements
------------

Linux:

- G++ 4.7
- Threading Building Blocks (apt-get install libtbb-dev)

OS X:

- Xcode
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


Implementations
---------------

colour-naive

- Follow pointers towards parents

- Pick a free colour from {0,1,2} for each node

colour-cv

- Colour reduction n -> 64 -> 12 -> 6 -> 4
  (compare my colour to the colour of my parent)

- Colour reduction 4 -> 3
  (eliminate colour 4, look at parent & parent-of-parent)

colour-cv-compact

- Similar to colour-cv

- More compact storage of temporary data

colour-cv-shift

- Similar to colour-cv

- The last phase is done in two steps


Extending
---------

- Create a new file colour-xxx.cc that implements function "colour".

- Update "SConscript" accordingly.
